int MOD = 1e9+7;
int factors (int x) {
    int count = 0;
    if (x % 2 == 0) {
        count++;
        while (x % 2 == 0) {
            x /= 2;
        }
    }
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            count++;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) count++;

    return count;
}
vector<int> solve2(vector<int>&v) {
    int n = v.size();
    stack <pair <int , int>> st;
    vector<int>vec(n , -1);
    for (int i = n - 1; i >= 0; i--) {
        if (st.empty()) {
            vec[i] = -1;
            st.push({v[i] , i});
            continue;
        }
        while (!st.empty() && st.top().first <= v[i]) st.pop();
        if (!st.empty()) {
            vec[i] = st.top().second;
        }
        st.push({v[i] , i});
    }
    return vec;
}
vector<int> solve(vector<int>&v) {
    int n = v.size();
    stack <pair <int , int>> st;
    vector<int>vec(n , -1);
    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            vec[i] = -1;
            st.push({v[i] , i});
            continue;
        }
        while (!st.empty() && st.top().first < v[i]) st.pop();
        if (!st.empty()) {
            vec[i] = st.top().second;
        }
        st.push({v[i] , i});
    }
    return vec;
}
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>v(n , -1);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                v[i] = 0;
                continue;
            }
            v[i] = factors(nums[i]);
        }
        vector<int>nge = solve2(v);
        for (int &i : nge) {
            if (i == -1) {
                i = n - 1;
                continue;
            }
            i--;
        }
        vector<int>lge = solve(v);
        for (int &i : lge) {
            if (i == -1) {
                i = 0;
                continue;
            }
            i++;
        }
        vector<pair <int , int>> pii;
        for (int i = 0; i < n; i++) {
            pii.push_back({nums[i] , i});
        }
        sort(pii.rbegin(),pii.rend());
        long long int ans = 1;
        for (int i = 0; i < pii.size(); i++) {
            int realIDX = pii[i].second;
            int realELE = pii[i].first;
            // cout << realELE << " ";
            int leftIDX = lge[pii[i].second];
            int rightIDX = nge[pii[i].second];
            long long int leftCount = realIDX - leftIDX + 1;
            long long int rightCount = rightIDX - realIDX + 1;
            long long int total = leftCount * rightCount;
            long long int  mn = min (total , (long long)k);
            k -= mn;
            // cout << mn << endl;
            ans = (ans * modExp(realELE, mn, MOD)) % MOD;
            if (k == 0) break;
        }
        return ans;
    }