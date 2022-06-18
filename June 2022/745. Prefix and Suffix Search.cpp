unordered_set<string> found;
    // Keep track of each prefix and suffix index
    unordered_map<string,vector<int>> prefixes;
    unordered_map<string,vector<int>> suffixes;
    // Cache already found solutions
    unordered_map<string,int> memo;
    WordFilter(vector<string>& words) {
        int n = words.size();
        // For each word from the one with largest index
        for (int i = n-1; i >= 0; i--) {
            string w = words[i];
            // If already stored, ignore it
            if (found.find(w) != found.end()) continue;
            // New word 
            found.insert(w);
            int n = w.length();
            // Map each prefix to current index
            for (int k = 1; k <= n; k++) {
                prefixes[w.substr(0, k)].push_back(i);
            }
            // Map each suffix to current index
            for (int k = 1; k <= n; k++) {
                suffixes[w.substr(w.length()-k, k)].push_back(i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        // Check if a solution has already been found
        string key = prefix + "," + suffix;
        if (memo.find(key) != memo.end()) return memo[key];
        // Retrieve indexes for prefix and suffix
        vector<int> pre = prefixes[prefix];
        vector<int> suf = suffixes[suffix];
        int m = pre.size();
        int n = suf.size();
        // If no prefix or no suffix return -1
        if (m == 0 || n == 0) return -1;
        int idxp = 0, idxs = 0;
        int p = pre[idxp], s = suf[idxp];
        // Search greatest common index 
        // Or, the word with the greatest index
        // with prefix and suffix
        while (idxp < m && idxs < n) {
            // Word found, store result and return it
            if (p == s) {
                memo[key] = p;
                return memo[key];
            };
            // Prefix is greater, check next one
            if (p > s) p = pre[++idxp];
            // Suffix is greater, check next one
            else s = suf[++idxs];
        }
        // No word found
        memo[key] = -1;
        return memo[key];
    }