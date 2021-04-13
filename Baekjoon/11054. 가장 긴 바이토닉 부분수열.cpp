#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> v(n);
	
	for(int i=0; i<n; i++)
		cin >> v[i];
	
	vector<int> dp1(1001, 0);
	vector<int> dp_ans1(n);
	for(int i=0; i<n; i++)
	{
		int mx=0;
		for(int j=v[i]-1; j>0; j--)
		{
			if(dp1[j]>mx)
				mx=dp1[j];
		}
		dp1[v[i]]=mx+1;
		dp_ans1[i]=*max_element(dp1.begin(), dp1.end());
	}
	
	vector<int> dp2(1001, 0);
	vector<int> dp_ans2(n);
	for(int i=n-1; i>=0; i--)
	{
		int mx=0;
		for(int j=v[i]-1; j>0; j--)
		{
			if(dp2[j]>mx)
				mx=dp2[j];
		}
		dp2[v[i]]=mx+1;
		dp_ans2[i]=*max_element(dp2.begin(), dp2.end());
	}
	int ans=0;
	for(int i=0; i<n; i++)
		ans=max(ans, dp_ans1[i]+dp_ans2[i]);
	cout << ans-1 << '\n';
	return 0;
}