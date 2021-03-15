#include <vector>
#include <string>
#include "ttt_functions.hpp"

//function file with functions defintions

//start the game script
void game_start() {
  std::cout << "Welcome to Tic-Tac-Toe!\nPlayer X goes first!\n";
}

//print the board 
void print_board(std::vector<std::string> board) {
  for (int i = 0; i < board.size(); i++) {
    std::cout << board[i];
  }
}

//out the end the game if person wins or full board 
void end_game(std::vector<std::string> board, std::string player_x, std::string player_o) {

  if (full_row(board, player_x) || full_col(board, player_x) || full_diag(board, player_x)) {
    std::cout << "Congrats! Player " << player_x << " won!\n";
  }
  else if (full_row(board, player_o) || full_col(board, player_o) || full_diag(board, player_o)) {
    std::cout << "Congrats! Player " << player_o << " won!\n";
  }
  else if (full_board(board)) {
    std::cout << "It's a tie!\n";
  }
}

//determine if the game is over due to full board or a winner
bool game_over(std::vector<std::string> board, std::string player_x, std::string player_o) {
  return full_board(board) || full_row(board, "X") || full_row(board, "O") || full_col(board, "X") || full_col(board, "O") || full_diag(board, "X") || full_diag(board, "O");
}

//check for full board
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

//check if a row has all of the values 
bool full_row(std::vector<std::string> board, std::string player) { 
  if ((board[0] == player && board[2] == player && board[4] == player) || (board[6] == player && board[8] == player && board[10] == player) || (board[12] == player && board[14] == player && board[16] == player)) {
    return true;
  }

  else{
    return false;
  }
}

//check if a column has all of the values 
bool full_col(std::vector<std::string> board, std::string player) { 
  if ((board[0] == player && board[6] == player && board[12] == player) || (board[2] == player && board[8] == player && board[14] == player) || (board[4] == player && board[10] == player && board[16] == player)) {
    return true;
  }

  else{
    return false;
  }
}

//check if the diagonal has all of the values 
bool full_diag(std::vector<std::string> board, std::string player) { 
  if ((board[0] == player && board[8] == player && board[16] == player) || (board[4] == player && board[8] == player && board[12] == player)) {
    return true;
  }

  else{
    return false;
  }
}

//check if a spot is taken
bool spot_taken(std::vector<std::string> board, int spot) {
  if (board[spot * 2 - 2] == " ") {
    return false;
  }
  else {
    return true;
  }
}

//check if an entry is within range 
bool valid_entry(int input) {
  if (input >= 1 && input <= 9) {
    return true;
  }
  else {
    return false;
  }
}
