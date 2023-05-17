class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>hash(26,0);
        for(char c:tasks)hash[c-'A']++;
        sort(hash.begin(),hash.end(),greater<int>());
        int slots=hash[0]-1;
        int idle=slots*n;
        for(int i=1;i<hash.size();i++)     //filling up the idle slot
        {
            idle-=min(slots,hash[i]);
        }
        return tasks.size()+max(0,idle);
    }
};

