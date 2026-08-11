class Solution {
public:
    bool isAlphaNum(char ch){
        if((ch >= '0' && ch <='9') || (tolower(ch) >='a' && tolower(ch) <='z')) {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int str=0, end = s.size()-1;
        while(str < end){
            if(!isAlphaNum(s[str])){
                str++;continue;
            }
            if(!isAlphaNum(s[end])){
                end--;continue;
            }
            if(tolower(s[str])!=tolower(s[end])){
                return false;
            }
            str++;end--;
        }
        return true;
    }
};