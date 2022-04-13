#include <string>
#include <vector>
#include <iostream>

using namespace std;

int phone[5][4]; 
pair<int ,int > le;
pair<int ,int> ri; 
string answer = "";
pair<int,int> d; 

pair<int,int> change(int number){

    switch(number){
        case 1:
            return {1,1}; 
        case 2:
            return {1,2}; 
        case 3:
            return {1,3}; 
        case 4:
            return {2,1}; 
        case 5:
            return {2,2}; 
        case 6:
            return {2,3}; 
        case 7:
            return {3,1}; 
        case 8:
            return {3,2}; 
        case 9:
            return {3,3}; 
        case 0:
            return {4,2};     
    }
}

void leftmove(){
     answer+= 'L'; 
     le.first=d.first; 
     le.second=d.second; 
}

void rightmove(){
      answer+= 'R'; 
      ri.first=d.first; 
      ri.second=d.second;
}

string solution(vector<int> numbers, string hand) {
    le.first= 4, le.second= 1; 
    ri.first= 4, ri.second= 3; 
    
    for(int i=0; i<numbers.size(); i++){
        d= change(numbers[i]);
        
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){
            leftmove(); 
            continue; 
        }
        if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9){
            rightmove(); 
            continue; 
        }
          
        int leftcnt= abs(le.first- d.first)+ abs(le.second- d.second);
        int rightcnt= abs(ri.first- d.first)+ abs(ri.second- d.second);
        
        if(leftcnt > rightcnt){
            rightmove(); 
        }
        else if(leftcnt < rightcnt){
            leftmove(); 
        }
        else if(hand=="right"){ 
            rightmove(); 
        }
        else{ //left 
            leftmove(); 
        }
    }
    
    return answer;
}
