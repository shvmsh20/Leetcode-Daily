#include <vector> // Added for clarity, though often included by other headers
using namespace std; // Added for clarity

class Bank {
private:
    // Stores the balance for each account. balances[i] is for account (i+1).
    vector<long long> balances;
    // Stores the total number of accounts.
    int n;

    // Helper function to check if account number is valid (1 <= account <= n).
    bool isValidAccount(int account) {
        return account >= 1 && account <= n;
    }

public:
    /**
     * @brief Initializes the Bank object.
     * @param balance A 0-indexed vector of initial balances.
     */
    Bank(vector<long long>& balance) {
        // Copy the initial balances.
        this->balances = balance;
        // Store the number of accounts.
        this->n = balance.size();
    }
    
    /**
     * @brief Transfers money from account1 to account2.
     * @return true if successful, false otherwise.
     */
    bool transfer(int account1, int account2, long long money) {
        // 1. Check if both accounts are valid.
        if (!isValidAccount(account1) || !isValidAccount(account2)) {
            return false;
        }
        
        // Convert to 0-based indices.
        int index1 = account1 - 1;
        int index2 = account2 - 1;
        
        // 2. Check for sufficient funds in the source account.
        if (balances[index1] < money) {
            return false;
        }
        
        // 3. Perform the transaction.
        balances[index1] -= money;
        balances[index2] += money;
        return true;
    }
    
    /**
     * @brief Deposits money into an account.
     * @return true if successful, false otherwise.
     */
    bool deposit(int account, long long money) {
        // 1. Check if the account is valid.
        if (!isValidAccount(account)) {
            return false;
        }
        
        // 2. Perform the deposit (adjusting to 0-based index).
        balances[account - 1] += money;
        return true;
    }
    
    /**
     * @brief Withdraws money from an account.
     * @return true if successful, false otherwise.
     */
    bool withdraw(int account, long long money) {
        // 1. Check if the account is valid.
        if (!isValidAccount(account)) {
            return false;
        }
        
        // Convert to 0-based index.
        int index = account - 1;
        
        // 2. Check for sufficient funds.
        if (balances[index] < money) {
            return false;
        }
        
        // 3. Perform the withdrawal.
        balances[index] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */