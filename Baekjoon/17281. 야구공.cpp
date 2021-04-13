#include<iostream>
#include<vector>

using namespace std;

vector<int> order(9);
vector<vector<int>> v(51, vector<int>(9));
vector<int> visit(9);

int n, ans;

void score()
{
	int mid_sum=0;
	int j=0;
	int state[3];
	for(int i=0; i<n; i++)
	{
		int out=0;
		while(1)
		{
			int play=v[i][order[j]];
			if(play==1)
			{
				if(state[2]==1)
					mid_sum++;
				state[2]=state[1];
				state[1]=state[0];
				state[0]=1;
			}
			else if(play==2)
			{
				if(state[2]==1)
					mid_sum++;
				if(state[1]==1)
					mid_sum++;
				state[2]=state[0];
				state[1]=1;
				state[0]=0;
			}
			else if(play==3)
			{
				if(state[2]==1)
					mid_sum++;
				if(state[1]==1)
					mid_sum++;
				if(state[0]==1)
					mid_sum++;
				state[2]=1;
				state[1]=0;
				state[0]=0;
			}
			else if(play==4)
			{
				if(state[2]==1)
					mid_sum++;
				if(state[1]==1)
					mid_sum++;
				if(state[0]==1)
					mid_sum++;
				mid_sum++;
				state[2]=0;
				state[1]=0;
				state[0]=0;
			}
			else if(play==0)
			{
				out++;
				if(out==3)
				{
					state[0]=0;
					state[1]=0;
					state[2]=0;
					j++;
					if(j==9)
						j=0;
					break;
				}
			}
			j++;
			if(j==9)
				j=0;
		}
	}
	ans=max(ans, mid_sum);
}


void dfs(int cnt)
{
	if(cnt==3)
		cnt++;
	if(cnt==9)
	{
		score();
		return;
	}
	
	for(int i=0; i<9; i++)
	{
		if(visit[i]==0 && i!=0)
		{
			visit[i]=1;
			order[cnt]=i;
			dfs(cnt+1);
			visit[i]=0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<9; j++)
			cin >> v[i][j];
	
	dfs(0);
	cout << ans << '\n';
	return 0;
}