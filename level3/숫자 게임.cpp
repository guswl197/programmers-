#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    int answer = 0; 
    sort(B.begin(), B.end()); 
    sort(A.begin(), A.end()); 
    
    for(int i= 0; i<A.size(); i++){
        int idx = upper_bound(B.begin(), B.end(), A[i])- B.begin(); 
        if(idx < B.size() && A[i] < B[idx]){
            B[idx]= -1; 
            answer++; 
        }
    }
    
    return answer;
}
