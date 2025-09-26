#include "board.hpp"
#include "fileHandlingUtils.hpp"
#include <chrono>
#include <memory>
#include <thread>

int main(int argc, char *argv[]) {
    std::unique_ptr<Board> board(new Board());
    board->readBoard(
        FileHandlingUtils::getFileLines("./src/ascii-patterns/pattern1.txt"));
    while (true) {
        board->displayBoard();
        board->passTimeUnit();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}
