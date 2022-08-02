// Corbin Park
// 11/26/19

#include "2048.h"
#include <stdlib.h> //srand, rand
#include <time.h> // time
#include <string>
#include <iostream>
#include<ios> // for <streamsize> 
#include<limits> // for numeric_limits



void gameBoard::print_gameBoard(std::ostream& out) {
    std::string values_output[16];

    //formats each gamePiece value to fit inside boxes for output
    for (int i = 0; i < 16; i++) {
        if (spaces[i].value == 0) {
            values_output[i] = "    ";
        }
        else {
            
            switch (std::to_string(spaces[i].value).length())
            {
                case 1:
                    values_output[i] = "  ";
                    values_output[i] += std::to_string(spaces[i].value);
                    values_output[i] += " ";
                    break;
                case 2:
                    values_output[i] = " " ;
                    values_output[i] += std::to_string(spaces[i].value);
                    values_output[i] += " ";
                    break;
                case 3: 
                    values_output[i] = " ";
                    values_output[i] += std::to_string(spaces[i].value);
                    break;
                case 4:
                    values_output[i] = std::to_string(spaces[i].value);
                    break;
            }
        }
    }

    out << std::endl
        << " ___________________________ \n"
        << "|      |      |      |      | \n" 
        << "| " << values_output[0] << " | " << values_output[1]  << " | " << values_output[2] << " | " << values_output[3] << " | \n" 
        << "|______|______|______|______| \n" 
        << "|      |      |      |      | \n" 
        << "| " << values_output[4] << " | " << values_output[5]  << " | " << values_output[6] << " | " << values_output[7] << " | \n"  
        << "|______|______|______|______| \n" 
        << "|      |      |      |      | \n" 
        << "| " << values_output[8] << " | " << values_output[9]  << " | " << values_output[10] << " | " << values_output[11] << " | \n"  
        << "|______|______|______|______| \n" 
        << "|      |      |      |      | \n" 
        << "| " << values_output[12] << " | " << values_output[13]  << " | " << values_output[14] << " | " << values_output[15] << " | \n"  
        << "|______|______|______|______| \n";
}

void gameBoard::add_gamePiece() {
    bool added_tile = false;
    srand(time(NULL));
    //randomly picks a spot until it finds an empty one
    //then adds gamePiece
    while (added_tile == false) {
        int random_space = rand() % 16;
        if (spaces[random_space].value == 0) {
            int random_bool = rand() % 2;
            switch (random_bool) {
                case 0:
                    spaces[random_space].value = 2;
                    added_tile = true;
                    break;
                case 1:
                    spaces[random_space].value = 4;
                    added_tile = true;
                    break;
            }
        }
    }
}


bool gameBoard::move_left() {
    bool moved = false;
    for (int n = 0; n < 3; n++) {
        for (int i = 0; i < 16; i++) {
            if (spaces[i].value != 0) {
                if(i != 0 && i != 4 && i != 8 && i != 12) {
                    if (spaces[i - 1].value > 0) {
                        if (spaces[i - 1].value == spaces[i].value) {
                            spaces[i - 1].value += spaces[i].value;
                            spaces[i].value = 0;
                            moved = true;
                        }
                    }
                    else {
                        spaces[i - 1].value = spaces[i].value;
                        spaces[i].value = 0;
                        moved = true;
                    }
                }
            }
        }
    }
    return moved;
}
bool gameBoard::move_right() {
    bool moved = false;
    for (int n = 0; n < 3; n++) {
        for (int i = 15; i >= 0; i--) {
            if (spaces[i].value != 0) {
                if(i != 3 && i != 7 && i != 11 && i != 15) {
                    if (spaces[i + 1].value > 0) {
                        if (spaces[i + 1].value == spaces[i].value) {
                            spaces[i + 1].value += spaces[i].value;
                            spaces[i].value = 0;
                            moved = true;
                        }
                    }
                    else {
                        spaces[i + 1].value = spaces[i].value;
                        spaces[i].value = 0;
                        moved = true;
                    }
                }
            }
        }
    }
    return moved;
}
bool gameBoard::move_up() {
    bool moved = false;
    for (int n = 0; n < 3; n++) {
        for (int i = 0; i < 16; i++) {
            if (spaces[i].value != 0) {
                if(i != 0 && i != 1 && i != 2 && i != 3) {
                    if (spaces[i - 4].value > 0) {
                        if (spaces[i - 4].value == spaces[i].value) {
                            spaces[i - 4].value += spaces[i].value;
                            spaces[i].value = 0;
                            moved = true;
                        }
                    }
                    else {
                        spaces[i - 4].value = spaces[i].value;
                        spaces[i].value = 0;
                        moved = true;
                    }
                }
            }
        }
    }
    return moved;
}

bool gameBoard::move_down() {
    bool moved = false;
    for (int n = 0; n < 3; n++) {
        for (int i = 16; i >= 0; i--) {
            if (spaces[i].value != 0) {
                if(i != 12 && i != 13 && i != 14 && i != 15) {
                    if (spaces[i + 4].value > 0) {
                        if (spaces[i + 4].value == spaces[i].value) {
                            spaces[i + 4].value += spaces[i].value;
                            spaces[i].value = 0;
                            moved = true;
                        }
                    }
                    else {
                        spaces[i + 4].value = spaces[i].value;
                        spaces[i].value = 0;
                        moved = true;
                    }
                }
            }
        }
    }
    return moved;
}


void gameBoard::check_gameState() {
    //if boared is full set gameState to Lost
    if (spaces[0].value > 0 && spaces[1].value > 0 && spaces[2].value > 0 && spaces[3].value > 0 && spaces[4].value > 0 && spaces[5].value > 0 && spaces[6].value > 0 && spaces[7].value > 0 && spaces[8].value > 0 && spaces[9].value > 0 && spaces[10].value > 0 && spaces[11].value > 0 && spaces[12].value > 0 && spaces[13].value > 0 && spaces[14].value > 0 && spaces[15].value > 0) {
        _2048State = Lost;
    }
    //if a gamePiece has value of 2048 or hight set gameState to Won
    for (int i = 0; i < 16; i++) {
        if (spaces[i].value >= 2048) {
            _2048State = Won;
        }
    }
}

gameBoard::gameBoard(size_t spaces_in[16]) {
    //checks that each value is a valid value for a gamePiece
    for (int i = 0; i < 16; i++) {
        if (spaces_in[i] > 0) {
        switch (spaces_in[i]) {
            case 2:
                spaces[i].value = spaces_in[i];
                break;
            case 4:
                spaces[i].value = spaces_in[i];
                break;
            case 8:
                spaces[i].value = spaces_in[i];
                break;
            case 16:
                spaces[i].value = spaces_in[i];
                break;
            case 32:
                spaces[i].value = spaces_in[i];
                break;
            case 64:
                spaces[i].value = spaces_in[i];
                break;
            case 128:
                spaces[i].value = spaces_in[i];
                break;
            case 256:
                spaces[i].value = spaces_in[i];
                break;
            case 512:
                spaces[i].value = spaces_in[i];
                break;
            case 1024:
                spaces[i].value = spaces_in[i];
                break;
            case 2048:
                spaces[i].value = spaces_in[i];
                break;
            default:
                break;
        }
    }
    }
    
}



gameBoard::gameBoard() {

}


void play_2048(size_t spaces_in[16], std::ostream& out) {
    gameBoard _2048(spaces_in);


    //check if array passed in initialized the board to an empty/default board
    int counter = 0;
    for (int i = 0; i < 16; i++) {
        if (_2048.spaces[i].value == 0) {
        counter++;
        }
    }
    //if empty board add 2 gamePieces
    if (counter == 16) {
        _2048.add_gamePiece();
        _2048.add_gamePiece();
    }


    //actual game loop
    while (_2048._2048State == Playing) { 
        bool moved = true;
        _2048.print_gameBoard();
        if (moved == true && _2048._2048State == Playing) {
            moved = false;

            //get char for movement input
            char a;
            std::cin >> a;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            //switch statement for input givin
            switch (a) {
                case 'w':
                    moved = _2048.move_up();
                    break;
                case 'a':
                    moved = _2048.move_left();
                    break;
                case 's':
                    moved = _2048.move_down();
                    break;
                case 'd':
                    moved = _2048.move_right();
                    break;
                default:
                    out << "Please use keys w, a, s, d" << std::endl;
            }
        }
        _2048.check_gameState();
        if (moved == true && _2048._2048State == Playing) {
            _2048.add_gamePiece();
        }
    }

    _2048.print_gameBoard();

    
    //if game is lost
    if (_2048._2048State == Lost) {
        out << std::endl << std::endl << "You Lost" << std::endl << std::endl;
    }

    //if game is won
    else if (_2048._2048State == Won) {
        out << std::endl << std::endl << "You Win" << std::endl << std::endl;
    }
}

void play_2048(std::ostream& out) {
    gameBoard _2048;

    //starts game with two gamePieces
    _2048.add_gamePiece();
    _2048.add_gamePiece();

    //actual game loop
    while (_2048._2048State == Playing) { 
        bool moved = true;
        _2048.print_gameBoard();
        if (moved == true && _2048._2048State == Playing) {
            moved = false;

            //get char for movement input
            char a;
            std::cin >> a;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            //switch statement for input givin
            switch (a) {
                case 'w':
                    moved = _2048.move_up();
                    break;
                case 'a':
                    moved = _2048.move_left();
                    break;
                case 's':
                    moved = _2048.move_down();
                    break;
                case 'd':
                    moved = _2048.move_right();
                    break;
                default:
                    out << "Please use keys w, a, s, d" << std::endl;
            }
        }
        _2048.check_gameState();
        if (moved == true && _2048._2048State == Playing) {
            _2048.add_gamePiece();
        }
    }

    _2048.print_gameBoard();


    //if game is lost
    if (_2048._2048State == Lost) {
        out << std::endl << std::endl << "You Lost" << std::endl << std::endl;
    }

    //if game is won
    else if (_2048._2048State == Won) {
        out << std::endl << std::endl << "You Win" << std::endl << std::endl;
    }
}