#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>>& grid) {
    int n = grid.size();
    map<int, vector<int>> diagonals; // Use map to maintain order

    // Step 1: Group elements by their diagonal index (row - col)
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            int d = row - col; // Calculate diagonal index
            diagonals[d].push_back(grid[row][col]);
        }
    }

    // Step 2: Sort each diagonal
    for (auto& pair : diagonals) {
        if (pair.first >= 0) {
            // Bottom-left triangle - sort in descending order
            sort(pair.second.rbegin(), pair.second.rend());
        } else {
            // Top-right triangle - sort in ascending order
            sort(pair.second.begin(), pair.second.end());
        }
    }

    // Step 3: Reconstruct the matrix
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            int d = row - col; // Get diagonal index again
            grid[row][col] = diagonals[d].back(); // Get the last sorted element
            diagonals[d].pop_back(); // Remove that element
        }
    }

    return grid; // Return the sorted matrix
}

int main() {
    vector<vector<int>> grid = {
        {3, 3, 1, 1},
        {2, 2, 1, 2},
        {1, 1, 1, 2},
        {1, 2, 2, 2}
    };

    vector<vector<int>> sortedGrid = diagonalSort(grid);

    // Print the sorted matrix
    for (const auto& row : sortedGrid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl; // New line for each row
    }

    return 0;
}
