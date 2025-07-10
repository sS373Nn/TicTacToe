#include "bitwise-engine/src/DecisionEngine.hpp"
#include "bitwise-engine/src/memory.hpp"
#include <iostream>

void test_ai_moves() {
    std::cout << "=== Testing AI Move Generation ===" << std::endl;
    
    // Clear memory
    long_term_memory.clear();
    short_term_memory.clear();
    
    // Test 1: AI as Player 1 on empty board
    uint64_t empty_board = 0;
    uint64_t move1 = DecisionEngine::get_best_move(empty_board, 1);
    std::cout << "AI as Player 1 move: " << move1 << std::endl;
    
    if (move1 == 0) {
        std::cout << "❌ ERROR: AI cannot make move as Player 1!" << std::endl;
        return;
    } else {
        std::cout << "✅ AI can make moves as Player 1" << std::endl;
    }
    
    // Test 2: AI as Player 2 on empty board  
    uint64_t move2 = DecisionEngine::get_best_move(empty_board, 2);
    std::cout << "AI as Player 2 move: " << move2 << std::endl;
    
    if (move2 == 0) {
        std::cout << "❌ ERROR: AI cannot make move as Player 2!" << std::endl;
        return;
    } else {
        std::cout << "✅ AI can make moves as Player 2" << std::endl;
    }
    
    // Test 3: Check if moves are different
    if (move1 == move2) {
        std::cout << "❌ WARNING: AI makes identical moves for both players" << std::endl;
    } else {
        std::cout << "✅ AI makes different moves for different players" << std::endl;
    }
    
    // Test 4: Verify player markers are correct
    bool found_p1_marker = false, found_p2_marker = false;
    
    for (int i = 0; i < 9; i++) {
        uint64_t mask = 3ULL << (i * 2);
        uint8_t val1 = (move1 & mask) >> (i * 2);
        uint8_t val2 = (move2 & mask) >> (i * 2);
        
        if (val1 == 1) found_p1_marker = true;
        if (val2 == 2) found_p2_marker = true;
    }
    
    if (found_p1_marker) {
        std::cout << "✅ Player 1 move contains correct marker (1)" << std::endl;
    } else {
        std::cout << "❌ Player 1 move missing correct marker!" << std::endl;
    }
    
    if (found_p2_marker) {
        std::cout << "✅ Player 2 move contains correct marker (2)" << std::endl;
    } else {
        std::cout << "❌ Player 2 move missing correct marker!" << std::endl;
    }
    
    std::cout << "\n=== Memory Status ===" << std::endl;
    std::cout << "Long-term memory entries: " << long_term_memory.size() << std::endl;
    std::cout << "Short-term memory entries: " << short_term_memory.size() << std::endl;
}

int main() {
    test_ai_moves();
    return 0;
}