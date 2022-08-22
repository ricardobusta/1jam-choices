//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 22/08/2022.
//

#include "game_scene.h"

using namespace Harpia;

enum CameraLayer : int {
    Ui = 1 << 0,
    Game = 1 << 1,
};

namespace Jam {
    void GameScene::Load(Application *application) {
        auto sizeV = 10.0f;

        auto gameCamera = CreateSimplePerspectiveCamera(30, 0.1f, 100, {0, 4, 15}, -15);
        gameCamera->SetClearColor(Color(111, 98, 139, 255));
        gameCamera->SetLayerMask(CameraLayer::Game);

        auto uiCamera = CreateSimpleOrthoCamera(sizeV);
        uiCamera->SetClearType(CameraClearType::Depth);
        uiCamera->SetClearColor(Color{0, 0, 0, 0});
        uiCamera->SetLayerMask(CameraLayer::Ui);
    }
}// namespace Jam