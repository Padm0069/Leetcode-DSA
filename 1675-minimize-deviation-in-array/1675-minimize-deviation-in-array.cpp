class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
// 1. Create a max heap and a variable to keep track of the minimum value in the array.
// 2. For each number in the input array, if it is odd, multiply it by 2 and push it onto the heap.        Otherwise, just push it onto the heap.
// 3. Also, update the minimum value if necessary.
// 4. Initialize a variable to keep track of the minimum deviation.
// 5. While the maximum value in the heap is even, pop it off the heap, divide it by 2, and push it back onto the heap. Update the minimum deviation and the minimum value if necessary.
// 6. If the maximum value in the heap is odd, we cannot reduce it any further by dividing by 2. In this case, break out of the loop.
// 7. Return the minimum deviation. 
        
        priority_queue<int> pq;
        int minVal = INT_MAX;
        for (int num : nums) {
            if (num % 2 == 1)
                num = num * 2;
            pq.push(num);
            minVal = min(minVal, num);
        }
        int minDeviation = INT_MAX;
        while (true) {
            int maxVal = pq.top();
            pq.pop();
            minDeviation = min(minDeviation, maxVal - minVal);
            //The reason we need to break out of the loop when the maximum value is odd is that we have already transformed all odd numbers in the input array to even numbers by multiplying them by 2. Therefore, if the maximum value in the priority queue is odd, it must have been obtained by performing the "multiply by 2" operation on some even number. We cannot undo this operation by performing the "divide by 2" operation, so we cannot reduce the maximum value any further.
            if (maxVal % 2 == 1)
                break;
            maxVal = maxVal / 2;
            minVal = min(minVal, maxVal);
            pq.push(maxVal);
        }
        return minDeviation;
    
    }
};