#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
  int N, K;
  cin >> N >> K;
  string str;
  stack<int> s;
  stack<int> ans;

  cin >> str;

  for(int i=0; i<N; i++)
  {
    while(!s.empty() && K>0 && s.top() < str[i])
    {
      K--;
      s.pop();
    }
    s.push(str[i]);
  }

  while(K!=0)
  {
    s.pop();
    K--;
  }

  while(!s.empty())
  {
    ans.push(s.top());
    s.pop();
  }

  while(!ans.empty())
  {
    cout << ans.top()-'0';
    ans.pop();
  }
  return 0;
}