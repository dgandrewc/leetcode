#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main(void)
{
  int n;
  cin >> n;
  vector<int> crain(n);
  vector<int> crain_load(n);
  for(int i=0; i<n; i++)
  {
    cin >> crain[i];
    crain_load[i]=0;
  }
  sort(crain.begin(), crain.end());

  int m;
  cin >> m;
  vector<int> box(m);
  for(int i=0; i<m; i++)
    cin >> box[i];
  sort(box.begin(), box.end());


  if(box[box.size()-1]>crain[crain.size()-1])
  {
    cout << -1;
    return 0;
  }

  for(int i=box.size()-1; i>=0; i--)
  {
    for(int j=0; j<crain.size(); j++)
    {
      if(crain[j]>=box[i])
      {
        int smallest=crain_load[j];
        int idx=j;
        for(int k=j; k<n; k++)
        {
          if(crain_load[k]<smallest)
          {
            smallest=crain_load[k];
            idx=k;
          }
        }
        crain_load[idx]+=1;
        break;
      }
    }
  }
  int biggest=0;
  for(int i=0; i<n; i++)
    if(crain_load[i]>biggest)
      biggest=crain_load[i];

  cout << biggest;
  return 0;
}