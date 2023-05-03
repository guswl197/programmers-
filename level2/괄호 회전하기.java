import java.util.*;

class Solution {
    public int solution(String s) {
        int ans=0;

        for(int i= 0; i<s.length() ; i++){
            StringBuilder sb = new StringBuilder(s);
            String subString = sb.substring(0,i);
            sb.delete(0,i);
            sb.append(subString);
            String str = sb.toString();

            if(check(str)){
                ans++;
            }
        }

        return ans; 
    }

    public static boolean check(String str){
        Stack<Character> st = new Stack<>();

        for(int i =0 ;  i<str.length() ; i++){
            char ch = str.charAt(i);
            if(ch == '[' || ch == '{' || ch == '('){
                st.push(ch);
            }
            else if(!st.empty() && ch == ']' && st.peek() == '['){
                st.pop();
            }
            else if(!st.empty() && ch == ')' && st.peek() == '('){
                st.pop();
            }
            else if(!st.empty() && ch == '}' && st.peek() == '{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        if(!st.empty()){
            return false;
        }
        return true;
    }
}
