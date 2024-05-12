#include<stdio.h>
#include<limits.h>

int count=0;

int connection[4][4]={
    {0,3,INT_MAX-100,7},
    {8,0,2,INT_MAX-100},
    {5,INT_MAX-100,0,1},
    {2,INT_MAX-100,INT_MAX-100,0}
};

int parent[4][4]={
    {-1,1,-1,1},
    {2,-1,2,-1},
    {3,-1,-1,3},
    {4,-1,-1,-1},
};

int min(int a,int b)
{
    int c=a>b?b:a;
    return c;
}

void floyd_warshal()
{
    while(count<4)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(i!=count && j!=count) 
                {
                    int temp=connection[i][j];
                    connection[i][j]=min(connection[i][j],(connection[i][count]+connection[count][j]));
                    if(temp!=connection[i][j])
                    {
                        parent[i][j]=count+1;
                    }
                }
            }
        }

        count++;
    }
}

void main()
{
    floyd_warshal();

    printf("A:\n");
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",connection[i][j]);
        }
        printf("\n");
    }

    printf("Parent:\n");
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",parent[i][j]);
        }
        printf("\n");
    }


}