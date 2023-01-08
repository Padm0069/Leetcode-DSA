class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //same line either same slope or same points
        int ans = 1;
        
         for(int i = 0; i < points.size(); i++){
        int samePoint = 1;   //for storing the same points
        unordered_map<double, int> map;  //for storing the slope and its count.

        
         for(int j = i + 1; j < points.size(); j++){
            if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){
                samePoint++;
            }
            else if(points[i][0] == points[j][0]){   //if x coordinates are equal they create a infinite
                //possitive slope.
                map[INT_MAX]++;
            }
            else{
                double slope = double(points[i][1] - points[j][1]) / double(points[i][0] - points[j][0]);
                map[slope]++;   //checking for slope and adding it
            }
        }
        int localMax = 0;
        for(auto it = map.begin(); it != map.end(); it++){
            localMax = max(localMax, it->second);
        }
        localMax += samePoint;   //adding same points along with the count of the slope
        ans = max(ans, localMax);
    }
    return ans;
        
    }
};