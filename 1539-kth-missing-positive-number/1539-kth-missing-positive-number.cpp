class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int low = 0;
       int high = arr.size()-1 ;
       int mid;
       while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] - (1 + mid) < k)  //A[m]-(m+1)   --> This gives umber of missing number before m'th index
                low = mid + 1;
            else
                high = mid-1;
        }
        return low + k;
        
    }
};


