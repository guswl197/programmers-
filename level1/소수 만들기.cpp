#include <bits/stdc++.h>

using namespace std;

int ans=0; 

bool decimal(int num){
    
    int cnt=0; 
    for(int i=1; i<=num; i++){
        if(num%i == 0){
            cnt++; 
        }
    }
    
    if(cnt == 2){
        return true; 
    }
    
    return false; 
}

int solution(vector<int> nums) {
    ios::sync_with_stdio(0);
	cin.tie(0);


    for(int i=0; i<nums.size()-2; i++){
        for(int j=i+1 ; j<nums.size()-1; j++){
            for(int k=j+1 ; k<nums.size(); k++){
                if(decimal(nums[i]+nums[j]+ nums[k])){
                    ans++; 
                } 
            }
        }
    }

    return ans; 
}
