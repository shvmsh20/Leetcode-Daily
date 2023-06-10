int maxValue(int n, int index, int maxSum) {
        int left = index, right = index;
    int ans = 1;
    maxSum -= n;
    while (left > 0 || right < n - 1) {
        int len = right - left + 1;
        if (maxSum >= len) {
            maxSum -= len;
            ans++;
            left = max(0, left - 1);
            right = min(n - 1, right + 1);
        } else {
            break;
        }
    }
    ans += maxSum / n;
    return ans;
    }