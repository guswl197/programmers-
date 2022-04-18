#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

unordered_map<string,int> mp[11]; 
int maxCnt[11]; 

void comb(string str, int pos, string candi){
    if(pos>= str.size()){
        int len= candi.size(); 
        if(len>=2){
            mp[len][candi]++;
            maxCnt[len]= max(mp[len][candi], maxCnt[len]);
        }
        return; 
    }
    comb(str, pos+1, candi+str[pos]);
    comb(str, pos+1, candi);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(string str : orders){
        sort(str.begin(), str.end());  
        comb(str, 0,"");
    }
    
    for(int len : course){
        for(auto item : mp[len]){
            if(item.second >=2 && item.second==maxCnt[len]){
                answer.push_back(item.first); 
            }
        }
    }
    
    sort(answer.begin(), answer.end()); 

    return answer;
}
