// Header file inclusion
#include "sandpiles.h"
#include <stdio.h>

// Function to print the sandpile grid
static void print_grid(int grid[3][3])
{
    int i, j;

    // Nested loops to iterate through each element in the grid
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            // Print a space before each element (except the first in the row)
            if (j)
                printf(" ");
            // Print the current element value
            printf("%d", grid[i][j]);
        }
        // Move to the next line after each row
        printf("\n");
    }
}

// Function to check if the sandpile is stable (no cell value > 3)
int is_stable(int grid[3][3]) {
    // Nested loops to iterate through each element in the grid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // If any cell value is greater than 3, the sandpile is not stable
            if (grid[i][j] > 3) {
                return 1;
            }
        }
    }
    // If no cell value is greater than 3, the sandpile is stable
    return 0;
}

// Function to perform a topple operation on the sandpile grid
void tupple(int grid[3][3]) {
    // Temporary array to store the result of the topple operation
    int tmp[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    // Nested loops to iterate through each element in the grid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // If the cell value is greater than 3, perform the topple operation
            if (grid[i][j] > 3) {
                // Decrease the current cell value by 4
                tmp[i][j] -= 4;
                // Increment neighboring cells if they are within the grid bounds
                if (i >= 1) {
                    tmp[i-1][j] += 1;
                }
                if (i <= 1) {
                    tmp[i+1][j] += 1;
                }
                if (j >= 1) {
                    tmp[i][j-1] += 1;
                }
                if (j <= 1) {
                    tmp[i][j+1] += 1;
                }
            }
        }
    }

    // Update the original grid by adding the results of the topple operation
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = grid[i][j] + tmp[i][j];
        }
    }
}

// Function to compute the sum of two sandpile grids and stabilize the result
void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    // Add corresponding elements of grid2 to grid1
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Perform topple operations until the resulting sandpile is stable
    while (is_stable(grid1) == 1) {
        // Print the current state of the sandpile
        printf("=\n");
        print_grid(grid1);
        // Perform a topple operation on the sandpile
        tupple(grid1);
    }
}
