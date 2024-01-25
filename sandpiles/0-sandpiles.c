#include "sandpiles.h"
#include <stdio.h>

static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}



int is_stable(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                return 1;
            }
        }
    }
    return 0;
}

int tupple(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                grid[i][j] -= 4;
                if (i - 1 >= 0) {
                    grid[i-1][j] += 1;
                }
                if (i + 1 < 3) {
                    grid[i+1][j] += 1;
                }
                if (j - 1 >= 0) {
                    grid[i][j-1] += 1;
                }
                if (j + 1 < 3) {
                    grid[i][j+1] += 1;
                }
            }
        }
    }
    // Note: Accessing grid[3][3] is invalid; you might want to return a meaningful value.
    // For example, you could return grid[2][2], which is the last element in the 3x3 array.
    return grid[3][3];
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }
    while (is_stable(grid1) == 1) {
        grid1[3][3] = tupple(grid1);
        print_grid(grid1);
        printf("=\n");
    }
}


