//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
//

#include "hge/debug.h"

#include "init_game.h"
namespace Jam {
    void InitGame::Update() {
        DebugLog("Loading scene 1");
        SceneManager()->LoadScene(1);
    }
}// namespace Jam