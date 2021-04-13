#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
vector<vector<pair<int, int>>> graph(10001);
vector<int> visit(10001);
int s, e;

bool bfs(int c)
{
	queue<int> q;
	q.push(s);
	visit[s]=1;
	while(!q.empty())
	{
		int cf=q.front();
		q.pop();
		if(cf==e)
			return true;
		
		for(int i=0; i<graph[cf].size(); i++)
		{
			if(!visit[graph[cf][i].first] && c<=graph[cf][i].second)
			{
				visit[graph[cf][i].first]=1;
				q.push(graph[cf][i].first);
			}
		}
	}
	return false;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	
	for(int i=0; i<m; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		graph[t1].push_back(pair(t2, t3));
		graph[t2].push_back(pair(t1, t3));
	}
	
	cin >> s >> e;
	
	int low=0, high=1000000000;
	while(low<=high)
	{
		fill(visit.begin(), visit.end(), 0);
		int mid=(low+high)/2;
		if(bfs(mid))
			low=mid+1;
		else
			high=mid-1;
	}
	cout << high << '\n';
	return 0;
}