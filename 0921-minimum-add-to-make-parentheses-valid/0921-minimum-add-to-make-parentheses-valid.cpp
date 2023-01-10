class Solution {
public:
    int minAddToMakeValid(string s) {
         int left = 0, right = 0;
        for (char c : s)
            if (c == '(')
                right++;
            else if (right > 0)   //if we get close left, decrement the right as it is balanced now.
                right--;
            else
                left++;          //the left with no right XD
        return left + right;
    }
};