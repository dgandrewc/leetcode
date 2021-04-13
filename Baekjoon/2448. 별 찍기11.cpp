#include<iostream>
#include<vector>

using namespace std;
vector<vector<char>> arr(7000, vector<char>(7000, '*'));

void rm(float size, float height, float width)
{
  int temp=size;
  if(size<1)
    return;
  for(int i=height; i<height+size; i++)
  {
    for(int j=width-temp; j<width+temp-1; j++)
      arr[i][j]=' ';
    temp-=1;
  }
  rm(int(size/2), int(height-size/2), width);
  rm(int(size/2), int(height+size/2), width+size);
  rm(int(size/2), int(height+size/2), width-size);
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int I;
  cin >> I;

  for(int i=0; i<I*2; i++)
  {
    for(int j=0; j<I-i-1; j++)
      arr[i][j]=' ';
    for(int j=I+i; j<2*I-1; j++)
      arr[i][j]=' ';
  }

  rm(int(I/2), int(I/2), I);

  for(int i=0; i<I; i++)
  {
    for(int j=0; j<I*2-1; j++)
      cout << arr[i][j];
    cout << '\n';
  }
  return 0;
}