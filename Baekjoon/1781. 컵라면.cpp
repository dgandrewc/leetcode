#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> arr(200001);
int parent[200001];

struct cmp{
  bool operator()(pair<int, int> a, pair<int, int> b)
  {
    if(a.first==b.first)
      return a.second<b.second;
    return a.first<b.first;
  }
};

int f(int x){
  if(x==parent[x])
    return x;
  parent[x]=f(parent[x]);
  return f(parent[x]);
}

void u(int x, int y){
  x=f(x);
  y=f(y);
  if(x==y)
  {
    parent[x]=x-1;
    parent[y]=y-1;
  }
  else if(x<y)
    parent[y]=x;
  else
    parent[x]=y;
}

int main(void)
{
  int n, t1, t2;
  cin >> n;
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

  for(int i=0; i<200001; i++)
    parent[i]=i;

  for(int i=0; i<n; i++)
  {
    cin >> t1 >> t2;
    q.push(pair(t2, t1));
  }

  while(!q.empty())
  {
    pair<int, int> tmp=q.top();
    int lamen=tmp.first;
    int dead=tmp.second;
    q.pop();

    if(f(dead)>0)
    {
      arr[f(dead)]=lamen;
      u(dead, f(dead-1));
    }
  }
  
  long long lamen=0;
  for(int i=1; i<200001; i++)
    lamen+=arr[i];

  cout << lamen;
  return 0;
}