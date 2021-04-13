#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, m, d, ans=0, mans;
vector<vector<int>> v(16, vector<int>(16));
vector<vector<int>> ov(16, vector<int>(16));
vector<int> sl;
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};

struct cmp
{
	bool operator()(vector<int> a, vector<int> b)
	{
		if(a[2]==b[2])
		{
			return a[1]>b[1];
		}
		else
			return a[2]>b[2];
	}
};

void attack()
{
	queue<pair<int, int>> killed;
	for(int i=0; i<sl.size(); i++)
	{
		priority_queue<vector<int>, vector<vector<int>>, cmp> q;
		q.push({n-1, sl[i], 1});
		vector<vector<int>> visit(n, vector<int>(m, 0));
		visit[n-1][sl[i]]=1;
		while(!q.empty())
		{
			vector<int> temp=q.top();
			q.pop();
			int x=temp[0];
			int y=temp[1];
			int c=temp[2];
			
			if(v[x][y]==1)
			{
				killed.push(pair(x, y));
				break;
			}
			
			for(int j=0; j<4; j++)
			{
				int nx=x+dx[j];
				int ny=y+dy[j];
				if(nx>=0 && nx<n && ny>=0 && ny<m && visit[nx][ny]==0 && (c+1)<=d)
				{
					visit[nx][ny]=1;
					q.push({nx, ny, c+1});
				}
			}
		}
	}
	
	while(!killed.empty())
	{
		pair<int, int> temp=killed.front();
		killed.pop();
		if(v[temp.first][temp.second]==1)
		{
			v[temp.first][temp.second]=0;
			mans++;
		}
	}
}
void move()
{
	for(int j=0; j<m; j++)
	{
		for(int i=n-1; i>0; i--)
			v[i][j]=v[i-1][j];
		v[0][j]=0;
	}
}

void game()
{
	mans=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			v[i][j]=ov[i][j];
	
	for(int i=0; i<n; i++)
	{
		attack();
		move();
	}
	
	ans=max(ans, mans);
}

void shooter_location(int x, int c)
{
	if(c==3)
	{
		game();
		return;
	}
	for(int i=x+1; i<m; i++)
	{
		sl.push_back(i);
		shooter_location(i, c+1);
		sl.pop_back();
	}
}

int main(void)
{
	cin >> n >> m >> d;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> ov[i][j];
	
	shooter_location(-1, 0);
	cout << ans << '\n';
	return 0;
}