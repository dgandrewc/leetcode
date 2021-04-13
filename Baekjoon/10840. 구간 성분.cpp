#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

long long m[]={535147846335, 342335366754, 867756895237, 395453845407, 868545713655, 215863258865, 749638206561, 230545539484, 457998200576, 567620952976, 345543204715, 678958995246, 459988789690, 432510924455, 239255054260, 547088518782, 163744969758, 873934664528, 436775367699, 321514669850, 459671581623, 159783536245, 954353446017, 198365975824, 216919542878, 321493883659
};

int main(void)
{
	char str1[1501], str2[1501];
	cin >> str1 >> str2;

	int ans=0;
	for(int i=1; i<=min(strlen(str1), strlen(str2)); i++)
	{
		long long x=0;
		vector<long long> arr;
		for(int j=0; j<i; j++)
			x+=m[str1[j]-'a'];
		arr.push_back(x);
		for(int j=1; j+i-1<strlen(str1); j++)
		{
			x=x-m[str1[j-1]-'a']+m[str1[j+i-1]-'a'];
			arr.push_back(x);
		}
		
		sort(arr.begin(), arr.end());
		
		x=0;
		for(int j=0; j<i; j++)
			x+=m[str2[j]-'a'];
		if(binary_search(arr.begin(), arr.end(), x))
		{
			ans=i;
			continue;
		}
		for(int j=1; j+i-1<strlen(str2); j++)
		{
			x=x-m[str2[j-1]-'a']+m[str2[j+i-1]-'a'];
			if(binary_search(arr.begin(), arr.end(), x))
			{
				ans=i;
				break;
			}
		}
	}
	cout << ans << endl;
}