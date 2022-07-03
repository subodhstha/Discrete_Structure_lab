
// Programs to implement binary integer addition, multiplication, and division
#include<stdio.h>
#include<stdlib.h>
int binaryAdd(int n1, int n2)
{
    int carry;
    while (n2 != 0)
    {
        // calculate the carry and do a left shift
        carry = (n1 & n2) << 1;
        // calculating the sum
        n1 = n1 ^ n2;
        n2 = carry;
    }
    return n1;
}
// perform binary subtraction for the given values
int binarySub(int n1, int n2)
{
    int carry;
    // finding two's complement for n2 and add o/p with n1
    n2 = binaryAdd(~n2, 1);
    while (n2 !=0)
    {
        // calculating the carry and do a left shift
        carry = (n1 & n2) <<1;
        // calculate the sum
        n1 = n1 ^ n2;
        n2 = carry;
    }
    return n1;
}
// perform binary multiplication for the given values
int binaryMulti(int n1, int n2)
{
    int res = 0;
    for (int i = 0; i < n2; i++)
    {
        res = binaryAdd(res, n1);
    }
    return res;
}
// perform binary division for the given values
int binaryDiv(int n1, int n2)
{
    int res, count = 0, twosComp;
    if (n1 < n2)
    {
        printf("Division of %d & %d is %d \n", n1, n2, 0);
        return 0;
    }
    res = n1;
    twosComp = binaryAdd(~n2, 1);
    // add n1 with 2's complement of n2 continuously
    // until n1 becomes lesser value than n2
    // division of two number without using arithmetic operator
    for (int i = 0; res > 0; i++)
    {
        res = binaryAdd(res, twosComp);
        if (res <= 0)
        {
            if (res == 0)
            {
                count = binaryAdd(count, 1);
                break;
            }
            else
            {
                count = binaryAdd(count, 1);
            }
        }
        return count;
    }
    
}

int main(){
    int n1, n2, res, ch;
    while (1)
    {
        printf("1.Binary Addition\n");
        printf("2.Binary Subtraction\n");
        printf("3.Binary Multiplication\n");
        printf("4.Binary Division\n5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        if (ch != 5)
        {
            printf("Enter the value of n1 & n2\n");
            scanf("%d %d", &n1, &n2);
        }
        switch (ch)
        {
            case 1:
                res = binaryAdd(n1, n2);
                break;
            case 2:
                res = binarySub(n1, n2);
                break;
            case 3:
                res = binaryMulti(n1, n2);
                break;
            case 4:
                res = binaryDiv(n1, n2);
                break;
            case 5:
                exit(0);
        default:
            printf("Wrong option!\n");
            break;
        }
        printf("Result is %d\n", res);
    }
    return 0;
}