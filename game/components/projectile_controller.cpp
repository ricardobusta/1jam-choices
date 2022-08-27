//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 26/08/2022.
//

#include "projectile_controller.h"
#include "hge/all_components.h"

using namespace Harpia;

namespace Jam {
    void ProjectileController::Initialize(GameController *controller, float lifeTime, const Vector3 &pos, MeshAsset *mesh, MaterialAsset *material, int layerMask) {
        auto obj = GetObject();
        obj->transform.SetPosition(pos);
        auto renderer = obj->AddComponent<RendererComponent>();
        renderer->SetLayerMask(layerMask);
        renderer->SetMesh(mesh);
        renderer->SetMaterial(material);
        _gameController = controller;
        _lifeTime = lifeTime;
    }

    void ProjectileController::Update() {
        _lifeTime -= Time()->deltaTime;
        if (_lifeTime <= 0) {
            GetObject()->SetEnabled(false);
            return;
        }

        GetObject()->transform.Translate({0, 10 * Time()->deltaTime, 0});
    }
}// namespace Jam