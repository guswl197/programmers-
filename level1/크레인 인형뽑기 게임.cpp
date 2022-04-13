#include <string>
#include <vector> 
#include <iostream>

using namespace std;
vector<int> v; 

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    for(int i=0; i<moves.size(); i++){
        int pos= moves[i]; 
        for(int j=0; j<board.size(); j++){
            if(board[j][pos-1]>0){
                v.push_back(board[j][pos-1]);
                board[j][pos-1]=0; 
                break; 
            }
        }
        
        //인형 터트리기
        if(v[v.size()-1] ==v[v.size()-2] ){
            v.resize(v.size()-2); 
            answer+=2; 
        }
    }
    
    return answer;
}
