#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>


bool exist(std::vector<std::vector<char>>& board, std::string word)
{
    // Save size of row and column
        int row_size = board.size();
        int column_size = board[0].size();

        // hashset used to keep track of visited coordinates during the dfs
        // search
        std::unordered_set<std::string> visited;

        // Create a lambda function with row, column, k index for the letter,
        // and its own function call
        auto dfs = [&](int r, int c, int k, auto& dfs) -> bool {
            // Base Case
            // If the k character index reaches the last character then the word
            // has been found return true
            if (k == word.length()) {
                return true;
            }

            if (r < 0 || r >= row_size || c < 0 || c >= column_size ||
                visited.count(std::to_string(r) + ',' + std::to_string(c)) ||
                word[k] != board[r][c]) {
                return false;
            }

            visited.insert(std::to_string(r) + ',' + std::to_string(c));
            bool exists =
                dfs(r - 1, c, k + 1, dfs) || dfs(r + 1, c, k + 1, dfs) ||
                dfs(r, c + 1, k + 1, dfs) || dfs(r, c - 1, k + 1, dfs);
            visited.erase(std::to_string(r) + ',' + std::to_string(c));
            return exists;
        };

        // Count the number of instances each letter has in the word
        std::unordered_map<char, int> count;

        // This might iterate through the chars reversely
        for (char letter : word) {
            count[letter]++;
        }

        // If the first letter appears more then the last letter reverse.
        // This is used because we can quickly return false when letter do not repeat a lot.
        // For example in the case where is like AAAAAABB
        // We can find the word faster starting from BBAAAAA because BB will return false faster then starting at AAAAABB
        if (count[word[0]] > count[word[word.length() - 1]]) {
            std::reverse(word.begin(), word.end());
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(i, j, 0, dfs)) {
                    return true;
                }
            }
        }

        return false;
}


// Brute Force Solution
// Time Complexity: n * 4^m | where n - number of first chars of word in board | where m - length of the word
// Space Complexity: m | depth - up to length of the word and worse case set holds m inputs
bool exist2(std::vector<std::vector<char>>& board, std::string word)
{
    int x_length = board.size();
    int y_length = board[0].size();
    std::pair<int, int> start; // n
    std::set<std::pair<int, int>> path; // m
    std::string cur_word;

    auto backtrack = [&](std::pair<int, int> index, std::string cur_word, int word_index, auto& backtrack) -> bool
    {
        if(cur_word == word) return true;

        // If index coordinate index is out of bounds or letter does not equal the required letter or coordinate index already in use return false
        if(index.first < 0 || index.first >= x_length || index.second < 0 || index.second >= y_length || board[index.first][index.second] != word[word_index] || path.count(index) >= 1) return false;
        char letter = board[index.first][index.second];
        cur_word += letter;
        path.insert(index);
        int first_original = index.first;
        int second_original = index.second;
        bool found = false;

        std::pair<int, int> left(0, -1);
        index.first = index.first + left.first;
        index.second = index.second + left.second;
        if(backtrack(index, cur_word, word_index + 1, backtrack)) found = true;

        index = {first_original, second_original};
        std::pair<int, int> top(-1, 0);
        index.first = index.first + top.first;
        index.second = index.second + top.second;
        if(!found && backtrack(index, cur_word, word_index + 1, backtrack)) found = true;

        index = {first_original, second_original};
        std::pair<int, int> right(0, 1);
        index.first = index.first + right.first;
        index.second = index.second + right.second;
        if (!found && backtrack(index, cur_word, word_index + 1, backtrack)) return true;

        index = {first_original, second_original};
        std::pair<int, int> bottom(1, 0);
        index.first = index.first + bottom.first;
        index.second = index.second + bottom.second;
        if(!found && backtrack(index, cur_word, word_index + 1, backtrack)) return true;
        index = {first_original, second_original};

        path.erase(index);
        return found;
    };

    // n
    for(int i = 0; i < x_length; i++)
    {
        for(int j = 0; j < y_length; j++)
        {
            if(word[0] == board[i][j])
            {
                start = {i, j};
                if(backtrack(start, cur_word, 0, backtrack)) return true;
            }
        }
    }

    return false;
}

// Time Complexity: O(n * 4^m) | n = number of cells and m = size of the word
// Space Complexity: O(m) | m = size of the word also max depth of recursive tree and max inputs held in set.
bool exist3(std::vector<std::vector<char>>& board, std::string word)
{

    // Save set to hold visited coordinates
    std::set<std::pair<int, int>> visited;

    // save column and row lengths of board
    int c_length = board.size();
    int r_length = board[0].size();

    auto backtracking = [&](std::pair<int, int> point, int i, auto& backtracking) -> bool
    {
        // Save current coordinate point
        int c = point.first;
        int r = point.second;

        // Check if index reached the end. means we reached the last char in word return true
        if(i == word.size()) return true;
        // Check if current point is valid. If point is out of bounds || char at current point does not match with char at current index || current point already visited return false
        if(c < 0 || c >= c_length || r < 0 || r >= r_length || board[c][r] != word[i] || visited.count({c, r}) == 1) return false;

        // Save current point in visited and check the four adjacent neighbors
        visited.insert(point); // log n
        // Short circuit bool - if one returns true a path is found, do not need to check the rest.
        // left | top | right | bottom
        bool res = (backtracking({c, r - 1}, i + 1, backtracking) ||
                    backtracking({c - 1, r}, i + 1, backtracking) ||
                    backtracking({c, r + 1}, i + 1, backtracking) ||
                    backtracking({c + 1, r}, i + 1, backtracking));
        visited.erase(point); // erase point on backtrack - if path found does not matter | log n
        return res;
    };

    // *To pass LeetCode time exceed uncomment this code
    // // Count the number of instances each letter has in the word
    // std::unordered_map<char, int> count;
    //
    // for (char letter : word) {
    //     count[letter]++;
    // }
    //
    // // If the first letter appears more then the last letter reverse.
    // // This is used because we can quickly return false when letter do not repeat a lot.
    // // For example in the case where is like AAAAAABB
    // // We can find the word faster starting from BBAAAAA because BB will return false faster then starting at AAAAABB
    // if (count[word[0]] > count[word[word.length() - 1]]) {
    //     std::reverse(word.begin(), word.end());
    // }
    //***************************************************


    // Iterate through the board and only call backtracking on coordinates
    // that start with the first char in word.
    for(int i = 0; i < c_length; i++)
    {
        for(int j = 0; j < r_length; j++)
        {
            if(word[0] == board[i][j])
            {
                // If backtracking returns true we found a path
                if(backtracking({i, j}, 0, backtracking)) return true;
            }
        }
    }
    // path not found return false
    return false;
}






int main()
{
    std::vector<std::vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
        };

    std::vector<std::vector<char>> board2 = {
        {'C','A','A'},
        {'A', 'A', 'A'},
        {'B', 'C', 'D'}
    };

    std::string word = "AAB";
    bool exists = exist3(board2, word);

    if(exists)
    {
        std::cout << "true\n";
    }
    else
    {
        std::cout << "false\n";
    }



    return 0;
}
