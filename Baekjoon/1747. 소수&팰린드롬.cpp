#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int n;
	vector<int> prime(2000001, 1);
	vector<int> pelin(2000001, 1);
	prime[0]=0;
	prime[1]=0;
	
	for(int i=2; i<1415; i++)
		if(prime[i])
			for(int j=i*2; j<2000001; j+=i)
				prime[j]=0;
	
	for(int i=0; i<2000001; i++)
	{
		string str=to_string(i);
		for(int j=0; j<str.size(); j++)
			if(str[j]!=str[str.size()-j-1])
				pelin[i]=0;
	}
	
	cin >> n;
	for(int i=n; i<2000001; i++)
		if(prime[i]==1 && pelin[i]==1)
		{
			cout << i << '\n';
			return 0;
		}
	return 0;
}