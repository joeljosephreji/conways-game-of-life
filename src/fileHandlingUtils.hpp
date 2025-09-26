#include <string>
#include <vector>
class FileHandlingUtils {
  public:
    static std::vector<std::string> getFileLines(const std::string &filename);
};
