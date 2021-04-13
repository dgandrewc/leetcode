#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int R, C, M, ans=0;
vector<vector<vector<int>>> v(101, vector<vector<int>>(101));
vector<vector<vector<int>>> t(101, vector<vector<int>>(101));

void move(int r, int c)
{
	int diff;
	int Or=r;
	int Oc=c;
	int s=v[r][c][0];
	int d=v[r][c][1];
	if(d==1 || d==2)
		diff=s%((R-1)*2);
	else
		diff=s%((C-1)*2);
	
	if(r==1 && d==1)
		d=2;
	else if(r==R && d==2)
		d=1;
	else if(c==1 && d==4)
		d=3;
	else if(c==C && d==3)
		d=4;
	while(diff--)
	{
		if(d==1)
		{
			if(r==1)
			{
				d=2;
				continue;
			}
			r--;
			if(r==1)
				d=2;
		}
		else if(d==2)
		{
			if(r==R)
			{
				d=1;
				continue;
			}
			r++;
			if(r==R)
				d=1;
		}
		else if(d==3)
		{
			if(c==C)
			{
				d=4;
				continue;
			}
			c++;
			if(c==C)
				d=4;
		}
		else if(d==4)
		{
			if(c==1)
			{
				d=3;
				continue;
			}
			c--;
			if(c==1)
				d=3;
		}
	}
	
	if(t[r][c].size()!=0)
	{
		if(t[r][c][2]<v[Or][Oc][2])
		{
			t[r][c]=v[Or][Oc];
			t[r][c][1]=d;
		}
	}
	else
	{
		t[r][c]=v[Or][Oc];
		t[r][c][1]=d;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C >> M;
	
	for(int i=0; i<M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		v[r][c]={s, d, z};
	}

	for(int i=1; i<C+1; i++)
	{
		for(int j=1; j<R+1; j++)
		{
			if(v[j][i].size()!=0)
			{
				ans+=v[j][i][2];
				v[j][i]={};
				break;
			}
		}
		
		for(int j=1; j<R+1; j++)
			for(int k=1; k<C+1; k++)
				if(v[j][k].size()!=0)
					move(j, k);
		
		v=t;
		for(int a=0; a<101; a++)
			for(int b=0; b<101; b++)
				t[a][b]={};
		
	}
	cout << ans << '\n';
	return 0;
}