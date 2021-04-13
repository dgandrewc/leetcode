#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<vector<int>> v(201, vector<int>(201));
vector<int> visit(201);

void dfs(int x)
{
	for(int i=1; i<n+1; i++)
	{
		if(v[x][i]==1 && visit[i]==0)
		{
			visit[i]=1;
			dfs(i);
		}
	}
}

int main(void)
{
	cin >> n >> m;
	
	vector<int> order(m);
	
	for(int i=1; i<n+1; i++)
		for(int j=1; j<n+1; j++)
			cin >> v[i][j];
	
	for(int i=0; i<m; i++)
		cin >> order[i];
	
	visit[order[0]]=1;
	dfs(order[0]);
	
	for(int i=0; i<order.size(); i++)
	{
		if(visit[order[i]]==0)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}