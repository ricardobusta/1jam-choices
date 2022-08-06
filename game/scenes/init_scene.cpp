//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
//

#include "init_scene.h"
#include "hge/camera_component.h"

namespace Jam {
    void InitScene::Load(Application *application) {
        auto camera = CreateSimpleOrthoCamera(5);
        camera->SetClearColor(Color::gray);
    }
} // Jam