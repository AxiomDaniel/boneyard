class PuzzleGame:
    def __init__(self, puzzle):
        self.puzzle = puzzle
        self.Xposition = self.trackXPosition(puzzle)

    def trackXPosition(self, puzzle):
        for row in range(len(puzzle)):
            for col in range(len(puzzle[row])):
                if puzzle[row][col] == " X":
                    return row, col

    def prettyPrint(self):
        [print(row) for row in self.puzzle]

    def move(self, direction):
        direction = direction.lower()
        rowAdjustment = 0
        colAdjustment = 0
        if direction == "up":
            if self.Xposition[0] == 0:
                print("Unable to move up, X is already at top row!")
            else:
                rowAdjustment = -1
        elif direction == "down":
            if self.Xposition[0] == len(self.puzzle) - 1:
                print("Unable to move down, X is already at bottom row")
            else:
                rowAdjustment = 1
        elif direction == "left":
            if self.Xposition[1] == 0:
                print("Unable to move left, X is already at leftmost column")
            else:
                colAdjustment = -1
        elif direction == "right":
            if self.Xposition[1] == len(self.puzzle) - 1:
                print("Unable to move right, X is already at rightmost column")
            else:
                colAdjustment = 1
        else:
            print("Invalid move, try again")
        newPosition = (self.Xposition[0] + rowAdjustment,
                       self.Xposition[1] + colAdjustment)
        self._swapPosition(self.Xposition, newPosition)
        self.Xposition = newPosition

    def _swapPosition(self, tuple1, tuple2):
        tuple1_row, tuple1_col = tuple1
        tuple2_row, tuple2_col = tuple2
        self.puzzle[tuple1_row][tuple1_col], self.puzzle[tuple2_row][tuple2_col] = self.puzzle[tuple2_row][tuple2_col], self.puzzle[tuple1_row][tuple1_col]


if __name__ == "__main__":
    newPuzzle = [[' 1', ' 2', ' 3', ' 4', ], [' 5', ' 6', ' 7', ' 8'],
                 [' 9', '10', '11', '12'], ['13', '14', '15', ' X']]
    newGame = PuzzleGame(newPuzzle)
