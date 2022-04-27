#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map<string,vector<int>> mp; 
string s[4], num; 

void add(int num){
    for(int i=0 ; i<16; i++){
        string str=""; 
        
        for(int j=0; j<4; j++){
            if(i & (1<<j)){
                str+='-'; 
            }
            else{
                str+=s[j]; 
            }
        }
        
        mp[str].push_back(num); 
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(auto &i : info){
        stringstream stream(i);
        stream >> s[0]>>s[1] >> s[2]>> s[3]>>num; 
        add(stoi(num)); 
    }
    
    for(auto &s : mp){
        sort(s.second.begin(), s.second.end()); 
    }
    
    for(auto &q : query){
        int score; 
        stringstream stream(q);
        stream >> s[0] >> num >> s[1] >> num >> s[2] >> num >> s[3]>> num; 
        score= stoi(num); 
        
        vector<int> v= mp[s[0] + s[1] + s[2] +s[3]];
        if(v.size()!=0){
            auto it= lower_bound(v.begin(), v.end(), score);
            answer.push_back(v.size() -(it - v.begin())); 
        }
        else{
            answer.push_back(0); 
        }
    }
    return answer;
}
