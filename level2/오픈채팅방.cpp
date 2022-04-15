#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

map<string,string> mp; 

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> temp; 
    
    for(int i=0; i<record.size(); i++){
        stringstream stream(record[i]);
        string act, userId, name; 
        stream >>act, stream >>userId;
        
        //act 
        if(act== "Enter"){
            stream>> name; 
            //기존 유저 검사
            if(mp.find(userId)!= mp.end()){
                for(int i=0; i<temp.size(); i++){
                    if(temp[i].first== userId){
                        temp[i].second= name; 
                    }
                }
            }
             mp[userId] = name; 
        }
        else if(act == "Change"){
            stream>> name; 
             for(int i=0; i<temp.size(); i++){
                    if(temp[i].first== userId){
                        temp[i].second= name; 
                    }
                }
            mp[userId]= name; 
            continue; 
        }
        else if(act=="Leave"){
            name= mp[userId];
        }
     temp.push_back({userId, name});
    }
    
    int j=0; 
    for(int i=0; i<record.size(); i++){
        if(record[i][0]=='E'){
            answer.push_back(temp[j++].second+ "님이 들어왔습니다.");   
        }
        else if(record[i][0]=='L'){
            answer.push_back(temp[j++].second+ "님이 나갔습니다."); 
        }
    }
    return answer;
}
