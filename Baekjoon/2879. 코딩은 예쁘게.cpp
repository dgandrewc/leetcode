#include<iostream>
#include<vector>

using namespace std;

int sign(int x)
{
  if(x<0)
    return 1;
  else if(x==0)
    return 0;
  else
    return -1;
}

int main(void)
{
  int n;
  cin >> n;
  vector<int> wrong(n);
  vector<int> correct(n);
  vector<int> diff(n);
  vector<int> comp(n);

  for(int i=0; i<n; i++)
    cin >> wrong[i];

  for(int i=0; i<n; i++)
    cin >> correct[i];

  for(int i=0; i<n; i++)
    diff[i]=correct[i]-wrong[i];

  for(int i=0; i<n; i++)
    comp[i]=0;

  int count=0;
  while(1)
  {
    if(diff==comp)
      break;
      
    count++;
    int i=0;
    while(diff[i]==0)
      i++;

    int num=sign(diff[i]);
    for(;i<n; i++)
    {
      diff[i]+=num;
      if(num!=sign(diff[i+1]))
        break;
    }
  }
  cout << count;
}