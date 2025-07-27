int countHillValley(vector<int>& nums) {
        vector<int> filtered;
        filtered.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) 
        {
            if (nums[i] != nums[i - 1]) 
            {
                filtered.push_back(nums[i]);
            }
        }

        // Step 2: Loop through the filtered array (Sliding Comparison)
        int count = 0;
        for (int i = 1; i < filtered.size() - 1; ++i) 
        {
            int prev = filtered[i - 1];
            int curr = filtered[i];
            int next = filtered[i + 1];

            // Step 3: Check for hills or valleys (Local Minima/Maxima Detection)
            if ((curr > prev && curr > next) || (curr < prev && curr < next)) 
            {
                ++count;  // Step 4: Increment the count for hills/valleys (Greedy Counting)
            }
        }

        return count;
    }