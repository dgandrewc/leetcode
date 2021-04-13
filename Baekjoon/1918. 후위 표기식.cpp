#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(void)
{
	string exp;
	cin >> exp;
	string ans="";
	stack<char> s;
	
	for(int i=0; i<exp.size(); i++)
	{
		if('A'<=exp[i] && 'Z'>=exp[i])
			ans+=exp[i];
		else if(exp[i]=='(')
			s.push(exp[i]);
		else if(exp[i]=='*' || exp[i]=='/')
		{
			while(!s.empty() && (s.top()=='*' || s.top()=='/'))
			{
				ans+=s.top();
				s.pop();
			}
			s.push(exp[i]);
		}
		else if(exp[i]=='+' || exp[i]=='-')
		{
			while(!s.empty() && s.top()!='(')
			{
				ans+=s.top();
				s.pop();
			}
			s.push(exp[i]);
		}
		else if(exp[i]==')')
		{
			while(!s.empty() && s.top()!='(')
			{
				ans+=s.top();
				s.pop();
			}
			s.pop();
		}
	}
	
	while(!s.empty())
	{
		ans+=s.top();
		s.pop();
	}
	cout << ans << '\n';
	return 0;
}