#include "bitwise-engine/src/memory.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Memory System ===" << std::endl;
    
    // Test initial state
    std::cout << "Initial memory sizes:" << std::endl;
    std::cout << "Long-term: " << long_term_memory.size() << std::endl;
    std::cout << "Short-term: " << short_term_memory.size() << std::endl;
    
    // Test adding positive outcome
    uint64_t test_board = 0x12345;
    std::cout << "\nAdding positive outcome for board: " << test_board << std::endl;
    add_positive_outcome(test_board);
    
    std::cout << "After positive outcome:" << std::endl;
    std::cout << "Long-term: " << long_term_memory.size() << std::endl;
    std::cout << "Short-term: " << short_term_memory.size() << std::endl;
    
    if (long_term_memory.count(test_board)) {
        std::cout << "Long-term value: " << long_term_memory[test_board] << std::endl;
        std::cout << "Short-term value: " << (int)short_term_memory[test_board] << std::endl;
    }
    
    // Test adding negative outcome
    std::cout << "\nAdding negative outcome for same board..." << std::endl;
    deduct_negative_outcome(test_board);
    
    std::cout << "After negative outcome:" << std::endl;
    std::cout << "Long-term value: " << long_term_memory[test_board] << std::endl;
    std::cout << "Short-term value: " << (int)short_term_memory[test_board] << std::endl;
    
    return 0;
}