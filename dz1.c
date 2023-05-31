#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#define INPUT_SIZE 11 //максимальная длина введенного числа +1. Взяли таким тк макс длина int 10

uint64_t  input (void), fool_defence ();
void dec_to_bool (uint64_t ); //исп ф-и

int main () {
    system("chcp 65001"); //правильное отображение кириллицы
    puts("введите размер множества:");
    uint64_t size = fool_defence(); 
    uint64_t i, j, multiplicity[size], dec_to_bool_mas[size], temp;
    bool uniq_ctr = true;

    puts("введите элементы множества:");
    for (i = 0; i < size; ++i) {
        temp = fool_defence ();
        while (true) { //проверка на повтор элемента
            for (j = 0; j < i; j++) {
                if (temp == multiplicity[j])
                uniq_ctr = false; //счетчик повторов
            }
            if (uniq_ctr) {
                multiplicity[i] = temp;
                break;
            } else {
                puts("такой элемент уже существует. Введите еще раз:");
                uniq_ctr = true;
                temp = fool_defence ();
            }
        }
    }

    puts("исходное множество:");
    for (uint64_t i = 0; i < size; ++i)
        printf ("%d\t", multiplicity[i]);
    puts("\nмножество двоичных чисел:");
    for (i = 0; i < size; ++i) {                  //выводим множество переведенных двоичных чисел
        dec_to_bool(multiplicity[i]);
        putchar('\t');
    }
}

uint64_t input (void) { //ввод только числа. Если была введена строка с цифрами, то будут записаны только цифры
    char symb;
    char nums[INPUT_SIZE + 1]; //строка с числом
    uint64_t i, result = 0;

    i = 0;
    while ((symb = getchar()) != '\n' && i < INPUT_SIZE) //резервируем 1 ячейку под символ конца строки \0
        if (symb >= '0' && symb <= '9') {
            nums[i] = symb - '0';
            i++;
        }
    if (!i) return -1; //проверка того, была ли введена хоть одна цифра    
    nums[i] = '\0'; //i == длине строки

    uint64_t increase = 1;

    for(i; i >= 1; i--) {
        result += (nums[i - 1]) * increase;
        increase *= 10;
    }
    return result;
}

uint64_t fool_defence () { //защита от дурака
    int64_t outp;
    while ((outp = input()) < 0) {
        puts("Некорректный ввод, попробуй ещё раз:");
    }
    return (uint64_t) outp;
}

void dec_to_bool (uint64_t n) {  //прога для перевода 10->2
    if (n >= 2)
        dec_to_bool(n / 2);
    putchar('0' + n % 2);
}  