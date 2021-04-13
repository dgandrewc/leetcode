#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> human(21, vector<int>(21, 0));
int n, ans=99999999;

void divide(int x, int y, int d1, int d2)
{
	vector<vector<int>> v(21, vector<int>(21, 0));
	vector<int> num(6, 0);
	for(int i=1; i<x+d1; i++)
		for(int j=1; j<=y; j++)
			v[i][j]=1;
	
	for(int i=1; i<=x+d2; i++)
		for(int j=y+1; j<=n; j++)
			v[i][j]=2;
	
	for(int i=x+d1; i<=n; i++)
		for(int j=1; j<y-d1+d2; j++)
			v[i][j]=3;
	
	for(int i=x+d2+1; i<=n; i++)
		for(int j=y-d1+d2; j<=n; j++)
			v[i][j]=4;
	
	for(int i=0; i<=d1; i++)
		v[x+i][y-i]=5;
	
	for(int i=0; i<=d2; i++)
		v[x+i][y+i]=5;
	
	for(int i=0; i<=d2; i++)
		v[x+d1+i][y-d1+i]=5;
	
	for(int i=0; i<=d1; i++)
		v[x+d2+i][y+d2-i]=5;
	
	for(int i=1; i<n+1; i++)
	{
		int cnt=0;
		for(int j=1; j<n+1; j++)
			if(v[i][j]==5)
				cnt++;
		
		if(cnt==2)
		{
			for(int j=1; j<n+1; j++)
			{
				if(v[i][j]==5)
				{
					j++;
					while(j<n+1 && v[i][j]!=5)
					{
						v[i][j]=5;
						j++;
					}
					break;
				}
			}
		}
	}

	for(int i=1; i<n+1; i++)
		for(int j=1; j<n+1; j++)
			num[v[i][j]]+=human[i][j];

	sort(num.begin(), num.end());
	ans=min(num[5]-num[1], ans);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=1; i<n+1; i++)
		for(int j=1; j<n+1; j++)
			cin >> human[i][j];
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			for(int k=1; (k+i+j)<=n; k++)
			{
				for(int l=i+1; l+j<=n; l++)
					divide(k, l, i, j);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}