#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	vector<vector<char>> arr(12, vector<char>(6));
	int dx[4]={0, 0, -1, 1};
	int dy[4]={-1, 1, 0, 0};
	queue<pair<int, int>> q;
	char bbuyo[5]={'R', 'G', 'B', 'P', 'Y'};
	for(int i=0; i<12; i++)
		for(int j=0; j<6; j++)
			cin >> arr[i][j];
	
	int countt=0;
	while(1)
	{
		int flag=0;
		vector<vector<int>> visit(12, vector<int>(6, 0));
		for(int i=0; i<12; i++)
		{
			for(int j=0; j<6; j++)
			{
				for(int k=0; k<5; k++)
				{
					if(arr[i][j]==bbuyo[k])
					{
						q.push(pair(i, j));
						visit[i][j]=1;
						queue<pair<int, int>> remove;
						remove.push(pair(i, j));
						while(!q.empty())
						{
							pair<int, int> temp=q.front();
							q.pop();
							int x=temp.first;
							int y=temp.second;
							
							for(int l=0; l<4; l++)
							{
								int nx=x+dx[l];
								int ny=y+dy[l];
								if(nx>=0 && nx<12 && ny>=0 && ny<6 && visit[nx][ny]==0 && arr[nx][ny]==bbuyo[k])
								{
									visit[nx][ny]=1;
									q.push(pair(nx, ny));
									remove.push(pair(nx, ny));
								}
							}
						}
						if(remove.size()>=4)
						{
							flag=1;
							while(!remove.empty())
							{
								pair<int, int> temp=remove.front();
								remove.pop();
								int rx=temp.first;
								int ry=temp.second;
								arr[rx][ry]='.';
							}
						}
					}
				}
			}
		}
		for(int l=0; l<6; l++)
		{
			for(int m=11; m>=0; m--)
			{
				if(arr[m][l]=='.')
				{
					int n;
					for(n=m; n>=0 && arr[n][l]=='.'; n--){}
					if(n==-1)
						n++;
					arr[m][l]=arr[n][l];
					arr[n][l]='.';
				}
			}
		}
		
		if(flag==0)
			break;
		countt++;
	}
	cout << countt << endl;
	return 0;
}