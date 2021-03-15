#include <iostream>
#include <stdlib.h>
#include "ttt_functions.hpp"

/** Tic Tac Toe Exercise From Code Academy
 * By Zach George 
 * Asks Player X to start by placing location, then Player O
 * Verifies spot is not taken and within range
 * DOES NOT include exception handling yet for not integer values 
 * loops this until there is a winner
 * **/

int main() {

  //create initial variables 
  std::vector<std::string> board{" ", "|", " ", "|", " ", "\n"," ", "|", " ", "|", " ", "\n"," ", "|", " ", "|", " ", "\n"};
  int x_spot;
  int o_spot;
  bool x_turn = true;
  bool o_turn = false;
  bool ask_for_spot = true;

  //start game 
  game_start();

  while (!game_over(board, "X", "O") && x_turn) {

    //output board 
    print_board(board);

    //ask player 1 (x) to place their piece and verify it is allowable
    while (ask_for_spot) {

      std::cout << "Enter your X. Top row: 1-3, Middle row: 4-6, Bottom row: 7-9.\n"; 
      std::cin >> x_spot;
      if (valid_entry(x_spot) && !spot_taken(board, x_spot)) {
        board[x_spot * 2 - 2] = "X";
        ask_for_spot = false;
      }
      else {
        std::cout << x_spot << " is invalid or taken. Please try again.\n";
      }
    }

    //output board and change variables 
    print_board(board);
    x_turn = false;
    o_turn = true;
    ask_for_spot = true;

    while (!game_over(board, "X", "O") && o_turn) {

      //ask player 2 (o) to place their piece and verify if it is allowable
      while (ask_for_spot) {

        std::cout << "Enter your O. Top row: 1-3, Middle row: 4-6, Bottom row: 7-9.\n"; 
        std::cin >> o_spot;
        if (valid_entry(o_spot) && !spot_taken(board, o_spot)) {
          board[o_spot * 2 - 2] = "O";
          ask_for_spot = false;
        }
        else {
          std::cout << o_spot << " is invalid or taken. Please try again.\n";
        }
      }

      //reset variables
      x_turn = true;
      o_turn = false;
      ask_for_spot = true;
    }
  }

  //output a winner occurs or full board (tie)
  end_game(board, "X", "O");
}