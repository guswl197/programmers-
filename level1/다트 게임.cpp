#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int sum[3]={0,0,0}; 

int solution(string dartResult) {
    stringstream stream(dartResult);
    int score;
    char bonus, option; 
    
    for (int i=0; i<3 ; i++){
        stream>>score; 
        bonus= stream.get(); 
        option=stream.get();
        
        if(option!= '*' && option!='#'){
            stream.unget();
        }
        
        switch(bonus){
            case 'S':
                sum[i]+= pow(score,1); 
                break; 
            case 'D':
                sum[i]+= pow(score,2); 
                break;
            case 'T':
                sum[i]+= pow(score,3); 
                break;    
        }
        
        switch(option){
            case '*':
                if(i>0){
                    sum[i-1]*=2; 
                }
                sum[i]*=2; 
                break; 
            case '#':
                sum[i]*=-1;
                break; 
            default:
                break; 
        }
    }
    
    int answer = sum[0]+sum[1]+sum[2]; 
    
    return answer;
}
