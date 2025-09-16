print("Введите номер автомобиля: ")
s = input().strip()

print("Результат: ")
if len(s) != 6:
    print("No")
else:
    # проверяем первый символ (должна быть заглавная буква)
    if not s[0].isupper() or not s[0].isalpha():
        print("No")
    # проверяем следующие три символа (должны быть цифрами)
    elif not s[1:4].isdigit():
        print("No")
    # проверяем последние два символа (должны быть заглавными буквами)
    elif not s[4:6].isalpha() or not s[4:6].isupper():
        print("No")
    else:
        print("Yes")