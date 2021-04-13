#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int n;
  cin >> n;
  int arr[n+1];
  int arr2[n];

  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr+n);
  arr2[0]=arr[0];
  for(int i=1; i<n; i++)
  {
    arr2[i]=arr2[i-1]+arr[i];
  }

  if(arr2[0]!=1)
  {
    cout << 1 << endl;
    return 0;
  }
  for(int i=0; i<n; i++)
  {
    if(arr2[i]+1<arr[i+1])
    {
      cout << arr2[i]+1;
      return 0;
    }
  }
  cout << arr2[n-1]+1;
}