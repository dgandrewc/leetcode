#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(void)
{
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	stack<int> s, ns;
	
	for(int i=0; i<n; i++)
		cin >> v[i];
	
	for(int i=n-1; i>=0; i--)
	{
		while(!s.empty() && s.top()<=v[i])
			s.pop();
		
		if(s.empty())
			ns.push(-1);
		else
			ns.push(s.top());
		s.push(v[i]);
	}
	
	while(!ns.empty())
	{
		cout << ns.top() << ' ';
		ns.pop();
	}
	cout << endl;
	return 0;
}