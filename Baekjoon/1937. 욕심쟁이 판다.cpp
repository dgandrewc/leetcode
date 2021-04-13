#include <iostream>
using namespace std;
 
int dp[500][500]={0};
int map[500][500]={0};
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int n;
 
int len=0;
int dfs(int y,int x){
    
    if(dp[y][x])
        return dp[y][x];
    
    dp[y][x]=1;
    
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        
        if(ny<0 ||ny>=n || nx<0 || nx>=n)
            continue;
        
        if(map[y][x]>=map[ny][nx])
            continue;
        
        dp[y][x]=max(dp[y][x],dfs(ny,nx)+1);
        
    }
    
    return dp[y][x];
}
int main(){
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans=max(ans,dfs(i,j));
        }
    }
    cout<<ans<<endl;
    return 0;
}