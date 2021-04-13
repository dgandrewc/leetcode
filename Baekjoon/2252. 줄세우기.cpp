#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	queue<int> q;
	vector<int> v[32001];
	
	vector<int> indegree(n+1, 0);
	
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		indegree[b]++; // b앞에 있어야 하는 학생 수
		v[a].push_back(b); // a이후에 세울 수 있는 학생 저장
	}
	
	for(int i=1; i<=n; i++)
		if(!indegree[i])
			q.push(i); // 앞에설 수 있는 학생들
	
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		
		cout << temp << ' ';
		
		for(int i=0; i<v[temp].size(); i++)
		{
			indegree[v[temp][i]]--;
			if(!indegree[v[temp][i]])
				q.push(v[temp][i]);
		}
	}
	cout << '\n';
	return 0;
}