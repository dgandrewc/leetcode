#include<iostream>
//#include<vector>
#include<queue>

using namespace std;

int INF=1000000000;

vector<vector<pair<int, int>>> graph(20001);
int dis[20001];

int main(void)
{
	int v, e;
	cin >> v >> e;
	int k;
	cin >> k;
	
	for(int i=0; i<20001; i++)
		dis[i]=INF;
	
	for(int i=0; i<e; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		graph[t1].push_back(pair(t2, t3));
	}
	
	dis[k]=0;
	priority_queue<pair<int, int>> pq;
	pq.push(pair(0, k));
	
	while(!pq.empty())
	{
		int x=pq.top().second;
		pq.pop();
		
		for(int i=0; i<graph[x].size(); i++)
		{
			int new_v=dis[x]+graph[x][i].second;
			int bef_v=dis[graph[x][i].first];
			
			if(new_v<bef_v)
			{
				dis[graph[x][i].first]=new_v;
				pq.push(pair(-1*new_v, graph[x][i].first));
			}
		}
	}
	
	for(int i=1; i<v+1; i++)
	{
		if(dis[i]==INF)
			cout << "INF" << '\n';
		else
			cout << dis[i] << '\n';
	}
	
	
	return 0;
}