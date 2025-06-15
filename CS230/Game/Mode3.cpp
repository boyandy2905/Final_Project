/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Mode3.cpp
Project:    CS230 Game
Author:     Jonathan Holmes, Sehoon Kim, Chanwoong Moon
Created:    June 14, 2025
*/

#include <iostream>
#include <raylib.h>
#include "Mode3.h"
#include "../Engine/Engine.h"
#include "States.h"
#include "Fonts.h"
#include "Floor.h"
#include "Portal.h"
#include "../Game/Player.h"
#include "../Game/OtherCar.h"
#include "../Game/OtherCarManager.h"
#include "../Engine/Score.h"
#include "../Engine/Particle.h"


Mode3::Mode3() : 
    player_ptr(nullptr), 
    last_time(0.0), 
    timer_texture(nullptr), 
    last_timer(static_cast<int>(timer_max)), 
    distance_texture(nullptr),
    total_distance(0.0)
    //smoke_manager(nullptr)
{
}

void Mode3::Load() {
#ifdef _DEBUG
    AddGSComponent(new CS230::ShowCollision());
#endif

    AddGSComponent(new CS230::Camera({ { 0.15 * Engine::GetWindow().GetSize().x, 0 }, { 0.35 * Engine::GetWindow().GetSize().x, 0 } }));
    AddGSComponent(new CS230::Timer(timer_max));
    AddGSComponent(new CS230::GameObjectManager());
    AddGSComponent(new Background());
    AddGSComponent(new CS230::Score());

    GetGSComponent<Background>()->Add("Assets/Road.png", 1.0);

    player_ptr = new Player({ 0, static_cast<double>(Engine::GetWindow().GetSize().y / 2) });
    GetGSComponent<CS230::GameObjectManager>()->Add(player_ptr);


    GetGSComponent<CS230::GameObjectManager>()->Add(new Portal(static_cast<int>(States::MainMenu), Math::irect{ { 14390, 0 }, { 14400, 600 } }));

    GetGSComponent<CS230::Camera>()->SetPosition({ 0,0 });
    GetGSComponent<CS230::Camera>()->SetLimit({ { 0,0 }, { GetGSComponent<Background>()->GetSize() - Engine::GetWindow().GetSize() } });

    GetGSComponent<CS230::GameObjectManager>()->Add(new OtherCarManager(this));
    
    AddGSComponent(new CS230::ParticleManager<Particles::Bump>());
    

    last_timer = static_cast<int>(timer_max);
    update_timer_text(last_timer);

    update_distance_text(static_cast<int>(total_distance));
}

void Mode3::Update(double dt) {
    UpdateGSComponents(dt);
    GetGSComponent<CS230::GameObjectManager>()->UpdateAll(dt);

    if (IsKeyPressed(KEY_ESCAPE)) {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::MainMenu));
    }
    GetGSComponent<CS230::Camera>()->Update(player_ptr->GetPosition());

    if (GetGSComponent<CS230::Timer>()->RemainingInt() < last_timer) {
        last_timer = GetGSComponent<CS230::Timer>()->RemainingInt();
        update_timer_text(last_timer);
    }
    if (last_timer == 0) {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::MainMenu));
    }

    total_distance += player_ptr->GetVelocity().x * dt;
    int cur_dist = static_cast<int>(total_distance);
    if (cur_dist != last_distance) {
        last_distance = cur_dist;
        update_distance_text(cur_dist);
    }
}

void Mode3::Unload() {
    if (timer_texture) {
        delete timer_texture;
        timer_texture = nullptr;
    }
    if (distance_texture) {
        delete distance_texture;
        distance_texture = nullptr;
    }

    player_ptr = nullptr;
    total_distance = 0;
    ClearGSComponents();
}

void Mode3::Draw() {
    Engine::GetWindow().Clear(0x000000FF);
    Math::TransformationMatrix camera_matrix = GetGSComponent<CS230::Camera>()->GetMatrix();
    GetGSComponent<Background>()->Draw(*GetGSComponent<CS230::Camera>());
    GetGSComponent<CS230::GameObjectManager>()->DrawAll(camera_matrix);

    Math::ivec2 window_size = Engine::GetWindow().GetSize();
    timer_texture->Draw(Math::TranslationMatrix(Math::ivec2{ window_size.x - 10 - timer_texture->GetSize().x, window_size.y - timer_texture->GetSize().y - 5 }));
    distance_texture->Draw(Math::TranslationMatrix(Math::ivec2{ window_size.x - 10 - distance_texture->GetSize().x, window_size.y - distance_texture->GetSize().y - 100 }));
}

void Mode3::update_timer_text(int value) {
    if (timer_texture) {
        delete timer_texture;
        timer_texture = nullptr;
    }
    timer_texture = Engine::GetFont(static_cast<int>(Fonts::Simple)).PrintToTexture("Timer: " + std::to_string(value), 0xFFFFFFFF);
}

void Mode3::update_distance_text(int distance) {
    if (distance_texture) {
        delete distance_texture;
        distance_texture = nullptr;
    }
    distance_texture = Engine::GetFont(static_cast<int>(Fonts::Simple)).PrintToTexture("Distance: " + std::to_string(distance), 0xFFFFFFFF);
}
