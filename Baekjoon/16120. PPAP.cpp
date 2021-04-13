#include<iostream>


using namespace std;

int main(void)
{
	string str;
	cin >> str;
	int cnt=0;

	for(int i=0; i<str.size(); i++)
	{
		if(str[i]=='P')
			cnt++;
		else if(str[i]=='A')
		{
			if(cnt>=2 && str[i+1]=='P')
			{
				cnt--;
				i++;
			}
			else
			{
				cout << "NP" << endl;
				return 0;
			}
		}
	}
	
	if(cnt==1)
		cout << "PPAP" << endl;
	else
		cout << "NP" << endl;
	return 0;
}