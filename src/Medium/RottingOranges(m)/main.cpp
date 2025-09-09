#include <iostream>
#include <vector>
#include <queue>
#include <map>


// Brute force implementation. Does not work
// int grid_row_index(int source, std::vector<std::vector<int>>& grid)
// {
//     if(source > -1 && source < 3)
//     {
//         return 0;
//     }
//     else if(source > 2 && source < 6)
//     {
//         return 1;
//     }
//     else if(source > 5 && source < 9)
//     {
//         return 2;
//     }
//     else
//     {
//         return -1;
//     }
// }
//
// int grid_column_index(int source, std::vector<std::vector<int>>& grid)
// {
//     if(source == 0 || source == 3 || source == 6)
//     {
//         return 0;
//     }
//     else if(source == 1 || source == 4 || source == 7)
//     {
//         return 1;
//     }
//     else if(source == 2 || source == 5 || source == 8)
//     {
//         return 2;
//     }
//     else
//     {
//         return -1;
//     }
// }
//
// bool within_rage(int source)
// {
//     if(source < 0 || source > 8)
//     {
//         return false;
//     }
//     return true;
// }
//
// void longest_distance(std::map<int, int>& prev, int last_index, int& counter)
// {
//     if(last_index == 0) return;
//
//     // last_index = prev.at(last_index);
//     // counter++;
//     longest_distance(prev, prev.at(last_index), ++counter);
// }
//
// // This is doing the breadth first search correctly. The last thing to add is a correct counter so that oranges withing the same 4 side range
// // are not counted multiple times but instead counted once. Idea Use a predecessor array to keep track of predecessors, if a new predecssor happens
// // increase time if 1 if old predecessor dont increase time. Another idea is to get the farthest distance from the source node
//
// // So this traverses the 2D array using the chess method where 0 is the top left index and 8 is the bottom left index and the index gets
// // incremented by one each time its moved to the right and once it reaches the end of the row it increments and goes down to next row
//
// // New problem: if a good orange is never reached by a rotten orange then return -1. Solution. Could the number of nodes visited and if its not the same as the number of oranges
// // with 1 and 2 then return -1.
//
// // Problem: If there are not good oranges 1 then return 0
//
//
// int organgesRotting(std::vector<std::vector<int>>& grid)
// {
//     std::queue<int> q; // queue keeping track of next nodes to visit
//     int time = 0; // Hold time counter
//     std::vector<bool> visited(9, false); // Initialize as all elements have not been visited
//     int source = 0;
//     // <current, pred>
//     std::map<int, int> prev;
//     int last_index = 0;
//
//     int counter = 0; //This keeps track of items in the same range so double counting
//
//     // Fill all spots in the grid with -1
//     for(int i = 0; i < 9; i++)
//     {
//         prev.emplace(i, -1);
//     }
//
//     prev[0] = 0;
//
//     // Count number of good oranges with one bad orage
//     int num_of_organges = 0;
//     for(int i = 0; i < grid.size(); i++)
//     {
//         for(int j = 0; j < grid[i].size(); j++)
//         {
//             if(grid[i][j] == 2 || grid[i][j] == 1)
//             {
//                 num_of_organges++;
//             }
//         }
//     }
//
//     if(num_of_organges == 1)
//     {
//         return 0;
//     }
//
//
//
//
//     // Finds the source orange
//     bool found = false;
//     for(int i = 0; i < grid.size(); i++)
//     {
//         for(int j = 0; j < grid[i].size(); j++)
//         {
//             if(grid[i][j] == 2)
//             {
//                found = true;
//                 break;
//             }
//             else
//             {
//                 source++;
//             }
//         }
//         if(found) break;
//     }
//
//     // mark source as visited
//     visited[source] = true;
//     q.push(source); // push to queue
//
//     while(!q.empty())
//     {
//         int current_index = q.front();
//         int item = grid[grid_row_index(current_index, grid)][grid_column_index(current_index, grid)];
//
//         std::cout <<"current index: " << current_index << "\n";
//         std::cout << "current item: " << item << "\n";
//
//         q.pop(); // Pop first element out of queue since were at that node right now
//
//         // if(counter != 0) counter--; // Ruel to keep track of time allocated only to one range. Not working at the moment
//         //
//         // if(item == 1 && counter == 0) time++;
//             for(int i = 1; i < 4; i += 2)
//             {
//                 // This checks the right and bottom sides
//                 if(within_rage(current_index + i) && grid[grid_row_index(current_index + i, grid)][grid_column_index(current_index + i, grid)] != 0 && visited[current_index + i] != true)
//                 {
//                     q.push(current_index + i);
//                     visited[current_index + i] = true;
//                     prev[current_index + i] = current_index;
//                     // counter++; // counter thing
//                 }
//                 // This checks the left and top sides
//                 if(within_rage(current_index - i) && grid[grid_row_index(current_index - i, grid)][grid_column_index(current_index - i, grid)] != 0 && visited[current_index - i] != true)
//                 {
//                     q.push(current_index - i);
//                     visited[current_index - i] = true;
//                     prev[current_index - i] = current_index;
//                     // counter++; //counter thing
//                 }
//             }
//
//         if(q.empty()) last_index = current_index;
//
//     }
//
//     int num_of_visited = 0;
//     for(int i = 0; i < visited.size(); i++)
//     {
//         if(visited[i] == true)
//         {
//             num_of_visited++;
//         }
//     }
//
//     if(num_of_visited != num_of_organges)
//     {
//         return -1;
//     }
//
//
//
//
//     longest_distance(prev, last_index, time);
//
//     return time;
// }


// Real implementation
int organgesRotting(std::vector<std::vector<int>>& grid)
{
    // Save row and column sizes to check range
    int row_size = grid.size();
    int column_size = grid[0].size();
    // Queue which stores pairs for a 2D array. Keep tracks of who is next in the bfs. Store all rotten oranges first
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> visited_grid = grid; // Keeps track of visited oranges. Changes the state of the orange if fresh.
    int minutes = -1; // keep track of minutes it takes to rot all oranges

    // Count number of fresh oranges and rotten oranges
    int num_fresh_oranges = 0;
    int num_rotten_oranges = 0;
    for(int i = 0; i < visited_grid.size(); i++)
     {
         for(int j = 0; j < visited_grid[i].size(); j++)
         {
             // if with an ifelse checks one or the other. If if then the if else is not check and vice versa
            if(visited_grid[i][j] == 1)
            {
                num_fresh_oranges++;
            }
            else if(visited_grid[i][j] == 2)
            {
                num_rotten_oranges++;
                q.push({i, j}); // push the coordinate of the rotten oranges in the queue
            }
         }
     }

    // Two if statemnets means both if statements will be checked regardless if one passes or not
    // If no fresh oranges return 0
    if(num_fresh_oranges <= 0)
    {
        return 0;
    }

    // If no rotten oranges return -1
    if(num_rotten_oranges <= 0)
    {
        return -1;
    }

    // Store the four directions to check fresh oranges| top           down          right         left
    std::vector<std::pair<int, int>> directions = {{-1, 0},{1, 0},{0, 1},{0, -1}};
    while(!q.empty())
    {
        int size = q.size(); // save size so that it won't affect the actual size of the queue
        while(size--) // Syntax this. This post decrements the size and the loop will stop once the size hits 0. Can also write liek this: while(size != 0) in the body size--.
        {
            auto [x, y] = q.front(); // Store the coordinate of the first orange in the queue
            q.pop(); // remove first orange in the queue
            // Loop through the directions vector to check all four sides from the current orange coordinate
            for(auto [dx, dy] : directions)
            {
                int i = x + dx;
                int j = y + dy;

                // Check if the i row side is a valid coordinate and if j column side is a valid coordinate and if side coordinate has not been visited yet.
                // i is the row side for checking the four sides. We check if it's greater than 0 but less then the row size of the grid
                // j is the column side for checking the four sides. We check if it's greater than 0 but less than the row size of the grid
                // If i and j are within range and in valid positions we check if that side contains a fresh orange
                if(i >= 0 && i < row_size && j >= 0 && j < column_size && visited_grid[i][j] == 1)
                {
                    visited_grid[i][j] = 2;
                    num_fresh_oranges--;
                    q.push({i, j});
                }
            }
        }
        minutes++;
    }

    // Check if there are any unreached fresh oranges
    if(num_fresh_oranges == 0) // if all fresh oranges covered return the minutes
    {
        return minutes;
    }
    return -1;
}


int main()
{
    std::vector<std::vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int time = organgesRotting(grid);
    std::cout <<"\nTime: " << time << "\n";


    return 0;


}
