class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> directions{
        {0, 1}, {1, 0}, {1, 1}, {0, -1},
        {-1, 0}, {1, -1}, {-1, 1}, {-1, -1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Start or destination blocked
        if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0) {
            return -1;
        }

        auto issafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;

        // {distance, {x, y}}
        pq.push({1, {0, 0}});
        result[0][0] = 1;

        while (!pq.empty()) {

            int d = pq.top().first;
            pair<int, int> node = pq.top().second;

            int x = node.first;
            int y = node.second;

            pq.pop();

            // Destination reached
            if (x == m - 1 && y == n - 1) {
                return d;
            }

            for (auto dir : directions) {

                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (issafe(x_, y_) &&
                    grid[x_][y_] == 0 &&
                    d + 1 < result[x_][y_]) {

                    result[x_][y_] = d + 1;

                    pq.push({d + 1, {x_, y_}});
                }
            }
        }

        return -1;
    }
};