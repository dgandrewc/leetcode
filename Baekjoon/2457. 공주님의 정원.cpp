#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int dateToNum(int m, int d)
{
  int day=d;
  if(m==2) day+=31;
  if(m==3) day+=59;
  if(m==4) day+=90;
  if(m==5) day+=120;
  if(m==6) day+=151;
  if(m==7) day+=181;
  if(m==8) day+=212;
  if(m==9) day+=243;
  if(m==10) day+=273;
  if(m==11) day+=304;
  if(m==12) day+=334;
  return day;
}

int main(void)
{
  int n, count=0;
  cin >> n;
  vector<pair<int, int>> flower;
  priority_queue<int> q;

  for(int i=0; i<n; i++)
  {
    int t1, t2, t3, t4;
    cin >> t1 >> t2 >> t3 >> t4;
    flower.push_back(pair(dateToNum(t1, t2), dateToNum(t3, t4)));
  }

  sort(flower.begin(), flower.end());

  int idx=-1;
  int temp=0;
  int result=0;

  for(int i=dateToNum(3, 1); i<=dateToNum(11, 30) && idx<n; i=temp)
  {
    bool flag=false;
    idx++;

    for(int j=idx; j<flower.size(); j++)
    {
      if(flower[j].first>i)
        break;
      if(temp<flower[j].second)
      {
        temp=flower[j].second;
        idx=j;

        flag=true;
      }
    }

    if(flag)
      result+=1;
    else
    {
      cout << 0;
      return 0;
    }
  }
  cout << result;
  return 0;
}