#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int visit[31][201][201];

int main(void)
{
	int k;
	cin >> k;
	int w, h;
	cin >> h >> w;
	queue<vector<int>> q;
	int _map[w][h];
	int dx1[4]={0, 0, -1, 1};
	int dy1[4]={-1, 1, 0, 0};
	int dx2[8]={-1, -2, -2, -1, 1, 2, 1, 2};
	int dy2[8]={-2, -1, 1, 2, 2, 1, -2, -1};
	
	for(int i=0; i<w; i++)
		for(int j=0; j<h; j++)
			cin >> _map[i][j];
	
	q.push({0, 0, 0});
	while(!q.empty())
	{
		vector<int> temp=q.front();
		q.pop();
		int x=temp[0];
		int y=temp[1];
		int c=temp[2];
		
		if(x==w-1 && y==h-1)
		{
			cout << visit[c][x][y] << endl;
			return 0;
		}
			
		for(int i=0; i<4; i++)
		{
			int nx=x+dx1[i];
			int ny=y+dy1[i];
			if(nx>=0 && nx<w && ny>=0 && ny<h && _map[nx][ny]==0 && visit[c][nx][ny]==0)
			{
				visit[c][nx][ny]=visit[c][x][y]+1;
				q.push({nx, ny, c});
			}
		}
		
		for(int i=0; i<8; i++)
		{
			int nx=x+dx2[i];
			int ny=y+dy2[i];
			if(nx>=0 && nx<w && ny>=0 && ny<h && _map[nx][ny]==0 && c+1<=k && visit[c+1][nx][ny]==0)
			{
				visit[c+1][nx][ny]=visit[c][x][y]+1;
				q.push({nx, ny, c+1});
			}
		}
	}
	cout << -1 << endl;
	return 0;
}