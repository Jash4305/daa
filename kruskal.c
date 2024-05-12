#include <stdio.h>
#include<limits.h>

int par[10];
int uni(int i,int j)
{
    if(i!=j)
    {
        par[j]=i;
        return 1;
    }
    return 0;
}
int find(int i)
{
    while(par[i])
    i=par[i];
    return i;
}
void main()
{
    int graph[5][5]={{0,1,7,10,5},
                    {1,0,3,0,0},
                    {7,3,0,4,0},
                    {10,0,4,0,2},
                    {5,0,0,2,0}};
    int min=INT_MAX,minCost=0,ne=0,a,u,b,v,i,j,n=5;
    while(ne<n-1)
    {
        min = INT_MAX;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(graph[i][j]<min && graph[i][j]!=0)
                {
                    min=graph[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            printf("Edge %d:(%d %d) cost:%d\n",++ne,a,b,min);
            minCost+=min;
        }
        graph[a][b]=graph[b][a]=0;
    }
    printf("Minimum cost:%d\n",minCost);
}