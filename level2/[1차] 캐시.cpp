#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

vector<string> v; 

int check(string city){
    for(int i=0; i<v.size(); i++){
        if(v[i]== city){
            return i;
        }
    }
    return -1; 
}

string toLower(string city){
    string lower; 
    for(int i=0; i<city.size(); i++){
        lower+= tolower(city[i]); 
    }
    
    return lower; 
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    string city; 
    int idx; 
    
    if(cacheSize==0){
        answer= cities.size()*5; 
        return answer; 
    }

    
    for(int i=0; i<cities.size(); i++){
        city= toLower(cities[i]);
        idx=check(city); 
        if(idx!=-1){ //캐시에 존재 
            answer+=1;
            v.erase(v.begin()+idx);
            v.push_back(city); 
        }
        else{ 
            if(v.size() == cacheSize &&v.size()!=0){ //캐시 full
                v.erase(v.begin()); 
            }
            v.push_back(city); 
            answer+=5;
        }

    }
    
    return answer;
}
