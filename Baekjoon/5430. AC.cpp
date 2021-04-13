#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	deque<int> dq;

	while(t--)
	{
		int n;
		string temp, cmd;
		cin >> cmd >> n >> temp;
		for(int i=0; i<temp.size(); i++)
		{
			string t_s="";
			if(temp[i]-'0'>=0 && temp[i]-'0'<=9)
			{
				for(;(temp[i]-'0'>=0 && temp[i]-'0'<=9); i++)
					t_s+=temp[i];
				dq.push_back(stoi(t_s));
			}
		}
		int state=0;
		for(int i=0; i<cmd.size(); i++)
		{
			if(cmd[i]=='R')
				state=(state+1)%2;
			if(cmd[i]=='D')
			{
				if(dq.size()==0)
				{
					state=2;
					break;
				}
				if(state==0)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}
		if(state==0)
		{
			cout << '[';
			while(dq.size())
			{
				cout << dq.front();
				dq.pop_front();
				if(dq.size())
					cout << ',';
			}
			cout << ']';
		}
		else if(state==1)
		{
			cout<< '[';
			while(dq.size())
			{
				cout << dq.back();
				dq.pop_back();
				if(dq.size())
					cout << ',';
			}
			cout << ']';
		}
		else if(state==2)
			cout << "error";
		cout << endl;
	}
	return 0;
}