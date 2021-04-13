#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> d(n+1);
		vector<int> pre(n+1, 0);
		vector<vector<int>> suc(n+1);
		
		for(int i=1; i<n+1; i++)
			cin >> d[i];
		for(int i=0; i<k; i++)
		{
			int x, y;
			cin >> x >> y;
			suc[x].push_back(y);
			pre[y]++;
		}
		int w;
		cin >> w;
		
		vector<int> result(n+1, 0);
		queue<int> q;
		
		for(int i=1; i<n+1; i++)
			if(!pre[i])
				q.push(i);
		
		while(pre[w]>0)
		{
			int u=q.front();
			q.pop();
			for(int i=0; i<suc[u].size(); i++)
			{
				result[suc[u][i]]=max(result[suc[u][i]], result[u]+d[u]);
				if(--pre[suc[u][i]]==0)
					q.push(suc[u][i]);
			}
		}
		cout << result[w]+d[w] << '\n';
	}
	return 0;
}