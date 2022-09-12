#include <bits/stdc++.h>

using namespace std;
int sum[3]= {0,0,0}; 

int solution(string dartResult) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    int score;
    char bonus, option;
    stringstream stream(dartResult);   
    
    for(int i=0; i<3; i++){
        stream >> score;
        bonus= stream.get(); 
        option= stream.get(); 
        
        if(option!='*' && option!='#'){
            stream.unget(); 
        }
        
        switch(bonus){
            case 'S' :
                sum[i]= score; 
                break; 
            case 'D' :
                sum[i]= pow(score,2); 
                break; 
            case 'T' :
                sum[i]= pow(score,3);
                break; 
        }
        
        switch(option){
            case '*' :
                if(i>0){
                    sum[i-1]*=2; 
                }
                sum[i]*=2; 
                break; 
            case '#' :
                sum[i]*=-1; 
                break; 
        }
    }
    
    return sum[0]+ sum[1]+ sum[2]; 
}

/*
#include <bits/stdc++.h>

using namespace std;
vector<int> v; 

int solution(string dartResult) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    int answer = 0;
    
    for(int i=0; i<dartResult.size(); i++){
        string number=""; 
        while('0'<=dartResult[i] && dartResult[i]<='9'){
            number+= dartResult[i];
            i++;
        }
        if(number!=""){
            v.push_back(stoi(number)); 
        }
        if(dartResult[i] == 'D'){
            v[v.size()-1]=pow(v.back(),2);
        }
        else if(dartResult[i] == 'T'){
            v[v.size()-1]= pow(v.back(),3);
        }
        else if(dartResult[i] == '*'){
            v[v.size()-1]*=2; 
            if(v.size() !=1){
                v[v.size()-2]*=2; 
            }
        }
        else if(dartResult[i] == '#'){
            v[v.size()-1]*=-1; 
        }
    }
    
    for(int i=0; i<v.size(); i++){
        answer+= v[i]; 
    }
    return answer;
}
*/
