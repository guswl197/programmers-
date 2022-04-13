#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0; i<s.size(); i++){
        if(s[i]==' '){
            answer+=' ';
        }
        else if('a'<= s[i]&& s[i]<= 'z'){ 
            if(s[i]+n > 'z'){
               answer+=s[i]+n-'Z'+'A'-1;
                continue;
            }
            answer+=s[i]+n;
        }
        else if('A'<= s[i]&& s[i]<= 'Z'){ 
            if(s[i]+n > 'Z'){
               answer+=s[i]+n-'z'+'a'-1;
                 continue;
            }
            answer+=s[i]+n;
        }
    }
    return answer;
}
