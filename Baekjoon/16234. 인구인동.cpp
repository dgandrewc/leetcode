#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int main(void)
{
	int n, l, r, count=0;
	int dx[4]={0, 0, -1, 1};
	int dy[4]={-1, 1, 0, 0};
	cin >> n >> l >> r;
	vector<vector<int>> arr(n, vector<int>(n));
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> arr[i][j];

	while(1)
	{
		int flag=0;
		count++;
		queue<pair<int, int>> q;
		vector<vector<int>> visit(n, vector<int>(n, 0));
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(visit[i][j]==0)
				{
					visit[i][j]=1;
					q.push(pair(i, j));
					vector<pair<int, int>> open_land;
					
					while(!q.empty())
					{
						pair<int, int> temp=q.front();
						q.pop();
						int x=temp.first;
						int y=temp.second;
						open_land.push_back(pair(x, y));
						
						for(int k=0; k<4; k++)
						{
							int nx=x+dx[k];
							int ny=y+dy[k];
							if(nx>=0 && nx<n && ny>=0 && ny<n && visit[nx][ny]==0 && abs(arr[nx][ny]-arr[x][y])>=l && abs(arr[nx][ny]-arr[x][y])<=r)
							{
								flag=1;
								visit[nx][ny]=1;
								q.push(pair(nx, ny));
							}
						}
					}
					int sum=0;
					for(int k=0; k<open_land.size(); k++)
						sum+=arr[open_land[k].first][open_land[k].second];
					for(int k=0; k<open_land.size(); k++)
						arr[open_land[k].first][open_land[k].second]=floor(sum/open_land.size());
					
				}
			}
		}
		if(flag==0)
			break;
	}
	cout << count-1 << endl;
	return 0;
}