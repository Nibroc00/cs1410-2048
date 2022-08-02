
#include "2048.h"
#include <queue>
#include <iostream>
#include <string>
#include "doctest.h"
#include <sstream>

TEST_CASE("gameBoard") {
    gameBoard test_board;
    std::string board;
    board = "\n";
    board += " ___________________________ \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    std::stringstream test;  
    test_board.print_gameBoard(test);
    REQUIRE(test.str() == board);
}

TEST_CASE("gameBoard constructor") {
    size_t a[16] {2, 2, 0, 3, 4, 8, 9, 0, 100, 64, 0, 0, 0, 0, 0, 0};
    gameBoard test_board(a);
    std::string board;
    board = "\n";
    board += " ___________________________ \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|   2  |   2  |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|   4  |   8  |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|      |  64  |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    std::stringstream test;  
    test_board.print_gameBoard(test);
    REQUIRE(test.str() == board);
}

TEST_CASE("move_functions") {
    size_t a[16] {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    gameBoard test_board(a);
    std::string board;
    board = "\n";
    board += " ___________________________ \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|   2  |      |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    std::stringstream test; 
    test_board.move_left();
    test_board.print_gameBoard(test);
    REQUIRE(test.str() == board);


    size_t b[16] {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    gameBoard test_board_b(b);
    std::string board_b;
    board_b = "\n";
    board_b += " ___________________________ \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|______|______|______|______| \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|      |      |      |   2  | \n" ;
    board_b += "|______|______|______|______| \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|______|______|______|______| \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|______|______|______|______| \n" ;
    test.str("");  
    test_board_b.move_right();
    test_board_b.print_gameBoard(test);
    REQUIRE(test.str() == board_b);

    size_t c[16] {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    gameBoard test_board_c(c);
    std::string board_c;
    board_c = "\n";
    board_c += " ___________________________ \n" ;
    board_c += "|      |      |      |      | \n" ;
    board_c += "|      |      |      |      | \n" ;
    board_c += "|______|______|______|______| \n" ;
    board_c += "|      |      |      |      | \n" ;
    board_c += "|      |      |      |      | \n" ;
    board_c += "|______|______|______|______| \n" ;
    board_c += "|      |      |      |      | \n" ;
    board_c += "|      |      |      |      | \n" ;
    board_c += "|______|______|______|______| \n" ;
    board_c += "|      |      |      |      | \n" ;
    board_c += "|      |   2  |      |      | \n" ;
    board_c += "|______|______|______|______| \n" ;
    test.str(""); 
    test_board_c.move_down();
    test_board_c.print_gameBoard(test);
    REQUIRE(test.str() == board_c);

    size_t d[16] {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0};
    gameBoard test_board_d(d);
    std::string board_d;
    board_d = "\n";
    board_d += " ___________________________ \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|      |   2  |      |      | \n" ;
    board_d += "|______|______|______|______| \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|______|______|______|______| \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|______|______|______|______| \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|______|______|______|______| \n" ;
    test.str(""); 
    test_board_d.move_up();
    test_board_d.print_gameBoard(test);
    REQUIRE(test.str() == board_d);
}


TEST_CASE("move_functions combining") {
    size_t a[16] {0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    gameBoard test_board(a);
    std::string board;
    board = "\n";
    board += " ___________________________ \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|      |      |      |   4  | \n" ;
    board += "|______|______|______|______| \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|      |      |      |      | \n" ;
    board += "|______|______|______|______| \n" ;
    std::stringstream test; 
    test_board.move_right();
    test_board.print_gameBoard(test);
    REQUIRE(test.str() == board);

    size_t b[16] {0, 2, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    gameBoard test_board_b(b);
    std::string board_b;
    board_b = "\n";
    board_b += " ___________________________ \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|   2  |   8  |      |      | \n" ;
    board_b += "|______|______|______|______| \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|______|______|______|______| \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|______|______|______|______| \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|______|______|______|______| \n" ;
    test.str("");  
    test_board_b.move_left();
    test_board_b.print_gameBoard(test);
    REQUIRE(test.str() == board_b);

    size_t c[16] {0, 8, 0, 0, 0, 8, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0};
    gameBoard test_board_c(c);
    std::string board_c;
    board_c = "\n";
    board_c += " ___________________________ \n" ;
    board_c += "|      |      |      |      | \n" ;
    board_c += "|      |      |      |      | \n" ;
    board_c += "|______|______|______|______| \n" ;
    board_c += "|      |      |      |      | \n" ;
    board_c += "|      |      |      |      | \n" ;
    board_c += "|______|______|______|______| \n" ;
    board_c += "|      |      |      |      | \n" ;
    board_c += "|      |      |      |      | \n" ;
    board_c += "|______|______|______|______| \n" ;
    board_c += "|      |      |      |      | \n" ;
    board_c += "|      |  32  |      |      | \n" ;
    board_c += "|______|______|______|______| \n" ;
    test.str(""); 
    test_board_c.move_down();
    test_board_c.print_gameBoard(test);
    REQUIRE(test.str() == board_c);

    size_t d[16] {0, 0, 0, 64, 0, 0, 0, 64, 0, 0, 0, 128, 0, 0, 0, 0};
    gameBoard test_board_d(d);
    std::string board_d;
    board_d = "\n";
    board_d += " ___________________________ \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|      |      |      |  256 | \n" ;
    board_d += "|______|______|______|______| \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|______|______|______|______| \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|______|______|______|______| \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|______|______|______|______| \n" ;
    test.str(""); 
    test_board_d.move_up();
    test_board_d.print_gameBoard(test);
    REQUIRE(test.str() == board_d);
}

TEST_CASE("add_gamePiece") {
    size_t a[16] {0, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4};
    gameBoard test_board(a);
    std::string board_d;
    board_d = "\n";
    board_d += " ___________________________ \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|   2  |   4  |   2  |   4  | \n" ;
    board_d += "|______|______|______|______| \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|   2  |   4  |   2  |   4  | \n" ;
    board_d += "|______|______|______|______| \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|   2  |   4  |   2  |   4  | \n" ;
    board_d += "|______|______|______|______| \n" ;
    board_d += "|      |      |      |      | \n" ;
    board_d += "|   2  |   4  |   2  |   4  | \n" ;
    board_d += "|______|______|______|______| \n" ;
    std::string board_b;
    board_b = "\n";
    board_b += " ___________________________ \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|   4  |   4  |   2  |   4  | \n" ;
    board_b += "|______|______|______|______| \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|   2  |   4  |   2  |   4  | \n" ;
    board_b += "|______|______|______|______| \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|   2  |   4  |   2  |   4  | \n" ;
    board_b += "|______|______|______|______| \n" ;
    board_b += "|      |      |      |      | \n" ;
    board_b += "|   2  |   4  |   2  |   4  | \n" ;
    board_b += "|______|______|______|______| \n" ;

    std::stringstream test;
    test_board.add_gamePiece();
    test_board.print_gameBoard(test);
    bool z = false;
    if (test.str() == board_b || test.str() == board_d) {
        z = true;
    }
    REQUIRE(z);
}

TEST_CASE("lose condition") {
    size_t a[16] {0, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4};
    gameBoard test_board(a);
    test_board.check_gameState();
    REQUIRE(test_board._2048State == Playing);
    test_board.add_gamePiece();
    test_board.check_gameState();
    REQUIRE(test_board._2048State == Lost);
}


TEST_CASE("win condition") {
    size_t a[16] {512, 512, 512, 512,};
    gameBoard test_board(a);
    test_board.check_gameState();
    REQUIRE(test_board._2048State == Playing);
    test_board.move_right();
    test_board.check_gameState();
    REQUIRE(test_board._2048State == Won);
}

