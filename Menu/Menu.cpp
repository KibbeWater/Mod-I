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
            ImGui::Text((G::m_iPlayerInventory != nullptr) ? "Player Inventory: Enabled" : "Player Inventory: Inactive");
        }

        if (G::m_iMoneyManager != nullptr && ImGui::CollapsingHeader("Money Manager")) {
            std::string cashText = "Cash: " + std::to_string(GameAPI::MoneyManager::GetCash());
            ImGui::Text(cashText.c_str());

            if (ImGui::Button("Add 10k Cash")) {
                GameAPI::MoneyManager::ChangeCash(10000);
            }

            ImGui::Spacing();

            std::string balanceText = "Balance: " + std::to_string(GameAPI::MoneyManager::GetBalance());
            ImGui::Text(balanceText.c_str());
            if (ImGui::Button("Add 10k Balance")) {
                GameAPI::MoneyManager::ChangeBalance(10000);
            }
        }

        if (ImGui::Button("Drugpocalypse")) {
            auto customers = GameAPI::Customer::GetUnlockedCustomers();
            for (auto customer : customers) {
                customer.RequestProduct();
            }
        }

        ImGui::End();
    }
}

