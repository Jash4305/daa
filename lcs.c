#include <stdio.h>
#include <string.h>
#define MAX 9999
int w[MAX][MAX], d[MAX][MAX];
void LCS(char x[], char y[])
{
    int m = strlen(x);
    int n = strlen(y);
    for(int k=0;k<=m;k++)
    w[k][0]=0;//initialing zero at first row
    for(int l=0;l<=n;l++)
    w[0][l]=0;//initialing zero at first column
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                w[i][j]=w[i-1][j-1]+1;
                d[i][j]=-1;// -1=>diagonal
            }
            else if(w[i-1][j]>w[i][j-1])
            {
                w[i][j]=w[i-1][j];
                d[i][j]=-2;// -2=> up
            }
            else
            {
                w[i][j]=w[i][j-1];
                d[i][j]=-3;// -3=> left
            }
        }
    }
}
void print_lcs(char x[],int i,int j,int n, char a[])
{
    if(d[i][j]==-1)
    {
        a[n-1]=x[i-1];
        print_lcs(x,i-1,j-1,n-1,a);
    }
    else if(d[i][j]==-3)
    print_lcs(x,i,j-1,n,a);
    else if(d[i][j]==-2)
    print_lcs(x,i-1,j,n,a);
}
void main()
{
    char x[1000], y[1000];
    char ans[1000];
    int n,m;
    printf("Enter string 1 : ");
    scanf("%s", &x);
    printf("Enter string 2 : ");
    scanf("%s", &y);
    LCS(x,y);
    n = w[strlen(x)][strlen(y)];
    print_lcs(x,strlen(x),strlen(y),n,ans);
    for(int l=0;l<n;l++)
    printf("%c",ans[l]);
}