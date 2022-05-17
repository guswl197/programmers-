#include <string>
#include <vector>
#include <map>

using namespace std;

int h,w; 
vector<vector<string>> rel; 
vector<int> v; 

bool check(int x){
    
    for(int i=0; i<v.size(); i++){
        if((v[i] & x )== v[i]){
        return false; 
        }
    }
    return true; 
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    h = relation.size(); 
    w= relation[0].size();
    rel= relation; 
    
    for(int i=1; i<(1<<w); i++){
        map<string,int> mp;  
        for(int j=0; j<h; j++){
            string str;
            for(int k=0; k<w; k++){
                if(i & (1<<k)){
                    str+= relation[j][k]; 
                }
            }
            mp[str]=1; 
        }
        if(mp.size()== h && check(i)){
            v.push_back(i); 
        }
    }
    return v.size();
}
