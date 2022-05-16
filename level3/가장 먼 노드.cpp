#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n+1);
    queue<int> q; 
    vector<int> visit(n+1, 0); 
    
    for(int i=0; i<edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]); 
        graph[edge[i][1]].push_back(edge[i][0]); 
    }
    
    q.push(1);
    visit[1]=1; 
    while(!q.empty()){
        int x = q.front(); 
        q.pop();
        
        for(int i=0; i<graph[x].size(); i++){
            if(!visit[graph[x][i]]){
               visit[graph[x][i]]= visit[x]+1; 
                q.push(graph[x][i]); 
            }
        }
    }
    
    sort(visit.begin(), visit.end(), greater<int>()); 
    for(auto i : visit){
        if(visit[0]== i){
            answer++;
        }
    }
    
    return answer;
}
