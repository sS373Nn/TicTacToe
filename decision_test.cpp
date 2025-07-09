#include "bitwise-engine/src/DecisionEngine.hpp"
#include <iostream>
#include <bitset>

void print_board_state(uint64_t board_state) {
    std::cout << "Board: " << std::bitset<18>(board_state) << " -> ";
    for (int i = 0; i < 9; i++) {
        uint8_t square_value = (board_state >> (i * 2)) & 0b11;
        char display = (square_value == 0) ? '.' : (square_value == 1) ? 'X' : 'O';
        std::cout << display;
        if (i % 3 == 2 && i < 8) std::cout << "|";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Testing Memory-Based Decision Engine..." << std::endl;
    
    // Create test board: X at position 0, O at position 4
    uint64_t test_board = 0b000000001000000001;
    
    std::cout << "\nInitial board state:" << std::endl;
    print_board_state(test_board);
    
    // Add some test memories to demonstrate rating system
    std::cout << "\nAdding test memories..." << std::endl;
    
    // Simulate that a particular move led to good outcomes
    uint64_t good_move = 0b000000001000000101; // X at pos 0,1 and O at pos 4
    add_positive_outcome(good_move);
    add_positive_outcome(good_move);
    add_positive_outcome(good_move);
    
    // Simulate that another move led to bad outcomes
    uint64_t bad_move = 0b000000001000010001; // X at pos 0,2 and O at pos 4
    deduct_negative_outcome(bad_move);
    deduct_negative_outcome(bad_move);
    
    // Rate all possible moves
    std::cout << "\nRating all possible moves for Player 1:" << std::endl;
    auto rated_moves = DecisionEngine::rate_all_moves(test_board, 0b01);
    
    for (size_t i = 0; i < rated_moves.size(); i++) {
        std::cout << "Move " << i + 1 << " (square " << (int)rated_moves[i].square_index << "): ";
        print_board_state(rated_moves[i].board_state);
        std::cout << "  Long-term: " << rated_moves[i].long_term_rating 
                  << ", Short-term: " << (int)rated_moves[i].short_term_rating << std::endl;
    }
    
    // Get the best move
    uint64_t best_move = DecisionEngine::get_best_move(test_board, 0b01);
    std::cout << "\nBest move selected:" << std::endl;
    print_board_state(best_move);
    
    return 0;
}