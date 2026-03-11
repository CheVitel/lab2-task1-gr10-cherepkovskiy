#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count_ones(int num) {
    int count = 0;
    while (num > 0) {
        if (num % 2 == 1) {
            count++;
        }
        num = num / 2;
    }
    return count;
}

void sort_by_ones(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (count_ones(arr[j]) > count_ones(arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int n;

    if (argc == 2) {
        n = atoi(argv[1]); 
    } else {
        printf("Введите размер массива n: ");
        scanf("%d", &n); 
    }

    if (n <= 0) {
        printf("Ошибка: размер должен быть положительным\n");
        return 1;
    }

    int arr[n];

    srand(time(NULL)); 

    printf("Сгенерированный массив (%d случайных чисел):\n", n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1; 
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nКоличество единиц в двоичной записи:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d единиц\n", arr[i], count_ones(arr[i]));
    }

    sort_by_ones(arr, n);

    printf("\nОтсортированный массив (по возрастанию количества единиц):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}