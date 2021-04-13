#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
  string str1, str2;
  int t=0;
  cin >> str1;
  cin >> str2;
  vector<vector<int>> arr(str2.length()+1, vector<int>(str1.length()+1, 0));
  int rem=0;
  for(int i=1; i<str2.length()+1; i++)
  {
    t=0;
    for(int j=1; j<str1.length()+1; j++)
    {
      if(str1[j-1]==str2[i-1])
        arr[i][j]=arr[i-1][j-1]+1;
      else
        arr[i][j]=arr[i-1][j]>arr[i][j-1] ? arr[i-1][j] : arr[i][j-1];
    }
  }

  cout << arr[str2.length()][str1.length()];
  return 0;
}