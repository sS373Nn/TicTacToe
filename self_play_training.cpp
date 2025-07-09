#include "bitwise-engine/src/GameSimulator.hpp"
#include <iostream>
#include <chrono>

void print_memory_stats() {
    std::cout << "\nMemory System Statistics:" << std::endl;
    std::cout << "Long-term memory entries: " << long_term_memory.size() << std::endl;
    std::cout << "Short-term memory entries: " << short_term_memory.size() << std::endl;
    
    // Sample some memory entries
    std::cout << "\nSample memory entries:" << std::endl;
    int count = 0;
    for (const auto& entry : long_term_memory) {
        if (count >= 5) break;
        std::cout << "Board state " << entry.first << ": Long-term=" << entry.second 
                  << ", Short-term=" << (int)short_term_memory[entry.first] << std::endl;
        count++;
    }
}

void run_training_phases() {
    std::cout << "=== BITWISE DECISION ENGINE SELF-PLAY TRAINING ===" << std::endl;
    std::cout << "Phase 1: Efficiency-focused neural network emulation" << std::endl;
    std::cout << "Using pure bitwise operations for decision making" << std::endl;
    std::cout << "=================================================" << std::endl;
    
    // Phase 1: Small training run
    std::cout << "\n--- Phase 1: Initial Training (100 games) ---" << std::endl;
    auto start_time = std::chrono::high_resolution_clock::now();
    
    GameStats stats1 = GameSimulator::run_self_play_training(100, true);
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    
    std::cout << "Phase 1 completed in " << duration.count() << " ms" << std::endl;
    print_memory_stats();
    
    // Phase 2: Larger training run
    std::cout << "\n--- Phase 2: Extended Training (1000 games) ---" << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    
    GameStats stats2 = GameSimulator::run_self_play_training(1000, true);
    
    end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    
    std::cout << "Phase 2 completed in " << duration.count() << " ms" << std::endl;
    print_memory_stats();
    
    // Phase 3: Performance analysis
    std::cout << "\n--- Phase 3: Performance Analysis ---" << std::endl;
    std::cout << "Total games played: " << (stats1.total_games + stats2.total_games) << std::endl;
    std::cout << "Memory efficiency: " << long_term_memory.size() << " unique board states learned" << std::endl;
    std::cout << "Learning rate: " << (double)long_term_memory.size() / (stats1.total_games + stats2.total_games) 
              << " unique states per game" << std::endl;
    
    // Test final performance
    std::cout << "\n--- Final Performance Test ---" << std::endl;
    std::cout << "Playing 10 sample games with trained engine..." << std::endl;
    
    for (int i = 0; i < 10; i++) {
        GameResult result = GameSimulator::play_single_game(false);
        std::cout << "Game " << (i + 1) << ": ";
        switch (result) {
            case GameResult::PLAYER1_WIN:
                std::cout << "Player 1 wins";
                break;
            case GameResult::PLAYER2_WIN:
                std::cout << "Player 2 wins";
                break;
            case GameResult::DRAW:
                std::cout << "Draw";
                break;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Bitwise Decision Engine - Self-Play Training System" << std::endl;
    std::cout << "Neural Network Emulation through Bitwise Operations" << std::endl;
    std::cout << "====================================================" << std::endl;
    
    run_training_phases();
    
    std::cout << "\n=== TRAINING COMPLETE ===" << std::endl;
    std::cout << "Your bitwise decision engine has learned TicTacToe strategy!" << std::endl;
    std::cout << "Ready for Phase 2: Precision tuning and optimization" << std::endl;
    
    return 0;
}