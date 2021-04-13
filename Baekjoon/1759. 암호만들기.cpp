#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int l, c;
vector<char> v(16);
vector<char> crypto;
vector<int> visit(16);

void bt(int cnt, int m, int j, int t)
{
	if(cnt==l && m>=1 && j>=2)
	{
		for(int i=0; i<l; i++)
			cout << crypto[i];
		cout << '\n';
		return;
	}
	for(int i=t; i<c; i++)
	{
		if(visit[i]==0)
		{
			visit[i]=1;
			crypto.push_back(v[i]);
			if(v[i]=='a' || v[i]=='e' || v[i]=='i' || v[i]=='o' || v[i]=='u')
				bt(cnt+1, m+1, j, i);
			else
				bt(cnt+1, m, j+1, i);
			
			crypto.pop_back();
			visit[i]=0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> l >> c;

	for(int i=0; i<c; i++)
		cin >> v[i];
	sort(v.begin(), v.begin()+c);
	
	bt(0, 0, 0, 0);
	
	return 0;
}