class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9LL * num) return "";
        string result = "";
        int nines = sum / 9;
        int rem = sum % 9;
        for(int i = 0; i<nines && result.size() < num; i++){
            result += "9";
        }
        if(rem > 0 && result.size() < num){
            result += to_string(rem);
        }
        while(result.size() < num){
            result += "0";
        }return result;
    }
};