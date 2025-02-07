#!/usr/bin/python3
"""Rain algorithm module"""


def rain(walls):
    """ rain algorithms"""
    total = 0
    bottom = 0
    left = 0
    right = 0

    for index in range(len(walls)):
        current_height = walls[index]

        # Find thehole
        if current_height == 0:
            # Define the left wall
            if (index - 1) >= 0 and walls[index - 1] != 0:
                left = walls[index - 1]
            # Define the right wall
            if (index + 1) < len(walls):
                right = walls[index + 1]
            # Update the bottom length
            if left != 0:
                height_left = left
                bottom += 1

                if right != 0:
                    height_right = right

                    # Calculate the area of a hole containing water
                    if height_left and height_right:
                        min_height = min(height_right, height_left)
                        local_area = min_height * bottom
                        total += local_area
                        bottom = 0
                        left = 0
                        right = 0
    return total
