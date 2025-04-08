//
// Created by kibbe on 2025-04-05.
//

#include "pch.h"

std::vector<std::function<void()>> g_vLambdas = std::vector<std::function<void()>>();

void game_thread::execute(const std::function<void()> &lambda) {
    g_vLambdas.push_back(lambda);
}

void game_thread::_processQueue() {
    // Process all queued lambdas
    for (auto& lambda : g_vLambdas) {
        if (lambda) {
            try {
                lambda();
            } catch (const std::exception& e) {
                // Handle any exceptions from lambda execution
                // You might want to log this in a real implementation
                std::cerr << "Exception in game thread lambda: " << e.what() << std::endl;
            }
        }
    }

    // Clear the queue after processing
    g_vLambdas.clear();
}
