#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	int m, n;
	cin >> m >> n;
	vector<string> v(n);
	vector<vector<int>> b(n, vector<int>(m, 9999));
	b[0][0]=0;
	
	for(int i=0; i<n; i++)
		cin >> v[i];
	
	queue<pair<int, int>> q;
	q.push(pair(0, 0));
	int dx[4]={0, 0, -1, 1};
	int dy[4]={1, -1, 0, 0};

	while(!q.empty())
	{
		pair<int, int> temp=q.front();
		q.pop();
		
		int x=temp.first;
		int y=temp.second;

		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx>=n || nx<0 || ny>=m || ny<0)
				continue;
			
			if(v[nx][ny]=='1')
			{
				if(b[nx][ny]>b[x][y]+1)
				{
					b[nx][ny]=b[x][y]+1;
					q.push(pair(nx, ny));
				}
			}
			else
			{
				if(b[nx][ny]>b[x][y])
				{
					b[nx][ny]=b[x][y];
					q.push(pair(nx, ny));
				}
			}
			
		}
	}
	cout << b[n-1][m-1] << '\n';
	return 0;
}