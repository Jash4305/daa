#include<stdio.h>
int inframe(int f[], int nf, int v)
{
    for(int i=0;i<nf;i++)
    {
        if(f[i]==v)
        return 1;
    }
    return 0;
}
int replace(int d[], int f[], int pos,int nf)
{
    int freq[100],ind[100],min = 999999,index=pos,frind;
    for(int i=0;i<nf;i++)
    {
        freq[i]=0,ind[i]=0;
        for(int j=pos;j>=0;j--)
        {
            if(d[j]==f[i])
            {
                freq[i]++;
                ind[i]=j;
            }
        }
        if(freq[i]<=min && ind[i]<index)
        {
            min = freq[i];
            index = ind[i];
            frind = i;
        }
    }
    return frind;
}
void main()
{
    int data[]={1,2,3,4,2,1,5,3,2,4,6};
    int n = sizeof(data)/sizeof(data[0]);
    int frame[100],nf=3,j,hit=0;
    for(int i=0;i<nf;i++)
    frame[i]=-1;
    for(int i=0;i<n;i++)
    {
        if(frame[i]==-1 && i<nf)
        frame[i]=data[i];
        else if(inframe(frame,nf,data[i])==1)
        hit++;
        else
        {
            int r = replace(data,frame,i,nf);
            frame[r]= data[i];
        }
        printf("\n%d -> ",data[i]);
        for(int l=0;l<nf;l++)
        printf("%d ",frame[l]);
    }
    printf("\nhits : %d and Faults : %d\n",hit, n-hit);
}