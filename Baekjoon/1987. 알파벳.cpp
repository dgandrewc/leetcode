#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_count;
vector<string> arr;
vector<char> visited;

int calx[4]={-1, 0, 0, 1};
int caly[4]={0, -1, 1, 0};

void dfs(int x, int y, int count)
{
  if(count>max_count)
  {
    max_count=count;
  }
  for(int i=0; i<4; i++)
  {
    if(x+calx[i]>=0 && x+calx[i]<arr.size() && y+caly[i]>=0 && y+caly[i]<arr[0].size() && find(visited.begin(), visited.end(), arr[x+calx[i]][y+caly[i]])==visited.end())
    {
      visited.push_back(arr[x+calx[i]][y+caly[i]]);
      dfs(x+calx[i], y+caly[i], count+1);
      visited.pop_back();
    }
  }
}

int main(void)
{
  int R, C;


  cin >> R >> C;
  string tmp;

  for(int i=0; i<R; i++)
  {
    cin >> tmp;
    arr.push_back(tmp);
  }

  visited.push_back(arr[0][0]);
  dfs(0, 0, 1);
  cout << max_count;
}