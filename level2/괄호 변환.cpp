#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std; 

bool check(string s){
    int cnt=0;  
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
           cnt++; 
        }
        else if(s[i]==')'){
           cnt--;
        }
        if(cnt<0){
            return false; 
        }
    }
    return cnt==0; 
}

int count1(string s){
    int cnt=0; 
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            cnt++;
        }
    }
    
    return cnt; 
}

int count2(string s){
    int cnt=0; 
    for(int i=0; i<s.size(); i++){
        if(s[i]==')'){
            cnt++;
        }
    }
    
    return cnt; 
}

string change(string s){
    //1단계
    if(s==""){
        return s;        
    }

    //2단계
    string u="", v=""; 
    u+=s[0]; 
    for(int i=1; i<s.size(); i++){
        if(count1(u)!= count2(u)){
            u+= s[i]; 
        }
        else{
            v+= s[i]; 
        }
    }

    if(check(u)){ //3
        v= change(v);
        return u+v; 
    }
    else{ //4
        string str=""; 
        str+='('; 
        str+= change(v);
        str+= ')'; 
        u.erase(u.begin()); 
        u.erase(u.size()-1); 
        
        for(int i=0; i<u.size(); i++){
            if(u[i]=='('){
                u[i]=')';   
            }
            else if(u[i]==')'){
                 u[i]='(';   
            }
        }
        
        str+=u; 
        return str; 
    } 
    
    return ""; 
}

string solution(string p) {
    string answer = "";
    
    if(p==""){
        answer=""; 
    }
    else if(check(p)){ //이미 올바른 괄호 문자열
       answer=p; 
    }
    else{ //균형잡힌 문자열
      answer= change(p); 
    }

    return answer;
}
