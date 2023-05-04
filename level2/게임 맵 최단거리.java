import java.util.*;

class Solution {
    static int[][] visited = new int[105][105];
    static int[][] map;
    static int[] dx = {1,-1 , 0 ,0 };
    static  int[] dy= {0,0,1,-1};
    static int n; 
    static int m; 
    
    public int solution(int[][] maps) {
        int ans= 0;
        map = maps;
        n = maps.length; 
        m = maps[0].length; 
        
        bfs(0,0 );

        ans = visited[n-1][m-1];
        if(ans == 0){
            ans = -1;
        }

        return ans; 
    }

    public static void bfs(int a , int b ){
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        q.add(new Pair(a,b));
        visited[a][b]=1;

        while(!q.isEmpty()){
            Pair<Integer , Integer> next = q.remove();
            int x= next.first;
            int y= next.second;

            for(int i =0; i<4 ; i++){
                int nx = x+ dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx>= n || ny<0 || ny>=m){
                    continue;
                }
                if(visited[nx][ny] == 0 && map[nx][ny] == 1 ){
                    visited[nx][ny] =visited[x][y]+1;
                    q.add(new Pair(nx, ny));
                }
            }
        }
    }

    static class Pair<T,S>{
        T first;
        S second;

        public Pair(T first, S second){
            this.first =first;
            this.second = second;
        }
    }
}
