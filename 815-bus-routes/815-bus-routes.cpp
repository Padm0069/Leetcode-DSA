// So, here is an idea behind this algo.
// Imagine you are standing on the starting bus stop.
// At the very least, you need to understand to which routes you can get from this bus stop. graph variable below does that.
// Now, you figured you can get to route 1, 5, 7.
// Cool.
// All of them cost you 1 ride.
// Then, now imagine you choose to go on route 1( all the bus stops on that route are free).
// What you do is you need to remember to which routes you have already been not to come back.
// You visit every bus stop on route 1 and check to which other routes can you transfer.
// You do this in BFS manner.
// Another thing that hints you at how you should approach this is that we care only about the # of routes, not the # of bus stops.
// Complexity is O(V + E) where V is the number of routes and E is the total number of connections in the graph.

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T)
            return 0;
        // For some reason leetcode decided that putting a testcase where
        // they concatenate several cycles together like 1->2->1->2->1->2
        // and also call it a bus route even though it doesn't really make sense.
        // So, use unordered_set as protection against this bs.
        unordered_map<int, unordered_set<int>> graph;
        for(int r = 0; r < routes.size(); r++){
            for(auto bs : routes[r]){
                graph[bs].insert(r);
            }
        }
        
        // visited has all the routes we have been to.
        unordered_set<int> visited;
        
        // queue contains integers that represent the index of the route.
        queue<int> q;
        
        // retrieve routes for the starting bus stop.
        for(auto route : graph[S]){
            q.push(route);
            visited.insert(route);
        }
        
        // all of them require you to take one bus.
        int dist = 1;
        
        while(q.size()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int route = q.front(); q.pop();
                int start = -1;
				
                // visit each bus stop on this route
                for(auto bs: routes[route]){
                    // this is just to avoid cycle iteration as 
                    // in the example above.
                    if(start == -1)
                        start = bs;
                    else if(start == bs)
                        break;
                    
                    // happens to be your destination
                    if(bs == T)
                        return dist;
                    
                    // to which routes can i transit from this bus stop or bullshit :)
                    for(auto access_routes : graph[bs]){
                        if(!visited.count(access_routes)){
                            visited.insert(access_routes);
                            q.push(access_routes);
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};