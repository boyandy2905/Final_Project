/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Splash.cpp
Project:    CS230 Game
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 13, 2025
*/

#include "../Engine/Engine.h"
#include "States.h"
#include "Splash.h"

Splash::Splash() {

}

void Splash::Load() {
    counter = 0;
    texture = Engine::GetTextureManager().Load("Assets/DigiPen.png");
    //texture.Load("Assets/DigiPen.png");
}

void Splash::Update(double dt) {
    Engine::GetLogger().LogDebug(std::to_string(counter));
    if (counter >= 2) {
        Engine::GetGameStateManager().ClearNextGameState();
    }
    counter += dt;
}

void Splash::Unload() {
    texture = nullptr;
    Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::MainMenu));
}

void Splash::Draw() {
    Engine::GetWindow().Clear(UINT_MAX);
    texture->Draw(Math::TranslationMatrix({ (Engine::GetWindow().GetSize() - texture->GetSize()) / 2.0 }));
    //texture.Draw(Math::TranslationMatrix({ (Engine::GetWindow().GetSize() - texture.GetSize()) / 2.0 }));
}
