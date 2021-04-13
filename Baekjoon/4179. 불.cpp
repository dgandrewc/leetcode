#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h, w;
	cin >> h >> w;
	vector<vector<char>> map(h, vector<char>(w));
	vector<vector<int>> visit(h, vector<int>(w, 0));
	queue<vector<int>> q;
	queue<pair<int, int>> fq;
		
	for(int i=0; i<h; i++)
	{
		for(int j=0; j<w; j++)
		{
			cin >> map[i][j];
			if(map[i][j]=='J')
			{
				q.push({i, j, 0});
				visit[i][j]=1;
			}
			if(map[i][j]=='F')
				fq.push(pair(i, j));
		}
	}
	
	int flag=0;
	int state=0;
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
			
			if(nx<0 || nx>=h || ny<0 || ny>=w)
			{
				cout << c+1 << '\n';
				flag=1;
				break;
			}
			if(c+1!=state)
			{
				state++;
					int sz=fq.size();
				for(int i=0; i<sz; i++)
				{
					int fx=fq.front().first;
					int fy=fq.front().second;
					fq.pop();
					for(int fi=0; fi<4; fi++)
					{
						int nfx=fx+dx[fi];
						int nfy=fy+dy[fi];
						if(nfx>=0 && nfx<h && nfy>=0 && nfy<w && map[nfx][nfy]=='.')
						{
							map[nfx][nfy]='F';
							fq.push({nfx, nfy});
						}
					}
				}
			}
			if(map[nx][ny]=='.' && visit[nx][ny]==0)
			{
				q.push({nx, ny, c+1});
				visit[nx][ny]=1;
			}
		}
		if(flag==1)
			break;
	}
	if(flag==0)
		cout << "IMPOSSIBLE" << '\n';
	return 0;
}