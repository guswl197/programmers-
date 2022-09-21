#include <bits/stdc++.h>

using namespace std;

vector<string> cnumber= {"zero", "one","two", "three", "four","five", "six", "seven", "eight", "nine" }; 
vector<string> number = {"0", "1", "2","3", "4", "5", "6", "7" ,"8", "9"}; 
int solution(string s) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    int answer = 0;
     
    for(int i=0; i<10; i++){
        s= regex_replace(s, regex(cnumber[i]), number[i]); 
    }
    
    answer= stoi(s); 
    return answer;
}
