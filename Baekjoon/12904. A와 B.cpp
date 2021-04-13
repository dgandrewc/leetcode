#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
  string s, t;

  cin >> s >> t;

  for(int i=t.size()-1; i>=0; i--)
  {
    if(s.size()>t.size())
      break;
    if(s==t)
    {
      cout << 1;
      return 0;
    }
    if(t[i]=='A')
      t.pop_back();
    else if(t[i]=='B')
    {
      t.pop_back();
      reverse(t.begin(), t.end());
    }
  }
  cout << 0;
  return 0;
}