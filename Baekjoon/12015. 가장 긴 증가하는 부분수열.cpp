#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int n, cnt=0;
	cin >> n;
	
	vector<int> v;
	v.push_back(-10000000);
	
	for(int i=0; i<n; i++)
	{
		int temp;
		cin >> temp;
		if(temp>v.back())
		{
			v.push_back(temp);
			cnt++;
		}
		else
		{
			vector<int>::iterator low=lower_bound(v.begin(), v.end(), temp);
			*low=temp;
		}
		
	}
	cout << cnt << '\n';
	return 0;
}