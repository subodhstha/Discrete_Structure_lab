// Program to implement the Extended Euclidean algorithm
#include<stdio.h>
int gcdEx(int a, int b, int* x, int* y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdEx(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
int main(){
    int a, b, x, y;
    printf("Enter any two number\n");
    scanf("%d %d",&a, &b);
    printf("The gcd of %d & %d is %d",a , b, gcdEx(a, b, &x, &y));
    return 0;
}