#include "simulator/sim.h"
#include "simulator/imgui/imgui.hpp"
#include "simulator/sim_RomExtractor.h"
#include "simulator/sim_gui.hpp"
#include "nds-extract.hpp"

#include <SDL2/SDL.h>
#include <filesystem>
#include <string>


void SIM_ShowRomExtractionDialog() {
    // Auto mode: if a rom.nds is bundled next to the executable, extract it
    // silently with no file dialog.
    if (std::filesystem::exists("rom.nds")) {
        SIM_NDSExtract("rom.nds");
        return;
    }

    bool fileSelected = false;
    SIM::GUI::Enable();
    SIM::GUI::OpenFileDialog([&fileSelected](std::string fileName) {
        SIM_NDSExtract(fileName);
        fileSelected = true;
    });
    while(!fileSelected) {
        SIM_Render(nullptr);
    }


    int foo = 1;
    foo++;
    printf("%d", foo);
}