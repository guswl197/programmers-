#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool check(char c, int dis, int number){
    if(c == '='){
        return dis == number;
    }else if(c == '>'){
        return dis > number;
    }else if(c == '<'){
        return dis < number;
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    
    do{
        bool flag = true;
        for(string text : data){
            char ff = text[0];
            char sf = text[2];
            char comp = text[3];
            int number = text[4] - '0';
            int diff = friends.find(ff) - friends.find(sf);
			int dis = abs(diff) - 1;
            
            if(check(comp, dis, number)) {
                continue;
            }
            
            flag = false;
            break;
        }
        if(flag) {
            answer++;
        }
        
    }while(next_permutation(friends.begin(), friends.end()));
    
    return answer;
}
