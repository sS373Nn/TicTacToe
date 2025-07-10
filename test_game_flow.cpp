#include "bitwise-engine/src/GameSimulator.hpp"
#include "bitwise-engine/src/DecisionEngine.hpp"
#include "bitwise-engine/src/MoveGenerator.hpp"
#include "bitwise-engine/src/memory.hpp"
#include <iostream>
#include <vector>

void test_single_game() {
    std::cout << "=== Testing Single Game Flow ===" << std::endl;
    
    // Clear memory
    long_term_memory.clear();
    short_term_memory.clear();
    
    // Simulate one game manually - AI as Player 1, Random as Player 2
    uint64_t board_state = 0;
    uint8_t current_player = 1; // Player 1 starts
    uint8_t ai_player = 1;
    int move_count = 0;
    
    std::cout << "Game: AI as Player 1, Random as Player 2" << std::endl;
    
    while (move_count < 20) { // Safety limit to prevent infinite loops
        std::cout << "Move " << move_count << " - Player " << (int)current_player << " turn" << std::endl;
        
        if (current_player == ai_player) {
            // AI move
            uint64_t ai_move = DecisionEngine::get_best_move(board_state, current_player);
            std::cout << "  AI move result: " << ai_move << std::endl;
            
            if (ai_move == 0) {
                std::cout << "  AI cannot move - game should end" << std::endl;
                break;
            }
            board_state = ai_move;
        } else {
            // Random move simulation
            auto valid_moves = MoveGenerator::generate_possible_moves(board_state, current_player);
            std::cout << "  Valid moves for random player: " << valid_moves.size() << std::endl;
            
            if (valid_moves.empty()) {
                std::cout << "  No valid moves - game should end" << std::endl;
                break;
            }
            
            // Take first valid move for simplicity
            board_state = valid_moves[0];
        }
        
        // Check for game end
        GameResult game_result = GameSimulator::check_game_state(board_state);
        std::cout << "  Game result: " << (int)game_result << std::endl;
        
        if (game_result != GameResult::ONGOING) {
            std::cout << "  Game ended after " << move_count << " moves" << std::endl;
            switch (game_result) {
                case GameResult::PLAYER1_WIN:
                    std::cout << "  Winner: Player 1" << std::endl;
                    break;
                case GameResult::PLAYER2_WIN:
                    std::cout << "  Winner: Player 2" << std::endl;
                    break;
                case GameResult::DRAW:
                    std::cout << "  Result: Draw" << std::endl;
                    break;
            }
            return;
        }
        
        current_player = 3 - current_player; // Switch player
        move_count++;
    }
    
    std::cout << "❌ ERROR: Game ran for " << move_count << " moves without ending!" << std::endl;
}

int main() {
    test_single_game();
    return 0;
}