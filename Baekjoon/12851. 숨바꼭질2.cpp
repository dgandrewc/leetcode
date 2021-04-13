#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	int n, k, countt=0, solution=9999999;
	cin >> n >> k;
	queue<pair<int, int>> q;
	vector<int> visit(100001, 0);
	
	q.push(pair(n, 0));
	
	while(!q.empty())
	{
		pair<int, int> temp=q.front();
		q.pop();
		int x=temp.first;
		int c=temp.second;
		
		if(x==k && c<=solution)
		{
			solution=c;
			countt++;
		}
		
		visit[x]=1;
		
		if(x-1>=0 && visit[x-1]==0)
			q.push(pair(x-1, c+1));
		if(x+1<100001 && visit[x+1]==0)
			q.push(pair(x+1, c+1));
		if(x*2<100001 && visit[x*2]==0)
			q.push(pair(x*2, c+1));
	}
	cout << solution << endl;
	cout << countt << endl;
	
	return 0;
}