#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	int l, w;
	int dx[4]={0, 0, -1, 1};
	int dy[4]={1, -1, 0, 0};
	
	cin >> l >> w;
	vector<vector<int>> arr(l, vector<int>(w));
	queue<pair<int, int>> q, s;
	
	for(int i=0; i<l; i++)
		for(int j=0; j<w; j++)
			cin >> arr[i][j];
	
	int count=0;
	int last_cheese=0;
	s.push(pair(0, 0));
	while(!s.empty())
	{
		last_cheese=s.size();
		vector<vector<int>> visit(l, vector<int>(w, 0));
		while(!s.empty())
		{
			pair<int, int> temp=s.front();
			s.pop();
			arr[temp.first][temp.second]=0;
		}
		
		count++;
		q.push(pair(0, 0));
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
				if(nx>=0 && nx<l && ny>=0 && ny<w && arr[nx][ny]==0 && visit[nx][ny]==0)
				{
					q.push(pair(nx, ny));
					visit[nx][ny]=1;
				}
				else if(nx>=0 && nx<l && ny>=0 && ny<w && arr[nx][ny]==1 && visit[nx][ny]==0)
				{
					s.push(pair(nx, ny));
					visit[nx][ny]=1;
				}
			}
		}
	}
	cout << count-1 << ' '<< last_cheese<< endl;
	return 0;
}