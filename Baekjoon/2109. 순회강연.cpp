#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> parent(10001);

int find(int x)
{
  if(parent[x]==x)
    return x;
  parent[x]=find(parent[x]);
  return parent[x];
}

void unio(int x, int y)
{
  int px=find(x);
  int py=find(y);

  if(px==py)
  {
    parent[x]=x-1;
    parent[y]=y-1;
  }
  else if(x<y)
    parent[y]=x;
  else
    parent[x]=y;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
  if(a.first==b.first)
    return a.second>b.second;
  return a.first>b.first;
}

int main(void)
{
  int n;
  cin >> n;
  vector<pair<int, int>> arr;
  vector<int> ans;

  for(int i=0; i<10001; i++)
  {
    parent[i]=i;
    ans.push_back(0);
  }

  for(int i=0; i<n; i++)
  {
    int first, second;
    cin >> first >> second;
    arr.push_back(pair(first, second));
  }

  sort(arr.begin(), arr.end(), cmp);

  for(int i=0; i<n; i++)
  {
    if(find(arr[i].second)>0)
    {
      ans[find(arr[i].second)]=arr[i].first;
      unio(arr[i].second, find(arr[i].second-1));
    }
  }

  int count=0;
  for(int i=0; i<10001; i++)
    count+=ans[i];

  cout << count;
  return 0;
}