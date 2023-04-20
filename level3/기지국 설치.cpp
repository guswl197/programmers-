#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int answer = 0;
    int index = 0; 
    
    for(int i=1; i<=n ; i++){
        if(stations[index]-w <= i && i<= stations[index]+w){
            i= stations[index]+w; 
            index++; 
        }
        else{
            answer++; 
            i+= w*2 ; 
        }
    }
    
    return answer;
}
