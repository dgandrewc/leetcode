#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int n, l, ans=0;
	cin >> n >> l;
	vector<vector<int>> m(n, vector<int>(n));
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> m[i][j];
			
	for(int i=0; i<n; i++)
	{
		int cnt=1;
		int f=1;
		for(int j=0; j+1<n; j++)
		{
			if(m[i][j]==m[i][j+1])
				cnt++;
			else if(m[i][j]-m[i][j+1]==-1)
			{
				if(cnt>=l)
					cnt=1;
				else
					f=0;
			}
			else if(m[i][j]-m[i][j+1]==1)
			{
				if(cnt<0)
					f=0;
				else
					cnt=-(l-1);
			}
			else f=0;
		}
		if(cnt>=0 && f)
			ans++;
	}
	
	for(int i=0; i<n; i++)
	{
		int cnt=1;
		int f=1;
		for(int j=0; j+1<n; j++)
		{
			if(m[j][i]==m[j+1][i])
				cnt++;
			else if(m[j][i]-m[j+1][i]==-1)
			{
				if(cnt>=l)
					cnt=1;
				else
					f=0;
			}
			else if(m[j][i]-m[j+1][i]==1)
			{
				if(cnt<0)
					f=0;
				else
					cnt=-(l-1);
			}
			else
				f=0;
		}
		if(cnt>=0 && f)
			ans++;
	}
	
	cout << ans << '\n';
	return 0;
}