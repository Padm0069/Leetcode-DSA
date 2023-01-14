class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        // We need to associate every lowercase english alphabet to it's lexicographically smallest equivalent using the given properties of equality and transitivity.
        char ch[26];

        for (int i=0; i<26; i++)

            ch[i] = 'a' + i;

        for (int i=0; i<s1.size(); i++) {

            char toReplace = max(ch[s1[i]-'a'], ch[s2[i]-'a']);

            char replaceWith = min(ch[s1[i]-'a'], ch[s2[i]-'a']);

            for (int i=0; i<26; i++)

                if (ch[i] == toReplace)

                    ch[i] = replaceWith;

        }

        

        for (int i = 0; i<baseStr.size(); i++)

            baseStr[i] = ch[baseStr[i]-'a'];

        return baseStr;
    }
    
    //Now for every index of string s1 and s2, we replace all elements pointing to the greater char between lowestEquivalent of s1[i] and lowestEquivalent of s2[i] with the smaller one.
};