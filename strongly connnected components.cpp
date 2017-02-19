#include<iostream>
#include<cstdlib>
using namespace std;
long long int arr[875714][875714],visited[875714],a[875714][875714];
long long int t=0,order[875714],finish[875714],leader[875714],parent=1;
void dfs_reverse(long long int i,long long int n)
{
	long long int j;
	visited[i]=1;
	for(j=1;j<=n;j++)
	{
		if(a[i][j]==1)
		{
		
		if(!visited[j])
		{
			dfs_reverse(j,n);
			
		}
	}
	
}
	t++;
	finish[i]=t;

}
void dfs(long long int i,long long int n)
{
	long long int j;
	visited[i]=1;
	leader[i]=parent;
	for(j=1;j<=n;j++)
	{
		if(arr[i][j]==1)
		{
			if(!visited[j])
			{
				dfs(j,n);
			}
		}
	}
}
int main()
{
	long long int n,e,i,u,v,j;
	cin>>n>>e;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			arr[i][j]=0;
		}
	}
	for(i=0;i<e;i++)
	{
		cin>>u>>v;
		arr[u][v]=1;
		a[v][u]=1;
	}
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	for(i=n;i>=1;i--)
	{
		if(!visited[i])
		{
			dfs_reverse(i,n);
		}
		order[finish[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}


	long long int count=0;
	for(i=n;i>=1;i--)
	{
		if(!visited[order[i]])
		{
			parent=order[i];
			dfs(order[i],n);
			count++;
		}
	}
	cout<<endl<<count;
	
	
	
	return 0;
	
}
