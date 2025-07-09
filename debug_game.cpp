#include "bitwise-engine/src/GameSimulator.hpp"
#include <iostream>
#include <bitset>

void print_board_visual(uint64_t board_state) {
    std::cout << "Board state: " << std::bitset<18>(board_state) << std::endl;
    std::cout << "Visual:" << std::endl;
    for (int i = 0; i < 9; i++) {
        uint8_t square_value = (board_state >> (i * 2)) & 0b11;
        char display = (square_value == 0) ? '.' : (square_value == 1) ? 'X' : 'O';
        std::cout << display << " ";
        if (i % 3 == 2) std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== DEBUG: Single Game Analysis ===" << std::endl;
    
    uint64_t board_state = 0;
    uint8_t current_player = 0b01; // Player 1 starts
    int move_count = 0;
    
    std::cout << "Initial board:" << std::endl;
    print_board_visual(board_state);
    
    while (move_count < 10) { // Safety limit
        std::cout << "=== Move " << (move_count + 1) << " - Player " << (current_player == 0b01 ? 1 : 2) << " ===" << std::endl;
        
        // Check game state
        GameResult result = GameSimulator::check_game_state(board_state);
        if (result != GameResult::DRAW || GameSimulator::is_board_full(board_state)) {
            std::cout << "Game over! Result: " << (int)result << std::endl;
            break;
        }
        
        // Generate possible moves
        auto possible_moves = MoveGenerator::generate_possible_moves(board_state, current_player);
        std::cout << "Possible moves: " << possible_moves.size() << std::endl;
        
        if (possible_moves.empty()) {
            std::cout << "No moves available!" << std::endl;
            break;
        }
        
        // Get best move
        uint64_t best_move = DecisionEngine::get_best_move(board_state, current_player);
        std::cout << "Best move selected:" << std::endl;
        print_board_visual(best_move);
        
        // Check if move was actually made
        if (best_move == board_state) {
            std::cout << "No move was made! Something is wrong." << std::endl;
            break;
        }
        
        board_state = best_move;
        current_player = (current_player == 0b01) ? 0b10 : 0b01;
        move_count++;
    }
    
    std::cout << "Final board:" << std::endl;
    print_board_visual(board_state);
    
    return 0;
}