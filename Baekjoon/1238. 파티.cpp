#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<vector<pair<int, int>>> graph(1001);
int INF=987654321;

vector<int> dijkstra(int start, int vertex)
{
	vector<int> distance(vertex, INF);
	distance[start]=0;
	
	queue<pair<int, int>> pq;
	pq.push(pair(0, start));
	
	while(!pq.empty())
	{
		int cost=pq.front().first;
		int cur=pq.front().second;
		pq.pop();
		
		if(distance[cur]<cost)
			continue;
		
		for(int i=0; i<graph[cur].size(); i++)
		{
			int neighbor=graph[cur][i].first;
			int neighborDistance=cost+graph[cur][i].second;
			
			if(distance[neighbor]>neighborDistance)
			{
				distance[neighbor]=neighborDistance;
				pq.push({neighborDistance, neighbor});
			}
		}
	}
	return distance;
}

int main(void)
{
	int n, m, x;
	cin >> n >> m >> x;
	
	for(int i=0; i<m; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;
		
		graph[s].push_back(pair(e, c));
	}
	
	int result=-1;
	for(int i=1; i<n+1; i++)
	{
		vector<int> temp1=dijkstra(i, n+1);
		vector<int> temp2=dijkstra(x, n+1);
		
		result=max(result, temp1[x]+temp2[i]);
	}
	
	cout << result << '\n';
	return 0;
}