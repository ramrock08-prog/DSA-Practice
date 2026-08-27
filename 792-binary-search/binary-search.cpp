class Solution {
public:
    int binary(vector<int>& arr, int tar, int st, int end){
        if(st<=end){
            int mid = st + (end-st)/2;
            if(tar == arr[mid]) return mid;
            else if (tar >= arr[mid]) {return binary(arr, tar, mid+1, end);}
            else { return binary( arr, tar, st, mid-1);}
        } return -1;
    }
    int search(vector<int>& arr, int tar){
        return binary(arr, tar, 0, arr.size()-1);
    }

};