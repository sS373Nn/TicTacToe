#include "bitwise-engine/src/MoveGenerator.hpp"
#include <iostream>
#include <bitset>

void print_board_state(uint64_t board_state) {
    std::cout << "Board state: " << std::bitset<18>(board_state) << std::endl;
    std::cout << "Board visualization:" << std::endl;
    
    for (int i = 0; i < 9; i++) {
        uint8_t square_value = (board_state >> (i * 2)) & 0b11;
        char display = (square_value == 0) ? '.' : 
                      (square_value == 1) ? 'X' : 'O';
        std::cout << display << " ";
        if (i % 3 == 2) std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Testing Move Generation System..." << std::endl;
    
    // Create a test board state: X at position 0, O at position 4 (center)
    // Position 0 = player 1 (01), Position 4 = player 2 (10)
    uint64_t test_board = 0b000000001000000001; // 18 bits: pos4=10, pos0=01
    
    std::cout << "Initial board state:" << std::endl;
    print_board_state(test_board);
    
    // Generate possible moves for player 1
    std::cout << "Generating moves for Player 1..." << std::endl;
    auto moves = MoveGenerator::generate_possible_moves(test_board, 0b01);
    
    std::cout << "Found " << moves.size() << " possible moves:" << std::endl;
    for (size_t i = 0; i < moves.size(); i++) {
        std::cout << "Move " << i + 1 << ":" << std::endl;
        print_board_state(moves[i]);
    }
    
    return 0;
}