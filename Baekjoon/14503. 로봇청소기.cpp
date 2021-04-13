#include<iostream>
#include<vector>

using namespace std;

int main(void)
{	
	int n, m, r, c, d;
	int dx[4]={-1, 0, 1, 0};
	int dy[4]={0, 1, 0, -1};
	
	int bx[4]={1, 0, -1, 0};
	int by[4]={0, -1, 0, 1};
	cin >> n >> m >> r >> c >> d;
	
	vector<vector<int>> v(n, vector<int>(m));
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> v[i][j];
	int test=0;
	int corw=0;
	v[r][c]=2;
	int ans=1;
	while(1)
	{
		int left_x=r+dx[(d+4-1)%4];
		int left_y=c+dy[(d+4-1)%4];
		if(left_x>=0 && left_x<n && left_y>=0 && left_y<m && v[left_x][left_y]==0)
		{
			corw=0;
			d=(d+4-1)%4;
			r=left_x;
			c=left_y;
			v[left_x][left_y]=2;
			ans++;
			continue;
		}
		else
		{
			corw++;
			d=(d+4-1)%4;
		}

		if(corw==4)
		{
			corw=0;
			r=r+bx[d];
			c=c+by[d];
			if(v[r][c]==0)
			{
				v[r][c]=2;
				ans++;
			}
			if(r<0 || r>=n || c<0 || c>=m || v[r][c]==1)
				break;
		}
	}
	cout << ans << '\n';
	return 0;
}