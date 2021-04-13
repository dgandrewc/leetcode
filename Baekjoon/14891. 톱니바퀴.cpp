#include<iostream>

using namespace std;

string t[5];
int v[5];

void rotate_r(int x)
{
	int temp=t[x][7];
	for(int i=6; i>=0; i--)
		t[x][i+1]=t[x][i];
	t[x][0]=temp;
}

void rotate_l(int x)
{
	int temp=t[x][0];
	for(int i=1; i<8; i++)
		t[x][i-1]=t[x][i];
	t[x][7]=temp;
	
}

void dfs(int n, int d)
{	
	if((n+1)<=4 && v[n+1]==0)
	{
		v[n+1]=1;
		if(t[n][2]!=t[n+1][6])
		{
			if(d==-1)
				dfs(n+1, 1);
			else
				dfs(n+1, -1);
		}
	}
	if((n-1)>=1 && v[n-1]==0)
	{
		v[n-1]=1;
		if(t[n][6]!=t[n-1][2])
		{
			if(d==-1)
				dfs(n-1, 1);
			else
				dfs(n-1, -1);
		}
	}
	if(d==-1)
		rotate_l(n);
	else
		rotate_r(n);
}

int main(void)
{
	for(int i=1; i<5; i++)
		cin >> t[i];
	
	int k;
	cin >> k;
	
	for(int i=0; i<k; i++)
	{
		for(int i=0; i<5; i++)
			v[i]=0;
		int n, d;
		cin >> n >> d;
		
		v[n]=1;
		dfs(n, d);

	}

	int ans=0;
	if(t[1][0]=='1')
		ans+=1;
	if(t[2][0]=='1')
		ans+=2;
	if(t[3][0]=='1')
		ans+=4;
	if(t[4][0]=='1')
		ans+=8;

	cout << ans << '\n';
	return 0;
}