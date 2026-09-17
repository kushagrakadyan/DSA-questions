class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(n);

        for(auto flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int wt = flight[2];

            graph[u].push_back({v, wt});
        }

        queue<pair<int, pair<int,int>>> q;
        

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;

        q.push({src, {0, 0}});

        while(!q.empty()) {

            auto val = q.front();
            q.pop();

            int node = val.first;
            int cost = val.second.first;
            int stops = val.second.second;

            // At most k stops => at most k+1 flights
            if(stops > k)
                continue;

            for(auto edge : graph[node]) {

                int v = edge.first;
                int wt = edge.second;

                int newCost = cost + wt;

                if(newCost < dist[v]) {

                    dist[v] = newCost;

                    q.push({
                        v,
                        {newCost, stops + 1}
                    });
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};