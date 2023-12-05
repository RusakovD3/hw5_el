# Тема кадры функций +gdb

Имеется программа (исходный код которой приводится ниже, компилировать с ключами: -fno-stack-protector -no-pie). Вам необходимо произвести анализ программы с помощью отладчика для выяснения длины массива для ввода пароля и адреса ветки условия проверки корректности ввода пароля, которая выполняется при условии совпадения паролей.Ввести пароль (строку символов)таким образом, чтобы перезаписать адрес возврата на выясненный адрес (есть символы которые нельзя ввести с клавиатуры, поэтому можно использовать перенаправление ввода(<) при запуске программы).

```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int IsPassOk(void);

int main(void){
  int PwStatus;

  puts("Enter password:");

  PwStatus = IsPassOk();

  if (PwStatus == 0) {
    printf("Bad password!\n");
    exit(1);
  } else {
    printf("Access granted!\n"); // Строка для которой нужно выяснить адрес
  }
  return 0;
}

int IsPassOk(void){
  char Pass[12];
  gets(Pass);
  return 0 == strcmp(Pass, "test");
}
```
## Компиляция
![Screenshot 2023-12-05 101346](https://github.com/RusakovD3/hw5_el/assets/103295869/ad85d0a3-5213-407f-9bd9-c6e9f6cea975)


## Disassemble
![Screenshot 2023-12-05 102206](https://github.com/RusakovD3/hw5_el/assets/103295869/9e621f92-b23b-4fc4-83f5-c41fb339d986)
Адрес возврата функции IsPassOk по дефолту: 0x0000555555555185
![Screenshot 2023-12-05 104930](https://github.com/RusakovD3/hw5_el/assets/103295869/08bed180-d104-4fb1-b8e9-4a1315a9424e)
Мне же нужно изменить его на 0x00005555555551ae (адрес успешно подобраного пароля)
