// Вариант 2. С одномерным массивом, состоящим из n вводимых с клавиатуры
// положительных и отрицательных целых чисел, вычислить количество элементов
// массива, расположенных между первым и последним нулевыми элементами.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

#define NMAX 100

int mezhdu(int* m, int n);

int main()
{
    setlocale(LC_ALL, "Rus");
    int m[NMAX], n, i, k;

    printf("n = ");
    scanf("%d", &n);
    if (n < 1 || n > NMAX)
    {
        printf("ошибка\n");
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        printf("m[%d] = ", i + 1);
        scanf("%d", &m[i]);
    }

    k = mezhdu(m, n);
    if (k < 0) printf("в массиве меньше двух нулей\n");
    else printf("между первым и последним нулем %d элементов\n", k);

    return 0;
}

int mezhdu(int* m, int n)
{
    int i, first = -1, last = -1;
    for (i = 0; i < n; i++)
        if (m[i] == 0)
        {
            if (first == -1) first = i;
            last = i;
        }
    if (first == last) return -1;
    return last - first - 1;
}