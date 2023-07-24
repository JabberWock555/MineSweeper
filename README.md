# MineSweeper

Welcome to the Text-Based Minesweeper game, a classic and challenging adventure that tests your logic, deduction, and luck! In this game, your goal is to reveal all the safe tiles on the board while avoiding hidden mines.

![minesweeper-logo](https://github.com/JabberWock555/MineSweeper/assets/97807224/a90ff6da-eedc-4fe3-8f66-56f0f93c3628)


## Instructions

- **Setting Difficulty:** Choose between Easy, Medium, or Hard difficulty levels, each determining the size of the grid and the number of mines hidden on the board.

- **Gameplay:** Take turns to enter the row and column numbers of the cell you wish to interact with. Select an action: Open a cell to reveal its content or Flag/Unflag a cell to indicate a suspected mine.

- **Game Rules:** Cells are numbered with the count of adjacent mines, ranging from 0 to 8. Opening a cell with no adjacent mines will automatically open adjacent cells until numbers are reached. Be careful! Opening a cell with a mine ends the game.

- **Winning and Losing:** You win by successfully opening all non-mine cells on the board without placing any incorrect flags. You lose if you open a cell containing a mine.

- **Legend:** The board uses symbols to represent various states: Blank (undiscovered cell), F (flagged cell), * (cell with a mine), and 0 to 8 (cells with numbers indicating adjacent mines).

- **Playing the Game:** Enter row number, column number, and action (O or F) when prompted. For example, to open row 2, column 3, enter "2 3 O". To flag row 4, column 5, enter "4 5 F".

- **Challenge Yourself:** Improve your score and speed as you become a Minesweeper expert! Use your deduction skills to navigate the minefield.

Try your luck and become a Minesweeper master! Enjoy the classic game in this text-based version. Good luck and have fun playing!

## How to Play

1. Clone the repository or download the game files.
2. Compile and run the C++ code to start the game.
3. Follow the on-screen instructions to select the difficulty level and make your moves.
4. Open cells or flag suspected mines using the provided commands.
5. Win by opening all non-mine cells, but be cautious not to open a mine!

## Requirements

- C++ Compiler
- Standard C++ Library

## Acknowledgments

This game is inspired by the classic Minesweeper game found on various platforms. Special thanks to the OUTSCAL community for their continued support and contributions.

Enjoy the game and happy mine hunting!

