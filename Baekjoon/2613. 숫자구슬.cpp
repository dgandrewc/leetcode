#include<iostream>
#include<vector>

using namespace std;

int n, m;
int arr[300];

bool isOk(int val){
	int cnt=1, sum=0;

	for(int i=0; i<n; i++)
	{	
		if(arr[i]>val) return false;
		if(sum+arr[i]<=val)
			sum+=arr[i];
		else
		{
			cnt++;
			sum=arr[i];
		}
	}
	return cnt<=m;
}

int main(void)
{
	cin >> n >> m;
	int l=1, r=n*100;
	
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(isOk(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	
	cout << l << endl;
	
	int cnt=0, sum=0, group=1;
	vector<int> ans;
	for(int i=0; i<n; i++)
	{
		sum+=arr[i];
		if(sum>l)
		{
			ans.push_back(cnt);
			sum=arr[i];
			cnt=0;
			group++;
		}
		cnt++;
	}
	ans.push_back(cnt);
	
	int pos=ans.size()-1;
	while(group<m)
	{
		if(ans[pos]==1)
		{
			--pos;
		}
		else{
			--ans[pos];
			ans.push_back(1);
			group++;
		}
	}
	for(int val : ans)
		cout << val << ' ';
	return 0;
}