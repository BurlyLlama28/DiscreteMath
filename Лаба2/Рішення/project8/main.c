#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n,x;
int main()
{
    printf("Array a elements:");
    scanf("%d",&n);
    int a[n];
    printf("Array b elements:");
    scanf("%d",&x);
    int b[x];
    for (int i=0;i<n;i++)
    {
        printf("a[%d]=",i);
        scanf("%d", &a[i]);
    }
    for (int i=0;i<x;i++)
    {
        printf("b[%d]=",i);
        scanf("%d", &b[i]);
    }
    printf("Pereriz = { ");
    int m = 0;
    for(int j=0;j<n;j++)
    {
        for (int i=0;i<x;i++)
        {
            if(a[j]==b[i]){
            printf("%d ",a[j]);
            m++;
            }
        }
    }
    printf("}\n");
    printf("|pereriz| = %d\n", m);
    int h=0;
    printf("Symetrychna riznytsya = { ");
    int c=0;
    for (int j=0;j<n;j++)
    {
        for(int i=0;i<x;i++)
        {
            if(a[j]!=b[i])
            {
            h++;
            }
        }
        if(h%x==0)
        {
            printf("%d ", a[j]);
            c++;
        }
        h=0;
    }
    int v=0;
    for(int j=0;j<x;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(b[j]!=a[i])
            {
            h++;
            }
        }
        if(h%n==0)
        {
            printf("%d ",b[j]);
            v++;
        }
        h=0;
    }
    printf("}\n");
    printf("|Symetrychna riznytsya| = %d\n",v+c);

    return 0;
}
