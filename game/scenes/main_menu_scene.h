//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
//

#ifndef INC_1JAMCHOICES_MAINMENU_H
#define INC_1JAMCHOICES_MAINMENU_H

#include "hge/scene.h"

using namespace Harpia;

namespace Jam {
    class MainMenuScene : public Scene {
    public:
        void Load(Application *application) override;
    };
} // Jam

#endif //INC_1JAMCHOICES_MAINMENU_H
