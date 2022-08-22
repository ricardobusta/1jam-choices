//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 22/08/2022.
//

#ifndef INC_1JAMCHOICES_GAME_SCENE_H
#define INC_1JAMCHOICES_GAME_SCENE_H

#include "hge/scene.h"

namespace Jam {
    class GameScene : public Harpia::Scene {
        HARPIA_SCENE
    public:
        void Load(Harpia::Application *application) override;
    };
}// namespace Jam

#endif//INC_1JAMCHOICES_GAME_SCENE_H
