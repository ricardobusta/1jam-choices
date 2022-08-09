//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
//

#include "hge/debug.h"

#include "init_game.h"
namespace Jam {
    void InitGame::Start() {
        DebugLog("Starting");
        _loadTime = 0;
    }

    void InitGame::Update() {
        if (_loadTime < 1) {
            _loadTime += Time()->deltaTime;
        } else {
            SceneManager()->LoadScene(1);
        }
    }
}// namespace Jam