/**
* 1. Получив на вход параметры начала, конца и шага, сформировать арифметическую прогрессию.
* 2. Получив на вход параметры начала, количества членов и шага, сформировать геометрическую прогрессию.
*/
#include <stdio.h>

void arithm_progression(int start, int stop, int step) {
    if (start < stop && step < 0) {
        printf("Возрастающая прогрессия с отрицательным шагом. Проверьте входные данные.\n");
    }
    else if (start > stop && step > 0) {
        printf("Убывающая прогрессия с положительным шагом. Проверьте входные данные.\n");
    }
    else if (step == 0) {
        printf("%d. Шаг равен 0, последовательность остановилась на первом члене.\n", start);
    }
    else if (start == stop) {
        printf("%d. Start равен stop, Последовательность состоит из одного элемента.\n", start);
    }
    else if ((stop - start)*(stop-start) < step*step) {
            printf("Шаг прогрессии больше, чем диапазон элементов.\n");
        }
    else {
        int sign = 1;
        if (step < 0) {
            sign = -1;
        }
        for (int i = start*sign; i <= stop*sign; i += step*sign) {
            printf("%d ", i*sign);
        }
        printf("\n");
    }
}
void geom_progression(int start, int denominator, int number) {

    if (number <= 0) {
        printf("Количество членов меньше 1. Пустая последовательность.\n");
    }
    int counter = 0;
    for (int i = start; counter < number; i = i * denominator, counter++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main(void) {
    int start, stop, number, step, denominator;
    printf("Введите 3 числа: значения начала, конца и шага арифметической прогрессии:\n");
    scanf("%d%d%d", &start, &stop, &step);
    arithm_progression(start, stop, step);

    printf("Введите 3 числа: значения начала, знаменателя и количества членов геометрической прогрессии:\n");
    scanf("%d%d%d", &start, &denominator, &number);
    geom_progression(start, denominator, number);
    return 0;
}