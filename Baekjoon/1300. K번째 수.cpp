#include<iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	
	int left=1, right=k, ans;
	while(left<=right)
	{
		long long cnt=0;
		int mid=(left+right)/2;
		for(int i=1; i<=n; i++)
			cnt+=min(mid/i, n);
		if(cnt<k)
			left=mid+1;
		else
		{
			ans=mid;
			right=mid-1;
		}
	}
	cout << ans << '\n';
	return 0;
}