#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionSort(int A[],int n)
{
    int i,j,least,pos;
    for(i=0;i<n;i++)
    {
        least=A[i];
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<least)
            {
                least=A[j];
                pos=j;
            }
        }

    }
}

void display(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");

}

int main()
{
    int A[100000],n,i;
    srand(time(NULL));
    clock_t start,end,diff;
    printf("Enter n:"); 
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        A[i]=rand();
    }
    display(A,n);
    start=clock();
    selectionSort(A,n);
    end=clock();
    printf("The sorted numbers are:\n");
    display(A,n);
    diff=end-start;
    printf("The time taken is %f seconds\n",(float)diff/CLOCKS_PER_SEC);
    return 0;
}
