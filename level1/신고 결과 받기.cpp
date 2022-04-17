#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>

using namespace std;

map<string,set<string>> mp1; 
map<string,int > mp2;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int len=id_list.size(); 
    vector<int> answer(len,0);
    
    for(int i=0; i<report.size(); i++){
        istringstream iss(report[i]); 
        string a,b; 
        iss >> a>> b; 
        mp1[a].insert(b); 
    }
    
    for(int i=0; i<len; i++){
        for(auto j : mp1[id_list[i]]){
            mp2[j]++; 
        }
    }
    
    for(int i=0; i<len; i++){
        for(auto j : mp1[id_list[i]]){
            if(mp2[j]>=k){
                answer[i]++;
            }
        }
    }
        
    return answer;
}
