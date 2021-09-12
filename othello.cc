#include "othello.h"
Othello::Othello(){
    passes = 0;
    game[3][3].make_white();
    game[3][4].make_black();
    game[4][3].make_black();
    game[4][4].make_white();
}
void Othello::display_status() const{
    cout<< RED <<"    A   B   C   D   E   F   G   H  "<< RESET <<endl;
    cout<< GREEN <<"   --- --- --- --- --- --- --- --- " << RESET << endl;
    cout<< RED<<"1" << RESET << GREEN<< " |";
    for(int i = 0; i < 8; i++){
        if(game[0][i].is_empty()){
            cout << " - |";
        }
        else if(game[0][i].is_black()){
            cout << RESET << MAGENTA <<" X" << RESET << GREEN << " |";
        }
        else if(game[0][i].is_white()){
            cout << RESET << WHITE <<" O" << RESET << GREEN <<" |";
        }
    }
    
    cout << endl;
    cout<<"  |--- --- --- --- --- --- --- ---|" << endl;
    cout << RESET;
    cout << RED << "2" << RESET << GREEN << " |";
    for(int i = 0; i < 8; i++){
        if(game[1][i].is_empty()){
            cout << " - |";
        }
        else if(game[1][i].is_black()){
            cout << RESET << MAGENTA <<" X" << RESET << GREEN << " |";
        }
        else if(game[1][i].is_white()){
            cout << RESET << WHITE <<" O" << RESET << GREEN <<" |";
        }
    }
    cout << endl;
    cout<<"  |--- --- --- --- --- --- --- ---|" << endl;
    cout << RESET;
    cout << RED <<"3" << RESET << GREEN << " |";
    for(int i = 0; i < 8; i++){
        if(game[2][i].is_empty()){
            cout << " - |";
        }
        else if(game[2][i].is_black()){
            cout << RESET << MAGENTA <<" X" << RESET << GREEN << " |";
        }
        else if(game[2][i].is_white()){
            cout << RESET << WHITE <<" O" << RESET << GREEN <<" |";
        }
    }
    cout << endl;
    cout<<"  |--- --- --- --- --- --- --- ---|" << endl;
    cout<< RESET;
    cout << RED << "4" <<RESET << GREEN << " |";
    for(int i = 0; i < 8; i++){
        if(game[3][i].is_empty()){
            cout << " - |";
        }
        else if(game[3][i].is_black()){
            cout << RESET << MAGENTA <<" X" << RESET << GREEN << " |";
        }
        else if(game[3][i].is_white()){
            cout << RESET << WHITE <<" O" << RESET << GREEN <<" |";
        }
    }
    cout << endl;
    cout<<"  |--- --- --- --- --- --- --- ---|" << endl;
    cout << RESET;
    cout <<RED <<"5" << RESET << GREEN << " |";
    for(int i = 0; i < 8; i++){
        if(game[4][i].is_empty()){
            cout << " - |";
        }
        else if(game[4][i].is_black()){
            cout << RESET << MAGENTA <<" X" << RESET << GREEN << " |";
        }
        else if(game[4][i].is_white()){
            cout << RESET << WHITE <<" O" << RESET << GREEN <<" |";
        }
    }
    cout << endl;
    cout<<"  |--- --- --- --- --- --- --- ---|" << endl;
    cout << RESET;
    cout << RED << "6" << RESET << GREEN << " |";
    for(int i = 0; i < 8; i++){
        if(game[5][i].is_empty()){
            cout << " - |";
        }
        else if(game[5][i].is_black()){
            cout << RESET << MAGENTA <<" X" << RESET << GREEN << " |";
        }
        else if(game[5][i].is_white()){
            cout << RESET << WHITE <<" O" << RESET << GREEN <<" |";
        }
    }
    cout << endl;
    cout<<"  |--- --- --- --- --- --- --- ---|" << endl;
    cout << RESET;
    cout << RED << "7" << RESET << GREEN << " |";
    for(int i = 0; i < 8; i++){
        if(game[6][i].is_empty()){
            cout << " - |";
        }
        else if(game[6][i].is_black()){
            cout << RESET << MAGENTA <<" X" << RESET << GREEN << " |";
        }
        else if(game[6][i].is_white()){
            cout << RESET << WHITE <<" O" << RESET << GREEN <<" |";
        }
    }
    cout << endl;
    cout<<"  |--- --- --- --- --- --- --- ---|" << endl;
    cout << RESET;
    cout << RED << "8" <<RESET << GREEN << " |";
    for(int i = 0; i < 8; i++){
        if(game[7][i].is_empty()){
            cout << " - |";
        }
        else if(game[7][i].is_black()){
            cout << RESET << MAGENTA <<" X" << RESET << GREEN << " |";
        }
        else if(game[7][i].is_white()){
            cout << RESET << WHITE <<" O" << RESET << GREEN <<" |";
        }
    }
    cout << endl;
    cout<<"   --- --- --- --- --- --- --- --- " << endl;
    cout << RESET;
}
void Othello::make_move(const std::string& move){
    bool n;
    bool s;
    bool w;
    bool e;
    bool nw;
    bool ne;
    bool se;
    bool sw;
    int column = toupper(move[0]) - 'A';
    int row = move[1] - '1';
    if(move == "XX"){
        ++passes;
        game::make_move(move);
    }
    else if(next_mover() == HUMAN){
        passes = 0;
        n = black_search_north(row, column);
        s = black_search_south(row, column);
        e = black_search_east(row,column);
        w = black_search_west(row,column);
        nw = black_search_nw(row, column);
        ne = black_search_ne(row,column);
        se = black_search_se(row,column);
        sw = black_search_sw(row,column);
        if(n){
            game[row][column].make_black();
            while(game[row-1][column].is_white()){
                game[row-1][column].make_black();
                --row;
            }
            row = toupper(move[1]) - '1';
        }
        if(s){
            game[row][column].make_black();
            while(game[row+1][column].is_white()){
                game[row+1][column].make_black();
                ++row; 
            }
            row = toupper(move[1]) - '1';
        }
        if(e){
            game[row][column].make_black();
            while(game[row][column+1].is_white()){
                game[row][column+1].make_black();
                ++column;
            }
            column = toupper(move[0]) - 'A';
        }
        if(w){
            game[row][column].make_black();
            while(game[row][column-1].is_white()){
                game[row][column-1].make_black();
                --column;
            }
            column = toupper(move[0]) - 'A';
        }
        if(nw){
            game[row][column].make_black();
            while(game[row-1][column-1].is_white()){
                game[row-1][column-1].make_black();
                --row;
                --column;
            }
            column = toupper(move[0]) - 'A';
            row = toupper(move[1]) - '1';
        }
        if(ne){
            game[row][column].make_black();
            while(game[row-1][column+1].is_white()){
                game[row-1][column+1].make_black();
                ++column;
                --row;
            }
            column = toupper(move[0]) - 'A';
            row = move[1] - '1';
        }
        if(se){
            game[row][column].make_black();
            while(game[row+1][column+1].is_white()){
                game[row+1][column+1].make_black();
                ++row;
                ++column;
            }
            column = toupper(move[0]) - 'A';
            row = toupper(move[1]) - '1';
        }
        if(sw){
            game[row][column].make_black();
            while(game[row+1][column-1].is_white()){
                game[row+1][column-1].make_black();
                --column;
                ++row;
            }
            column = toupper(move[0]) - 'A';
            row = toupper(move[1]) - '1';
        }
        game::make_move(move);
    }
    else if(next_mover() == COMPUTER){
        passes = 0;
        n = white_search_north(row, column);
        s = white_search_south(row, column);
        e = white_search_east(row,column);
        w = white_search_west(row,column);
        nw = white_search_nw(row, column);
        ne = white_search_ne(row,column);
        se = white_search_se(row,column);
        sw = white_search_sw(row,column);
        if(n){
            game[row][column].make_white();
            while(game[row-1][column].is_black()){
                game[row-1][column].make_white();
                --row;
            }
            row = move[1] - '1';
        }
        if(s){
            game[row][column].make_white();
            while(game[row+1][column].is_black()){
                game[row+1][column].make_white();
                ++row;
            }
            row = move[1] - '1';
        }
        if(e){
            game[row][column].make_white();
            while(game[row][column+1].is_black()){
                game[row][column+1].make_white();
                ++column;
            }
            column = move[0] - 'A';
        }
        if(w){
            game[row][column].make_white();
            while(game[row][column-1].is_black()){
                game[row][column-1].make_white();
                --column;
            }
            column = move[0] - 'A';
        }
        if(nw){
            game[row][column].make_white();
            while(game[row-1][column-1].is_black()){
                game[row-1][column-1].make_white();
                --row;
                --column;
            }
            column = move[0] - 'A';
            row = move[1] - '1';
        }
        if(ne){
            game[row][column].make_white();
            while(game[row-1][column+1].is_black()){
                game[row-1][column+1].make_white();
                ++column;
                --row;
            }
            column = move[0] - 'A';
            row = move[1] - '1';
        }
        if(se){
            game[row][column].make_white();
            while(game[row+1][column+1].is_black()){
                game[row+1][column+1].make_white();
                ++row;
                ++column;
            }
            column = move[0] - 'A';
            row = move[1] - '1';
        }
        if(sw){
            game[row][column].make_white();
            while(game[row+1][column-1].is_black()){
                game[row+1][column-1].make_white();
                --column;
                ++row;
            }
            column = move[0] - 'A';
            row = move[1] - '1';
        }
        game::make_move(move);
    }
}
bool Othello::is_legal(const std::string& move) const{
    bool north;
    bool south;
    bool west;
    bool east;
    bool nw;
    bool ne;
    bool sw;
    bool se;
    int column = toupper(move[0]) - 'A';
    int row = move[1] - '1';
    if(move == "XX"){
        return true;
    }
    else if(next_mover() == HUMAN) {
        north = black_search_north(row, column);
        south = black_search_south(row,column);
        east = black_search_east(row, column);
        west = black_search_west(row, column);
        nw = black_search_nw(row, column);
        ne = black_search_ne(row, column);
        sw = black_search_sw(row, column);
        se = black_search_se(row, column);
        if(north || south || east || west || nw || ne || se|| sw){
            return true;
        }
        else{
            return false;
        }
    }
    else if(next_mover() == COMPUTER){
        north = white_search_north(row, column);
        south = white_search_south(row,column);
        east = white_search_east(row, column);
        west = white_search_west(row, column);
        nw = white_search_nw(row, column);
        ne = white_search_ne(row, column);
        sw = white_search_sw(row, column);
        se = white_search_se(row, column);
        if(north || south || east || west || nw || ne || se|| sw){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        cout << "Something Is Very Wrong" << endl;
        return false;
    }
}
bool Othello::black_search_north(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row-1][column].is_empty()){
        return false;
    }
    else if(game[row-1][column].is_black()){
        return false;
    }
    else if(game[row-1][column].is_white()){
        while(game[row-1][column].is_white() && row-1 >= 1){
            --row;
        } 
        if(game[row-1][column].is_black()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::black_search_south(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row+1][column].is_empty()){
        return false;
    }
    else if(game[row+1][column].is_black()){
        return false;
    }
    else if(game[row+1][column].is_white()){
        while(game[row+1][column].is_white() && row+1 <= 6){
            ++row;
        } 
        if(game[row+1][column].is_black()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::black_search_east(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row][column+1].is_empty()){
        return false;
    }
    else if(game[row][column+1].is_black()){
        return false;
    }
    else if(game[row][column+1].is_white()){
        while(game[row][column+1].is_white() && column+1 <= 6){
            ++column;
        } 
        if(game[row][column+1].is_black()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::black_search_west(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row][column-1].is_empty()){
        return false;
    }
    else if(game[row][column-1].is_black()){
        return false;
    }
    else if(game[row][column-1].is_white()){
        while(game[row][column-1].is_white() && column-1 >= 1){
            --column;
        } 
        if(game[row][column-1].is_black()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::black_search_nw(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row-1][column-1].is_empty()){
        return false;
    }
    else if(game[row-1][column-1].is_black()){
        return false;
    }
    else if(game[row-1][column-1].is_white()){
        while(game[row-1][column-1].is_white() && column-1 >= 1 && row-1 >=1){
            --column;
            --row;
        } 
        if(game[row-1][column-1].is_black()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::black_search_sw(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row+1][column-1].is_empty()){
        return false;
    }
    else if(game[row+1][column-1].is_black()){
        return false;
    }
    else if(game[row+1][column-1].is_white()){
        while(game[row+1][column-1].is_white() && column-1 >= 1 && row+1 <= 6){
            --column;
            ++row;
        } 
        if(game[row+1][column-1].is_black()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::black_search_ne(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row-1][column+1].is_empty()){
            return false;
        }
    else if(game[row-1][column+1].is_black()){
        return false;
    }
    else if(game[row-1][column+1].is_white()){
        while(game[row-1][column+1].is_white() && column+1 <= 6 && row-1 >= 1){
            ++column;
            --row;
        } 
        if(game[row-1][column+1].is_black()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::black_search_se(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row+1][column+1].is_empty()){
        return false;
    }
    else if(game[row+1][column+1].is_black()){
        return false;
    }
    else if(game[row+1][column+1].is_white()){
        while(game[row+1][column+1].is_white() && column+1 <= 6 && row+1 <= 6){
            ++column;
            ++row;
        } 
        if(game[row+1][column+1].is_black()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::white_search_north(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row-1][column].is_empty()){
        return false;
    }
    else if(game[row-1][column].is_white()){
        return false;
    }
    else if(game[row-1][column].is_black()){
        while(game[row-1][column].is_black() && row-1 >= 1){
            --row;
        } 
        if(game[row-1][column].is_white()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::white_search_south(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row+1][column].is_empty()){
        return false;
    }
    else if(game[row+1][column].is_white()){
        return false;
    }
    else if(game[row+1][column].is_black()){
        while(game[row+1][column].is_black() && row+1 <= 6){
            ++row;
        } 
        if(game[row+1][column].is_white()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::white_search_east(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row][column+1].is_empty()){
        return false;
    }
    else if(game[row][column+1].is_white()){
        return false;
    }
    else if(game[row][column+1].is_black()){
        while(game[row][column+1].is_black() && column+1 <= 6){
            ++column;
        } 
        if(game[row][column+1].is_white()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::white_search_west(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row][column-1].is_empty()){
        return false;
    }
    else if(game[row][column-1].is_white()){
        return false;
    }
    else if(game[row][column-1].is_black()){
        while(game[row][column-1].is_black() && column-1 >= 1){
            --column;
        } 
        if(game[row][column-1].is_white()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::white_search_nw(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row-1][column-1].is_empty()){
        return false;
    }
    else if(game[row-1][column-1].is_white()){
        return false;
    }
    else if(game[row-1][column-1].is_black()){
        while(game[row-1][column-1].is_black() && column-1 >= 1 && row-1 >=1){
            --column;
            --row;
        } 
        if(game[row-1][column-1].is_white()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::white_search_sw(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row+1][column-1].is_empty()){
        return false;
    }
    else if(game[row+1][column-1].is_white()){
        return false;
    }
    else if(game[row+1][column-1].is_black()){
        while(game[row+1][column-1].is_black() && column-1 >= 1 && row+1 <= 6){
            --column;
            ++row;
        } 
        if(game[row+1][column-1].is_white()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::white_search_ne(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row-1][column+1].is_empty()){
            return false;
        }
    else if(game[row-1][column+1].is_white()){
        return false;
    }
    else if(game[row-1][column+1].is_black()){
        while(game[row-1][column+1].is_black() && column+1 <= 6 && row-1 >= 1){
            ++column;
            --row;
        } 
        if(game[row-1][column+1].is_white()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::white_search_se(int row, int column) const{
    if(!game[row][column].is_empty()){
        return false;
    }
    else if(game[row+1][column+1].is_empty()){
        return false;
    }
    else if(game[row+1][column+1].is_white()){
        return false;
    }
    else if(game[row+1][column+1].is_black()){
        while(game[row+1][column+1].is_black() && column+1 <= 6 && row+1 <= 6){
            ++column;
            ++row;
        } 
        if(game[row+1][column+1].is_white()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Othello::is_game_over( ) const{
    
    std::queue<std::string> moves;
    bool slot = false;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(game[i][j].is_empty()){
                slot = true;
            }
        }
    }
    if(slot){
        if(passes == 2){
            cout << "NEITHER PLAYER CAN MOVE GAME OVER" << endl;
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return true;
    }
    
}
void Othello::compute_moves(std::queue<std::string>& moves) const{
    string move;
    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            move = i +'A';
            move += j + '1';
            if(is_legal(move)){
                moves.push(move);
            }
        }
    }
    if(moves.empty()){
        moves.push("XX");
    }
}
std::string Othello::get_user_move( ) const{
    string ans;
    queue<string> moves;
    compute_moves(moves);
    ans = moves.front();
    if(ans == "XX"){
        if(next_mover() == HUMAN){
            cout << "Human Has No Available Moves Turn Forfeited" << endl;
        }
        return ans;
    }
	else{
        cout << "Available Moves: ";
        while(!moves.empty()){
            cout << moves.front() << " ";
            moves.pop();
        }
        cout << endl;
	    return game::get_user_move();
    }
}
int Othello::evaluate( ) const{
    int white_counter = 0;
    int black_counter = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(game[i][j].is_white()){
                ++white_counter;
            }
            else if(game[i][j].is_black()){
                ++black_counter;
            }
        }
    }
    return white_counter - black_counter;
}
main_savitch_14::game::who Othello::winning() const{
    int value = evaluate();
    if(value < 0){
        return HUMAN;
    }
    else if(value > 0){
        return COMPUTER;
    }
    else{
        return NEUTRAL;
    }
}
