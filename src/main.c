#include <stdio.h>

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

int main() {
    int n;

    printf("Введите размер массива n: ");
    scanf("%d", &n);

    int arr[n];

    printf("Введите %d натуральных чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nИсходный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Количество единиц в двоичной записи:\n");
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