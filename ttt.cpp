#include <iostream>
#include <stdlib.h>
#include "ttt_functions.hpp"

int main() {
  std::vector<std::string> board{" ", "|", " ", "|", " ", "\n"," ", "|", " ", "|", " ", "\n"," ", "|", " ", "|", " ", "\n"};
  int x_spot;
  int o_spot;
  while (not full_board(board) && not full_row(board, "X") && not full_col(board, "X")) {
    std::cout << full_board(board) << "\n";
    //output board 
    print_board(board);

    //ask player 1 (x) to place their piece
    std::cout << "Enter your X. Top row: 1-3, Middle row: 4-6, Bottom row: 7-9.\n"; 
    std::cin >> x_spot;
    board[x_spot * 2 - 2] = "X";
    print_board(board);

    //ask player 2 (o) to place their piece
    std::cout << "Enter your O. Top row: 1-3, Middle row: 4-6, Bottom row: 7-9.\n"; 
    std::cin >> o_spot;
    board[o_spot * 2 - 2] = "O";
    print_board(board);
  }
  //loop until a winner occurs or full board 
  
}