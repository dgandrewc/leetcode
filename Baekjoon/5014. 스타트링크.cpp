#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void)
{
	int f, s, g, u, d;
	
	cin >> f >> s >> g >> u >> d;
	
	queue<pair<int, int>> q;
	vector<int> visit(f+1, 0);
	
	visit[s]=1;
	q.push(pair(s, 0));
	
	while(!q.empty())
	{
		pair<int, int> temp=q.front();
		q.pop();
		int x=temp.first;
		int c=temp.second;
		
		if(x==g)
		{
			cout << c << endl;
			return 0;
		}
		
		if(x+u<=f && visit[x+u]==0)
		{
			visit[x+u]=1;
			q.push(pair(x+u, c+1));
		}
		if(x-d>=1 && visit[x-d]==0 )
		{
			visit[x-d]=1;
			q.push(pair(x-d, c+1));
		}
	}
	cout << "use the stairs" << endl;
	return 0;
}