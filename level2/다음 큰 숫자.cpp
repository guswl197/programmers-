#include <bits/stdc++.h>

using namespace std;

int bit(int x){
    int cnt =0; 
    while(x>0){
        if(x%2 == 1){
            cnt++;
        }
        x= x/2; 
    }
    
    return cnt; 
}

int solution(int n) {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int ans = n+1;
    int nCnt= bit(n); 
    
    while(1){
        if(nCnt == bit(ans)){
            break; 
        } 
        ans++;
    }
    
    return ans;
}
