import java.util.*;

public class Solution {
    public int solution(int n) {
      int ans =0;
      Integer[] d = new Integer[5];

      d[0]=0;
      d[1]=1;
      d[2]=1;
      d[3]=2;

      while(n>2){
          if(n%2 == 0){
              n/=2;
          }
          else{
              n/=2;
              ans++;
          }
      }

      ans+= d[n];

      return ans; 
    }
}
