#include<iostream>
#include<vector>

using namespace std;
vector<int> v(1000001);

int find(int x)
{
	if(v[x]==x)
		return x;
	v[x]=find(v[x]);
	return v[x];
}

void unio(int a, int b)
{
	int fa=find(v[a]);
	int fb=find(v[b]);
	if(fa>fb)
		v[fa]=fb;
	else
		v[fb]=fa;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	for(int i=0; i<n+1; i++)
		v[i]=i;
	
	for(int i=0; i<m; i++)
	{
		int cmd, a, b;
		cin >> cmd >> a >> b;
		
		if(cmd==0)
			unio(a, b);

		if(cmd==1)
		{
			if(find(a)==find(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}
	return 0;
}