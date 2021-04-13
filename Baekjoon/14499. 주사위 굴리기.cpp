#include<iostream>
#include<vector>
using namespace std;

int dice[7];

void up()
{
	int t;
	t=dice[1];
	dice[1]=dice[2];
	dice[2]=dice[6];
	dice[6]=dice[5];
	dice[5]=t;
}
void down()
{
	int t;
	t=dice[1];
	dice[1]=dice[5];
	dice[5]=dice[6];
	dice[6]=dice[2];
	dice[2]=t;
}
void left()
{
	int t;
	t=dice[1];
	dice[1]=dice[4];
	dice[4]=dice[6];
	dice[6]=dice[3];
	dice[3]=t;
}

void right()
{
	int t;
	t=dice[1];
	dice[1]=dice[3];
	dice[3]=dice[6];
	dice[6]=dice[4];
	dice[4]=t;
}
int main(void)
{
	int n, m, x, y, k;
	cin >> n >> m >> y >> x >> k;
	vector<vector<int>> v(n+1, vector<int>(m+1));
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> v[i][j];
	
	
	if(v[y][x]==0)
		v[y][x]=dice[1];
	else
	{
		dice[1]=v[y][x];
		v[y][x]=0;
	}
	for(int i=0; i<k; i++)
	{
		int r;
		cin >> r;
		
		if(r==1)
		{
			if(x+1<m)
			{
				x+=1;
				right();
				if(v[y][x]==0)
					v[y][x]=dice[1];
				else
				{
					dice[1]=v[y][x];
					v[y][x]=0;
				}
				cout << dice[6] << '\n';
			}
		}
		if(r==2)
		{
			if(x-1>=0)
			{
				x-=1;
				left();
				if(v[y][x]==0)
					v[y][x]=dice[1];
				else
				{
					dice[1]=v[y][x];
					v[y][x]=0;
				}
				cout << dice[6] << '\n';
			}
		}

		if(r==3)
		{
			if(y-1>=0)
			{
				y-=1;
				up();
				if(v[y][x]==0)
					v[y][x]=dice[1];
				else
				{
					dice[1]=v[y][x];
					v[y][x]=0;
				}
				cout << dice[6] << '\n';
			}
		}
		if(r==4)
		{
			if(y+1<n)
			{
				y+=1;
				down();
				if(v[y][x]==0)
					v[y][x]=dice[1];
				else
				{
					dice[1]=v[y][x];
					v[y][x]=0;
				}
				cout << dice[6] << '\n';
			}
		}
	}
	return 0;
}