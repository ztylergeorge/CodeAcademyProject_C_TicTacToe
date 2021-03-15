#include <vector>
#include <iostream>
#include <string>
#include "ttt_functions.hpp"

void print_board(std::vector<std::string> board) {
  for (int i = 0; i < board.size(); i++) {
    std::cout << board[i];
  }
}

bool full_board(std::vector<std::string> board) {
  int count = 0;

  for (int i = 0; i < board.size(); i++) {
    if (board[i] == "O" || board[i] == "X") {
      count++;
    }
  }

  if (count < 9) {
    return false;
  }
  else{
    return true;
  }
}

bool full_row(std::vector<std::string> board, std::string player) { 
  if ((board[0] == player && board[2] == player && board[4] == player) || (board[6] == player && board[8] == player && board[10] == player) || (board[12] == player && board[14] == player && board[16] == player)) {
    return true;
  }

  else{
    return false;
  }
}

bool full_col(std::vector<std::string> board, std::string player) { 
  if ((board[0] == player && board[6] == player && board[12] == player) || (board[2] == player && board[8] == player && board[14] == player) || (board[4] == player && board[10] == player && board[16] == player)) {
    return true;
  }

  else{
    return false;
  }
}