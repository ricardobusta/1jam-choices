//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 22/08/2022.
//

#include "game_controller.h"
#include "hge/scene.h"

namespace Jam {
    void GameController::Start() {
        Component::Start();
    }

    void GameController::Update() {
        Component::Update();
    }

    void GameController::OnPlayerShoot() {
        ProjectileController *p;
        if(_projectilePool.Empty()){
            auto po = CreateObject("Projectile");
            p = po->AddComponent<ProjectileController>();
            p->Initialize();
        }else{
            p = _projectilePool.Pop();
        }

        _projectiles.push_back(p);
    }
}// namespace Jam