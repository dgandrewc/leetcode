#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> arr;
int best=0, N, M;

void dfs(int x, int y, int l, int s, int f)
{
  if(l==3)
  {
    if(s==22) cout << x<< y<<endl;
    if(s>best)
      best=s;
  }
  else 
  {
    if(x+1<N && f!=3)
      dfs(x+1, y, l+1, s+arr[x+1][y], 1);
    if(y+1<M && f!=4)
      dfs(x, y+1, l+1, s+arr[x][y+1], 2);
    if(x-1>=0 && f!=1)
      dfs(x-1, y, l+1, s+arr[x-1][y], 3);
    if(y-1>=0 && f!=2)
      dfs(x, y-1, l+1, s+arr[x][y-1], 4);
  }
}

int main(void)
{
  int t;
  cin >> N >> M;

  for(int i=0; i<N; i++)
  {
    vector<int> temp;
    for(int j=0; j<M; j++)
    {
      cin >> t;
      temp.push_back(t);
    }
    arr.push_back(temp);
  }

  for(int i=0; i<N; i++)
  {
    for(int j=0; j<M; j++)
    {
      dfs(i, j, 0, arr[i][j], 0);
      if(j-1>=0 && j+1<M && i-1>=0)
        if(arr[i][j-1]+arr[i][j+1]+arr[i][j]+arr[i-1][j]>best)
          best=arr[i][j-1]+arr[i][j+1]+arr[i][j]+arr[i-1][j];
      if(i-1>=0 && i+1<N && j+1<M)
        if(arr[i-1][j]+arr[i+1][j]+arr[i][j]+arr[i][j+1]>best)
          best=arr[i-1][j]+arr[i+1][j]+arr[i][j]+arr[i][j+1];
      if(j-1>=0 && j+1<M && i+1<N)
        if(arr[i][j-1]+arr[i][j+1]+arr[i][j]+arr[i+1][j]>best)
          best=arr[i][j-1]+arr[i][j+1]+arr[i][j]+arr[i+1][j];
      if(i-1>=0 && i+1<N && j-1>=0)
        if(arr[i-1][j]+arr[i+1][j]+arr[i][j]+arr[i][j-1]>best)
          best=arr[i-1][j]+arr[i+1][j]+arr[i][j]+arr[i][j-1];
    }
  }
  
  cout << best;
  return 0;
}