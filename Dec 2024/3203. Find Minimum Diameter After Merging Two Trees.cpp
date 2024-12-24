int  maxi1,  maxi2;

    // Helper function to calculate the diameter of a tree
    int solve(int node, int par, vector<vector<int>>& adj,int& maxi) {
        // Corrected leaf node condition
        if (adj[node].size() == 1 && par != -1) {
            return 1; // Height of a leaf node is 1
        }

        int m1 = 0; // Largest height
        int m2 = 0; // Second largest height

        for (auto neighbor : adj[node]) {
            if (neighbor == par) continue; // Skip parent
            int height = solve(neighbor, node, adj, maxi);
            if (height > m1) {
                m2 = m1;
                m1 = height;
            } else if (height > m2) {
                m2 = height;
            }
        }

        // Update minimum and maximum path lengths through the node
        maxi = max(maxi, m1 + m2); // Update maximum of two largest heights

        return m1 + 1; // Return height of the current subtree
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1; // Number of nodes in the first tree
        int n2 = edges2.size() + 1; // Number of nodes in the second tree

        vector<vector<int>> adj1(n1), adj2(n2);
        for (auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for (auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        // Initialize diameters
        maxi1 = maxi2 = INT_MIN;

        // Calculate diameters for both trees
        solve(0, -1, adj1,  maxi1);
        solve(0, -1, adj2,  maxi2);


        
        int combinedDiameter =
            ceil(maxi1/ 2.0) + ceil(maxi2/ 2.0) + 1;        // Diameter from the connection
        int largestExistingDiameter = max(maxi1, maxi2);  // Largest existing diameter
        return max(combinedDiameter, largestExistingDiameter);
    }