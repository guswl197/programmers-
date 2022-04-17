#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(int n, string s){
    vector<string> v;
    for(int i=0; i<s.size(); i+=n){
        v.push_back(s.substr(i,n)); 
    }
    
    return v; 
}

int solution(string s) {
    int answer = s.size();
    vector<string> v; 
    string first=""; 
    string str=""; 
    int cnt=1; 
    
    for(int i=1 ; i<=s.size()/2 ; i++){
        v=split(i, s); 
        first= v[0];  
        str=""; 
        cnt=1; 
        for(int j=1; j<v.size(); j++){
            if(first==v[j]){
                cnt++; 
            }
            else{
                if(cnt!=1){
                    str+= to_string(cnt); 
                }
                str+= first;
                first=v[j];
                cnt=1;
            }
        }
       if(cnt!=1){
            str+= to_string(cnt); 
        }
        str+= first;
    
        if(answer> str.size()){
            answer= str.size(); 
        }
        
    }
    return answer;
}
