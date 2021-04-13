#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
  int r, c;
  cin >> r >> c;
  int dx[4]={0, 0, -1, 1};
  int dy[4]={1, -1, 0, 0};

  vector<vector<char>> arr(r, vector<char>(c));
  vector<vector<int>> dis(r, vector<int>(c));
  queue<pair<int, int>> water;
  queue<pair<int, int>> gosum;

  for(int i=0; i<r; i++)
    for(int j=0; j<c; j++)
    {
      cin >> arr[i][j];
      dis[i][j]=0;
      if(arr[i][j]=='*')
        water.push(pair(i, j));
      else if(arr[i][j]=='S')
        gosum.push(pair(i, j));
    }

  while(!gosum.empty())
  {
    int tmp=water.size();
    for(int j=0; j<tmp; j++)
    {
      pair<int, int> tmp=water.front();
      int x=tmp.first;
      int y=tmp.second;
      water.pop();

      for(int i=0; i<4; i++)
      {
        if(x+dx[i]>=0 && x+dx[i]<r && y+dy[i]>=0 && y+dy[i]<c && (arr[x+dx[i]][y+dy[i]]=='.' || arr[x+dx[i]][y+dy[i]]=='v'))
        {
          arr[x+dx[i]][y+dy[i]]='*';
          water.push(pair(x+dx[i], y+dy[i]));
        }
      }
    }
    
    tmp=gosum.size();
    for(int j=0; j<tmp; j++)
    {
      pair<int, int> temp=gosum.front();
      int x=temp.first;
      int y=temp.second;

      gosum.pop();
      if(arr[x][y]=='D')
      {
        cout << dis[x][y];
        return 0;
      }

      for(int i=0; i<4; i++)
      {
        if(x+dx[i]>=0 && x+dx[i]<r && y+dy[i]>=0 && y+dy[i]<c && (arr[x+dx[i]][y+dy[i]]=='.' || arr[x+dx[i]][y+dy[i]]=='D'))
        {
          if(arr[x+dx[i]][y+dy[i]]!='D')
            arr[x+dx[i]][y+dy[i]]='v';
          dis[x+dx[i]][y+dy[i]]=dis[x][y]+1;
          gosum.push(pair(x+dx[i], y+dy[i]));
        }
      }
    }
  }

  cout << "KAKTUS" << endl;
  return 0;
}