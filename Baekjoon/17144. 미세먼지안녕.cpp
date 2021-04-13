#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> v(1001, vector<int>(1001));
vector<vector<int>> s;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r, c, t, actx=-1, acbx=-1;
	int dx[4]={-1, 0, 1, 0};
	int dy[4]={0, 1, 0, -1};
	
	cin >> r >> c >> t;
	
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			cin >> v[i][j];
			if(v[i][j]==-1 && actx==-1)
				actx=i;
			else if(v[i][j]==-1 && actx!=-1)
				acbx=i;
		}
	}
	
	s=v;
	while(t--)
	{
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				for(int k=0; k<4; k++)
				{
					int ni=i+dx[k];
					int nj=j+dy[k];
					if(v[i][j]>=5 && ni>=0 && ni<r && nj>=0 && nj<c && v[ni][nj]!=-1)
					{
						s[ni][nj]+=int(v[i][j]/5);
						s[i][j]-=int(v[i][j]/5);
					}
				}
			}
		}

		if(actx!=0)
		{
			for(int i=1; i<actx; i++)
				s[actx-i][0]=s[actx-i-1][0];
			for(int i=0; i<c-1; i++)
				s[0][i]=s[0][i+1];
			for(int i=0; i<actx; i++)
				s[i][c-1]=s[i+1][c-1];
			for(int i=c-1; i>=2; i--)
				s[actx][i]=s[actx][i-1];
			s[actx][1]=0;
		}
		
		if(acbx!=r-1)
		{
			for(int i=1; i+1<r; i++)
				s[acbx+i][0]=s[acbx+i+1][0];
			for(int i=0; i<c-1; i++)
				s[r-1][i]=s[r-1][i+1];
			for(int i=r-1; i>acbx; i--)
				s[i][c-1]=s[i-1][c-1];
			for(int i=c-1; i>=2; i--)
				s[acbx][i]=s[acbx][i-1];
			s[acbx][1]=0;
		}
		v=s;
	}
	
	int ans=0;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			ans+=v[i][j];
	
	cout << ans+2 << '\n';
	return 0;
}