#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> graph(101, vector<int>(101, 0));
	int dx[4]={0, -1, 0, 1};
	int dy[4]={1, 0, -1, 0};
	
	for(int i=0; i<n; i++)
	{
		int x, y, d, g;
		vector<int> state;
		cin >> y >> x >> d >> g;
		
		state.push_back(d);
		graph[x][y]=1;
		for(int j=0; j<g; j++)
		{
			int l=state.size();
			for(int k=l-1; k>=0; k--)
				state.push_back((state[k]+1)%4);
		}
		for(int k=0; k<state.size(); k++)
		{
			x+=dx[state[k]];
			y+=dy[state[k]];
			graph[x][y]=1;
		}
	}
	
	int ans=0;
	for(int i=0; i<100; i++)
		for(int j=0; j<100; j++)
			if(graph[i][j]==1 && graph[i+1][j]==1 && graph[i][j+1]==1 && graph[i+1][j+1]==1)
				ans++;
	
	cout << ans << '\n';

	return 0;
}