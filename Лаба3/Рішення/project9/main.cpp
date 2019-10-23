#include <iostream>
#include <math.h>
#include <stdio.h>


int main()
{
    //std::cout<<"Starting...\n";
    //zapyt i vivyd 2 mnozhin
    std::cout<<"Put the amount of array's a elements: ";
    int n;
    std::cin>>n;
    int a[n];
    std::cout<<"Put the amount of array's b elements: ";
    int x;
    std::cin>>x;
    int b[x];
    for (int i=0;i<n;i++)
    {
        p:std::cout<<"a["<<i<<"]= " ;
        std::cin>>a[i];
        if(std::cin.fail())
        {
            std::cin.clear();
            while(std::cin.get() != '\n');
            {
            std::cout << "Please enter a valid value.\n";
            }
            goto p;

        }
        if(a[i]==a[i-1])
        {
            std::cout<< "Don't input the same numbers.\n";
            goto p;
        }
    }
    for (int i=0;i<x;i++)
    {
        q:std::cout<<"b["<<i<<"]= ";
        std::cin>>b[i];
        if(std::cin.fail())
        {
            std::cin.clear();
            while(std::cin.get() != '\n');
            {
            std::cout << "Please enter a valid value.\n";
            }
            goto q;

        }
        if(b[i]==b[i-1])
        {
            std::cout<< "Don't input the same numbers.\n";
            goto q;
        }
    }
    //matryx
    int A[n][x];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<x; j++)
        {
            if((2*a[i]+1)<b[j])
            {
                A[i][j]=1;
            }
            else
            {
                A[i][j]=0;
            }
        }
    }
    //vyvodymo matrix(massyv A)
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<x;j++)
        {
            std::cout<<A[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    if(n=x)
    {
        //type of matrix: reflex
        int m=0;
        for (int i=0;i<n;i++)
    {
        if(A[i][i]==1)
        {
            m++;
        }
    }

    if(m==n)
    {
        std::cout<<"Reflex\n";
    }
    //antireflex
    int c=0;
    for (int i=0;i<n;i++)
    {
        if(A[i][i]==0)
        {
            c++;
        }
    }
    if(c==n)
    {
        std::cout<<"Antireflex\n";
    }
    if(c!=n&&m!=n)
    {
        std::cout<<"Not reflex, not antireflex\n";
    }
    //Symetry
    int z=0;
    for (int i=0;i<n;i++)
    {

        for(int j=1;j<x;j++)
        {
            if(A[i][j]==A[j][i])
            {
                z++;
            }
        }
    }
    //i need sum
    int sum=n*(x-1);
    if( z==sum)
    {
        printf("Symetry\n");
    }
    else
    {
        printf("Antisymetry\n");
    }
    }
    //transitivity
    int amount_of_tranzitivity = 0;
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<x;j++)
        {
            if(A[i][j]==1)
            {
                for(int k=0;k<x;k++)
                {
                    if(A[j][k]==1 && A[i][k]==1)
                    {
                        amount_of_tranzitivity++;
                    }
                }
            }
        }
    }
    if(amount_of_tranzitivity >=1)
    {
        std::cout<<"Tranzitivity\n";
    }
    //Antitranzitivity
    int amount_of_antitranzitivity = 0;
     for (int i=0;i<n-1;i++)
    {
        for(int j=0;j<x;j++)
        {
            if(A[i][j]==1)
            {
                for(int k=0;k<x;k++)
                {
                    if(A[j][k]==1 && A[i][k]==0)
                    {
                        amount_of_antitranzitivity++;
                    }
                }
            }
        }
    }
    if(amount_of_antitranzitivity >=1)
    {
        std::cout<<"Antitranzitivity\n";
    }
    if(amount_of_antitranzitivity<1&&amount_of_tranzitivity<1)
    {
        std::cout<<"No tranzitivity, no antitranzitivity";
    }
    return 0;
}

