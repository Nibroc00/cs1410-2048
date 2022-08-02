// Corbin Park
// 11/26/19

#ifndef _2048_H
#define _2048_H

#include <iostream>
#include <string>

//different types of gameStates
enum gameState {Playing, Lost, Won};

//objects placed into the board
struct gamePiece {
    //value gamePiece holds
    size_t value = 0;
};


//gameBoard for the game 2048
class gameBoard {
    private:


    public:
        //tracker for gameState
        gameState _2048State = Playing;

        //array of gamePieces (represents the board)
        gamePiece spaces[16];

        //changes gamePiece values into string format and outputs 
        void print_gameBoard(std::ostream& out = std::cout);
        
        //adds a gamepiece to board
        void add_gamePiece();

        //moves all pieces left while combining gamePieces of the same value
        //returns true if any pieces moved
        bool move_left();

        //moves all pieces right while combining gamePieces of the same value
        //returns true if any pieces moved
        bool move_right();

        //moves all pieces up while combining gamePieces of the same value
        //returns true if any pieces moved
        bool move_up();

        //moves all pieces down while combining gamePieces of the same value
        //returns true if any pieces moved
        bool move_down();

        //checks the state the game is in
        //changes _2048State if a gamePiece has reached 2048 or if board is full
        void check_gameState();

        //if an array is passed in constructor initializes board to array values
        gameBoard(size_t spaces_in[16]);
        gameBoard();


};


//function to call to play the game
void play_2048(std::ostream& out = std::cout);

//function to call to play the with loading preset gamePieces
//loaded pieces can only be of values {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048}
//or else default to 0
void play_2048(size_t spaces_in[16], std::ostream& out = std::cout);


#endif