#include "piece.h"
Piece::Piece(){
    spot = 0;
}
bool Piece::is_empty() const{
    if(spot == 0){
        return true;
    }
    else{
        return false;
    }
}
bool Piece::is_black() const{
    if(spot == 1){
        return true;
    }
    else{
        return false;
    }
}
bool Piece::is_white() const{
    if(spot == 2){
        return true;
    }
    else{
        return false;
    }
}
void Piece::make_black(){
    spot = 1;
}
void Piece::make_white(){
    spot = 2;
}

