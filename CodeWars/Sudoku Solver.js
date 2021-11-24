function sudoku(puzzle) {
    // check
    let row = {}, column = {}, block = {}, space = [];
    let temp = [false, false, false, false, false, false, false, false, false];
    let valid = false;
    for (let i = 0; i < 9; i++) {
        row[i] = temp.concat([]);
        column[i] = temp.concat([]);
        block[Math.floor(i / 3)] = {'0': temp.concat([]), '1': temp.concat([]), '2': temp.concat([])};
    }
    
    // initial board
    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            if (puzzle[i][j] === 0) {
                space.push([i, j]);
            } else {
                let digit = parseInt(puzzle[i][j]) - 1;
                row[i][digit] = column[j][digit] = block[Math.floor(i / 3)][Math.floor(j / 3)][digit] = true;
            }
        }
    }

    var backtracking = function (puzzle, pos) {
        // finished
        if (pos === space.length) {
            valid = true;
            return;
        }
        
        let x = space[pos][0];
        let y = space[pos][1];
        for (let num = 0; num < 9; num++) {
            if (valid) {
                break;
            }
            if (!row[x][num] && !column[y][num] && !block[Math.floor(x / 3)][Math.floor(y / 3)][num]) {
                row[x][num] = column[y][num] = block[Math.floor(x / 3)][Math.floor(y / 3)][num] = true;
                puzzle[x][y] = num + 1;
                backtracking(puzzle, pos + 1);
                row[x][num] = column[y][num] = block[Math.floor(x / 3)][Math.floor(y / 3)][num] = false;
            }
        }
    }
    
    backtracking(puzzle, 0);
    return puzzle;
};