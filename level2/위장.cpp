#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string,int> m; 
     
    for(int i=0; i<clothes.size(); i++){
        m[clothes[i][1]]++; 
    }
    
    answer=1; 
    for(auto i=m.begin(); i!=m.end(); i++){
         answer*=(i->second)+1; 
    }
    answer-=1;
    
    return answer;
}
