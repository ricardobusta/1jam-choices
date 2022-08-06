//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
//

#include "game_config.h"
#include <filesystem>
#include <hge/application.h>
#include <hge/debug.h>

using namespace Jam;

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
    if (!std::filesystem::is_directory("./assets")) {
        DebugLogError("Assets folder missing");
        return -1;
    }
    auto app = Harpia::Application(GameConfig::Configure);
    return app.Execute();
}