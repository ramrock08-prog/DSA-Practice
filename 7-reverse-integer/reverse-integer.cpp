class Solution {
public:
    int reverse(int x) {
        int reversenum = 0;
        while(x!=0){
            int n = x%10;
            if( INT_MIN/10 > reversenum || reversenum > INT_MAX/10){
                return 0;
            }
            reversenum = reversenum *10 + n;
            x=x/10;
        }
        return reversenum;    
    }
};