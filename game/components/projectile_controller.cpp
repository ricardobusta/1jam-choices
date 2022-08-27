//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 26/08/2022.
//

#include "projectile_controller.h"
#include "hge/all_components.h"
#include "game_controller.h"

using namespace Harpia;

namespace Jam {
    void ProjectileController::Initialize(float lifeTime, const Vector3 &pos, MeshAsset *mesh, MaterialAsset *material, int layerMask) {
        auto obj = GetObject();
        obj->transform.SetPosition(pos);
        auto renderer = obj->AddComponent<RendererComponent>();
        renderer->SetLayerMask(layerMask);
        renderer->SetMesh(mesh);
        renderer->SetMaterial(material);
        this->lifeTime = lifeTime;
    }
}// namespace Jam