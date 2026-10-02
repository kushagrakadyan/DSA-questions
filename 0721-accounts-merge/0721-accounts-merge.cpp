class Solution {
public:

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        unordered_map<string, vector<string>> graph;
        unordered_map<string, string> emailToName;

        // Build graph
        for (auto &account : accounts) {

            string name = account[0];
            string firstEmail = account[1];

            for (int i = 1; i < account.size(); i++) {

                string email = account[i];

                emailToName[email] = name;

                // Connect first email with current email
                graph[firstEmail].push_back(email);
                graph[email].push_back(firstEmail);
            }
        }

        unordered_set<string> visited;
        vector<vector<string>> ans;

        // DFS for every unvisited email
        for (auto &[email, neighbours] : graph) {

            if (visited.count(email))
                continue;

            vector<string> component;

            dfs(email, graph, visited, component);

            // Emails must be sorted
            sort(component.begin(), component.end());

            vector<string> account;

            account.push_back(emailToName[email]);

            for (string &e : component)
                account.push_back(e);

            ans.push_back(account);
        }

        return ans;
    }

private:

    void dfs(
        string email,
        unordered_map<string, vector<string>>& graph,
        unordered_set<string>& visited,
        vector<string>& component) {

        visited.insert(email);
        component.push_back(email);

        for (string neighbour : graph[email]) {

            if (!visited.count(neighbour)) {
                dfs(neighbour, graph, visited, component);
            }
        }
    }
};