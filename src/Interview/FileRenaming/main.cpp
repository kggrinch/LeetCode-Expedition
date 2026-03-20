#include <iostream>
#include <vector>



int renameFile(std::string newName, std::string oldName) {
    int MOD = 1e9 + 7;
    int n = oldName.size();
    int m = newName.size();

    std::vector<int> dp(m + 1, 0);

    dp[0] = 1; // empty string

    for (int i = 0; i < n; i++) // traverse old name
    {
        for (int j = m - 1; j >= 0; j--) // traverse new name in reverse
        {
            if (oldName[i] == newName[j]) dp[j + 1] = (dp[j + 1] + dp[j]) % MOD;
        }
    }

    return dp[m];
}

int main()
{
    std::string old_name = "ababa";
    std::string new_name = "aba";
    std::cout << renameFile(old_name, new_name) << "\n";
    return 0;
}