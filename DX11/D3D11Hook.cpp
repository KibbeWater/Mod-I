#include "pch.h"

typedef HRESULT (__stdcall*Present)(IDXGISwapChain *pSwapChain, UINT SyncInterval, UINT Flags);

static std::once_flag g_isInitialized;

Present oPresent;
HWND window = nullptr;
HWND g_hwnd = nullptr;
WNDPROC oWndProc;
ID3D11Device *pDevice = nullptr;
ID3D11DeviceContext *pContext = nullptr;
ID3D11RenderTargetView *mainRenderTargetView;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
        return true;

    return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

HRESULT __stdcall hkRender(IDXGISwapChain *pSwapChain, UINT SyncInterval, UINT Flags) {
    std::call_once(g_isInitialized, [&]() {
        if (!SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)& pDevice)))
            MessageBox(nullptr, "Failed to get device from window", "Error", MB_OK);

        pDevice->GetImmediateContext(&pContext);

        DXGI_SWAP_CHAIN_DESC sd;
        pSwapChain->GetDesc(&sd);
        window = sd.OutputWindow;

        ID3D11Texture2D *pBackBuffer;
        pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID *) &pBackBuffer);
        pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &mainRenderTargetView);
        pBackBuffer->Release();

        oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);

        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

        ImGui::StyleColorsDark();

        ImGui_ImplWin32_Init(window);
        ImGui_ImplDX11_Init(pDevice, pContext);
    });

    if (GetAsyncKeyState(VK_INSERT) & 0x1) {
        Menu::bIsOpen = !Menu::bIsOpen;
    }

    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();

    ImGui::NewFrame();

    // Super advanced menu code in here
    if (Menu::bIsOpen) Menu::Render();

    ImGui::EndFrame();
    ImGui::Render();

    pContext->OMSetRenderTargets(1, &mainRenderTargetView, nullptr);
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    return oPresent(pSwapChain, SyncInterval, Flags);
}

void ImplHookDX11_Init(HWND hwnd) {
    g_hwnd = hwnd;

    bool init_hook = false;
    do {
        if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success) {
            kiero::bind(8, reinterpret_cast<void **>(&oPresent), (void *) hkRender);
            init_hook = true;
        }
    } while (!init_hook);
}
