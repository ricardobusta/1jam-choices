//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 19/08/2022.
//

#ifndef INC_1JAMCHOICES_MAIN_MENU_CONTROLLER_H
#define INC_1JAMCHOICES_MAIN_MENU_CONTROLLER_H

#include "hge/component.h"

namespace Jam {
    class MainMenuController : public Harpia::Component {
    public:
        void Update() override;
    };
}// namespace Jam

#endif//INC_1JAMCHOICES_MAIN_MENU_CONTROLLER_H
