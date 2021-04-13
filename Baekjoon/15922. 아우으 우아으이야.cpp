#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
  long long n, st, ed;
  long ans=0;
  cin >> n;
  vector<pair<long long, long long>> arr(n);
  pair<long long, long long> tmp;

  for(int i=0; i<n; i++)
  {
    cin >> tmp.first >> tmp.second;
    arr[i]=tmp;
  }

  sort(arr.begin(), arr.end());

  st=arr[0].first;
  ed=arr[0].second;
  for(int i=1; i<n; i++)
  {
    if(arr[i].first<=ed && arr[i].second<=ed)
      continue;
    if(arr[i].first<=ed)
      ed=arr[i].second;
    else
    {
      ans=ans+ed-st;
      st=arr[i].first;
      ed=arr[i].second;
    }
  }
  ans=ans+ed-st;
  cout << ans;
  return 0;
}