#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	
	for(int i=0; i<t; i++)
	{
		int n;
		cin >> n;
		vector<string> v(n);
		for(int j=0; j<n; j++)
			cin >> v[j];
		
		sort(v.begin(), v.end());
		
		int flag=0;
		for(int j=0; j<v.size()-1; j++)
		{
			if(v[j]==v[j+1].substr(0, v[j].size()))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";
	}
	return 0;
}