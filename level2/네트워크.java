class Solution {
    static Integer[] visited= new Integer[205];
    static int[][] computer;
    
    public int solution(int n, int[][] computers) {
        computer =computers;
        int ans =0;

        for(int i =0; i<n ; i++){
            visited[i] =0;
        }

        for(int i =0; i<n ; i++){
            for(int j =0; j<n; j++){
                if(computers[i][j] == 1 && visited[j] == 0 ){
                    visited[i]=1;
                    ans++;
                    dfs(j);
                }
            }
        }

        return ans; 
    }

    public static void dfs(int x){
        for(int i =0; i<computer.length ; i++){
            if(i!= x && visited[i]== 0 && computer[x][i]==1){
                visited[i]=1;
                dfs(i);
            }
        }
    }
}
