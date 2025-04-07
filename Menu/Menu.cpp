//
// Created by kibbe on 4/3/2025.
//

#include "pch.h"

void Menu::Render() {
    ImGui::GetIO().MouseDrawCursor = Menu::bIsOpen;

    {
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("Mod I");                          // Create a window called "Hello, world!" and append into it.

        if (ImGui::CollapsingHeader("Subsystems"))
        {
            ImGui::Text("Active Subsystems:");
            ImGui::Text((G::m_iMoneyManager != nullptr) ? "Money Manager: Enabled" : "Money Manager: Inactive");
            ImGui::Text((G::m_iGameTimeManager != nullptr) ? "Game Time: Enabled" : "Game Time: Inactive");
        }

        if (G::m_iMoneyManager != nullptr && ImGui::CollapsingHeader("Money Manager")) {
            if (ImGui::Button("Add 10k")) {
                game_thread::execute([]() {
                    GameAPI::MoneyManager::ChangeBalance(10000);
                });
            }
        }

        ImGui::End();
    }
}

