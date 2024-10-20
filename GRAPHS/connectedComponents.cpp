#include <bits/stdc++.h> // This includes all the standard libraries of C++, like iostream, vector, queue, etc.
using namespace std;

// Function to perform BFS traversal to explore one connected component
void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis) {
    // Mark the starting cell as visited
    vis[row][col] = 1;

    // Get the number of rows (n) and columns (m) in the grid
    int n = grid.size();
    int m = grid[0].size();

    // Create a queue to store cells to visit
    queue<pair<int, int>> q;
    q.push({row, col}); // Start BFS from the current cell

    // BFS continues until all cells connected to the starting cell are visited
    while (!q.empty()) {
        // Get the front cell from the queue
        int row = q.front().first;
        int col = q.front().second;
        q.pop(); // Remove the current cell from the queue

        // Traverse all 8 possible neighbors (left, right, up, down, and diagonals)
        for (int delRow = -1; delRow <= 1; delRow++) {
            for (int delCol = -1; delCol <= 1; delCol++) {
                // Calculate new row and column
                int nrow = row + delRow;
                int ncol = col + delCol;

                // Check if the new position is valid (inside the grid) and is an unvisited land cell ('1')
                if ((nrow >= 0 && nrow < n) && (ncol >= 0 && ncol < m) && !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    // Mark the new cell as visited and push it to the queue for further exploration
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

// Function to find the number of connected components (islands) in the grid
int numIslands(vector<vector<char>> &grid) {
    // Get the number of rows (n) and columns (m) in the grid
    int n = grid.size();
    int m = grid[0].size();

    // Create a 2D visited array (vis) to keep track of visited cells, initialized to 0 (unvisited)
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int cnt = 0; // This will count the number of islands (connected components)

    // Traverse each cell of the grid
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            // If the current cell is a land cell ('1') and has not been visited
            if (!vis[row][col] && grid[row][col] == '1') {
                cnt++; // Increment the count of islands
                bfs(row, col, grid, vis); // Perform BFS to explore this island and mark all connected land cells as visited
            }
        }
    }
    return cnt; // Return the total number of islands
}

int main() {
    int n, m;
    cout << "Enter the no of rows and columns" << endl;
    cin >> n >> m; // Input number of rows and columns

    // Create a 2D grid of size n x m to store the input grid
    vector<vector<char>> grid(n, vector<char>(m));
    
    cout << "Enter the elements of the matrix" << endl;
    // Input the grid (1 for land, 0 for water)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Output the number of islands (connected components of land)
    cout << numIslands(grid) << endl;
    
    return 0;
}
