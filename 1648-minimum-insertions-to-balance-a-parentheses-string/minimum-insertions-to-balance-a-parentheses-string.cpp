class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int n = s.length();
        int open_count = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                open_count++;
            }else{
                if(i+1 < n && s[i+1] == ')'){
                    i++;
                }else{
                    insertions++;
                }
            if(open_count > 0){
                open_count--;
            }else{
                insertions++;
                }
            }
        }return insertions + (open_count*2);
    }
};