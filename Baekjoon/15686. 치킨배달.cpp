#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, m, ans=999999999;
vector<vector<int>> city(51, vector<int>(51));
vector<pair<int, int>> chicken;
vector<pair<int, int>> cv;
queue<pair<int, int>> q;
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};
vector<vector<int>> visit(51, vector<int>(51));
vector<vector<int>> dis(51, vector<int>(51));

void bfs()
{
	int ans_m=0;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx>=0 && nx<n && ny>=0 && ny<n && visit[nx][ny]==0)
			{
				visit[nx][ny]=1;
				dis[nx][ny]=dis[x][y]+1;
				if(city[nx][ny]==1)
					ans_m+=dis[nx][ny];
				q.push(pair(nx, ny));
			}
		}
	}
	ans=min(ans, ans_m);
}

void dfs(int x, int c)
{
	if(c==m)
	{
		fill(visit.begin(), visit.end(), vector<int>(51, 0));
		fill(dis.begin(), dis.end(), vector<int>(51, 0));
		for(int i=0; i<cv.size(); i++)
		{
			visit[cv[i].first][cv[i].second]=1;
			q.push(pair(cv[i].first, cv[i].second));
		}
		bfs();
		return;
	}
	
	for(int i=x; i<chicken.size(); i++)
	{
		cv.push_back(pair(chicken[i].first, chicken[i].second));
		dfs(i+1, c+1);
		cv.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> city[i][j];
			if(city[i][j]==2)
				chicken.push_back(pair(i, j));
		}
	}
	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}