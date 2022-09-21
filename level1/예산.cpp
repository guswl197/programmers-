#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> d, int budget) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int answer = 0;
    sort(d.begin(), d.end()); 
    for(int i=0; i<d.size(); i++){
        if(budget >= d[i]){
            answer++;
            budget-= d[i]; 
        }
        else{
            break; 
        }
    }
    
    return answer;
}
