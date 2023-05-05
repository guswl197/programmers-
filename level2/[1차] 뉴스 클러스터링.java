import java.util.*;
import static java.lang.Math.*;

class Solution {
    
    static Map<String ,Integer> mp1 = new HashMap<>();
    static Map<String ,Integer> mp2 = new HashMap<>();
    
    public int solution(String str1, String str2) {
        int union =0;
        int inter = 0;
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();

        mp1 = solveMap(str1);
        mp2 = solveMap(str2);

        for(String key : mp1.keySet()){
            if(mp2.containsKey(key)) {
                union+= max(mp2.get(key), mp1.get(key));
                inter += min(mp2.get(key), mp1.get(key));
            }
            else{
                union+= mp1.get(key);
            }
        }

        for(String key : mp2.keySet()){
            if(!mp1.containsKey(key)){
                union+= mp2.get(key);
            }
        }
        
        double ans = (inter/(double)union);
        if(inter == 0 && union == 0){
            ans =1; 
        }
        
        ans*= 65536;
        return (int)ans;
    }

    public static boolean checkAlpha(char ch){
        if('a' <= ch && ch <= 'z'){
            return true;
        }
        return false;
    }

    public static Map<String, Integer> solveMap(String str){
        Map<String, Integer> mp = new HashMap<>();
        for(int i =0; i<str.length()-1 ; i++){
            String s = "";
            if(!checkAlpha(str.charAt(i)) || !checkAlpha(str.charAt(i+1)) ){
                continue;
            }
            s += str.charAt(i);
            s += str.charAt(i+1);

            if(mp.containsKey(s)){
                int cnt = mp.get(s);
                mp.put(s, cnt+1);
            }
            else{
                mp.put(s, 1);
            }
        }

        return mp;
    }
}
