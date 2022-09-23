#include <bits/stdc++.h>

using namespace std;

map<char, int> mp; 
vector<string> v= {"RT", "CF", "JM", "AN"}; 

string solution(vector<string> survey, vector<int> choices) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    string answer = "";
        
    for(int i=0; i<choices.size() ; i++){
        
        if(choices[i] == 1){
            mp[survey[i][0]]+=3; 
        }
        else if(choices[i] == 2){
            mp[survey[i][0]]+=2; 
        }
        else if(choices[i] == 3){
            mp[survey[i][0]]+=1;
        }
        else if(choices[i] == 5){
            mp[survey[i][1]]+=1;
        }
        else if(choices[i] == 6){
            mp[survey[i][1]]+=2; 
        }
        else if(choices[i] == 7){ 
            mp[survey[i][1]]+=3; 
        }
    }
    
    for(int i=0; i<4; i++){
        if(mp[v[i][0]] >= mp[v[i][1]]){
            answer+= v[i][0]; 
        }
        else if(mp[v[i][0]] < mp[v[i][1]]){
            answer+= v[i][1]; 
        }
    }
    
    return answer;
}
