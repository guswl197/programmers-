#include <string>
#include <cctype>
#include <map> 
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string,int> m1; 
    unordered_map<string,int> m2;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower); 
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower); 
    
    for(int i=0; i<str1.size()-1 ; i++){
        if(isalpha(str1[i]) && isalpha(str1[i+1])){
            m1[str1.substr(i,2)]++; 
        }
    }

   for(int i=0; i<str2.size()-1 ; i++){
        if(isalpha(str2[i]) && isalpha(str2[i+1])){
            m2[str2.substr(i,2)]++; 
        }
    }
    
    int inter_cnt=0; 
    int uni_cnt=0; 
    
    for(auto &p :m1){
        inter_cnt+= min(p.second, m2[p.first]); 
    }
    
    for (auto & p : m1)
        m2[p.first] = max(m2[p.first], p.second);

    for (auto & p : m2)
        uni_cnt += p.second;
    
  
    if(inter_cnt==0 && uni_cnt==0 ){
        return 65536; 
    }
    
    else{
        return (double)inter_cnt/uni_cnt *65536; 
    }
}
