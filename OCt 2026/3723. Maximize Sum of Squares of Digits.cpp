string maxSumOfSquares(int num, int sum) {
        string shortest = string(sum / 9, '9') + (sum % 9 ? to_string(sum % 9) : "");  // the shortest number with this digit sum
        return shortest.size() <= num ? shortest + string(num - shortest.size(), '0') : "";
    }