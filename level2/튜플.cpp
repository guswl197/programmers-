#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

int number;  
map<int, int> m; 

bool compare(pair<int,int>& a ,pair<int,int>& b){
    return a.second > b.second; 
}

vector<int> solution(string s) {
    vector<int> answer; 
    for(int i=0; i<s.size(); i++){
        if(!('0'<=s[i] && s[i]<='9')){
            s[i]=' '; 
        }
    }
    stringstream stream(s);
    
     while(stream >> number){
         m[number]++; 
    }
    
    vector<pair<int,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare); 

    for(auto i = v.begin(); i!=v.end(); i++){
        answer.push_back(i->first); 
    }
  
    return answer;
}
