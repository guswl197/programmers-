#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<long> num;
vector<char> op; 
vector<char> top;
vector<long> temp; 
string order="*+-";  
char operation;
long number; 

void intcopy(vector<long>& a, vector<long>& b){ 
    for(int i=0; i<b.size(); i++){
        a.push_back(b[i]);  
    }
}

void charcopy(vector<char>& a, vector<char>& b){ 
    for(int i=0; i<b.size(); i++){
        a.push_back(b[i]);  
    }
}

long long solution(string expression) {
    long long answer = 0;
 
    stringstream stream(expression);  
    while(!stream.eof()){
        stream >> number;  
        num.push_back(number);
        if(!stream.eof()){
            operation= stream.get();
            op.push_back(operation);
        }
    }
    
    intcopy(temp, num); 
    charcopy(top, op); 
    sort(order.begin(), order.end());
    
    do{
        for(int i=0; i<order.size(); i++){
            for(int j=0; j<op.size(); j++){
                if(order[i]== op[j]){
                    long a= num[j], b=num[j+1];
        
                    if(order[i]=='*'){
                        num[j]= a*b; 
                    }
                    else if(order[i]=='+'){
                        num[j]= a+b; 
                    }
                    else if(order[i]=='-'){
                        num[j]= a-b; 
                    }
                    num.erase(num.begin()+j+1,num.begin()+j+2); 
                    op.erase(op.begin()+j, op.begin()+j+1);  
                    j--;
                }
            }
        }
        answer= max(answer, (long long)abs(num[0]));
        num.erase(num.begin(),num.begin()+1); 
        intcopy(num, temp); 
        charcopy(op, top);
    }
    while(next_permutation(order.begin(), order.end())); 
    
    return answer;
}
