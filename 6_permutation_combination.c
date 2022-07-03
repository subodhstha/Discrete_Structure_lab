// Programs to generate permutations and combinations
#include<stdio.h>
#include<conio.h>
long double fact(int p)
{
    long double facts = 1;
    for (int  i = 1; i <= p; i++)
    {
        facts = facts * i;
    }
    return (facts);
}
int ncr(int n, int r)
{
    return (fact(n) / (fact(r)* fact(n-r)));
}
int npr(int n, int r)
{
    return (fact(n)/fact(n-r));
}
int main()
{
    int n, r;
    printf("Enter the value of n & r \n");
    scanf("%d %d",&n ,&r);
    if (n >= r)
    {
        printf("%dC%d is %d\n",n ,r ,ncr(n,r));
        printf("%dP%d is %d\n",n ,r ,npr(n,r));
    }
    else
    {
        printf("Wrong Input");
    }
    return 0;
}