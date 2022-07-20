class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //to get unique string and not repetitive
    unordered_map<string, int> counter;
    
    //to store answer in string format
    vector<string> result;
    
    //if input string is not of length 10 then return this string directly as answer
    if (s.size() < 10) return result;
    
    
    /*
    substr(position, length): 
    say length of input string is 12 
    so loop run till 12-9= 3
    
    substr function will pick input string's characters 
    i=0 -> 0 to 9 (as indexing start from 0)
    i=1 -> 1 to 10
    i=2 -> 2 to 11

    hence covered whole input string length and we are doing this in hashmap so frequency is being taken care of simultaneously
    Here take first 10 characters starting from i so every character is covered in the string.
    */
    for (int i=0; i<s.size()-9; i++)
        counter[s.substr(i, 10)]++;
    
    //if frequency is greater than 1 push the string in result vector
    for (auto a:counter)
        if (a.second > 1)
            result.push_back(a.first);
    
    return result;
    }
};