 
#include <stdio.h>

#define ROWS 6
#define COLS 6

char maze[ROWS][COLS] = {
    {'S', '0', '1', '0', '1', '1'},
    {'0', '0', '0', '0', '0', '0'},
    {'1', '0', '1', '1', '0', '1'},
    {'1', '0', '1', '0', '0', '0'},
    {'1', '0', '0', '0', '1', 'G'},
    {'1', '1', '1', '0', '1', '1'}
};

int is_valid_move(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] != '1');
}

int solve_maze(int x, int y) {
    if (!is_valid_move(x, y)) {
        return 0; // Invalid move
    }

    if (maze[x][y] == 'G') {
        return 1; // Goal reached
    }

    if (maze[x][y] == '0' || maze[x][y] == 'S') {
        maze[x][y] = 'P'; // Mark the path

        // Explore in all possible directions (up, down, left, right)
        if (solve_maze(x - 1, y) || solve_maze(x + 1, y) || solve_maze(x, y - 1) || solve_maze(x, y + 1)) {
            return 1; // Found a path
        }

        maze[x][y] = '0'; // Backtrack if no path found
    }

    return 0; // No path found
}

void print_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int start_row, start_col;

    // Find the starting position
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 'S') {
                start_row = i;
                start_col = j;
                break;
            }
        }
    }

    if (solve_maze(start_row, start_col)) {
        printf("Solution Path:\n");
        print_maze();
    } else {
        printf("No solution found.\n");
    }

    return 0 ; 
}