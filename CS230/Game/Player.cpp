/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Player.cpp
Project:    CS230 Game
Author:     Sehoon Kim, Chanwoong Moon
Created:    June 14, 2025
*/

#pragma once
#include "Player.h"
#include "../Engine/Engine.h"
#include "Mode3.h"
#include "States.h"
#include "../Game/OtherCar.h"

Player::Player(Math::vec2 start_position) :
    GameObject(start_position)
{
    AddGOComponent(new CS230::Sprite("Assets/Car.spt", this));

    hurt_timer = new CS230::Timer(0.0);
    boost_timer = new CS230::Timer(0.0);
    boost_cooldown_timer = new CS230::Timer(0.0);
    AddGOComponent(hurt_timer);
    AddGOComponent(boost_timer);
    AddGOComponent(boost_cooldown_timer);


    SetVelocity({ 0, 0 });
}

void Player::Update(double dt) {
    GameObject::Update(dt);
    CS230::RectCollision* collider = GetGOComponent<CS230::RectCollision>();
    Engine::GetGameStateManager().GetGSComponent<CS230::ParticleManager<Particles::Exhaust>>()->Emit(1, GetPosition(), { 0, 0 }, { -100, 0 }, 2 * PI / 3);
    if (collider->WorldBoundary().Left() < Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().x) {
        UpdatePosition({ Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().x - collider->WorldBoundary().Left(), 0 });
        SetVelocity({ 0, GetVelocity().y });
        
    }
    if (collider->WorldBoundary().Right() > Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().x + Engine::GetWindow().GetSize().x) {
        UpdatePosition({ Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().x + Engine::GetWindow().GetSize().x - collider->WorldBoundary().Right(), 0 });
        SetVelocity({ 0, GetVelocity().y });
       
    }
    if (collider->WorldBoundary().Bottom() -20 < Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().y) {
        UpdatePosition({ 0, Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().y - collider->WorldBoundary().Bottom() + 20 });
        SetVelocity({ GetVelocity().x, GetVelocity().y });
        
    }
    if (collider->WorldBoundary().Top() + 20 > Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().y + Engine::GetWindow().GetSize().y) {
        UpdatePosition({ 0, Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().y + Engine::GetWindow().GetSize().y - collider->WorldBoundary().Top() - 20});
        SetVelocity({ GetVelocity().x, GetVelocity().y });
        
    }

    double current_acceleration = x_acceleration;
    double current_max_velocity = max_velocity;
    if (is_boosting) {
        current_acceleration *= 2;
        current_max_velocity *= 2;
    }

    if (Engine::GetInput().KeyDown(CS230::Input::Keys::W)) {
        SetVelocity({ GetVelocity().x + current_acceleration * dt , GetVelocity().y });
        if (GetVelocity().x > current_max_velocity) {
            SetVelocity({ current_max_velocity, GetVelocity().y });
        }
    }
    if (Engine::GetInput().KeyDown(CS230::Input::Keys::S)) {
        SetVelocity({ GetVelocity().x - current_acceleration * dt, GetVelocity().y });
        if (GetVelocity().x < min_velocity) {
            SetVelocity({ min_velocity, GetVelocity().y });
        }
    }
    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::A)) {
        SetPosition({ GetPosition().x, GetPosition().y + 125 });
    }
    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::D)) {
        SetPosition({ GetPosition().x, GetPosition().y - 125 });
    }

    if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Left_Shift) && boost_cooldown_timer->Remaining() <= 0.0) {
        boost_timer->Set(boost_time);
        is_boosting = true;
        was_boosting = true;
    }
    if (is_boosting && boost_timer->Remaining() <= 0.0) {
        is_boosting = false;
        boost_cooldown_timer->Set(5.0);
    }
    if (!is_boosting && GetVelocity().x > max_velocity) {
        double dec_velocity = GetVelocity().x - x_acceleration * dt;
        if (dec_velocity < max_velocity) {
            dec_velocity = max_velocity;
        }
        SetVelocity({ dec_velocity, GetVelocity().y });
    }
}

bool Player::CanCollideWith(GameObjectTypes other_object_type) {
    return other_object_type != GameObjectTypes::Particle;
}

void Player::ResolveCollision(GameObject* other_object) {
    if (other_object->Type() == GameObjectTypes::OtherCar) {
        if (is_boosting == true) {
            static_cast<OtherCar*>(other_object)->Break();
        }
        else if (hurt_timer->Remaining() <= 0.0) {
            hurt_timer->Set(hurt_time);
            SetVelocity({ GetVelocity().x * 0.3, GetVelocity().y });
            Engine::GetGameStateManager().GetGSComponent<CS230::ParticleManager<Particles::Bump>>()->Emit(2, GetPosition(), { 0, 0 }, { 0, 100 }, 2 * PI / 3);
        }
        return;
    }

    if (other_object->Type() == GameObjectTypes::Portal) {
        static_cast<Portal*>(other_object)->GoToState();
    }
}

void Player::Draw(Math::TransformationMatrix camera_matrix) {
    if (hurt_timer->Remaining() == 0.0 || hurt_timer->TickTock() == true) {
        CS230::GameObject::Draw(camera_matrix);
    }
}