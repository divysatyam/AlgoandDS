#include<iostream>
#include<queue>
using namespace std;
int arr[100][100];
bool visited[100];
void bfs(int s,int n)
{
	int i;
  queue<int>q;
  q.push(s);
  while(!q.empty())
  {
    int x=q.front();
    q.pop();
    visited[x]=true;
    for(i=1;i<=n;i++)
    {
      if(arr[x][i]==1)
      {
        if (!visited[i]) {
          visited[i]=true;
          q.push(i);
        }
      }
      
    }
  
  }
}
int main()
{
  int n,e,i,j;
  cin>>n>>e;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      arr[i][j]=0;
    }
  }
  int u,v;
  for(i=1;i<=e;i++)
  {
  	cin>>u>>v;
  	arr[u][v]=1;
  	arr[v][u]=1;
  }
  for(i=1;i<=n;i++)
  {
    visited[i]=false;
  }
  int count=0;
  
  for(i=1;i<=n;i++)
  {
    if(!visited[i])
    {
    count++;  
    bfs(i,n);
  }
  }
  cout<<count;
  
  return 0;
}
