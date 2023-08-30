class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        unordered_map<char, int> count;
    for(auto c: moves) count[c]++;
    return max(count['L'],count['R']) - min(count['L'], count['R']) + count['_'];
    }
};