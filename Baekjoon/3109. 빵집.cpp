#include <iostream>
#include <vector>

using namespace std;
int R, C, count=0;
vector<string> arr;

int dfs1(int x, int y)
{
  int check1=1, check2=1, check3=1;
  arr[x][y]='x';
  if(y==C)
  {
    count+=1;
    return 0;
  }

  if(x-1>=0 && arr[x-1][y+1]!='x')
    check1=dfs1(x-1, y+1);
  if(arr[x][y+1]!='x' && check1==1)
    check2=dfs1(x, y+1);
  if(x+1<R && arr[x+1][y+1]!='x' && check1==1 && check2==1)
    check3=dfs1(x+1, y+1);

  if(check1==1 && check2==1 && check3==1)
  {
    return 1;
  }
  else
    return 0;
}

int dfs2(int x, int y)
{
  int check1=1, check2=1, check3=1;
  arr[x][y]='x';
  if(y==C)
  {
    count+=1;
    return 0;
  }
  
  if(x+1<R && arr[x+1][y+1]!='x')
    check1=dfs2(x+1, y+1);
  if(arr[x][y+1]!='x' && check1==1)
    check2=dfs2(x, y+1);
  if(x-1>=0 && arr[x-1][y+1]!='x' && check1==1 && check2==1)
    check3=dfs2(x-1, y+1);

  if(check1==1 && check2==1 && check3==1)
  {
    return 1;
  }
  else 
    return 0;
}

int main(void)
{
  cin >> R >> C;
  string tmp;

  for(int i=0; i<R; i++)
  {
    cin >> tmp;
    arr.push_back(tmp);
  }

  for(int i=0; i<R; i++)
  {
    if(i>R-1-i)
      break;
    dfs1(i, 0);
    dfs2(R-1-i, 0);
  }

  cout << count;
  return 0;
}