//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 22/08/2022.
//

#include "game_controller.h"
#include "hge/scene.h"

using namespace Harpia;

namespace Jam {
    void GameController::Start() {
        audioComponent = GetObject()->AddComponent<AudioComponent>();
    }

    void GameController::Update() {
        UpdateProjectiles();
    }

    void GameController::OnPlayerShoot(const Vector3 &pos) {
        ProjectileController *p;
        if (_projectilePool.Empty()) {
            auto po = CreateObject("Projectile");
            p = po->AddComponent<ProjectileController>();
            p->Initialize(2, pos, projectileMesh, projectileMaterial, layerMask);
            po->transform.SetRotation(playerRotation);
        } else {
            p = _projectilePool.Pop();
            p->Initialize(2, pos, projectileMesh, projectileMaterial, layerMask);
            p->GetObject()->SetEnabled(true);
        }
        audioComponent->SetAudio(playerShootAudio);
        audioComponent->Play();
        _projectiles.push_back(p);
    }

    void GameController::OnProjectileDestroyed(ProjectileController *projectile) {
        projectile->GetObject()->SetEnabled(false);
        _projectiles.remove(projectile);
        _projectilePool.Push(projectile);
    }

    void GameController::UpdateProjectiles() {
        for(auto p : _projectiles){
            p->lifeTime -= Time()->deltaTime;
            if (p->lifeTime <= 0) {
                OnProjectileDestroyed(p);
                return;
            }

            p->GetObject()->transform.Translate({0, p->speed * Time()->deltaTime, 0});
        }
    }
}// namespace Jam