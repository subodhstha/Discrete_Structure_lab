// Program to implement linear search recursively
#include<stdio.h>
int recursiveLS(int arr[], int value, int index, int n)
{
    int pos = 0;
    if (index >= n)
    {
        return 0;
    }
    else if (arr[index] == value)
    {
        pos = index + 1;
        return pos;
    }
    else
    {
        return recursiveLS(arr, value, index+1, n);
    }
    return pos;
}
int main()
{
    int n, value, pos, m=0, arr[100];
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the element of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to search \n");
    scanf("%d",&value);
    pos = recursiveLS(arr, value, 0, n);
    if (pos != 0)
    {
        printf("Element found at pos %d",pos);
    }
    else
    {
        printf("Element not found");
    }
    return 0;
}