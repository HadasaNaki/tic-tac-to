#include <fstream>
#include <yaml-cpp/yaml.h>
#include "Board.h"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    try {
      YAML::Node test_case = YAML::LoadFile(argv[1]);

      int N = test_case["board_size"].as<int>();

      Board board(N);

      for (const auto& num : test_case["inputs"]) {
        board.insert(num.as<int>());

        board.print();

        if (board.ChekingIfRowIsFilled()) {
          std::cout << board.getCurrentPlayer() << " is the winner!! \n";
          break;
        }
        if (board.isBoardFull()) {
          std::cout << "It's a draw!\n";
          break;
        }

        board.switchPlayer();
      }

      return 0;
    }
    catch (const std::exception& e) {
      std::cerr << "Error: " << e.what() << std::endl;
      return 1;
    }
  }

  int N;
  int num;
  std::cin >> N;
  try {
    Board board(N);
    while (true) {
      tag: std::cin >> num;
      board.insert(num);
      board.print();
      if (board.ChekingIfRowIsFilled()) {
        std::cout << board.getCurrentPlayer() << " is the winner!! \n";
        break;
      }
      if (board.isBoardFull()) {
        std::cout << "It's a draw!\n";
        break;
      }
      board.switchPlayer();
    }
  } catch (const char* msg) {
    std::cerr << msg;
  }
  return 0;
}
