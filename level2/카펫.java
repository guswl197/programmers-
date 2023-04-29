class Solution {
    public int[] solution(int brown, int yellow) {
        int[] ans= {0,0};
        
        for(int i = 1; i<= brown ; i++){
            for(int j =1; j<=brown ; j++){
                if((i-2)*(j-2) == yellow && (2*i)+(2*j)-4 == brown ){
                    ans[0] =j;
                    ans[1] = i;
                    return ans ; 
                }
            }
        }
        
        return ans; 
    }
}
