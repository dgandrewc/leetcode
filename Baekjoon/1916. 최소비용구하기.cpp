#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
long long INF=99999999999;

struct cmp
{
	bool operator()(pair<long long, long long> a, pair<long long, long long>b)
	{
		return a.second<b.second;
	}
};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m, start, end;
	cin >> n >> m;
	vector<vector<pair<long long, long long>>> cost(n+1);
	
	for(long long i=0; i<m; i++)
	{
		long long t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		cost[t1].push_back(pair(t2, t3));
	}

	cin >> start >> end;
	vector<long long> d(n+1, INF);
	d[start]=0;
	priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, cmp> pq;
	pq.push(pair(start, 0));
	while(!pq.empty())
	{
		long long current=pq.top().first;
		long long distance=pq.top().second;
		pq.pop();
		
		if(d[current]<distance)
			continue;
		
		for(long long i=0; i<cost[current].size(); i++)
		{
			long long next=cost[current][i].first;
			long long nextDistance=distance+cost[current][i].second;
			if(nextDistance<d[next])
			{
				d[next]=nextDistance;
				pq.push(pair(next, nextDistance));
			}
		}
	}
	cout << d[end] << '\n';
	return 0;
}