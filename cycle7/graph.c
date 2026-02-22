#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int adj[100][100];
void addEdge(int u,int v)
{
    adj[u][v]=1;
    adj[v][u]=1;
}
void dfs(int start,int v,bool visited[100])
{
    int stack[100];
    int top=-1;
    stack[++top]=start;
    while(top!=-1)
    {
        int curr=stack[top--];
        if(!visited[curr])
        {
            visited[curr]=true;
            printf("%d ",curr);
        }
        for(int i=v;i>=1;i--)
        {
            if(adj[curr][i]==1&&!visited[i])
            {
                stack[++top]=i;
            }
        }
    }
}
void bfs(int start,int v)
{
    bool visited[100]={false};
    int queue[100],front=0,rear=0;
    queue[rear++]=start;
    visited[start]=true;
    while(front<rear)
    {
        int curr=queue[front++];
        printf("%d ",curr);
        for(int i=1;i<=v;i++)
        {
            if(adj[curr][i]==1&&!visited[i])
            {
                queue[rear++]=i;
                visited[i]=true;
            }
        }
    }
}
int main()
{
    int e,ver,u,v;
    printf("\nenter the number of vertices: ");
    scanf("%d",&ver);
    printf("Enter the number of edges: ");
    scanf("%d",&e);
    printf("\nEnter the edges(u v)\n");
    int i=e;
    for(int i=1;i<=ver;i++)
    {
        for(int j=1;j<=ver;j++)
        {
            adj[i][j]=0;
        }
    }
    while(i>0)
    {
        scanf("%d %d",&u,&v);
        if(u>=1&&u<=ver&&v>=1&&v<=ver)
        {
            addEdge(u,v);
            i--;
        }
        else
        {
            printf("Invalid edge\n");
        }
    }
    for(int i=1;i<=ver;i++)
    {
        for(int j=1;j<=ver;j++)
        {
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
    bool visited[100]={false};
    dfs(1,ver,visited);
    printf("\n");
    bfs(2,ver);
}