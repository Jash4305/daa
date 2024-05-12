#include<stdio.h>
#include<stdlib.h>
#define n 5

int max,min,a[n];

void maxmin(int a[],int first,int last)
{
    int max1,min1,mid;
    if(first==last)
    max=min=a[first];
    else if(first==last-1)
    {
        if(a[first]<a[last])
        {
            min=a[first];
            max=a[last];
        }
        else
        {
            min=a[last];
            max=a[first];
        }
    }
    else
    {
        mid=(first+last)/2;
        maxmin(a,first,mid);
        max1=max;
        min1=min;
        maxmin(a,mid+1,last);
        if(max1>max)
            max=max1;
        if(min1<min)
            min=min1;
    }
}
void main()
{
    int i;
    for(i=0;i<n;i++)
    {
        //scanf("%d",&a[i]);
        a[i]=rand()/100;
        printf("%d ",a[i]);
    }
    max=a[0];
    min=a[0];
    maxmin(a,0,n-1);
    printf("\nMax is %d\nMin is %d",max,min);
}