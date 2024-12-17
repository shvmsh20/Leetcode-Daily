string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Step 2: Create a max-heap based on character
        priority_queue<pair<char, int>> maxHeap;
        for (char c = 'z'; c >= 'a'; c--) {
            if (freq[c - 'a'] > 0) {
                maxHeap.push({c, freq[c - 'a']});
            }
        }

        string result;
        
        // Step 3: Construct the result string
        while (!maxHeap.empty()) {
            auto [char1, count1] = maxHeap.top();
            maxHeap.pop();

            // Determine how many times we can add char1
            int timesToAdd = min(count1, repeatLimit);
            result.append(timesToAdd, char1);
            count1 -= timesToAdd;

            // If we still have more of char1 left, we need to add a different character
            if (count1 > 0) {
                if (maxHeap.empty()) {
                    break; // No more characters to use
                }

                // Get the next largest character
                auto [char2, count2] = maxHeap.top();
                maxHeap.pop();

                // Add one instance of char2
                result += char2;
                count2--;

                // If char2 still has remaining instances, push it back to the heap
                if (count2 > 0) {
                    maxHeap.push({char2, count2});
                }

                // Push char1 back to the heap with the remaining count
                maxHeap.push({char1, count1});
            }
        }

        return result;
    }