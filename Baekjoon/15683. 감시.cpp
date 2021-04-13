#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int>> cop;
vector<vector<int>> loc;
vector<vector<int>> cas;
vector<int> temp;

void dfs(int c)
{
	if(temp.size()==loc.size())
	{
		cas.push_back(temp);
		return;
	}
	
	for(int i=0; i<4; i++)
	{
		temp.push_back(i);
		dfs(c+1);
		temp.pop_back();
	}
}

void cctv1(int x, int y, int d)
{
	if(d==0)
		for(int i=x; i>=0; i--)
		{
			if(cop[i][y]==6)
				break;
			cop[i][y]=2;
		}
	else if(d==1)
		for(int i=y; i<m; i++)
		{
			if(cop[x][i]==6)
				break;
			cop[x][i]=2;
		}
	else if(d==2)
		for(int i=x; i<n; i++)
		{
			if(cop[i][y]==6)
				break;
			cop[i][y]=2;
		}
	else if(d==3)
		for(int i=y; i>=0; i--)
		{
			if(cop[x][i]==6)
				break;
			cop[x][i]=2;
		}

}

void cctv2(int x, int y, int d)
{
	if(d==0 || d==1)
	{
		cctv1(x, y, 0);
		cctv1(x, y, 2);
	}
	else
	{
		cctv1(x, y, 1);
		cctv1(x, y, 3);
	}
}

void cctv3(int x, int y, int d)
{
	if(d==0)
	{
		cctv1(x, y, 0);
		cctv1(x, y, 1);
	}
	else if(d==1)
	{
		cctv1(x, y, 1);
		cctv1(x, y, 2);
	}
	else if(d==2)
	{
		cctv1(x, y, 2);
		cctv1(x, y, 3);
	}
	else if(d==3)
	{
		cctv1(x, y, 3);
		cctv1(x, y, 0);
	}
}

void cctv4(int x, int y, int d)
{
	if(d==0)
	{
		cctv1(x, y, 0);
		cctv1(x, y, 1);
		cctv1(x, y, 2);
	}
	else if(d==1)
	{
		cctv1(x, y, 1);
		cctv1(x, y, 2);
		cctv1(x, y, 3);
	}
	else if(d==2)
	{
		cctv1(x, y, 2);
		cctv1(x, y, 3);
		cctv1(x, y, 0);
	}
	else if(d==3)
	{
		cctv1(x, y, 3);
		cctv1(x, y, 0);
		cctv1(x, y, 1);
	}
}

void cctv5(int x, int y, int d)
{
	cctv1(x, y, 0);
	cctv1(x, y, 1);
	cctv1(x, y, 2);
	cctv1(x, y, 3); 
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> v[i][j];
			if(v[i][j]!=0 && v[i][j]!=6)
				loc.push_back({i, j, v[i][j]});
		}
		cop.push_back(v[i]);
	}

	int ans=999999999;
	dfs(0);
	for(int i=0; i<cas.size(); i++)
	{
		cop=v;
		
		for(int j=0; j<cas[i].size(); j++)
		{
			if(loc[j][2]==1)
				cctv1(loc[j][0], loc[j][1], cas[i][j]);
			else if(loc[j][2]==2)
				cctv2(loc[j][0], loc[j][1], cas[i][j]);
			else if(loc[j][2]==3)
				cctv3(loc[j][0], loc[j][1], cas[i][j]);
			else if(loc[j][2]==4)
				cctv4(loc[j][0], loc[j][1], cas[i][j]);
			else if(loc[j][2]==5)
				cctv5(loc[j][0], loc[j][1], cas[i][j]);
		}
		
		int ans_m=0;
		for(int j=0; j<cop.size(); j++)
			for(int k=0; k<cop[j].size(); k++)
				if(cop[j][k]==0)
					ans_m+=1;
		if(ans_m<ans)
			ans=ans_m;
	}
	cout << ans << '\n';
	return 0;
}