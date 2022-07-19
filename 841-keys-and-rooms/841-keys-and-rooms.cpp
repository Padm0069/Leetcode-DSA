// When we enter a room, mark it as visited.
// Then we put the keys in the current room to our unordered_set keys.
// Check all the keys we have, if we haven't visited all corresponding room, go DFS.
// If we have visited all rooms, number of visited rooms should be the same as number of rooms.

class Solution {
    void dfs(vector<vector<int>>& rooms, unordered_set<int> & keys, unordered_set<int> & visited, int curr) {
        visited.insert(curr);
        for (int k : rooms[curr]) keys.insert(k);
        for (int k : keys) if (visited.find(k) == visited.end()) dfs(rooms, keys, visited, k);
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> keys;
        unordered_set<int> visited;
        dfs(rooms, keys, visited, 0);
        return visited.size() == rooms.size();
    }
};
