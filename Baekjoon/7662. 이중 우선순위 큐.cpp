#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;
		vector<bool> visit(1000001, false);
		priority_queue<pair<int, int>> max_q;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_q;
		
		for(int i=0; i<n; i++)
		{
			char cmd;
			int num;
			cin >> cmd >> num;
			if(cmd=='I')
			{
				max_q.push(pair(num, i));
				min_q.push(pair(num, i));
				visit[i]=true;
			}
			else
			{
				if(num==1)
				{
					while(!max_q.empty() && !visit[max_q.top().second])
						max_q.pop();
					if(!max_q.empty())
					{
						visit[max_q.top().second]=false;
						max_q.pop();
					}
				}
				else
				{
					while(!min_q.empty() && !visit[min_q.top().second])
						min_q.pop();
					if(!min_q.empty())
					{
						visit[min_q.top().second]=false;
						min_q.pop();
					}
				}
			}
		}
		while(!max_q.empty() && !visit[max_q.top().second])
			max_q.pop();
		while(!min_q.empty() && !visit[min_q.top().second])
			min_q.pop();
		
		if(min_q.empty() && max_q.empty())
			cout << "EMPTY" << '\n';
		else
			cout << max_q.top().first << ' ' << min_q.top().first << '\n';
	}
	
	return 0;
}