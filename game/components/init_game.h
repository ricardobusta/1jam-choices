//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
//

#ifndef INC_1JAMCHOICES_INIT_GAME_H
#define INC_1JAMCHOICES_INIT_GAME_H

#include "hge/component.h"

using namespace Harpia;
namespace Jam {
    class InitGame : public Component {
    public:

        void Update() override;
    };
}// namespace Jam

#endif//INC_1JAMCHOICES_INIT_GAME_H
