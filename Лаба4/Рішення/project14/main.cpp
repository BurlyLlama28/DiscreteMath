#include <stdio.h>
#include <iostream>
#include <stdlib.h>
const int q = 11;
int MakeTrees(int n, int A[q][q]);
void RemoveRepeated(int n, int A[q][q]);
int AreInDifferentTrees(int n, int A[q][q], int first, int second);
void AddToTree(int n, int A[q][q],int first, int second);

int main()
{
    int A[10][10] =
       {0,2,5,7,0,0,0,0,0,0,0,
        2,0,0,0,7,0,7,0,0,0,0,
        5,0,0,0,5,4,0,0,0,0,0,
        7,0,0,0,0,3,1,0,0,0,0,
        0,7,5,0,0,0,0,4,1,0,0,
        0,0,4,3,0,0,0,4,0,2,0,
        0,7,0,1,0,0,0,0,3,2,0,
        0,0,0,0,4,4,0,0,0,0,3,
        0,0,0,0,1,0,3,0,0,0,6,
        0,0,0,0,0,2,2,0,0,0,4,
        0,0,0,0,0,0,0,3,6,4,0};
    RemoveRepeated(11, A);
    for (int i =1 ; i <= 7; i++)
    {
        std::cout<<"\nNodes with weight: "<< i<<": ";
        for (int j=1;j <=11;j++)
        {
            for (int k=1; k<=11; k++)
            {
                if (A[j-1][k-1] == i)
                {
                    std::cout<<" "<<j<<"-"<<k;;
                }
            }
        }
    }
    std::cout<<"\n";
    //Check sorted nodes and add to the tree

    int B[11][11];
    MakeTrees(11,B);
    std::cout<<"\n\nNew Tree: ";//weight 7 is max weight
    for (int i = 1; i<=7;i++)
    {
        //first node
        for (int j = 1; j<=11; j++)
        {
            //second node
            for (int k = 1 ; k<=11; k++)
            {
                if (A[j-1][k-1] == i && AreInDifferentTrees(11, B, j ,k))
                {
                    AddToTree(11, B,j,k);
                    std::cout<<" "<<j <<"-"<<k;
                }
            }
        }
    }
    return 0;
}

int MakeTrees(int n, int A[q][q])
{
    for (int i=0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            A[i][j] = 0;
        }
    }
    for (int i = 0; i<n; i++)
    {
        A[i][i] = i+1;
    }
    return A[n][n];
}

void RemoveRepeated(int n, int A[q][q])
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if (j < i)
            {
                A[i][j] = 0;
            }
        }
    }
}

int AreInDifferentTrees(int n, int A[q][q], int first, int second)
{
    int temp1, temp2;
    //Line
    for (int i = 0; i < n; i++)
    {
        temp1 = 0;
        temp2 = 0;
        //first element
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == first)
            {
                temp1 = 1;
            }
        }
        //second element
        for (int k = 0; k < n; k++)
        {
            if (A[i][k] == second)
            {
                temp2 = 1;
            }
        }
        if (temp1 && temp2)
        {
            return 0;
        }
    }
    return 1;
}

void AddToTree(int n, int A[q][q], int first, int second)
{
   int scndLine;
   for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < n; j++)
       {
           if (A[i][j] == second)
           {
               scndLine = i;
           }
       }
   }
   for (int i = 0; i < n; i++)
   {
       for ( int j = 0; j < n; j++)
       {
           if (A[i][j] == first)
           {
               for (int k = 0; k < n; k++)
               {
                   if (A[scndLine][k])
                   {
                       A[i][k] = A[scndLine][k];
                       A[scndLine][k] = 0;
                   }
               }
           }
       }
   }
}
