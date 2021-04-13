#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	int n, m;
	int dx[8]={0, 0, -1, 1, 1, -1, -1, 1};
	int dy[8]={1, -1, 0, 0, 1, -1, 1, -1};
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	queue<pair<int, int>> q;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> v[i][j];
	
	int ans=0;
	while(1)
	{
		int flag=0;
		vector<vector<int>> visit(n, vector<int>(m, 0));
		vector<vector<int>> fv=v;
		
		q.push(pair(0, 0));
		visit[0][0]=1;
		fv[0][0]=-1;
		while(!q.empty())
		{
			pair<int, int> temp=q.front();
			q.pop();
			int x=temp.first;
			int y=temp.second;
			for(int k=0; k<4; k++)
			{
				int nx=x+dx[k];
				int ny=y+dy[k];
				if(nx>=0 && nx<n && ny>=0 && ny<m && v[nx][ny]==0 && visit[nx][ny]==0)
				{
					visit[nx][ny]=1;
					fv[nx][ny]=-1;
					q.push(pair(nx, ny));
				}
			}
		}

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{	
				if(fv[i][j]==1 && visit[i][j]==0)
				{
					flag=1;
					visit[i][j]=1;
					q.push(pair(i, j));
					while(!q.empty())
					{
						pair<int, int> temp=q.front();
						q.pop();
						int x=temp.first;
						int y=temp.second;

						int cnt=0;
						for(int k=0; k<8; k++)
						{
							int nx=x+dx[k];
							int ny=y+dy[k];
							if(nx>=0 && nx<n && ny>=0 && ny<m && visit[nx][ny]==0 && v[nx][ny]==1)
							{
								visit[nx][ny]=1;
								q.push(pair(nx, ny));
							}
							
						}
						
						for(int k=0; k<4; k++)
						{
							int nx=x+dx[k];
							int ny=y+dy[k];
							if(nx>=0 && nx<n && ny>=0 && ny<m && fv[nx][ny]==-1)
								cnt++;
						}
						if(cnt>=2)
							v[x][y]=0;
					}
				}
			}
		}
		if(flag==0)
			break;
		ans++;
	}
	
	cout << ans << '\n';
	return 0;
}