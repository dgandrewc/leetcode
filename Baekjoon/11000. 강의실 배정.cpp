#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool comp(pair<int, int>p1, pair<int, int>p2)
{
  if(p1.first>p2.first)
    return false;
  else if(p1.first==p2.first)
  {
    if(p1.second>p2.second)
    {
      return false;
    }
    else
      return true;
  }
  else
    return true;
}

int main(void)
{
  int N;
  int start, end;
  cin >> N;
  pair<int, int> sub[N];
  priority_queue<int, vector<int>, greater<int>> room;

  for(int i=0; i<N; i++)
  {
    cin >> start >> end;
    sub[i]=make_pair(start, end);
  }

  sort(sub, sub+N, comp);
  
  room.push(sub[0].second);

  for(int i=1; i<N; i++)
  {
    if(sub[i].first>=room.top())
    {
      room.pop();
      room.push(sub[i].second);
    }
    else
      room.push(sub[i].second);
  }

  cout << room.size();
  return 0;
}