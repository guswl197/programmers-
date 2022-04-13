#include <string>
#include <vector>
#include  <algorithm>
#include <iostream>

using namespace std;


bool compare(pair<int,float> a , pair<int,float> b){
    if(a.second> b.second){
        return true;
    }
    else if(a.second < b.second){
        return false;
    }
    else if(a.first> b.first){
        return false;
    }
    else{
         return true;
    }

}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int cnt;
    int num=0; 
    vector<pair<int,float>> v(N+1); 
    
    for(int i=1; i<=N; i++){
        cnt=0; 
        num=0; 
        for(int j=0; j<stages.size(); j++){ 
            if(i==stages[j]){
                cnt++;
                num++; 
            }
            else if(i <=stages[j]){
                num++; 
            }
        }
        
        v[i].first= i; 
        if(cnt==0){
            v[i].second=0; 
        }
        else{
            v[i].second=(float)cnt/num; 
        }
    }
    
    
    sort(v.begin()+1, v.end(), compare); 
    
    for(int i=1; i<=N; i++){
        answer.push_back(v[i].first); 
    }
    
    return answer;
}
