/*
Name: Johnny Gilbert
Class: Piece
Description: a class for individual places on the Othello board holds a value of 0 for empty, value 1 for black, and value of 2 for white.
Date: 04/11/2020
*/
#ifndef PIECE_H
#define PIECE_H
using namespace std;
class Piece{
    public:
        Piece();
        bool is_empty() const;
        bool is_black() const;
        bool is_white() const;
        void make_black();
        void make_white();
        bool operator ==(const int x) const;
    private:
        int spot;
};
#endif