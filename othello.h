/*
Name: Johnny Gilbert
Class: Othello
Description: As of right now the class is inherited from the game class and allows the user to make one of the 4 legal moves.
Date: 04/11/2020
*/
#ifndef OTHELLO_H
#define OTHELLO_H
#include "piece.h"
#include "game.h"
#include "colors.h"
#include <iostream>
#include <queue>
#include <cctype>
using namespace std;
class Othello:public main_savitch_14::game{
    public:
        Othello();
        void display_status() const;
        void make_move(const std::string& move);
        bool is_legal(const std::string& move) const;
        game* clone( ) const{return new Othello(*this);}
        void compute_moves(std::queue<std::string>& moves) const;
        int evaluate( ) const;
        bool is_game_over( ) const;
        bool black_search_north(int row, int column) const;
        bool black_search_south(int row, int column) const;
        bool black_search_east(int row, int column) const;
        bool black_search_west(int row, int column) const;
        bool black_search_nw(int row, int column) const;
        bool black_search_sw(int row, int column) const;
        bool black_search_ne(int row, int column) const;
        bool black_search_se(int row, int column) const;
        bool white_search_north(int row, int column) const;
        bool white_search_south(int row, int column) const;
        bool white_search_east(int row, int column) const;
        bool white_search_west(int row, int column) const;
        bool white_search_nw(int row, int column) const;
        bool white_search_sw(int row, int column) const;
        bool white_search_ne(int row, int column) const;
        bool white_search_se(int row, int column) const;
        std::string get_user_move( ) const;
        game::who winning( ) const;
        //who winning( ) const;
    private:
        Piece game[8][8];
        int passes;
};
#endif