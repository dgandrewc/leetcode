#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> duration(501);
vector<int> inDegree(501);
vector<vector<int>> graph(501);
vector<int> result(501);
int n;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for(int i=1; i<=n; i++)
	{
		int time;
		cin >> time;
		
		duration[i]=time;
		while(1)
		{
			int node;
			cin >> node;
			
			if(node==-1)
				break;
			
			inDegree[i]++;
			graph[node].push_back(i);
		}
	}
	
	queue<int> q;
	
	for(int i=1; i<=n; i++)
	{
		if(inDegree[i]==0)
			q.push(i);
	}
	
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		
		for(int i=0; i<graph[node].size(); i++)
		{
			int nextNode=graph[node][i];
			
			result[nextNode]=max(result[nextNode], result[node]+duration[node]);
			
			if(--inDegree[nextNode]==0)
				q.push(nextNode);
		}
	}
	
	for(int i=1; i<=n; i++)
		cout << result[i]+duration[i] << '\n';
	
	return 0;
	
	return 0;
}