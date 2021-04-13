#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string n;
string cl="";
int minn=99999999;
vector<int> num(10, 1);

void bt(int c)
{
	if(c==n.size()+2)
		return;
	
	if(cl.size()!=0)
	{
		int t=abs(stoi(n)-stoi(cl))+int(cl.size());
		if(t<minn)
			minn=t;
	}
	for(int i=0; i<10; i++)
	{
		if(num[i]==1)
		{
			cl+=to_string(i);
			bt(c+1);
			cl.pop_back();
		}
	}
}

int main(void)
{
	cin >> n;
	int t;
	cin >> t;
	
	for(int i=0; i<t; i++)
	{
		int te;
		cin >> te;
		num[te]=0;
	}
	
	bt(0);
	cout << min(minn, abs(100-stoi(n))) << '\n';
	return 0;
}