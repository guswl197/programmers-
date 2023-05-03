import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        int ans=0;
        Queue<String > q= new LinkedList<>();
        Map<String, Integer> mp = new HashMap();
        
        if(cacheSize == 0){
            return cities.length *5; 
        }

        for(int i=0; i<cities.length ; i++){
            if(mp.containsKey(cities[i].toLowerCase())&& mp.get(cities[i].toLowerCase())== 1){
                ans++;
                int len = q.size(); 
                
                for(int j =0; j<len; j++){
                    String str = q.remove(); 
                    if(!str.equals(cities[i].toLowerCase())){
                        q.add(str);
                    }
                }
                q.add(cities[i].toLowerCase()); 
            }
            else{
                if(cacheSize == q.size()) {
                    String del = q.remove();
                    mp.put(del, 0);
                }
                q.add(cities[i].toLowerCase());
                mp.put(cities[i].toLowerCase(), 1);
                ans+=5;
            }

        }

        return ans;
    }
}
