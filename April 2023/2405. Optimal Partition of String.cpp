int partitionString(string s) {
        int partitions = 1;

        // A list of last seen index of each character
        vector<int> last_seen(26, -1);
        
        // Position of the new partition
        int new_partition_idx = 0;

        // Iterate the entire string and increase partitions
        for(int i = 0; i < s.size(); i++) { // O(n)
            int idx = s.at(i) - 'a';

            // If the letter is part of the current partition
            // We proceed to create a new partition
            if(last_seen[idx] >= new_partition_idx) {
                partitions++;
                new_partition_idx = i;
            }

            // Remember the last seen index of the current letter
            last_seen[idx] = i;
        }
        
        return partitions;
    }