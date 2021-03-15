#include <vector>
#include<iostream>

//Header file with function declarations

void game_start();

void print_board(std::vector<std::string> board);

bool full_board(std::vector<std::string> board);

bool full_row(std::vector<std::string> board, std::string player);

bool full_col(std::vector<std::string> board, std::string player);

bool full_diag(std::vector<std::string> board, std::string player);

bool spot_taken(std::vector<std::string> board, int spot);

bool game_over(std::vector<std::string> board, std::string player_x, std::string player_o);

void end_game(std::vector<std::string> board, std::string player_x, std::string player_o);

bool valid_entry(int input);

