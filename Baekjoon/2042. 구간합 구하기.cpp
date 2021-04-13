#include<iostream>
#include<vector>
using namespace std;

long long n, m, k;
vector<long long> v;
vector<long long> tree(21*1000001);

long long init(long long start, long long end, long long node)
{
	if(start==end)
		return tree[node]=v[start];
	long long mid=(start+end)/2;
	return tree[node]=init(start, mid, node*2)+init(mid+1, end, node*2+1);
}

long long sum(long long start, long long end, long long node, long long left, long long right)
{
	if(left>end || right <start)
		return 0;
	if(start>=left && right>=end)
		return tree[node];
	long long mid=(start+end)/2;
	return sum(start, mid, node*2, left, right)+sum(mid+1, end, node*2+1, left, right);
}

void update(long long start, long long end, long long node, long long index, long long dif)
{
	if(index<start || index > end)
		return;
	tree[node]+=dif;
	if(start==end)
		return;
	long long mid=(start+end)/2;
	update(start, mid, node*2, index, dif);
	update(mid+1, end, node*2+1, index, dif);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;

	v.push_back(0);
	for(long long i=0; i<n; i++)
	{
		long long t;
		cin >> t;
		v.push_back(t);
	}
	
	init(1, n, 1);
	
	for(long long i=0; i<m+k; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		
		if(a==1)
		{
			long long dif=c-v[b];
			v[b]=c;
			update(1, n, 1, b, dif);
		}
		if(a==2)
			cout << sum(1, n, 1, b, c) << '\n';
	}
	return 0;
}