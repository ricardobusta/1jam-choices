//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 26/08/2022.
//

#ifndef INC_1JAMCHOICES_PROJECTILE_CONTROLLER_H
#define INC_1JAMCHOICES_PROJECTILE_CONTROLLER_H

#include "hge/component.h"

namespace Jam {
    class GameController;

    class ProjectileController : public Harpia::Component {
    private:
        GameController *_gameController = nullptr;
        float _lifeTime;

    public:
        void Initialize(GameController *controller, float lifeTime, const Harpia::Vector3 &pos, Harpia::MeshAsset *mesh, Harpia::MaterialAsset *material, int layerMask);
        void Update() override;
    };
}// namespace Jam

#endif//INC_1JAMCHOICES_PROJECTILE_CONTROLLER_H
