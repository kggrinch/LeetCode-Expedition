#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>


// My trial
// void exist_helper(std::vector<std::vector<char>>& board, std::string word, std::string& word_builder,
//     std::vector<std::pair<int, int>>& board_coordinates, std::pair<int, int> current_coordinate,
//     int row_size, int column_size, int& current_word_index)
// {
//     //                                              up             down          left            right
//     std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//     int x_c = current_coordinate.first;
//     int y_c = current_coordinate.second;
//     char letter_at_current_coordinate = board[x_c][y_c];
//     word_builder.push_back(letter_at_current_coordinate);
//     current_word_index++;
//
//
//     for(auto [x, y] : directions)
//     {
//         int dx =  x_c + x;
//         int dy =  y_c + y;
//         if(dx >= 0 && dx < row_size && dy >= 0 && dy < column_size && (word[current_word_index] == board[dx][dy]))
//         {
//
//             board_coordinates.push_back({dx, dy});
//             return exist_helper(board, word, word_builder, board_coordinates, {dx, dy}, row_size, column_size, current_word_index);
//         }
//     }
// }
//
//
// bool exist(std::vector<std::vector<char>>& board, std::string word)
// {
//     // plan.
//     // Create a string that will build the word from the board. iF the word is built the word exists
//     // Use pair to hold coordinates
//     // Use a dfs starting at source
//     // use vector with pair to check four sides. Means we need to save range of row and column of the board
//     // Use a hashmap with a pair<int, int>(coordinate) and a char to check for already visited chars
//
//     // 1. Iterate the board and find first char in the board from the word and store its coordinate to the grid
//     // 2. use a recursive method. pass in the board, building string, the word, the directions vector, pass in index of next char in the word
//     // 3. Base case at the end return if no correct letter found
//     // 3. if correct letter found call recusive method with the next letters coordinate
//     // 4. after the recursion ends check if the built word matches the passed in word. If it matches return true otherwise return false
//
//
//     char start_char = word[0];
//     int row_size = board.size();
//     int column_size = board[0].size();
//     std::string word_builder = "";
//     int current_word_index = 0;
//
//     // <row, column>
//     std::vector<std::pair<int, int>> board_coordinates;
//     bool break_for_loop = false;
//
//
//     for(int i = 0; i < row_size; i++)
//     {
//         if(break_for_loop)
//         {
//             break;
//         }
//             for(int j = 0; j < column_size; j++)
//             {
//                 if(start_char == board[i][j])
//                 {
//                     board_coordinates.push_back({i, j});
//                     break_for_loop = true;
//                     break;
//                 }
//             }
//     }
//
//     // std::pair<int, int> current_coordinate = board_coordinates[0];
//
//     exist_helper(board, word, word_builder, board_coordinates, board_coordinates[0], row_size, column_size, current_word_index);
//
//
//     if(word_builder == word)
//     {
//         return true;
//     }
//     return false;
// }


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
        // For example in the case where is liek AAAAAABB
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
    bool exists = exist(board2, word);

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
