class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> myset;
        int sum;
        int add;
        
        while(1)
        {
            sum = 0;
            while(n)
            {
                add = n%10;
                sum += add*add;
                n /=10;
            }
            if(sum==1)
                return true;
            else if(myset.find(sum)!=myset.end())
                return false;
            
            myset.insert(sum);
            n = sum;
        }
        return false;
        
    }
};