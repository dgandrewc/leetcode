#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};
int cnt=1;
int main(void)
{
	while(1)
	{
		int n;
		cin >> n;
		if(n==0)
			break;
		
		vector<vector<int>> v(n, vector<int>(n));
		vector<vector<int>> ans(n, vector<int>(n, 987654321));
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin >> v[i][j];
		
		queue<vector<int>> q;
		q.push({0, 0, v[0][0]});
		
		while(!q.empty())
		{
			int x=q.front()[0];
			int y=q.front()[1];
			int c=q.front()[2];
			q.pop();
			
			for(int i=0; i<4; i++)
			{
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(nx<n && nx>=0 && ny<n && ny>=0 && c+v[nx][ny]<ans[nx][ny])
				{
					ans[nx][ny]=c+v[nx][ny];
					q.push({nx, ny, ans[nx][ny]});
				}
			}
		}
		cout << "Problem " << cnt << ": "<< ans[n-1][n-1] << '\n';
		cnt++;
	}
	
	return 0;
}