class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size() == 1) return 0; // single element
        
        int n = arr.size();
        
		// check if 0th/n-1th index is the peak element
        if(arr[0] > arr[1]) return 0;
        if(arr[n-1] > arr[n-2]) return n-1;
		
		// search in the remaining array
        int start = 1;
        int end = n-2;
        
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            else if(arr[mid] < arr[mid-1]) end = mid - 1;
            else if(arr[mid] < arr[mid+1]) start = mid + 1;
        }
        return -1; // dummy return statement
    }
};