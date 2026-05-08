class Solution {
public:
    int minJumps(vector<int>& nums) {
         int n = nums.size();

        if (n == 1) return 0;

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> spf(mx + 1);

        for (int i = 0; i <= mx; i++) {
            spf[i] = i;
        }

        for (int i = 2; i * i <= mx; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= mx; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            unordered_set<int> used;

            while (x > 1) {
                int p = spf[x];

                if (!used.count(p)) {
                    mp[p].push_back(i);
                    used.insert(p);
                }

                x /= p;
            }
        }

        queue<int> q;

        vector<int> dist(n, -1);

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int steps = dist[i];

            if (i == n - 1) {
                return steps;
            }

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = steps + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = steps + 1;
                q.push(i + 1);
            }

            int val = nums[i];

            if (val > 1 && spf[val] == val) {

                for (int nxt : mp[val]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = steps + 1;
                        q.push(nxt);
                    }
                }

                mp[val].clear();
            }
        }

        return -1;
    }
};