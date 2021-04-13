#include<iostream>
#include<vector>

using namespace std;

vector<vector<bool>> Visit(31, vector<bool>(31, false));
int N, M, H, Answer;

bool check()
{
	for(int i=1; i<N+1; i++)
	{
		int state=i;
		for(int j=1; j<H+1; j++)
		{
			if(Visit[state][j]==true)
				state=state+1;
			else if(Visit[state-1][j]==true)
				state=state-1;
		}
		if(state!=i)
			return false;
	}
	return true;
}

void Select_Line(int Idx, int Cnt)
{
	if(Cnt>=4)
		return;
	if(check())
	{
		Answer=min(Cnt, Answer);
		return;
	}
	
	for(int i=Idx; i<=H; i++)
	{
		for(int j=1; j<N; j++)
		{
			if(Visit[j][i]==true || Visit[j-1][i]==true || Visit[j+1][i]==true)
				continue;
			
			Visit[j][i]=true;
			Select_Line(i, Cnt+1);
			Visit[j][i]=false;
		}
	}
}

void Input()
{
    Answer = 9999999;
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        Visit[b][a] = true;
    }
}

void Solution()
{
    Select_Line(1, 0);    
 
    if (Answer == 9999999) Answer = -1;
    
    cout << Answer << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Solve();

	return 0;
}