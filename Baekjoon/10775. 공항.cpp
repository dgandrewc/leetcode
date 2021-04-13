#include <iostream>

using namespace std;
int *arr, *parent;

int getParent(int x)
{
  if(parent[x]==x)
    return x;
  parent[x]=getParent(parent[x]);
  return parent[x];
}

void unionParent(int x, int y){
  x=getParent(x);
  y=getParent(y);
  if(x==y)
    parent[x]=x-1;
  else if(x<y)
    parent[y]=x;
  else
    parent[x]=y;
}

int main(void)
{
  int G, P, flag=0, count=0;
  cin >> G >> P;
  arr=new int[P];
  parent=new int[G+1];

  for(int i=0; i<P; i++)
    cin >> arr[i];
  for(int i=0; i<G+1; i++)
    parent[i]=i;

  for(int i=0; i<P; i++)
  {
    if(getParent(arr[i])==0)
      break;
    unionParent(arr[i], arr[i]-1);
    count+=1;
  }

  cout << count;
  return 0;
}