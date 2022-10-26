class Solution {
public:
// Starting from left of array and keep adding elements to a variable sum
// Add -1 for 0 and 1 for 1
// Now, everytime sum becomes zero, we know all the elements from begining of array have been neutralized , meaning we have got equal number of ones and zeroes,
// let this occurs at index i, so longestContArray = i+1 ('coz w're dealing with indices)
// But we are not done yet!, consider the case : [1,1,0,1,1]
// In this case sum will never become zero,
// but there exists a subarray of length 2, having equal 0 & 1
// let's see the value of sum at index : 1 and 3
// Ohh!! sum = 2 for both indices
// what does this mean???
// This means that if we get the same sum value for two indices i and j, then all the elements within the range [i,j) or (i,j] have been neutralized
// What datastructure can remember the sum and index
// Ofcourse ! Map, so we use a map to store the sum and index values,
// if sum == 0 then we have already solved the cases
// but if sum!=0 and this sum doesn't already exist in the map,
// then store it with it's corresponding index
// but if sum !=0 and sum already exists in the map then,
// dependig on whether i - m[sum] > LongestContArray, update LongestContArray
// Note we need to store a unique sum value only once, after that whenever we encounter the same sum again our interval length is going to increase only and that is what we want
// ex- [1,0,1,0,1] we get sum = 1 three times
// we store sum = 1 for index = 0 only
// and never update it as we want longest length
    
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        unordered_map<int,int> record;
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                sum -= 1;
            else if(nums[i] == 1)
                sum += 1;
            
            if(sum == 0){
                result = max(result, i+1);
            }
            
            if(record.find(sum) != record.end()){
                result = max(result, i - record[sum]);
            }
            else{
                record[sum] = i;
            }
        }
        return result;
    }
};