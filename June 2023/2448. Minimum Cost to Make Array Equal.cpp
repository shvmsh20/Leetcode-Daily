long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = LLONG_MAX; // Initialize ans with maximum possible value
        vector<long long> pref; // Prefix sum array
        vector<pair<long, long>> p; // Array of pairs (nums[i], cost[i])
        
        // Create pairs and store them in array p
        for(int i = 0; i < cost.size(); i++)
         {
            p.push_back({nums[i], cost[i]});
        }
        
        sort(p.begin(), p.end()); // Sort the pairs based on nums values
        
        pref.push_back(0); // Add initial 0 to prefix sum array
        // Calculate prefix sum of costs
        for(int i = 0; i < p.size(); i++)
         {
            pref.push_back(pref[i] + p[i].second);
        }
        long long left = 0, right = 0; // Initialize left and right costs
        for(int i = 0; i < nums.size(); i++)
         {
            if(i == 0)
             {
                left = 0;
                // Calculate the right cost from the second pair to the last pair
                for(int j = 1; j < cost.size(); j++)
                 {
                    right += (long long)(p[j].first - p[0].first) * (long long)p[j].second;
                }
                // Update ans if the current cost is smaller
                if(ans > right + left)
                 {
                    ans = left + right;
                }
                continue;
            }
            long long elevation = p[i].first - p[i - 1].first; // Calculate the elevation
            
            // Update right cost by subtracting the elevation cost and the remaining prefix sum
            right -= elevation * (long long)(p[i].second);
            right -= elevation * (pref[pref.size() - 1] - pref[i + 1]);
            // Update left cost by adding the elevation cost and the prefix sum
            left += elevation * (pref[i] - pref[0]);
            // Update ans if the current cost is smaller
            if(ans > right + left)
             {
                ans = left + right;
            }
        }
        return ans;
    }