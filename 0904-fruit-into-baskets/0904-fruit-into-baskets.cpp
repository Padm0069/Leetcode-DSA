class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //same as pick toys question
        //number of unique substrings with k unique char, here k = 2
        int i=0,j=0;
        int maxi=1;
        unordered_map<int,int> mp;
        while (j<fruits.size())
        {
            mp[fruits[j]]++;
            while (mp.size()>2)
            {
                mp[fruits[i]]--;
                if (mp[fruits[i]]==0)
                    mp.erase(fruits[i]);
                i++;
            }
            if (mp.size()<=2)
                maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};