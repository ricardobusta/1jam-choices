//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
//

#include "main_menu_scene.h"

#include "hge/application.h"
#include "hge/assets.h"
#include "rotate_around.h"
#include "main_menu_controller.h"

using namespace Harpia;

enum CameraLayer : int {
    Ui = 1 << 0,
    Game = 1 << 1,
};

namespace Jam {
    void MainMenuScene::Load(Application *application) {
        auto sizeV = 10.0f;

        auto gameCamera = CreateSimplePerspectiveCamera(30, 0.1f, 100, {0, 4, 15}, -15);
        gameCamera->SetClearColor(Color(111, 98, 139, 255));
        gameCamera->SetLayerMask(CameraLayer::Game);

        auto uiCamera = CreateSimpleOrthoCamera(sizeV);
        uiCamera->SetClearType(CameraClearType::Depth);
        uiCamera->SetClearColor(Color{0, 0, 0, 0});
        uiCamera->SetLayerMask(CameraLayer::Ui);

        auto fontAtlas = LoadTextureAsset("assets/fonts/pixel.png");
        fontAtlas->_filter = TextureFilter::Nearest;
        auto fontShader = LoadShaderAsset("assets/shaders/text.vert", "assets/shaders/text.frag");
        auto fontMaterial = LoadMaterialAsset(fontShader);
        fontMaterial->SetTexture(fontAtlas);
        fontMaterial->SetColor(Color::white);
        fontMaterial->_transparent = true;

        CreateCenteredText("Space Game", fontMaterial, {0, sizeV / 2 + 2}, 1.5f);
        CreateCenteredText("Game by Ricardo Bustamante <ricardo@busta.dev>", fontMaterial, {0, -sizeV + 1}, 0.65f);

        auto spacing = 6.0f;
        auto fontSize = 0.65f;
        auto shipModelY = -sizeV + 14;
        auto shipInfoY = -sizeV + 6;

        CreateCenteredText("Model: DPS9K+", fontMaterial, {-spacing, shipModelY}, fontSize*1.1f);
        CreateCenteredText("Press [1] to select", fontMaterial, {-spacing, shipInfoY-1}, fontSize);
        CreateCenteredText("+atk -def", fontMaterial, {-spacing, shipInfoY}, fontSize);

        CreateCenteredText("Model: T4-NK", fontMaterial, {spacing, shipModelY}, fontSize*1.1f);
        CreateCenteredText("Press [2] to select", fontMaterial, {spacing, shipInfoY-1}, fontSize);
        CreateCenteredText("+def -atk", fontMaterial, {spacing, shipInfoY}, fontSize);

        std::map<std::string, MeshAsset *, std::less<>> meshCollection;
        if (!LoadFbxMeshAssets("assets/models/ships.fbx", meshCollection)) {
            DebugLogError("Error!");
        }

        auto defaultShader = LoadShaderAsset("assets/shaders/default.vert", "assets/shaders/default.frag");

        auto bigShipModel = meshCollection["ShipBig"];
        auto smallShipModel = meshCollection["ShipSmall"];
        auto shipLandingFoot = meshCollection["Foot"];

        auto shipMaterial = LoadMaterialAsset(defaultShader);
        auto shipTexture = LoadTextureAsset("assets/textures/ships.png");
        shipTexture->_filter = TextureFilter::Nearest;
        shipMaterial->SetTexture(shipTexture);
        shipMaterial->SetColor(Color::white);

        auto smallShip = CreateObject("SmallShip");
        auto smallShipRenderer = smallShip->AddComponent<RendererComponent>();
        smallShipRenderer->SetLayerMask(CameraLayer::Game);
        smallShipRenderer->SetMaterial(shipMaterial);
        smallShipRenderer->SetMesh(smallShipModel);
        auto smallShipLandingRenderer = smallShip->AddComponent<RendererComponent>();
        smallShipLandingRenderer->SetLayerMask(CameraLayer::Game);
        smallShipLandingRenderer->SetMaterial(shipMaterial);
        smallShipLandingRenderer->SetMesh(shipLandingFoot);
        smallShip->transform.SetPosition({-2, 0, 0});

        auto rotateSmall = smallShip->AddComponent<RotateAround>();
        rotateSmall->target = &smallShip->transform;
        rotateSmall->speed = {0, 20, 0};

        auto bigShip = CreateObject("BigShip");
        auto bigShipRenderer = bigShip->AddComponent<RendererComponent>();
        bigShipRenderer->SetLayerMask(CameraLayer::Game);
        bigShipRenderer->SetMaterial(shipMaterial);
        bigShipRenderer->SetMesh(bigShipModel);
        auto bigShipLandingRenderer = bigShip->AddComponent<RendererComponent>();
        bigShipLandingRenderer->SetLayerMask(CameraLayer::Game);
        bigShipLandingRenderer->SetMaterial(shipMaterial);
        bigShipLandingRenderer->SetMesh(shipLandingFoot);
        bigShip->transform.SetPosition({2, 0, 0});

        auto rotateBig = bigShip->AddComponent<RotateAround>();
        rotateBig->target = &bigShip->transform;
        rotateBig->speed = {0, 20, 0};

        auto sceneManager = CreateObject("SceneManager");
        sceneManager->AddComponent<MainMenuController>();
    }

    Object *MainMenuScene::CreateCenteredText(const std::string &text, MaterialAsset *material, const Vector2 &pos, float scale) {
        auto textObject = CreateObject("Text");
        auto textRenderer = textObject->AddComponent<TextRendererComponent>();
        textRenderer->SetFontMaterial(material, 7, 9);
        textRenderer->SetText(text);
        textRenderer->SetLayerMask(CameraLayer::Ui);
        textObject->transform.SetPosition({((scale * -textRenderer->GetSize().x) / 2)+pos.x, pos.y});
        textObject->transform.SetScale(scale);

        return textObject;
    }
}// namespace Jam