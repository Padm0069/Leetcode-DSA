
class Solution {
public:
    string decodeString(string s) {
        // encoding rule is k[encoded_string]
        stack<string> chars; // stack for keeping trakc of the already decoded string
        stack<int> nums; // stack for k
        string res;
        int num = 0;
        
        //Iterate through every single character in s -->o(n); n is size of s
        for(char c : s) {
            /*
            There are 4 possible states that we can see
            (1) number --> use built in isdigit(char)
            (2) alphabet --> use built in isaplha(char)
                >> Just add the character to the result if we see a letter
            (3) '[' -->just compare with that char
            (4) ']' --> just compare with that char
            */
            if(isdigit(c)) {
                num = num*10 + (c-'0');  // coverts the string number to integer
                // Note you need to handle cases like 22[a], this is just using increasing the place value by one and then adding the single digit to the ones place value
            }
            else if(isalpha(c)) { // check if characteris a letter
                res.push_back(c);            
            }
            else if(c == '[') { // From the encoding rule, we are guaranteeda number
                // prior to '[' and an encoded_string after '['
                // Hence we can push all number and encoded_string to their stacks
                
                chars.push(res); // put the encoded_string to stack
                nums.push(num); // put the number into the stack
                
                // reset back to default 
                res = "";
                num = 0;
            }
            else if(c == ']') {
                // every time we see ']' we are guaranteed to have finished a set of 
                // k[encoded_string]. Hence we can start processing the stacks emptying
                // them and moving it to res. 
                
                string tmp = res; 
                for(int i = 0; i < nums.top()-1; ++i) {
                    res += tmp;
                }
                res = chars.top() + res;
                chars.pop(); 
                nums.pop();
            }
        }
        return res;
     }
};

/*
3[a]2[bc] --> aaabcbc
(case 1) num = 3
(case 3) push 3 to stack nums, nums = 0
(case 2) res = a
(case 4) res = aaa (Note chars.top() is empty)
--------- we finished 3[a]
Do again:
(case 1) num = 2
(case 3) push 3 to stack nums, push "aaa" to stack char, nums =0, res = ""
(case 2) res = b
(case 2) res = bc
(case 4) res += tmp --> res = bcbc 
        res = chars.top() + res --> res = aaabcbcbc
 */

/*
What about an example where it is nested. 
 3[a2[bc]] = 3[abcbc] = abcbcabcbcabcbc
 (case 1) num = 3
 (case 3) push 3 to stack nums (nothing is added to chars)
 (case 2) res = a
 (case 1) num = 2
 (case 3) push 2 to stack nums, push a to stack chars
 so stack nums = top {2, 3} bottom  and stack chars = {"a"}, res = "", nums = 0
 (case 2) res = b
 (case 2) res = bc
 (case 4) time to empty the stacks and move to the final result!
        res = bcbc since nums.top() = 2 
        res = chars.top() + res --> res = abcbc since a is at the top of stack chars
        pop off from char and pop off from num
        chars = {} num = {3}
 (case 4) repeat for the last ']'
        res = abcbcabcbcabcbc
        res = chars.top() + res --> chars.top is empty so res = abcbcabcbcabcbc
    Done!    
*/