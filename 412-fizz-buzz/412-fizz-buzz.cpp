class Solution {
public:
    vector<string> fizzBuzz(int n) {
         vector<string> vec;
        int i=1;
        while(i!=n+1){
            if(i%3==0 && i%5==0)
                vec.push_back("FizzBuzz");
            else if(i%3==0)
                vec.push_back("Fizz");
            else if(i%5==0)
                vec.push_back("Buzz");
                else 
                vec.push_back(to_string(i));
            i++;
        }
return vec;
    }
};