vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        
        // find maximum of all candies
        
        int maxi = *max_element(candies.begin(), candies.end());
        
        vector<bool> res(n, false);
        
        // now traverse over the candies and fill the res array
        
        for(int i = 0; i < n; i++)
        {
            if(candies[i] + extraCandies >= maxi)
            {
                res[i] = true;
            }
        }
        
        return res;
    }