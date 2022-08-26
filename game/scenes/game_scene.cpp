//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 22/08/2022.
//

#include "game_scene.h"

#include "player_controller.h"
#include "static_data.h"
#include "game_controller.h"

using namespace Harpia;

enum CameraLayer : int {
    Ui = 1 << 0,
    Game = 1 << 1,
};

namespace Jam {
    void GameScene::Load(Application *application) {
        auto sizeV = 10.0f;

        auto gameCamera = CreateSimplePerspectiveCamera(20, 0.1f, 1000, {0, -20, 90}, 15);
        gameCamera->SetClearColor(Color(0, 10, 10, 255));
        gameCamera->SetLayerMask(CameraLayer::Game);

        auto uiCamera = CreateSimpleOrthoCamera(sizeV);
        uiCamera->SetClearType(CameraClearType::Depth);
        uiCamera->SetClearColor(Color{0, 0, 0, 0});
        uiCamera->SetLayerMask(CameraLayer::Ui);

        std::map<std::string, MeshAsset *, std::less<>> meshCollection;
        if (!LoadFbxMeshAssets("assets/models/ships.fbx", meshCollection)) {
            DebugLogError("Error!");
        }

        auto defaultShader = LoadShaderAsset("assets/shaders/default.vert", "assets/shaders/default.frag");

        auto selectedRedShip = StaticData::selectedShip == 1;

        auto shipModel = meshCollection[selectedRedShip ? "ShipSmall" : "ShipBig"];

        auto shipMaterial = LoadMaterialAsset(defaultShader);
        auto shipTexture = LoadTextureAsset("assets/textures/ships.png");
        shipTexture->_filter = TextureFilter::Nearest;
        shipMaterial->SetTexture(shipTexture);
        shipMaterial->SetColor(Color::white);

        auto gameControllerObject = CreateObject("GameController");
        auto gameController = gameControllerObject->AddComponent<GameController>();

        auto player = CreateObject("Player");
        auto playerController = player->AddComponent<PlayerController>();
        playerController->gameController = gameController;

        auto playerShip = CreateObject("PlayerShip");
        auto smallShipRenderer = playerShip->AddComponent<RendererComponent>();
        smallShipRenderer->SetLayerMask(CameraLayer::Game);
        smallShipRenderer->SetMaterial(shipMaterial);
        smallShipRenderer->SetMesh(shipModel);
        playerShip->transform.SetPosition({0, 0, 0});
        playerShip->transform.SetRotation(180 * Math::Deg2Rad, {0, 1, 0});
        playerShip->transform.Rotate(-90 * Math::Deg2Rad, {1, 0, 0});
        playerShip->transform.SetParent(&player->transform);
    }
}// namespace Jam