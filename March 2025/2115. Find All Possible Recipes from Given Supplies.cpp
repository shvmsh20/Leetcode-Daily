vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        const int n = recipes.size();
        unordered_set<string> supp(supplies.begin(), supplies.end());
        vector<int> deg(n, 0);
        unordered_map<string, vector<int>> adj;

        for (int i = 0; i < n; i++) {
            [[unroll]]
            for (const string& s : ingredients[i]) {
                if (!supp.count(s)) {
                    adj[s].push_back(i);
                    deg[i]++;
                }
            }
        }

        int q[101], front=0, back=0;
        for (int i = 0; i < n; i++)
            if (deg[i] == 0) q[back++]=i;

        vector<string> ans;
        while (front!=back) {
            const int i = q[front++];
            auto s=recipes[i];
            ans.push_back(s);
            for (auto j : adj[s]) {
                if (--deg[j] == 0) q[back++]=j;
            }
        }
        return ans;
    }