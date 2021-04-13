#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	vector<vector<pair<int, int>>> land;
	vector<vector<int>> visit(n, vector<int>(n, 0));
	queue<pair<int, int>> q;
	int dx[4]={0, 0, -1, 1};
	int dy[4]={-1, 1, 0, 0};
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> map[i][j];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(map[i][j]==0 || visit[i][j]==1)
				continue;
			vector<pair<int, int>> temp;
			visit[i][j]=1;
			
			q.push(pair(i, j));
			temp.push_back(pair(i, j));

			while(!q.empty())
			{
				pair<int, int> t=q.front();
				q.pop();
				int x=t.first;
				int y=t.second;
				
				for(int k=0; k<4; k++)
				{
					int nx=x+dx[k];
					int ny=y+dy[k];

					if(nx>=0 && nx<n && ny>=0 && ny<n && map[nx][ny]==1 && visit[nx][ny]==0)
					{
						visit[nx][ny]=1;
						q.push(pair(nx, ny));
						temp.push_back(pair(nx, ny));
					}
				}
			}
			land.push_back(temp);
		}
	}
	
	int shortest=9999999;
	
	for(int i=0; i<land.size(); i++)
	{
		for(int j=0; j<land.size(); j++)
		{
			if(i==j)
				continue;
			for(int k=0; k<land[i].size(); k++)
			{
				for(int l=0; l<land[j].size(); l++)
				{
					if(abs(land[i][k].first-land[j][l].first)+abs(land[i][k].second-land[j][l].second)<shortest)
						shortest=abs(land[i][k].first-land[j][l].first)+abs(land[i][k].second-land[j][l].second);
				}
			}
		}
	}
	cout << shortest-1 << endl;
	return 0;
}