#include <bits/stdc++.h>

using namespace std;

string S; 

bool remove(){
    string tmp; 
    bool flag= false; 
    tmp+= S[0];
    for(int i=1; i<S.length(); i++){
        if(tmp[tmp.length()-1]!= S[i]){
            tmp+= S[i]; 
        }
        else{
            tmp.erase(tmp.end()-1); 
            flag= true; 
        }
    }
    S = tmp; 
    return flag; 
}

int solution(string s){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    S= s; 
    int ans = -1;
    
    if(S.length()%2 != 0){
        return 0; 
    }
    
    while(S.length()>=1){
        if(remove()){
            ans=1; 
        }
        else{
            ans = 0; 
            break; 
        }
    }
    
    return ans;
}
