#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> dp(1002, vector<int>(1002));

int main(void)
{
	string str1, str2;
	cin >> str1 >> str2;
	str1='0'+str1;
	str2='0'+str2;
	
	for(int i=1; i<str1.size(); i++)
	{
		for(int j=1; j<str2.size(); j++)
		{
			if(str1[i]==str2[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
		}
	}
	
	int i=str1.size()-1;
	int j=str2.size()-1;
	cout << dp[i][j] << '\n';
	
	string ans="";
	while(dp[i][j]!=0)
	{
		if(dp[i][j]==dp[i-1][j])
			i--;
		else if(dp[i][j]==dp[i][j-1])
			j--;
		else
		{
			ans=ans+str1[i];
			i--;
			j--;
		}
	}
	for(int i=ans.size()-1; i>=0; i--)
		cout << ans[i];
	cout << '\n';
	return 0;
}