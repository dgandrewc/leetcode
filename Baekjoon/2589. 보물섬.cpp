#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	int l, w;
	cin >> l >> w;
	vector<string> mapp(l);
	int dx[4]={0, 0, -1, 1};
	int dy[4]={-1, 1, 0, 0};
	
	for(int i=0; i<l; i++)
		cin >> mapp[i];
	
	int longest=0;
	
	for(int i=0; i<l; i++)
	{
		for(int j=0; j<w; j++)
		{
			if(mapp[i][j]=='W')
				continue;
			
			queue<pair<int, int>> q;
			vector<vector<int>> visit(l, vector<int>(w, 0));
			vector<vector<int>> dis(l, vector<int>(w, 0));
			visit[i][j]=1;
			q.push(pair(i, j));
			
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
					if(nx>=0 && nx<l && ny>=0 && ny<w && mapp[nx][ny]=='L' && visit[nx][ny]==0)
					{
						visit[nx][ny]=visit[x][y]=1;
						dis[nx][ny]=dis[x][y]+1;
						q.push(pair(nx, ny));
						if(dis[nx][ny]>longest)
							longest=dis[nx][ny];
					}
				}
			}
		}
	}
	
	cout << longest << endl;
	return 0;
}