bool isit(vector<int>& candies, long long k, long long part) {
        long long count = 0;
        for (int &i : candies) {
            count = count + (i / part);
        }
        return count >= k;
    }

    long long maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        int mini = INT_MAX;
        for (int &i : candies) {
            sum += i;
            mini = min(mini, i);
        }

        if (sum < k) return 0;

        long long low = 1, high = sum / k, ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isit(candies, k, mid)) {
                ans = mid;
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return ans;
    }