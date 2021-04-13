#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int N, K, i, temp, count=0;
  cin >> N >> K;
  int arr[K];

  vector<int> plug, _plug;
  std::vector<int>::iterator it, it2;

  for(i=0; i<K; i++)
    cin >> arr[i];

  for(i=0; i<K; i++)
  {
    auto it=find(plug.begin(), plug.end(), arr[i]);
    if(plug.size()<N && it==plug.end())
    {
      plug.push_back(arr[i]);
      continue;
    }
    if(it!=plug.end())
    {
      continue;
    }

    temp=arr[i];
    i++;
    if(i==K)
    {
      count+=1;
      break;
    }

    _plug.clear();
    for(int j=i; j<K && _plug.size()<N-1; j++)
    {
      it=find(plug.begin(), plug.end(), arr[j]);
      it2=find(_plug.begin(), _plug.end(), arr[j]);
      if(it!=plug.end() && it2==_plug.end())
        _plug.push_back(arr[j]);
    }

    for(int j=0; j<plug.size(); j++)
    {
      auto it=find(_plug.begin(), _plug.end(), plug[j]);
      if(it==_plug.end())
      {
        plug[j]=temp;
        count++;
        i--;
        break;
      }
    }
    i--;
  }
  cout << count;
  return 0;
}