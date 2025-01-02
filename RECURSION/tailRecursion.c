#include<stdio.h>

int fact(int n,int a)
{
    if(n==0)
    {
        return a;
    }
    else{
        return fact(n-1,a*n);
    }
}

int main()
{   
    int n;
    printf("Enter the number whose factorial you want:");
    scanf("%d",&n);
    printf("%d is the factorial of %d.",fact(n,1),n);
    return 0;

}