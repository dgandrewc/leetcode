#include<cstdio>
#include<stack>

using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);
	stack<pair<int, int>> s;
	
	for(int i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		
		while(s.size()!=0 && s.top().second<t)
			s.pop();
		
		if(s.size()==0)
		{
			printf("0 ");
			s.push(pair(i, t));
			continue;
		}
		
		printf("%d ",s.top().first+1);
		s.push(pair(i, t));
	}
	return 0;
}