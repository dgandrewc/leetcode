#include<iostream>
#include<vector>

using namespace std;

int n, m, ans=0;
vector<vector<int>> _map(501, vector<int>(501));
vector<vector<int>> dp(501, vector<int>(501, -1));
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};

int dfs(int x, int y)
{
	int ret=0;
	if(x==0 && y==0)
		return 1;
	
	for(int i=0; i<4; i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0 && nx<n && ny>=0 && ny<m && _map[nx][ny]>_map[x][y])
		{
			if(dp[nx][ny]==-1)
			{
				dp[nx][ny]=dfs(nx, ny);
				ret+=dp[nx][ny];
			}
			else
				ret+=dp[nx][ny];
			
		}
	}
	return ret;
}

int main(void)
{
	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> _map[i][j];
	
	
	cout << dfs(n-1, m-1) << '\n';
	return 0;
}