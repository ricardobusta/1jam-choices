//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
//

#ifndef INC_1JAMCHOICES_INIT_GAME_H
#define INC_1JAMCHOICES_INIT_GAME_H

#include "hge/component.h"

namespace Jam {
    class InitGame : public Harpia::Component {
    private:
        float _loadTime = 0;

    public:
        void Start() override;
        void Update() override;
    };
}// namespace Jam

#endif//INC_1JAMCHOICES_INIT_GAME_H
