// Program to Implement Euclidean algorithm.
#include<stdio.h>
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}
int main()
{
    int a, b;
    printf("Enter any two number\n");
    scanf("%d %d",&a ,&b);
    printf("The GCD of %d & %d is %d",a ,b ,gcd(a, b));
    return 0;
}