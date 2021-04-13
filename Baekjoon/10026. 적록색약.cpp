#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
  int n, x, y, count1=0, count2=0, temp;
  int calx[4]={-1, 0, 0, 1};
  int caly[4]={0, -1, 1, 0};
  cin >> n;
  string arr[n];
  char arr2[n][n];
  queue<int> qx, qy;

  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      if(arr[i][j]=='R' || arr[i][j]=='G')
      {
        arr2[i][j]='A';
      }
      else
      {
        arr2[i][j]='B';
      }
    }
  }

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      if(arr[i][j]!='C')
      {
        temp=arr[i][j];
        count1+=1;
        qx.push(i);
        qy.push(j);

        while(!qx.empty())
        {
          x=qx.front();
          qx.pop();
          y=qy.front();
          qy.pop();

          for(int k=0; k<4; k++)
          {
            if(x+calx[k]>=0 && x+calx[k]<n && y+caly[k]>=0 && y+caly[k]<n && arr[x+calx[k]][y+caly[k]]==temp)
            {
              qx.push(x+calx[k]);
              qy.push(y+caly[k]);
              arr[x+calx[k]][y+caly[k]]='C';
            }
          }
        }
      }
    }
  }

  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      if(arr2[i][j]!='C')
      {
        temp=arr2[i][j];
        count2+=1;
        qx.push(i);
        qy.push(j);

        while(!qx.empty())
        {
          x=qx.front();
          qx.pop();
          y=qy.front();
          qy.pop();

          for(int k=0; k<4; k++)
          {
            if(x+calx[k]>=0 && x+calx[k]<n && y+caly[k]>=0 && y+caly[k]<n && arr2[x+calx[k]][y+caly[k]]==temp)
            {
              qx.push(x+calx[k]);
              qy.push(y+caly[k]);
              arr2[x+calx[k]][y+caly[k]]='C';
            }
          }
        }
      }
    }
  }
  cout << count1 << ' ' << count2;
  return 0;
}