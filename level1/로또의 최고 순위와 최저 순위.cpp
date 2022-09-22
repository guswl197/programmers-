#include <bits/stdc++.h>

using namespace std;
int cnt;
int zero; 

int grade(int num){
    if(num == 6){
        return 1; 
    }
    else if(num == 5){
        return 2; 
    }
    else if(num == 4){
        return 3; 
    }
    else if(num ==3){
        return 4; 
    }
    else if(num == 2){
        return 5; 
    }
    else{ 
        return 6; 
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    vector<int> answer;
    sort(lottos.begin(), lottos.end()); 
    sort(win_nums.begin(), win_nums.end()) ;
    
    for(int i=0; i<6 ; i++){
        if(lottos[i] == 0){
            zero++;
            continue; 
        }
        
        for(int j=0 ; j<6; j++){
            if(win_nums[j] == lottos[i]){
                cnt++; 
                break; 
            }
        }
    }
    
    answer.push_back(grade(cnt + zero));
    answer.push_back(grade(cnt));
    return answer;
}
