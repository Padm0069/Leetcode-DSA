class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        
        queue<int>q,q1;
   int n=s.size(); 
    for(int i=0;s[i]!='\0';i++){
        q.push(s[i]);
		 q1.push(goal[i]);
       }
	   
    //if the string s and goal are equal
        if(s==goal){
            return true;
        }  
		
      int i=0;
     while(i<n){
        q.push(q.front());   //doing the shift operation
            q.pop();
            if(q==q1)         //comapring the strings basically
                return true;
            i++;
        }
      return false;
    }
};