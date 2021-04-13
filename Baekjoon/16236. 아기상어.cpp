#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> arr;
vector<vector<int>> map;
int level=2, n, expr, countt, sum;

void make_map()
{
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      if(arr[i][j]==9)
        map[i][j]=0;
      else if(arr[i][j]>level)
        map[i][j]=8;
      else if(arr[i][j]==0 || arr[i][j]==level)
        map[i][j]=0;
      else
        map[i][j]=arr[i][j];
    }
  }
}

int main(void)
{
  cin >> n;
  vector<int> temp;

  vector<vector<int>> dis(n, vector<int>(n, 0));
  int tmp, min_dis=99999999, min_x=99999999, min_y=99999999;
  queue<int> qx, qy;
  int x, y;
  int dx[4]={0, -1, 1, 0};
  int dy[4]={-1, 0, 0, 1};

  for(int i=0; i<n; i++)
  {
    temp.clear();
    for(int j=0; j<n; j++)
    {
      cin >> tmp;
      temp.push_back(tmp);
      if(tmp==9)
      {
        qx.push(i);
        qy.push(j);
      }
    }
    arr.push_back(temp);
    map.push_back(temp);
  }

  make_map();
  while(!qx.empty())
  {
    x=qx.front();
    qx.pop();
    y=qy.front();
    qy.pop();


    if(x==min_x && y==min_y)
    {
	  min_dis=9999999;
	  min_x=99999999;
	  min_y=99999999;
      countt+=dis[x][y];
      for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) 
          dis[i][j]=0;
      arr[x][y]=0;
      expr++;
      if(expr==level)
      {
        expr=0;
        level+=1;
      }
      make_map();
      qx=queue<int>();
      qy=queue<int>();
      qx.push(x);
      qy.push(y);
      continue;
    }
    sum=0;
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<n; j++)
      {
        sum+=arr[i][j];
      }
    }
    if(sum==9)
      break;

    for(int i=0; i<4; i++)
    {
      if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<n && map[x+dx[i]][y+dy[i]]!=8)
      {
        dis[x+dx[i]][y+dy[i]]=dis[x][y]+1;
		if(map[x+dx[i]][y+dy[i]]!=0)
		{
			if(min_dis>dis[x+dx[i]][y+dy[i]])
			{
				min_x=x+dx[i];
				min_y=y+dy[i];
				min_dis=dis[x+dx[i]][y+dy[i]];
			}
			else if(min_dis==dis[x+dx[i]][y+dy[i]])
			{
				if(min_x==x+dx[i])
				{
					if(min_y>y+dy[i])
					{
						min_x=x+dx[i];
						min_y=y+dy[i];
					}
				}
				else if(min_x>x+dx[i])
				{
					min_x=x+dx[i];
					min_y=y+dy[i];
				}
			}
		}
		qx.push(x+dx[i]);
        qy.push(y+dy[i]);
        if(map[x+dx[i]][y+dy[i]]==0)
          map[x+dx[i]][y+dy[i]]=8;
      }
    }
  }
  cout << countt;
  return 0;
}