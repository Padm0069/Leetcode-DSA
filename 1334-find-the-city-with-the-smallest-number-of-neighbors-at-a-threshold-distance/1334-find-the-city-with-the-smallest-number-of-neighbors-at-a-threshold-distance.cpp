class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        //using floyd warshall
        vector<vector<int>> dis(n, vector(n, 10001));
        int res = 0, smallest = n;   //max possible city possible is n
        for (auto& e : edges)
            dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];
        for (int i = 0; i < n; ++i)
            dis[i][i] = 0;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; ++j)
                if (dis[i][j] <= distanceThreshold)     //distance less than the threshold
                    ++count;                            //count for every city(node)
            if (count <= smallest) {                    //returning the one having the lowest count.
                res = i;
                smallest = count;
            }
        }
        return res;
    }
};