#include <bits/stdc++.h>

using namespace std;

pair<int, int> left_loc; 
pair<int, int> right_loc; 
pair<int, int> number_loc;  

pair<int,int> change(int num){
    
    pair<int,int> p; 
    
    if(num == 0){
        return {3,1};    
    }
    
    int cnt=1; 
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(cnt == num){
                return {i,j};        
          } 
            cnt++; 
        }
    }
    
    return {0,0}; 
}

string solution(vector<int> numbers, string hand) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    string answer = "";
    
    left_loc={3,0};  //L
    right_loc={3,2}; //R 
    
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer+='L'; 
            left_loc= change(numbers[i]); 
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer+='R'; 
            right_loc= change(numbers[i]); 
        }
        else{
            number_loc= change(numbers[i]); 
            int Ldis= abs(left_loc.first- number_loc.first) + abs(left_loc.second- number_loc.second); 
            int Rdis= abs(right_loc.first- number_loc.first) + abs(right_loc.second- number_loc.second); 
            
            if(Ldis < Rdis){
                answer+='L';
                left_loc= {number_loc.first, number_loc.second};
            }
            else if(Ldis > Rdis){
                answer+='R';
                right_loc= {number_loc.first, number_loc.second};
            }
            else{
                if(hand == "right"){
                    answer+='R';
                    right_loc= {number_loc.first, number_loc.second};
                }
                else{
                    answer+='L';
                    left_loc= {number_loc.first, number_loc.second};
                }
            }
        }
    }
    
    return answer;
}
