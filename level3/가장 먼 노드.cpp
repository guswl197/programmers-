#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n+1); 
    vector<int> count(n+1, 0); 
    vector<bool> visit(n+1, false); 
    queue<int> q; 
    
    for(int i=0; i<edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]); 
        graph[edge[i][1]].push_back(edge[i][0]); 
    }
    
    q.push(1); 
    visit[1]= true; 
    
    while(!q.empty()){
        int node= q.front(); 
        q.pop(); 
        
        for(int i=0; i<graph[node].size(); i++){
            if(!visit[graph[node][i]]){
                int curcnt= count[node]+1; 
                visit[graph[node][i]]=true; 
                count[graph[node][i]]= curcnt; 
                q.push(graph[node][i]); 
            }
        }
    }
    
    sort(count.begin(), count.end(), greater<int>()); 
    for(auto cnt : count){
        if(count[0]!= cnt ){
            break;
        }
        answer++;
    }
    return answer;
}
