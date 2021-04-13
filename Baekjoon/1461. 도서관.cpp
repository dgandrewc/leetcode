#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
  long long n, m, t, ans=0;
  cin >> n >> m;
  vector<int> Marr;
  vector<int> Parr;

  for(int i=0; i<n; i++)
  {
    cin >> t;
    if(t<0)
      Marr.push_back(t);
    else
      Parr.push_back(t);
  }

  sort(Marr.begin(), Marr.end());
  sort(Parr.begin(), Parr.end());

  for(int i=0; i<Marr.size(); i+=m)
    ans+=(-Marr[i])*2;

  for(int i=Parr.size()-1; i>=0; i-=m)
    ans+=Parr[i]*2;

  if(Parr.size()==0)
    ans+=Marr[0];
  else if(Marr.size()==0)
    ans-=Parr[Parr.size()-1];
  else if(-Marr[0]>Parr[Parr.size()-1])
    ans+=Marr[0];
  else if(-Marr[0]<=Parr[Parr.size()-1])
    ans-=Parr[Parr.size()-1];

  cout << ans;
}