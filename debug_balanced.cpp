#include "bitwise-engine/src/GameSimulator.hpp"
#include <iostream>

int main() {
    std::cout << "Debug: Testing single balanced game..." << std::endl;
    
    // Test a few games manually
    for (int i = 0; i < 5; i++) {
        std::cout << "Game " << (i+1) << " - AI as player " << ((i % 2) + 1) << std::endl;
        
        GameResult result = GameSimulator::play_vs_random_game(false);
        
        std::cout << "Result: ";
        switch (result) {
            case GameResult::PLAYER1_WIN:
                std::cout << "Player 1 wins" << std::endl;
                break;
            case GameResult::PLAYER2_WIN:
                std::cout << "Player 2 wins" << std::endl;
                break;
            case GameResult::DRAW:
                std::cout << "Draw" << std::endl;
                break;
        }
        std::cout << "Memory entries: " << long_term_memory.size() << std::endl;
        std::cout << "---" << std::endl;
    }
    
    return 0;
}