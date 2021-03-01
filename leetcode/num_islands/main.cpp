#include <iostream>
#include <vector>
#include <assert.h> 

using namespace std;

class Solution {
public:

  
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Base case: End condition of searching. 
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == '0')
        {
            return;
        }

        // Action: Searching
        grid[i][j] = '0'; // Mark the visited node as 0. 
        dfs(grid, i - 1, j); // downward
        dfs(grid, i + 1, j); // upward
        dfs(grid, i, j - 1); // leftward
        dfs(grid, i, j + 1); // rightward
    }


    int numIslands(vector<vector<char>>& grid) {
        
        // num count
        int count = 0;
        
        // main loop
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++count;    // Found the first '1' of an island. 
                    dfs(grid, i, j); // Then, nullify all the '1's of this island. i.e., set to 0. 
                }
            }
        }
        
        
        return count;
        
        
    }

  
};


int main() {
    // Example 1
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    int result1;
    
    // Example 2 
    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'}, 
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'} 
    };
    int result2; 
    
    Solution s;
    result1 = s.numIslands(grid1); 
    result2 = s.numIslands(grid2); 
    
    cout << "result1: " << result1 << endl;
    cout << "result2: " << result2 << endl; 
    
    // assert(result1 == 1);
    // assert(result2 == 3); 
    
    return 0;
}
