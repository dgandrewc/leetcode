#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	priority_queue<int> max_h;
	priority_queue<int, vector<int>, greater<int>> min_h;
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		int num;
		cin >> num;
		
		if(max_h.size()>min_h.size())
			min_h.push(num);
		else
			max_h.push(num);
		
		if(min_h.size()!=0 && min_h.size()!=0)
		{
			if(max_h.top()>min_h.top())
			{
				int max_v=max_h.top();
				max_h.pop();
				int min_v=min_h.top();
				min_h.pop();
				max_h.push(min_v);
				min_h.push(max_v);
			}
		}
		cout << max_h.top() << '\n';
	}
}