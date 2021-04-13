#include<iostream>
#include<vector>

using namespace std;

int n, cnt=0;
vector<int> arr(15);

bool promising(int i)
{
	for(int j=0; j<i; j++)
		if(arr[i]==arr[j] || abs(arr[i]-arr[j])==(i-j))
			return false;
	return true;
}

void dfs(int i)
{
	if(i==n)
	{
		cnt++;
		return;
	}
	for(int j=0; j<n; j++)
	{
		arr[i]=j;
		if(promising(i))
			dfs(i+1);
	}
}

int main(void)
{
	cin >> n;
	
	dfs(0);

	cout << cnt << endl;
	return 0;
}