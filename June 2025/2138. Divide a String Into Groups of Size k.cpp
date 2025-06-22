vector<string> divideString(string s, int k, char fill) {
        vector<string> result;

        // Step 2: Iterate through string in chunks of k
        for (int i = 0; i < s.length(); i += k) {
            string chunk = "";

            // Step 3: Append k characters or until end of string
            int j = 0;
            while (j < k && i + j < s.length()) {
                chunk += s[i + j];
                j++;
            }

            // Step 4: Fill with 'fill' character if needed
            while (chunk.length() < k) {
                chunk += fill;
            }

            // Step 5: Add to result
            result.push_back(chunk);
        }

        // Step 6: Return the final result
        return result;
    }