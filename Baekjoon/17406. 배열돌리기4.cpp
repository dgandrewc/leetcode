#include<iostream>
#include<vector>

using namespace std;

int n, m, k;
vector<vector<int>> ov(51, vector<int>(51));
vector<vector<int>> v(51, vector<int>(51));
vector<vector<int>> info;
vector<vector<int>> order;
vector<int> visit(7);
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, -1, 0, 1};

void rotate(int r, int c, int s)
{
	for(int i=1; i<s+1; i++)
	{
		int save=v[r+i][c+i];
		int cnt=0;
		int d=0;
		while(1)
		{
			v[r+i][c+i]=v[r+i+dx[d]][c+i+dy[d]];
			r+=dx[d];
			c+=dy[d];
			cnt++;
			if(cnt==(1+i*2)-1)
			{
				cnt=0;
				d++;
			}
			if(d==4)
				break;
		}
		v[r+i][c+i-1]=save;
	}
}

vector<int> tmp;
void dfs(int cnt)
{
	if(cnt==k)
		order.push_back(tmp);
	for(int i=0; i<k; i++)
	{
		if(visit[i]==0)
		{
			visit[i]=1;
			tmp.push_back(i);
			dfs(cnt+1);
			tmp.pop_back();
			visit[i]=0;
		}
	}
}

int main(void)
{

	cin >> n >> m >> k;

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> ov[i][j];
	
	for(int i=0; i<k; i++)
	{
		vector<int> temp(3);
		int a, b, c;
		cin >> a >> b >> c;
		temp[0]=a-1;
		temp[1]=b-1;
		temp[2]=c;
		info.push_back(temp);
	}
	
	dfs(0);
	
	int ans=99999999;
	
	for(int i=0; i<order.size(); i++)
	{
		v=ov;
		for(int j=0; j<order[i].size(); j++)
			rotate(info[order[i][j]][0], info[order[i][j]][1], info[order[i][j]][2]);
		
		for(int j=0; j<n; j++)
		{
			int mid=0;
			for(int k=0; k<m; k++)
			{
				mid+=v[j][k];
			}
			ans=min(ans, mid);
		}
	}
	cout << ans << '\n';
	return 0;
}