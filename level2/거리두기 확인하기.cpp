#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

char arr[6][6];
int visit[6][6]; 
int dx[]={1,-1,0,0}; 
int dy[]={0,0,1,-1}; 
int Min=0;
bool flag=true; 

bool bfs(int x, int y ){
    queue<pair<int ,int>> q; 
    q.push(make_pair(x,y)); 
    
    while(!q.empty()){
        int qx= q.front().first; 
        int qy =q.front().second;
        q.pop(); 
        
        for(int i=0; i<4; i++){
            int nx= qx+ dx[i]; 
            int ny= qy+dy[i]; 
            
        if(nx<0 || nx>= 5 || ny<0 || ny>=5 || arr[nx][ny]=='X'){
            continue; 
        }
  
        if(arr[nx][ny]=='O' && visit[nx][ny]==0){
            visit[nx][ny]= visit[qx][qy]+1; 
            q.push({nx,ny}); 
        }
        if(arr[nx][ny]=='P' && visit[qx][qy]+1<=2 && (nx!=x || ny!=y)){
            return false;
        }  
        }
    }

    return true; 
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int t=0; t<5 ; t++){
                arr[j][t]= places[i][j][t]; 
            }
        }
        
        for(int k=0; k<5; k++){
            for(int l=0; l<5; l++){
                flag =true;
                if(arr[k][l]=='P'){
                    memset(visit, 0, sizeof(visit)); 
                    flag= bfs(k,l); 
                    if(flag== false){
                        break;
                    }
                }
            }
            if(flag== false){
                break; 
            }
        }
        flag== true?answer.push_back(1) : answer.push_back(0);
    }

    return answer;

}
