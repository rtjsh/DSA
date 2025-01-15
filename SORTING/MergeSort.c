#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Merge(int A[], int l,int m,int r)
{
    int i,j,k,B[100000];
    i=l;
    j=m;
    k=l;
    while(i<m && j<=r)
    {
        if(A[i]<A[j])
        {
            B[k++]=A[i++];
        }
        else{
            B[k++]=A[j++];
        }
    }
    for( ;i<m;i++,k++)
    {
        B[k]=A[i];
    }
    for( ;j<=r;j++,k++)
    {
        B[k]=A[j];
    }
    for(k=l;k<=r;k++)
    {
        A[k]=B[k];
    }

}
void MergeSort(int A[],int l,int r)
{
    int m;
    if(l<r)
    {
        m=(l+r)/2;
        MergeSort(A,l,m);
        MergeSort(A,m+1,r);
        Merge(A,l,m+1,r);
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
    clock_t start,end,diff;
    printf("Enter n:"); 
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        A[i]=rand();
    }
    // display(A,n);
    start=clock();
    MergeSort(A,0,n-1);
    end=clock();
    printf("The sorted numbers are:\n");
    // display(A,n);
    diff=end-start;
    printf("The time taken is %f seconds\n",(float)diff/CLOCKS_PER_SEC);
    return 0;
}
