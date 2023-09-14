#include<bits/stdc++.h>
using namespace std;
const int N=52;
int ans,n,m,l1[N][N],l2[N][N],cnt1,cnt2,cnt,head[N*N],vis[N*N],pir[N*N];
string mp[N];
struct node{
	int to,nxt;
}edge[N*N];
void add(int x,int to)
{
	edge[++cnt].to=to;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
	return;
}
bool dfs(int x,int tag)
{
	if(vis[x]==tag)
	return 0;
	vis[x]=tag;
	for(int i=head[x];i!=0;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(pir[to]==0||dfs(pir[to],tag)==1)
		{
			pir[to]=x;
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>mp[i];
		mp[i]=" "+mp[i];
	}
	for(int i=1;i<=m+1;i++)
	{
		mp[0]+=" ";
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='#')
			continue;
			if(mp[i][j-1]==' '||mp[i][j-1]=='#')
			l1[i][j]=++cnt1;
			else
			l1[i][j]=cnt1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[i][j]=='#')
			continue;
			if(mp[i][j-1]==' '||mp[i][j-1]=='#')
			l2[i][j]=++cnt2;
			else
			l2[i][j]=cnt2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='#'||mp[i][j]=='x')
			continue;
			add(l1[i][j],l2[i][j]);
		}
	}
	for(int i=1;i<=cnt1;i++)
	{
		if(dfs(i,i)==1)
		ans++;
	}
	cout<<ans;
	return 0;
}