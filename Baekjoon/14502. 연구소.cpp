#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> arr)
{
  int x, y, count=0;
  queue<int> qx, qy;

  for(int i=0; i<arr.size(); i++)
  {
    for(int j=0; j<arr[i].size(); j++)
    {
      if(arr[i][j]==2)
      {
        qx.push(i);
        qy.push(j);
      }
    }
  }
  while(!qx.empty())
  {
    x=qx.front();
    qx.pop();
    y=qy.front();
    qy.pop();

    if(x-1>=0 && arr[x-1][y]==0)
    {
      qx.push(x-1);
      qy.push(y);
      arr[x-1][y]=2;
    }
    if(x+1<arr.size() && arr[x+1][y]==0)
    {
      qx.push(x+1);
      qy.push(y);
      arr[x+1][y]=2;
    }
    if(y-1>=0 && arr[x][y-1]==0)
    {
      qx.push(x);
      qy.push(y-1);
      arr[x][y-1]=2;
    }
    if(y+1<arr[0].size() && arr[x][y+1]==0)
    {
      qx.push(x);
      qy.push(y+1);
      arr[x][y+1]=2;
    }
  }
  for(int i=0; i<arr.size(); i++)
  {
    for(int j=0; j<arr[i].size(); j++)
    {
      if(arr[i][j]==0)
        count++;
    }
  }
  return count;
}

int main(void)
{
  int N, M;
  int count, max=0;
  cin >> N >> M;
  vector<int> x, y;
  vector<vector<int>> arr(N, vector<int>(M));

  for(int i=0; i<N; i++)
  {
    for(int j=0; j<M; j++)
    {
      cin >> arr[i][j];
    }
  }

  for(int i=0; i<N; i++)
  {
    for(int j=0; j<M; j++)
    {
      if(arr[i][j]==0)
      {
        x.push_back(i);
        y.push_back(j);
      }
    }
  }

  for(int i=0; i<x.size(); i++)
  {
    for(int j=i; j<x.size(); j++)
    {
      for(int k=j; k<x.size(); k++)
      {
        if(i==j || j==k || i==j)
          continue;
        arr[x[i]][y[i]]=1;
        arr[x[j]][y[j]]=1;
        arr[x[k]][y[k]]=1;
        count=bfs(arr);
        if(count>max)
          max=count;
        arr[x[i]][y[i]]=0;
        arr[x[j]][y[j]]=0;
        arr[x[k]][y[k]]=0;
      }
    }
  }
  cout << max;
  return 0;
}