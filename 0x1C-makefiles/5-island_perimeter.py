#!/usr/bin/python3
"""
This module is function to solve island perimeter
"""

def island_perimeter(grid):
	"""
	This function computes the perimeter of island in a grid
	"""
	height = len(grid)
	width = len(grid[0])
	counter = 0
	adj_count = 0 #Adjacent land count

	for i in range(0, height):
		for j in range(0, width):
			if grid[i][j] == 1:
				counter += 1
				if i > 0 and grid[i - 1][j] == 1:
					adj_count += 1
				if j > 0 and grid[i][j - 1] == 1:
					adj_count += 1

	perimeter = 4 * counter - 2 * adj_count
	return perimeter
