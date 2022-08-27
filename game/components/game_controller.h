//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 22/08/2022.
//

#ifndef INC_1JAMCHOICES_GAME_CONTROLLER_H
#define INC_1JAMCHOICES_GAME_CONTROLLER_H

#include "enemy_controller.h"
#include "hge/component.h"
#include "hge/pool.h"
#include "projectile_controller.h"
#include "hge/harpia_math.h"

namespace Jam {
    class GameController : public Harpia::Component {
    public:
        Harpia::MaterialAsset *projectileMaterial = nullptr;
        Harpia::MeshAsset *projectileMesh = nullptr;
        int layerMask = 0;
        Harpia::Quaternion playerRotation;

    private:
        std::list<ProjectileController *> _projectiles;
        std::list<EnemyController *> _enemies;

        Harpia::Pool<ProjectileController> _projectilePool;

    public:
        void Start() override;
        void Update() override;

        void OnPlayerShoot(const Harpia::Vector3 &pos);
    };
}// namespace Jam

#endif//INC_1JAMCHOICES_GAME_CONTROLLER_H
