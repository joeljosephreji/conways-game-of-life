#include "board.hpp"
#include "fileHandlingUtils.hpp"
#include <iostream>
#include <vector>

void Board::displayBoard() {
    std::cout << "\033[2J\033[1;1H";
    for (const std::vector<int> &row : board) {
        for (const int digit : row) {
            if (digit == 1) {
                std::cout << "█";
            } else {
                std::cout << " ";
            }
        };
        std::cout << "\n";
    }
}

void Board::readBoard(const std::vector<std::string> &lines) {
    for (const std::string &line : lines) {
        std::vector<int> row;
        for (char c : line) {
            if (c == 'O')
                row.push_back(1);
            else
                row.push_back(0);
        }
        board.push_back(row);
    }
}

void Board::passTimeUnit() {
    std::vector<std::vector<int>> newBoard(board);

    int rowLength = board.size();
    int columnLength = board[0].size();

    for (int row = 0; row < rowLength; ++row) {
        for (int column = 0; column < columnLength; ++column) {

            int sum = 0;
            for (int diffRow = -1; diffRow <= 1; ++diffRow) {
                for (int diffColumn = -1; diffColumn <= 1; ++diffColumn) {
                    if (diffRow == 0 && diffColumn == 0) {
                        continue;
                    }

                    int newRow = row + diffRow;
                    int newColumn = column + diffColumn;

                    if (newRow >= 0 && newRow < rowLength && newColumn >= 0 &&
                        newColumn < columnLength) {
                        sum += board[newRow][newColumn];
                    }
                }
            }

            if (board[row][column] == 1) {
                newBoard[row][column] = (sum == 2 || sum == 3) ? 1 : 0;
            } else {
                newBoard[row][column] = (sum == 3) ? 1 : 0;
            }
        }
    }
    board = std::move(newBoard);
}
