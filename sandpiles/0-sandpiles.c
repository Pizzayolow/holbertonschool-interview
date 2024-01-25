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

void tupple(int grid[3][3]) {

    int tmp[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}

    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                tmp[i][j] -= 4;
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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = grid[i][j] + tmp[i][j];
        }
    }
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }
    while (is_stable(grid1) == 1) {
        print_grid(grid1);
        printf("=\n");
        tupple(grid1);
        
    }
}


