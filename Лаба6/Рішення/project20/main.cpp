#include <stdio.h>
#include <iostream>
//#include <cs50.h>

int fact(int n);
int C(int k);

int main()
{
    int n;
    std::cin>> n;
    int arr[n];
    for(int i=0;i<n;i++)
    arr[i]=i+1;
    int j;
    for(int i=0;i<n;i++)
    {
    for(j=i;j<n;j++)
    printf("{%d;%d} ",arr[i],arr[j]);
    printf("\n");
    }
    std::cout<< "\n";
    printf("BINOM PART\n");
    for(int i=0;i<=5;i++)
    {
        printf("%d*(-y)^%d*x^%d + ", C(i),i,6-i);
    }
    printf("%d*(-y)^%d*x^%d\n", C(6),6,6-6);
}

int C(int k)
{
    int C=fact(6)/(fact(6-k)*fact(k));
    return C;
}

int fact(int n)
{
    return (n < 2) ? 1 : n * fact (n - 1);
}
