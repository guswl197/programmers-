#include <bits/stdc++.h>

using namespace std;

stack<int> st; 
int ans; 

int solution(vector<vector<int>> board, vector<int> moves) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    int len = board[0].size(); 
    
    for(int i=0; i<moves.size(); i++){
        for(int j=0; j<len; j++){
            if(board[j][moves[i]-1]>0){
                int num = board[j][moves[i]-1]; 
                board[j][moves[i]-1]=0; 
                
                if(!st.empty() && st.top() == num){
                    st.pop(); 
                    ans+=2; 
                    break; 
                }
                else {
                    st.push(num); 
                    break;
                }
            }
        }
    }
 
    return ans;
}
