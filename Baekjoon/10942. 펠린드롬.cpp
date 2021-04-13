#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> dp(2001, vector<int>(2001));

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n+1);
	for(int i=1; i<n+1; i++)
		cin >> arr[i];
	
	for (int i=1; i<=n; i++)
	{ 
		dp[i][i]=1; 
		if (arr[i] == arr[i - 1])
			dp[i-1][i]=1; 
	}
	
	for(int i=2; i<n; i++)
		for(int j=1; i+j<=n; j++)
		{
			int k=i+j;
			if(arr[j]==arr[k] && dp[j+1][k-1]==1)
				dp[j][k]=1;
		}
	
	int m;
	cin >> m;

	for(int i=0; i<m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		cout << dp[t1][t2] << '\n';
	}
	
	return 0;
}