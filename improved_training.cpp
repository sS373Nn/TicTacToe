#include "bitwise-engine/src/GameSimulator.hpp"
#include <iostream>
#include <chrono>

void print_memory_stats(const std::string& label) {
    std::cout << "\n" << label << " Memory Statistics:" << std::endl;
    std::cout << "Long-term memory entries: " << long_term_memory.size() << std::endl;
    std::cout << "Short-term memory entries: " << short_term_memory.size() << std::endl;
    
    // Sample some memory entries
    if (long_term_memory.size() > 0) {
        std::cout << "Sample memory entries:" << std::endl;
        int count = 0;
        for (const auto& entry : long_term_memory) {
            if (count >= 5) break;
            std::cout << "  Board " << entry.first << ": LT=" << entry.second 
                      << ", ST=" << (int)short_term_memory[entry.first] << std::endl;
            count++;
        }
    }
}

int main() {
    std::cout << "=== IMPROVED BITWISE DECISION ENGINE TRAINING ===" << std::endl;
    std::cout << "Comparing self-play vs random opponent training" << std::endl;
    std::cout << "===============================================" << std::endl;
    
    // Phase 1: Self-play training (baseline)
    std::cout << "\n--- Phase 1: Self-Play Training (500 games) ---" << std::endl;
    auto start_time = std::chrono::high_resolution_clock::now();
    
    GameStats self_play_stats = GameSimulator::run_self_play_training(500, true);
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    
    std::cout << "Self-play completed in " << duration.count() << " ms" << std::endl;
    print_memory_stats("Self-Play");
    
    // Phase 2: Random opponent training
    std::cout << "\n--- Phase 2: Random Opponent Training (500 games) ---" << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    
    GameStats random_stats = GameSimulator::run_vs_random_training(500, true);
    
    end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    
    std::cout << "Random opponent training completed in " << duration.count() << " ms" << std::endl;
    print_memory_stats("Combined");
    
    // Phase 3: Performance comparison
    std::cout << "\n--- Phase 3: Performance Analysis ---" << std::endl;
    std::cout << "Total games played: " << (self_play_stats.total_games + random_stats.total_games) << std::endl;
    std::cout << "Total unique board states learned: " << long_term_memory.size() << std::endl;
    
    std::cout << "\nSelf-play results:" << std::endl;
    std::cout << "  P1 wins: " << self_play_stats.player1_wins << " (" 
              << (100.0 * self_play_stats.player1_wins / self_play_stats.total_games) << "%)" << std::endl;
    std::cout << "  P2 wins: " << self_play_stats.player2_wins << " (" 
              << (100.0 * self_play_stats.player2_wins / self_play_stats.total_games) << "%)" << std::endl;
    std::cout << "  Draws: " << self_play_stats.draws << " (" 
              << (100.0 * self_play_stats.draws / self_play_stats.total_games) << "%)" << std::endl;
    
    std::cout << "\nRandom opponent results:" << std::endl;
    std::cout << "  P1 wins: " << random_stats.player1_wins << " (" 
              << (100.0 * random_stats.player1_wins / random_stats.total_games) << "%)" << std::endl;
    std::cout << "  P2 wins: " << random_stats.player2_wins << " (" 
              << (100.0 * random_stats.player2_wins / random_stats.total_games) << "%)" << std::endl;
    std::cout << "  Draws: " << random_stats.draws << " (" 
              << (100.0 * random_stats.draws / random_stats.total_games) << "%)" << std::endl;
    
    // Phase 4: Test final performance
    std::cout << "\n--- Phase 4: Final Performance Test ---" << std::endl;
    std::cout << "Testing trained engine vs random opponent (10 games):" << std::endl;
    
    int test_wins = 0, test_losses = 0, test_draws = 0;
    
    for (int i = 0; i < 10; i++) {
        GameResult result = GameSimulator::play_vs_random_game(false);
        std::cout << "Game " << (i + 1) << ": ";
        switch (result) {
            case GameResult::PLAYER1_WIN:
                std::cout << "Engine wins";
                test_wins++;
                break;
            case GameResult::PLAYER2_WIN:
                std::cout << "Random wins";
                test_losses++;
                break;
            case GameResult::DRAW:
                std::cout << "Draw";
                test_draws++;
                break;
        }
        std::cout << std::endl;
    }
    
    std::cout << "\nFinal test results:" << std::endl;
    std::cout << "Engine wins: " << test_wins << "/10 (" << (test_wins * 10) << "%)" << std::endl;
    std::cout << "Random wins: " << test_losses << "/10 (" << (test_losses * 10) << "%)" << std::endl;
    std::cout << "Draws: " << test_draws << "/10 (" << (test_draws * 10) << "%)" << std::endl;
    
    std::cout << "\n=== IMPROVED TRAINING COMPLETE ===" << std::endl;
    std::cout << "Your bitwise decision engine now has diverse training experience!" << std::endl;
    
    return 0;
}