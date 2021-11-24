import java.util.*;
public class SudokuSolver {
    // board
    private int[][] board = new int[9][9];
    private int[][] ans = new int[9][9];

    // check
    private int[] row = new int[9];
    private int[] col = new int[9];
    private int[][] block = new int[3][3];
    private boolean valid = false;

    // empty slots to fill
    private List<int[]> blanks = new ArrayList<int[]>();

    public SudokuSolver(int[][] grid) {
        // check whther the board is 9 x 9
        if (grid.length != 9 || grid[0].length != 9) {
            throw new IllegalArgumentException();
        }

        // initialization
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // blanks
                if (grid[i][j] == 0) {
                    blanks.add(new int[]{i, j});
                } else if (grid[i][j] >= 1 && grid[i][j] <= 9) {
                // numbers
                    int num = grid[i][j] - 1;
                    board[i][j] = grid[i][j];
                    // repeating numbers
                    if (((row[i] | col[j] | block[i / 3][j / 3]) & (1 << num)) != 0) {
                        throw new IllegalArgumentException();
                    }
                    flip(i, j, num);
                } else {
                // invalid board
                    throw new IllegalArgumentException();
                }
            }
        }
    }
    
    public int[][] solve() {
        backtracking(0);
        // no answer
        if (!valid) {
            throw new IllegalArgumentException();
        }
        return ans;
    }

    private void backtracking(int pos) {
        // no more blanks
        if (pos == blanks.size()) {
            // multiple answers
            if (valid) {
                throw new IllegalArgumentException();
            } else {
                // recording an answer
                valid = true;
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        ans[i][j] = board[i][j];
                    }
                }
                return;                
            }
        }

        // fill in the blanks
        int[] blank = blanks.get(pos);
        int i = blank[0], j = blank[1];

        // set slots to 1 (~) and initialize irrelevant bits to 0 (&)
        int mask = ~(row[i] | col[j] | block[i / 3][j / 3]) & 0x1ff;

        // recursively remove the rightmost 1
        for (; mask != 0; mask &= (mask - 1)) {
            // only keep the rightmost 1
            int rightmost = mask & (- mask);
            // get the idx
            int digit = Integer.bitCount(rightmost - 1);
            flip(i, j, digit);
            board[i][j] = digit + 1;
            backtracking(pos + 1);
            flip(i, j, digit);
        }
    }

    private void flip(int i, int j, int digit) {
        row[i] ^= (1 << digit);
        col[j] ^= (1 << digit);
        block[i / 3][j / 3] ^= (1 << digit);
    }
}