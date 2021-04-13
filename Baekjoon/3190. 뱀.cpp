#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> arr(n, vector<int>(n, 0));
	
	for(int i=0; i<k; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		arr[t1-1][t2-1]=1;
	}
	
	int l;
	cin >> l;
	vector<pair<int, char>> play(l);
	for(int i=0; i<l; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		play[i].first=x;
		play[i].second=c;
	}
	
	deque<pair<int, int>> dq;
	dq.push_front(pair(0, 0));
	int dx[4]={-1, 0, 1, 0};
	int dy[4]={0, 1, 0, -1};
	int state=1;
	int cnt=0;
	for(int i=0; i<l+1;)
	{
		if(i==l || play[i].first!=cnt)
		{
			int nx=(dq.front().first)+dx[state];
			int ny=(dq.front().second)+dy[state];
			cnt++;

			if(nx<0 || nx>=n || ny<0 || ny>=n)
				break;
			int flag=0;
			for(int j=0; j<dq.size(); j++)
			{
				if(dq[j].first==nx && dq[j].second==ny)
					flag=1;
			}
			if(flag==1) break;
			
			dq.push_front(pair(nx, ny));
			if(arr[nx][ny]==0)
				dq.pop_back();
			else
				arr[nx][ny]=0;
		}
		else
		{
			if(i==l)
				break;
			
			if(play[i].second=='L')
			{
				state-=1;
				if(state<0)
					state+=4;
			}
			else
				state=(state+1)%4;
			
			i++;

		}
	}
	cout << cnt << endl;
	return 0;
}