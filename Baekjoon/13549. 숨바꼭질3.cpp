#include<iostream>
#include<vector>
#include<deque>
#include<cmath>

using namespace std;

int main(void)
{
	int n, k, solution=9999999;
	cin >> n >> k;
	deque<pair<int, int>> dq;
	vector<int> visit(100001, 0);
	
	dq.push_back(pair(n, 0));
	
	while(!dq.empty())
	{
		pair<int, int> temp=dq.front();
		dq.pop_front();
		int x=temp.first;
		int c=temp.second;
		
		if(x==k)
		{
			solution=c;
			break;
		}
		
		if(x*2<100001 && visit[x*2]==0)
		{
			dq.push_front(pair(x*2, c));
			visit[x*2]=1;
		}
		if(x-1>=0 && visit[x-1]==0)
		{
			dq.push_back(pair(x-1, c+1));
			visit[x-1]=1;
		}
		if(x+1<100001 && visit[x+1]==0)
		{
			dq.push_back(pair(x+1, c+1));
			visit[x+1]=1;
		}

	}
	cout << solution << endl;
	
	return 0;
}