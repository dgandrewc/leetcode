#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main(void)
{
	int n;
	int cnt=400;
	cin >> n;
	vector<string> arr(n);
	map<char, char> change;
	change['H']='T';
	change['T']='H';
	
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	int bit=(1<<n)-1;
	while(bit)
	{
		vector<string> newarr;
		newarr=arr;
		int cmpcnt=0;
		for(int i=0; i<n; i++)
			if(bit & (1<<i))
				for(int j=0; j<n; j++)
					newarr[i][j]=change[newarr[i][j]];
		
		for(int i=0; i<n; i++)
		{
			int front=0, back=0;
			for(int j=0; j<n; j++)
			{
				if(newarr[j][i]=='T')
					front++;
				else
					back++;
			}
			if(front>back)
				cmpcnt+=back;
			else
				cmpcnt+=front;
		}
		cnt=min(cmpcnt, cnt);
		bit--;
	}
	cout << cnt << endl;
	return 0;
}