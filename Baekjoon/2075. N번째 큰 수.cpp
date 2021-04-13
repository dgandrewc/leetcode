#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			int t;
			cin >> t;
			pq.push(t);
			if(pq.size()>n)
				pq.pop();
		}
	cout << pq.top() << '\n';
	return 0;
}