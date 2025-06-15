/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  OtherCarManager.cpp
Project:    CS230 Game
Author:     Sehoon Kim, Chanwoong Moon
Created:    June 14, 2025
*/

#pragma once
#include "OtherCarManager.h"
#include "../Engine/Engine.h"
#include "../Engine/GameObjectManager.h"
#include "../Engine/Window.h"
#include "../Engine/Camera.h"
#include "../Game/OtherCar.h"
#include "../Game/Mode3.h"

OtherCarManager::OtherCarManager(Mode3* mode)
    : CS230::GameObject({ 0, 0 }), mode3_ptr(mode), spawn_timer(4.5) {
}

void OtherCarManager::Update(double dt) {
    spawn_timer.Update(dt);

    if (spawn_timer.Remaining() <= 0.0) {
        std::vector<int> available_indices;
        for (int i = 0; i < static_cast<int>(y_positions.size()); ++i) {
            if (i != last_used_index) {
                available_indices.push_back(i);
            }
        }

        if (!available_indices.empty()) {
            int index = available_indices[rand() % available_indices.size()];
            last_used_index = index;
            double y = y_positions[index];

            Math::vec2 camera_pos = Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition();
            double screen_width = Engine::GetWindow().GetSize().x;
            Math::vec2 spawn_pos{ camera_pos.x + screen_width + 80.0, y };
            auto* car = new OtherCar(spawn_pos);
            Engine::GetGameStateManager().GetGSComponent<CS230::GameObjectManager>()->Add(car);
        }

        spawn_timer.Set(0.5);
    }
}