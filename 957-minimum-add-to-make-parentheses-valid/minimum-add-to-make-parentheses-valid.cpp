class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_count =0;
        int open_needed =0;
        for(int  i=0; i<s.length();i++){
            if(s[i] == '('){
                open_count++;
            }else {
                if(open_count > 0){
                    open_count--;
                }else{
                    open_needed++;
                }
            }
        }return open_count + open_needed;
    }
};