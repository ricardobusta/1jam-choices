//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
//

#ifndef INC_1JAMCHOICES_MAINMENU_H
#define INC_1JAMCHOICES_MAINMENU_H

#include "hge/scene.h"

namespace Jam {
    class MainMenuScene : public Harpia::Scene {
        HARPIA_SCENE
    public:
        void Load(Harpia::Application *application) override;

    private:
        Harpia::Object *CreateCenteredText(const std::string &text, Harpia::MaterialAsset *material, const Harpia::Vector2 &pos, float scale);
    };
}// namespace Jam

#endif//INC_1JAMCHOICES_MAINMENU_H
