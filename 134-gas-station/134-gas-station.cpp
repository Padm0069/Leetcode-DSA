// There are 4 parts to it-

// Part 1- sum of gas array>=sum of cost array---> 
// very intuitive, we should always have enough gas.

// Part 2- we are keeping a total+=gas[i]-cost[i] for each i, and whenever it is <0 we are skipping that point and moving forward, making total 0--->
//  It means we ran out of gas if we started at some point which was <= current pos of i, so now we have to find a new starting position,
// which wall be > curr pos of i.

// Now think, why will this new start lie ahead of curr pos i, not anywhere before it,  you could think, we started from point A------>B(total till +ve)------->C(total<0), as per this algo we try to find start ahead of C, what if we started from B and skipped A instead, well that won't work, You moved from A--------> B with some positive value(or 0), or else you would have stopped right at B and made total to 0. So add A improved our chances of having a positive total, so there is no point in looking for the new position start anywhere behind point C.

// Part 3- When the total stays +ve, we dn't do anything to the start point, our start pointer points to the first index when our total became positive.

// Again this is similar to the above explanation-l
// Lets suppose we start from X(-ve)--->Y(-ve)--->A(+ve)---->B(+ve)---->C(+ve), where C is the end of the array, our start(which is also the ans) would be A.
// Why not B? why not C?
// It is because we moved from A to B with some +ve value or atleast 0, whereas if we started from B we would have had only the value of B so earlier point added some value to our total, so its more favorable to help us reach the ans, hence earliest point is always better.

// Part 4-- Why we just stop at point C and don t complete the cycle and check.
// It is because from Part 1 we would have already identified that if the given set of inputs will have an ans, so if we have reached to Part 3 it means we surely have an ans, and it is mentioned in the question that there is only one valid ans, so we will always choose the most favorable ans-- which is also the fundamental idea of Greedy Algorithims.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_surplus = 0;
        int surplus = 0;
        int start = 0;
        
        for(int i = 0; i < n; i++){
            total_surplus += gas[i] - cost[i];
            surplus += gas[i] - cost[i];
            if(surplus < 0){
                surplus = 0;
                start = i + 1;
            }
        }
        return (total_surplus < 0) ? -1 : start;
    }
};