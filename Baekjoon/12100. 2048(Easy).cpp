#include<iostream>
#include<vector>
#include <ctime>

using namespace std;
int n, ans=0;

void game(int c, vector<vector<int>> v)
{
	vector<vector<vector<int>>> v_c(4, vector<vector<int>>(n, vector<int>(n)));
	vector<int> broken(n+1, 0);
	for(int i=0; i<4; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
				v_c[i][j][k]=v[j][k];
	
	for(int j=0; j<n; j++) //위쪽으로 
	{
		for(int i=0; i<n; i++)
		{
			if(v_c[0][i][j]==0)
				continue;
			if(i!=0 && v_c[0][i-1][j]==0)
			{
				v_c[0][i-1][j]=v_c[0][i][j];
				v_c[0][i][j]=0;
				i-=2;
			}
			else if(i!=0 && broken[i-1]!=1 && v_c[0][i-1][j]==v_c[0][i][j])
			{
				v_c[0][i][j]=0;
				v_c[0][i-1][j]=v_c[0][i-1][j]*2;
				ans=max(ans, v_c[0][i-1][j]);
				broken[i-1]=1;
			}
		}
		fill(broken.begin(), broken.end(), 0);
	}	
	
	fill(broken.begin(), broken.end(), 0);
	for(int j=0; j<n; j++) //아래쪽으로 
	{
		for(int i=n-1; i>=0; i--)
		{
			if(v_c[1][i][j]==0)
				continue;
			if(i!=n-1 && v_c[1][i+1][j]==0)
			{
				v_c[1][i+1][j]=v_c[1][i][j];
				v_c[1][i][j]=0;
				i+=2;
			}
			else if(i!=n-1 && broken[i+1]!=1 && v_c[1][i+1][j]==v_c[1][i][j])
			{
				v_c[1][i][j]=0;
				v_c[1][i+1][j]=v_c[1][i+1][j]*2;
				ans=max(ans, v_c[1][i+1][j]);
				broken[i+1]=1;
			}
		}
		fill(broken.begin(), broken.end(), 0);
	}
	
	fill(broken.begin(), broken.end(), 0);
	for(int i=0; i<n; i++) //왼쪽으로 
	{
		for(int j=0; j<n; j++)
		{
			if(v_c[2][i][j]==0)
				continue;
			if(j!=0 && v_c[2][i][j-1]==0)
			{
				v_c[2][i][j-1]=v_c[2][i][j];
				v_c[2][i][j]=0;
				j-=2;
			}
			else if(j!=0 && broken[j-1]!=1 && v_c[2][i][j-1]==v_c[2][i][j])
			{
				v_c[2][i][j]=0;
				v_c[2][i][j-1]=v_c[2][i][j-1]*2;
				ans=max(ans, v_c[2][i][j-1]);
				broken[j-1]=1;
			}
		}
		fill(broken.begin(), broken.end(), 0);
	}	
	
	fill(broken.begin(), broken.end(), 0);
	for(int i=0; i<n; i++) //오른쪽으로 
	{
		for(int j=n-1; j>=0; j--)
		{
			if(v_c[3][i][j]==0)
				continue;
			if(j!=n-1 && v_c[3][i][j+1]==0)
			{
				v_c[3][i][j+1]=v_c[3][i][j];
				v_c[3][i][j]=0;
				j+=2;
			}
			else if(j!=n-1 && broken[j+1]!=1 && v_c[3][i][j+1]==v_c[3][i][j])
			{
				v_c[3][i][j]=0;
				v_c[3][i][j+1]=v_c[3][i][j+1]*2;
				ans=max(ans, v_c[3][i][j+1]);
				broken[j+1]=1;
			}
		}
		fill(broken.begin(), broken.end(), 0);
	}
	
	if(c==4)
		return;
	
	game(c+1, v_c[0]);
	game(c+1, v_c[1]);
	game(c+1, v_c[2]);
	game(c+1, v_c[3]);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	
	vector<vector<int>> v(n, vector<int>(n));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> v[i][j];
			ans=max(ans, v[i][j]);
		}
	}

	game(0, v);
	cout << ans << '\n';
	return 0;
}