#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int ans = 0, start =1, index =0; 
    
    while(start <= n){
        if(start >= stations[index]-w && start <= stations[index]+w){
            start = stations[index]+w; 
            index++;
        }
        else{
            start+= 2*w; 
            ans++; 
        }
        start++; 
    }
 
    
    return ans;
}
