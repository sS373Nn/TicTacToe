#include "bitwise-engine/src/GameSimulator.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Single Training Game ===" << std::endl;
    
    // Test memory before
    std::cout << "Memory before game:" << std::endl;
    std::cout << "Long-term: " << long_term_memory.size() << std::endl;
    std::cout << "Short-term: " << short_term_memory.size() << std::endl;
    
    // Play a single game with verbose output
    std::cout << "\nPlaying single game with learning..." << std::endl;
    GameResult result = GameSimulator::play_single_game(true);
    
    std::cout << "\nFinal result: " << (int)result << std::endl;
    
    // Test memory after
    std::cout << "\nMemory after game:" << std::endl;
    std::cout << "Long-term: " << long_term_memory.size() << std::endl;
    std::cout << "Short-term: " << short_term_memory.size() << std::endl;
    
    // Sample memory entries
    if (long_term_memory.size() > 0) {
        std::cout << "\nSample memory entries:" << std::endl;
        int count = 0;
        for (const auto& entry : long_term_memory) {
            if (count >= 3) break;
            std::cout << "Board " << entry.first << ": LT=" << entry.second 
                      << ", ST=" << (int)short_term_memory[entry.first] << std::endl;
            count++;
        }
    }
    
    return 0;
}