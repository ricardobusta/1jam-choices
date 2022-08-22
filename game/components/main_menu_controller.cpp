//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 19/08/2022.
//

#include "main_menu_controller.h"

#include "static_data.h"

namespace Jam {
    void MainMenuController::Update() {
        if (Input()->GetKeyDown(SDLK_F5)) {
            SceneManager()->LoadScene(1);
        }

        if (Input()->GetKeyDown(SDLK_1)) {
            StaticData::selectedShip = 1;
            SceneManager()->LoadScene(2);
        }

        if (Input()->GetKeyDown(SDLK_2)) {
            StaticData::selectedShip = 2;
            SceneManager()->LoadScene(2);
        }
    }
}// namespace Jam