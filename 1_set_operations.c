// C program to perform the set operations (Union and Intersection)
#include<stdio.h>
int main()
{
    int p, k, ch, n1, n2, set1[20], set2[20], set3[20], flag, wish;
    printf("Enter the size of set1 \n");
    scanf("%d",&n1);
    printf("Enter the element of the set1\n");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d",&set1[i]);
    }
    printf("Enter the size of set2 \n");
    scanf("%d",&n2);
    printf("Enter the element of the set1\n");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d",&set2[i]);
    }
    do
    {
        printf("Choose any options\n");
        printf("Press 1 for UNION\n");
        printf("Press 2 for INTERSECTION\n");
        printf("Press 3 for DIFFERENCE\n");
        printf("Enter your choice \n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            k=0;
            for (int i = 0; i < n1; i++)
            {
                set3[k] = set1[i];
                k++;
            }
            for (int i = 0; i < n2; i++)
            {
                flag = 1 ;
                for (int j = 0; i < n1; j++)
                {
                    if (set2[i] == set1[j])
                    {
                        flag = 0;
                        break;
                    }   
                }
                if (flag == 1)
                {
                    set3[k] = set2[i];
                    k++;
                }
            }
            p = k;
            printf("The Union of two set are\n");
            printf("{");
            for (int k = 0; k < p; k++)
            {
                printf(" %d",set3[k]);
            }
            printf(" }\n");
            break;

        case 2:
            k=0;
            for (int i = 0; i < n2; i++)
            {
                flag = 1;
                for (int j = 0; j < n1; j++)
                {
                    if (set2[i] == set1[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 0)
                {
                    set3[k] = set2[i];
                    k++;
                }
            }
            p = k;
            printf("The Intersection of two set are\n");
            printf("{");
            for (int k = 0; k < p; k++)
            {
                printf(" %d",set3[k]);
            }
            printf(" }\n");
            break;

        case 3:
            k = 0;
            for (int i = 0; i < n1; i++)
            {
                flag = 1;
                for (int j = 0; j < n2; j++)
                {
                    if (set1[i] == set2[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1)
                {
                    set3[k] = set1[i];
                    k++;
                }
            }
            p = k;
            printf("The difference of two set are\n");
            printf("{");
            for (int k = 0; k < p; k++)
            {
                printf(" %d",set3[k]);
            }
            printf(" }\n");
            break;
    }
    printf("Do you want to continue(1/0)");
    scanf("%d",&wish);
    } while (wish == 1);
    return 0;
}