class Solution {
public:
    long long getPos(int side, vector<int>& p) {
        long long x = p[0], y = p[1];

        if (y == 0)
            return x;
        if (x == side)
            return side + y;
        if (y == side)
            return 2LL * side + (side - x);
        return 3LL * side + (side - y);
    }

    bool can(vector<long long>& a, long long P, int k, long long d) {
        int n = a.size();
        vector<long long> b = a;

        for (int i = 0; i < n; i++) {
            b.push_back(a[i] + P);
        }

        int m = b.size();
        vector<int> nxt(m, m);

        for (int i = 0; i < m; i++) {
            nxt[i] = lower_bound(b.begin(), b.end(), b[i] + d) - b.begin();
        }

        int LOG = 20;
        vector<vector<int>> up(LOG, vector<int>(m + 1, m));

        for (int i = 0; i < m; i++)
            up[0][i] = nxt[i];

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < m; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        for (int start = 0; start < n; start++) {
            int cur = start;
            int steps = k - 1;

            for (int j = 0; j < LOG; j++) {
                if (steps & (1 << j)) {
                    cur = up[j][cur];
                }
            }

            if (cur < start + n && b[cur] - b[start] <= P - d) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> a;

        for (auto& p : points) {
            a.push_back(getPos(side, p));
        }

        sort(a.begin(), a.end());

        long long P = 4LL * side;
        long long l = 0, r = 2LL * side, ans = 0;

        while (l <= r) {
            long long mid = (l + r) / 2;

            if (can(a, P, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};