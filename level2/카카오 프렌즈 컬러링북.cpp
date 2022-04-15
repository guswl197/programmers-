#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool visit[101][101];
int dx[5];
int dy[5];
int r,c; 
int cnt; 
int p[101][101]; 
int number; 
int max_cnt; 

void dfs(int x, int y){
    visit[x][y]=1; 
    cnt++;
    
    for(int i=0; i<4 ; i++){
        int nx= x+ dx[i]; 
        int ny= y+ dy[i]; 
        if(nx<0 || nx>=r || ny<0 || ny>=c ){
            continue; 
        }
        if(visit[nx][ny]==false&& p[nx][ny]== p[x][y]){
            dfs(nx,ny); 
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) { 
    dx[0]=0, dx[1]=0, dx[2]=1, dx[3]=-1; 
    dy[0]=1, dy[1]=-1, dy[2]=0, dy[3]=0; 
    cnt=0;
    number=0; 
    max_cnt=0; 
    vector<int> answer(2);
    memset(visit,false, sizeof(visit));
    r=m , c= n; 
 
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            p[i][j] = picture[i][j];
        }
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(p[i][j]>0 && visit[i][j]==false ){
                dfs(i,j); 
                number++; 
            }
        }
        max_cnt= max(max_cnt, cnt); 
        cnt=0; 
    }
    
    answer[0]=number;
    answer[1]=max_cnt;
    
    return answer;
}
