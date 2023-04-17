#include <bits/stdc++.h>

using namespace std;

map<string, int> mp; 

vector<int> solution(int n, vector<string> words) {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    vector<int> answer;
    int num=0, order=0; 
    char end = words[0][0];   
    
    for(int i=0; i<words.size(); i++){
        if(end != words[i][0] || mp[words[i]] == 1){ 
            num = i%n + 1; 
            order = i/n +1; 
            break; 
        }
    
        mp[words[i]]=1; 
        end = words[i][words[i].length()-1]; 
    }
    
    answer.push_back(num);
    answer.push_back(order); 
    return answer;
}
