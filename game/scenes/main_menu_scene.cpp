//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/08/2022.
//

#include "main_menu_scene.h"

#include "hge/application.h"
#include "hge/assets.h"
#include "hge/camera_component.h"
#include "hge/text_renderer_component.h"
#include "rotate_around.h"

enum CameraLayer : int {
    Ui = 1<<0,
    Game = 1<<1,
};

namespace Jam {
    void MainMenuScene::Load(Application *application) {
        auto sizeV = 10.0f;
        auto aspect = application->GetScreenAspect();
        auto sizeH = sizeV * aspect;

        auto shipCamera = CreateSimplePerspectiveCamera(30, 0.1f, 100, {0, 9, 12}, -35);
        shipCamera->SetClearColor(Color(111, 98, 139, 255));
        shipCamera->SetLayerMask(CameraLayer::Game);

        auto uiCamera = CreateSimpleOrthoCamera(sizeV);
        uiCamera->SetClearType(Harpia::CameraClearType::Depth);
        uiCamera->SetClearColor(Color{0, 0, 0, 0});
        uiCamera->SetLayerMask(CameraLayer::Ui);

        auto fontAtlas = LoadTextureAsset("assets/fonts/pixel.png");
        fontAtlas->_filter = TextureFilter::Nearest;
        auto fontShader = LoadShaderAsset("assets/shaders/text.vert", "assets/shaders/text.frag");
        auto fontMaterial = LoadMaterialAsset(fontShader);
        fontMaterial->SetTexture(fontAtlas);
        fontMaterial->SetColor(Color::white);
        fontMaterial->_transparent = true;

        CreateCenteredText("Space Game", fontMaterial, sizeV / 2, 1.5f);
        CreateCenteredText("Game by Ricardo Bustamante <ricardo@busta.dev>", fontMaterial, -sizeV + 1, 0.65f);

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
        smallShip->transform.SetPosition({2,0,0});

        auto rotateSmall = smallShip->AddComponent<RotateAround>();
        rotateSmall->target = &smallShip->transform;
        rotateSmall->speed = {0, 20, 0};

        auto bigShip = CreateObject("BigShip");
        auto bigShipRenderer = bigShip->AddComponent<RendererComponent>();
        bigShipRenderer->SetLayerMask(CameraLayer::Game);
        bigShipRenderer->SetMaterial(shipMaterial);
        bigShipRenderer->SetMesh(bigShipModel);
        bigShip->transform.SetPosition({-2,0,0});

        auto rotateBig = bigShip->AddComponent<RotateAround>();
        rotateBig->target = &bigShip->transform;
        rotateBig->speed = {0, 20, 0};
    }

    Object *MainMenuScene::CreateCenteredText(const std::string &text, MaterialAsset *material, float y, float scale) {
        auto textObject = CreateObject("Text");
        auto textRenderer = textObject->AddComponent<TextRendererComponent>();
        textRenderer->SetFontMaterial(material, 7, 9);
        textRenderer->SetText(text);
        textRenderer->SetLayerMask(CameraLayer::Ui);
        textObject->transform.SetPosition({(scale * -textRenderer->GetSize().x) / 2, y});
        textObject->transform.SetScale(scale);

        return textObject;
    }
}// namespace Jam