#!/usr/bin/python3
"""
~~~~~~~~~~~~~~~~~~~~
Calculate the perimeter of an island described in a grid
"""


def island_perimeter(grid):
    """
    Parameter:
        grid (list of list of int): The grid representing the island
    Return:
        int: The perimeter of the island
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
    return perimeter
