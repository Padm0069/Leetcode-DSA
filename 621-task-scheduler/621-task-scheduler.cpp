class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         unordered_map<char,int>mp;
        int count = 0;
        for(auto e : tasks)
        {
            mp[e]++;
            count = max(count, mp[e]);
        }
        
        int ans = (count-1)*(n+1);
        for(auto e : mp) if(e.second == count) ans++;
        return max((int)tasks.size(),ans);
    }
};

// 1.First count the number of occurrences of each element.
// 2. Let the max frequency seen be M for element E
// 3. We can schedule the first M-1 occurrences of E, each E will be followed by at least N CPU cycles in between successive schedules of E
// 4. Total CPU cycles after scheduling M-1 occurrences of E = (M-1) * (N + 1) // 1 comes for the CPU cycle for E itself
// 5. Now schedule the final round of tasks. We will need at least 1 CPU cycle of the last occurrence of E. If there are multiple tasks with frequency M, they will all need 1 more cycle.
// 6. Run through the frequency dictionary and for every element which has frequency == M, add 1 cycle to result.
// 7. If we have more number of tasks than the max slots we need as computed above we will return the length of the tasks array as we need at least those many CPU cycles.