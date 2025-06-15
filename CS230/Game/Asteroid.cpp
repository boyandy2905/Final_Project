/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Asteroid.cpp
Project:    CS230 Game
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 26, 2025
*/

#pragma once
#include "Asteroid.h"
#include "../Engine/Engine.h"
#include "Mode1.h"

//Asteroid::Asteroid(Math::vec2 start_position) :
//    /*start_position(start_position), */position(start_position) {
//    sprite.Load("Assets/Asteroid.spt");
//    velocity = { 0,0 };
//    position = start_position;
//    current_state = &state_bouncing;
//    current_state->Enter(this);
//}

//void Asteroid::Load() {
//	   sprite.Load("Assets/Asteroid.spt");
//    velocity = { 0,0 };
//	   position = start_position;
//    current_state = &state_bouncing;
//    current_state->Enter(this);
//}

//void Asteroid::Update(double dt) {
//    //velocity.y -= Mode1::gravity * dt;
//    //position += velocity * dt;
//
//    //if (position.y < Mode1::floor) {
//    //    position.y = Mode1::floor;
//    //    velocity.y = bounce_velocity;
//    //}
//    current_state->Update(this, dt);
//    sprite.Update(dt);
//    current_state->CheckExit(this);
//    object_matrix = Math::TranslationMatrix(position);
//}

//void Asteroid::Draw(Math::TransformationMatrix camera_matrix) {
//    sprite.Draw(camera_matrix * object_matrix);
//}

//void Asteroid::Update(double dt) {
//    current_state->Update(this, dt);
//    sprite.Update(dt);
//    UpdatePosition(dt * GetVelocity());
//    current_state->CheckExit(this);
//}

// State Log
//void Asteroid::change_state(State* new_state) {
//    Engine::GetLogger().LogDebug("Asteroid Leaving State: " + current_state->GetName());
//    Engine::GetLogger().LogDebug("Asteroid Entering State: " + new_state->GetName());
//    current_state = new_state;
//    current_state->Enter(this);
//}

//Asteroid::Asteroid(Math::vec2 start_position) :
//    GameObject(start_position),
//    start_y_position(start_position.y)
//{
//    AddGOComponent(new CS230::Sprite("Assets/Asteroid.spt", this));
//    change_state(&state_landing);
//
//    //AddGOComponent(new CS230::Sprite("Assets/Asteroid.spt"));
//    //sprite.Load("Assets/Asteroid.spt");
//}

Asteroid::Asteroid(Math::vec2 start_position) :
    GameObject(start_position)
{
    AddGOComponent(new CS230::Sprite("Assets/Asteroid.spt", this));
    change_state(&state_landing);
}

bool Asteroid::CanCollideWith(GameObjectTypes type) {
    return type == GameObjectTypes::Floor;
}

void Asteroid::ResolveCollision(GameObject* other_object) {
    if (other_object->Type() == GameObjectTypes::Floor) {
        SetPosition({ GetPosition().x, other_object->GetGOComponent<CS230::RectCollision>()->WorldBoundary().Top()});
        SetVelocity({ 0, 0 });
        change_state(&state_landing);
    }
}

// Bouncing
void Asteroid::State_Bouncing::Enter(GameObject* object) {
    Asteroid* asteroid = static_cast<Asteroid*>(object);

    asteroid->GetGOComponent<CS230::Sprite>()->PlayAnimation(static_cast<int>(Animations::None));
    asteroid->SetVelocity({ 0, bounce_velocity });
}
void Asteroid::State_Bouncing::Update(GameObject* object, double dt) {
    Asteroid* asteroid = static_cast<Asteroid*>(object);

    asteroid->SetVelocity({ asteroid->GetVelocity().x, asteroid->GetVelocity().y - Engine::GetGameStateManager().GetGSComponent<Gravity>()->GetValue() * dt});
}
void Asteroid::State_Bouncing::CheckExit([[maybe_unused]] GameObject* object) {
    //Asteroid* asteroid = static_cast<Asteroid*>(object);
    //if (asteroid->GetPosition().y < asteroid->start_y_position) {
    //    asteroid->SetPosition({ asteroid->GetPosition().x, asteroid->start_y_position });
    //    asteroid->SetVelocity({ 0, 0 });
    //    asteroid->change_state(&asteroid->state_landing);
    //}
}
//void Asteroid::State_Bouncing::Enter(Asteroid* asteroid) {
//    asteroid->sprite.PlayAnimation(static_cast<int>(Animations::None));
//    asteroid->velocity.y = Asteroid::bounce_velocity;
//}
//void Asteroid::State_Bouncing::Update(Asteroid* asteroid, double dt) {
//    asteroid->velocity.y -= Mode1::gravity * dt;
//    asteroid->position.y += asteroid->velocity.y * dt;
//}
//void Asteroid::State_Bouncing::CheckExit(Asteroid* asteroid) {
//    if (asteroid->position.y <= Mode1::floor) {
//        asteroid->change_state(&asteroid->state_landing);
//    }
//}

// Landing
void Asteroid::State_Landing::Enter(GameObject* object) {
    Asteroid* asteroid = static_cast<Asteroid*>(object);

    asteroid->GetGOComponent<CS230::Sprite>()->PlayAnimation(static_cast<int>(Animations::Land));
}
void Asteroid::State_Landing::Update([[maybe_unused]] GameObject* object, [[maybe_unused]] double dt) {

}
void Asteroid::State_Landing::CheckExit(GameObject* object) {
    Asteroid* asteroid = static_cast<Asteroid*>(object);

    if (asteroid->GetGOComponent<CS230::Sprite>()->AnimationEnded() == true) {
        asteroid->change_state(&asteroid->state_bouncing);
    }
}
//void Asteroid::State_Landing::Enter(Asteroid* asteroid) {
//    asteroid->sprite.PlayAnimation(static_cast<int>(Animations::Land));
//    asteroid->velocity.y = 0;
//    asteroid->position.y = Mode1::floor;
//}