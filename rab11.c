#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

#define N 10
#define M 100

float preobr(float a);
float srednee(float* A, int n);
double f(double x);
double nakop(double* m, int n, int znak, int* k);

int main()
{
    setlocale(LC_ALL, "Rus");
    float A[N], B[N], temp, sr;
    double y[M], a = 0.1, b = 2.1, h, sp, so, x;
    int i, kp, ko;

    printf("Задание 1\n");
    for (i = 0; i < N; i++)
    {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
    }
    for (i = 0; i < N; i++)
        B[i] = preobr(A[i]);

    printf("| индекс | исходное значение | новое значение |\n");
    for (i = 0; i < N; i++)
        printf("| %6d | %17.2f | %14.2f |\n", i, A[i], B[i]);

    sr = srednee(A, N);
    printf("среднее арифметическое = %.3f\n", sr);

    printf("\nЗадание 2\n");
    h = (b - a) / (M - 1);
    for (i = 0; i < M; i++)
    {
        x = a + i * h;
        y[i] = f(x);
    }
    sp = nakop(y, M, 1, &kp);
    so = nakop(y, M, -1, &ko);

    if (kp > 0)
        printf("массив y: сумма+ = %.4lf, сумма- = %.4lf, кол-во+ = %d, кол-во- = %d, среднее+ = %.4lf\n",
            sp, so, kp, ko, sp / kp);
    else
        printf("массив y: положительных элементов нет\n");

    return 0;
}

float preobr(float a)
{
    return 2 * a;
}

float srednee(float* A, int n)
{
    float s = 0;
    int i;
    for (i = 0; i < n; i++)
        s += A[i];
    return s / n;
}

double f(double x)
{
    return x * x + sin(5 * x);
}

double nakop(double* m, int n, int znak, int* k)
{
    double s = 0;
    int i;
    *k = 0;
    for (i = 0; i < n; i++)
        if (m[i] * znak > 0)
        {
            s += m[i];
            (*k)++;
        }
    return s;
}