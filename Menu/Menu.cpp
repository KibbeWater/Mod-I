//
// Created by kibbe on 4/3/2025.
//

#include "pch.h"

void Menu::Render() {
    ImGui::GetIO().MouseDrawCursor = Menu::bIsOpen; {
        ImGui::Begin("Mod I"); // Create a window called "Hello, world!" and append into it.

        ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 8);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
        ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(25, 25, 25, 255));
        if (ImGui::BeginChild("subsys", ImVec2(0, 85), ImGuiChildFlags_Border)) {
            ImGui::Text("Active Subsystems:");

            ImGui::Text((G::m_iMoneyManager != nullptr) ? "Money Manager: Enabled" : "Money Manager: Inactive");
            ImGui::Text((G::m_iGameTimeManager != nullptr) ? "Game Time: Enabled" : "Game Time: Inactive");
            ImGui::Text((G::m_iPlayerInventory != nullptr)
                            ? "Player Inventory: Enabled"
                            : "Player Inventory: Inactive");

            ImGui::EndChild();
        }
        ImGui::PopStyleColor(1);
        ImGui::PopStyleVar(2);

        ImGui::Spacing();

        static GameAPI::Instance *instance = GameAPI::Instance::GetInstance();

        if (instance->IsHost() || instance->IsClientOnly()) {
            if (ImGui::CollapsingHeader("Money Manager")) {
                ImGui::BeginGroup(); {
                    ImGui::PushID("cash");
                    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(5, 5));

                    if (ImGui::Button("-")) GameAPI::MoneyManager::ChangeCash(-1000); ImGui::SameLine();
                    if (ImGui::Button("--")) GameAPI::MoneyManager::ChangeCash(-10000); ImGui::SameLine();
                    if (ImGui::Button("---")) GameAPI::MoneyManager::ChangeCash(-100000); ImGui::SameLine();

                    std::string cashText = "Cash: " + std::to_string(GameAPI::MoneyManager::GetCash());
                    ImGui::Text(cashText.c_str()); ImGui::SameLine();

                    if (ImGui::Button("+++")) GameAPI::MoneyManager::ChangeCash(100000); ImGui::SameLine();
                    if (ImGui::Button("++")) GameAPI::MoneyManager::ChangeCash(10000); ImGui::SameLine();
                    if (ImGui::Button("+")) GameAPI::MoneyManager::ChangeCash(1000);

                    ImGui::PopStyleVar(1);
                    ImGui::PopID();
                } ImGui::EndGroup();

                ImGui::Spacing();

                ImGui::BeginGroup(); {
                    ImGui::PushID("balance");
                    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(5, 5));

                    if (ImGui::Button("-")) GameAPI::MoneyManager::ChangeBalance(-1000); ImGui::SameLine();
                    if (ImGui::Button("--")) GameAPI::MoneyManager::ChangeBalance(-10000); ImGui::SameLine();
                    if (ImGui::Button("---")) GameAPI::MoneyManager::ChangeBalance(-100000); ImGui::SameLine();

                    std::string balanceText = "Balance: " + std::to_string(GameAPI::MoneyManager::GetBalance());
                    ImGui::Text(balanceText.c_str()); ImGui::SameLine();

                    if (ImGui::Button("+++")) GameAPI::MoneyManager::ChangeBalance(100000); ImGui::SameLine();
                    if (ImGui::Button("++")) GameAPI::MoneyManager::ChangeBalance(10000); ImGui::SameLine();
                    if (ImGui::Button("+")) GameAPI::MoneyManager::ChangeBalance(1000);

                    ImGui::PopStyleVar(1);
                    ImGui::PopID();

                } ImGui::EndGroup();
            }

            if (ImGui::Button("Drugpocalypse")) {
                auto customers = GameAPI::Customer::GetUnlockedCustomers();
                for (auto customer: customers) {
                    customer.RequestProduct();
                }
            }

            if (ImGui::Button("Unhook")) {
                MH_DisableHook(MH_ALL_HOOKS);
            }
        } else {
            ImGui::Text("Game not started or you are not the host!");
        }


        ImGui::End();
    }
}
