#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 500005

priority_queue<pair<int,int>> pq; 

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int d[N+5]; 
    vector<pair<int,int>> v[N+5]; 
    
    for(int i=0; i<road.size(); i++){
        v[road[i][0]].push_back({road[i][1], road[i][2]}); 
        v[road[i][1]].push_back({road[i][0], road[i][2]}); 
    }
    
    fill(d, d+N+5, INF); 
    pq.push(make_pair(0,1)); //거리, 노드
    d[1]=0;
    
    while(!pq.empty()){
        int dis= -pq.top().first; 
        int now= pq.top().second; 
        pq.pop(); 
        
        if(dis> d[now]){
            continue; 
        }
        
        for(int i=0; i<v[now].size(); i++){
            int cost= dis+ v[now][i].second; 
            
            if(cost < d[v[now][i].first]){
                d[v[now][i].first]= cost; 
                pq.push({-cost, v[now][i].first}); 
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        if(d[i]<=K){
            answer++; 
        }
    }

    return answer;
}
