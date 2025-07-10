#include "bitwise-engine/src/DecisionEngine.hpp"
#include <iostream>

int main() {
    // Test if AI can make moves as both players
    uint64_t empty_board = 0;
    
    std::cout << "Testing AI move generation..." << std::endl;
    
    // Test AI as player 1
    uint64_t move1 = DecisionEngine::get_best_move(empty_board, 1);
    std::cout << "AI as player 1 move: " << move1 << std::endl;
    
    // Test AI as player 2  
    uint64_t move2 = DecisionEngine::get_best_move(empty_board, 2);
    std::cout << "AI as player 2 move: " << move2 << std::endl;
    
    if (move1 == 0) std::cout << "ERROR: AI cannot move as player 1!" << std::endl;
    if (move2 == 0) std::cout << "ERROR: AI cannot move as player 2!" << std::endl;
    
    return 0;
}