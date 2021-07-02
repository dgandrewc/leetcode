#include <vector>
#include <queue>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    int dx[4]={0, -1, 1, 0};
    int dy[4]={-1, 0, 0, 1};
    
    
    queue<pair<int, int>> q;
    for(int i=0; i<picture.size(); i++)
    {
        for(int j=0; j<picture[0].size(); j++)
        {
            if(picture[i][j]!=0)
            {
                int c=picture[i][j];
                number_of_area++;
                int size=0;
                picture[i][j]=-1;
                
                q.push(pair(i, j));
                while(!q.empty())
                {
                    size++;
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    
                    for(int k=0; k<4; k++)
                    {
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        
                        if(nx>=0 && nx<picture.size() && ny>=0 && ny<picture[0].size() && picture[nx][ny]==c)
                        {
                            picture[nx][ny]=0;
                            q.push(pair(nx, ny));
                        }
                    }
                }
                max_size_of_one_area=max(max_size_of_one_area, size);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}