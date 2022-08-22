//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 22/08/2022.
//

#ifndef INC_1JAMCHOICES_GAME_CONTROLLER_H
#define INC_1JAMCHOICES_GAME_CONTROLLER_H

#include "hge/component.h"

namespace Jam {
    class GameController : public Harpia::Component {
    public:
        void Start() override;
        void Update() override;
    };
}// namespace Jam

#endif//INC_1JAMCHOICES_GAME_CONTROLLER_H
