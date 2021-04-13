#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> v(n+1, vector<int>(n+1, 0));
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	queue<vector<int>> q;
	
	for(int i=1; i<n+1; i++)
		for(int j=1; j<n+1; j++)
			cin >> v[i][j];

	dp[1][2]=1;
	q.push({1, 2, 0});
	
	while(!q.empty())
	{
		int x=q.front()[0];
		int y=q.front()[1];
		int s=q.front()[2];
		q.pop();
		if(s==0)
		{
			if(y+1<n+1 && v[x][y+1]==0)
			{
				dp[x][y+1]++;
				q.push({x, y+1, 0});
			}
			if(x+1<n+1 && y+1<n+1 && v[x][y+1]==0 && v[x+1][y]==0 && v[x+1][y+1]==0)
			{
				dp[x+1][y+1]++;
				q.push({x+1, y+1, 1});
			}
		}
		else if(s==1)
		{
			if(x+1<n+1 && y+1<n+1 && v[x][y+1]==0 && v[x+1][y]==0 && v[x+1][y+1]==0)
			{
				dp[x+1][y+1]++;
				q.push({x+1, y+1, 1});
			}
			
			if(x+1<n+1 && v[x+1][y]==0)
			{
				dp[x+1][y]++;
				q.push({x+1, y, 2});
			}
			
			if(y+1<n+1 && v[x][y+1]==0)
			{
				dp[x][y+1]++;
				q.push({x, y+1, 0});
			}
		}
		else
		{
			if(x+1<n+1 && v[x+1][y]==0)
			{
				dp[x+1][y]++;
				q.push({x+1, y, 2});
			}
			if(x+1<n+1 && y+1<n+1 && v[x][y+1]==0 && v[x+1][y]==0 && v[x+1][y+1]==0)
			{
				dp[x+1][y+1]++;
				q.push({x+1, y+1, 1});
			}
		}
	}
	cout << dp[n][n] << '\n';
	return 0;
}