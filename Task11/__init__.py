import cv2
import numpy as np

# загружает изображение из файла
image = cv2.imread("test_1.jpg")
result_image = image.copy()

blurred_image = cv2.GaussianBlur(image, (11, 11), 0) #добавляет размытие к изображению
hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV) #преобразует изображение в цветовую модель HSV

hsv_min = np.array((36, 25, 25), np.uint8) #устанавливает минимальные значения для зеленого цвета
hsv_max = np.array((70, 255, 255), np.uint8)

green_mask = cv2.inRange(hsv_image, hsv_min, hsv_max) #создает маску для зеленого цвета, создает бинарную маску: 255 для зеленых пикселей, 0 для остальных
contours, hierarchy = cv2.findContours(green_mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE) #находит контуры на маске

    #findContours() - находит контуры на бинарном изображении
    #RETR_EXTERNAL - возвращает только внешние контуры (игнорирует дыры внутри)
    #CHAIN_APPROX_SIMPLE - упрощает контур (сохраняет только угловые точки)
    #contours - список найденных контуров
    #hierarchy - иерархия между контурами (здесь не используется)

for i, contour in enumerate(contours):
    if cv2.contourArea(contour) < 100: #если площадь контура меньше 100, то пропускаем
        continue
    
    x, y, w, h = cv2.boundingRect(contour) #находит прямоугольник, в который вписан контур
    center_x = int(x + w/2)
    center_y = int(y + h/2)
    
    cv2.circle(result_image, (center_x, center_y), 10, (0, 0, 255), -1)
    cv2.drawContours(result_image, [contour], -1, (255, 0, 0), 2)
    
    print(f"Объект {i+1}: центр в точке ({center_x}, {center_y}), размер: {w}x{h}")

cv2.imshow("Оригинальное изображение", image)
cv2.imshow("Зеленая маска", green_mask)
cv2.imshow("Результат с отмеченными центрами", result_image)

cv2.waitKey(0)
cv2.destroyAllWindows()
#исходное изображение -> размытие -> HSV конвертация -> цветовая маска -> нахождение контуров -> отрисовка результатов