#include <string>
#include <vector>
class Board {
    std::vector<std::vector<int>> board;

  public:
    void passTimeUnit();
    void readBoard(const std::vector<std::string> &filename);
    void displayBoard();
};
