#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> line;
bool visit[20001], colors[20001];
bool isCycle=false;

void dfs(int x)
{
	visit[x]=true;
	
	for(int i=0; i<line[x].size(); i++)
	{
		if(!visit[line[x][i]])
		{
			colors[line[x][i]]=!colors[x];
			dfs(line[x][i]);
		}
		else if(colors[line[x][i]]==colors[x])
		{
			isCycle=true;
			return;
		}
	}
}

int main(void)
{
	int k;
	cin >> k;
	
	for(int i=0; i<k; i++)
	{
		int v, e;
		cin >> v >> e;
		line.clear();
		
		for(int j=0; j<v+1; j++)
		{
			vector<int> temp;
			line.push_back(temp);
			visit[j]=false;
			colors[j]=false;
			isCycle=false;
		}
		
		for(int j=0; j<e; j++)
		{
			int t1, t2;
			cin >> t1 >> t2;
			line[t1].push_back(t2);
			line[t2].push_back(t1);
		}
		
		for(int j=1; j<v+1; j++)
			if(!visit[j])
				dfs(j);
		
		if(isCycle)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}