#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int n, sum=0, zeroflag=0, i, j;
  int *arr;
  cin >> n;
  arr=new int[n];

  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr+n);

  for(i=n-1; arr[i-1]>1 && i>0; i-=2)
  {
    if(arr[i]==1 || arr[i-1]==1)
      break;
    sum+=arr[i]*arr[i-1];
  }
  if(arr[i]>1 && i>=0)
  {
    sum+=arr[i];
    i-=1;
  }
  while(arr[i]==1)
  {
    sum+=1;
    i-=1;
  }
  if(arr[i]==0 && i>=0)
  {
    zeroflag=1;
    i-=1;
  }
  else if(arr[i-1]==0 && (i-1)>=0)
  {
    sum+=arr[i];
    zeroflag=1;
    i-=2;
  }
  for(j=0; (j+1)<=i && arr[j]<0; j+=2)
  {
    sum+=arr[j]*arr[j+1];
  }
  if(!zeroflag && arr[j]<0)
  {
    sum+=arr[j];
  }
  cout << sum;
}