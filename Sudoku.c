#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

# define H 9 // number of columns and rows

bool can_write(int A[H][H], int m, int n, int x) { // checking if x can be legally written in (m, n) (m represents the row, n column)
    int k = m - m % 3, l = n - n % 3;
    for (int i = 0; i < H; i++) {
        if (A[m][i] == x) return false;
    }
     for (int j = 0; j < H; j++) {
        if (A[j][n] == x) return false;
    }
    for (int i = k; i < k + 3; i++) {
        for (int j = l; j < l + 3; j++){
            if (A[i][j] == x) return false;
        }
    }
    return true;
}

bool solve(int A[H][H]) { // recursively checking if the grid is solvable, we use backtracking. The function also solves the grid - if possible
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (A[i][j] == 0) {
                for (int x = 1; x <= 9; x++) {
                    if (can_write(A, i, j, x)) {
                        A[i][j] = x;
                        if (solve(A)) return true;
                        else A[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main() {
    int grid[H][H];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    if (solve(grid)) {
        for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
        }
    }
    else printf("Not solvable\n");
}
