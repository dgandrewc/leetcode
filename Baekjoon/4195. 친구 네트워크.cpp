#include<iostream>
#include<map>

using namespace std;
map<string, string> parent;
map<string, int> friends;

string find(string x)
{
	if(parent[x]==x)
		return x;
	parent[x]=find(parent[x]);
	return parent[x];
}

void unio(string f1, string f2)
{
	f1=find(f1);
	f2=find(f2);
	
	if(f1>f2)
		parent[f1]=f2;
	else
		parent[f2]=f1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	
	for(int i=0; i<t; i++)
	{
		int f;
		parent.clear();
		cin >> f;
		
		for(int j=0; j<f; j++)
		{
			string f1, f2;
			cin >> f1 >> f2;
			if(parent.count(f1)==0)
			{
				parent[f1]=f1;
				friends[f1]=1;
			}
			if(parent.count(f2)==0)
			{
				parent[f2]=f2;
				friends[f2]=1;
			}
			
			if(find(f1)!=find(f2))
			{
				int temp=friends[find(f1)]+friends[find(f2)];
				friends[find(f1)]=temp;
				friends[find(f2)]=temp;
			}
			unio(f1, f2);

			cout << friends[find(f1)] << '\n';
		}
	}
	return 0;
}