class Solution {
public:
    int maximum69Number (int num) {
         string s = to_string(num);
        
        // Change the first '6' to '9'
        for (char &c : s) {
            if (c == '6') {
                c = '9';
                break; // Only one change allowed
            }
        }
        
        return stoi(s); // Convert string back to integer
    }
};