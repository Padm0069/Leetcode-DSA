class Solution {
public:
     bool checkIfCanBreak(string& a, string& b) 
    {
        bool b1 = true;
        bool b2 = true;
        
        countingSort(a);
        countingSort(b);
        
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] < b[i])
                b1 = false;
            if (b[i] < a[i])
                b2 = false;
        }
        
        return b1 || b2;
    }
private:
    void countingSort(std::string& s)
    {
        std::vector<int> freq(26, 0);
        for (const char& c : s)
        {
            freq[c - 'a']++;
        }
        
        s.clear();
        
        for (int i = 25; i >= 0; i--)
        {
            if (freq[i])
            {
                s += std::string(freq[i], 'a' + i);
            }
        }
    }
};