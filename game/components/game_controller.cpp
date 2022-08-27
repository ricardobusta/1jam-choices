//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 22/08/2022.
//

#include "game_controller.h"
#include "hge/scene.h"

using namespace Harpia;

namespace Jam {
    void GameController::Start() {
        Component::Start();
    }

    void GameController::Update() {
        Component::Update();
    }

    void GameController::OnPlayerShoot(const Vector3 &pos) {
        ProjectileController *p;
        if (_projectilePool.Empty()) {
            auto po = CreateObject("Projectile");
            p = po->AddComponent<ProjectileController>();
            p->Initialize(this, 2, pos, projectileMesh, projectileMaterial, layerMask);
            po->transform.SetRotation(playerRotation);
        } else {
            p = _projectilePool.Pop();
        }

        _projectiles.push_back(p);
    }
}// namespace Jam