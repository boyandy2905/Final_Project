/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Cat.cpp
Project:    CS230 Game
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 22, 2025
*/

#pragma once
#include "Cat.h"
#include "../Engine/Engine.h"
#include "Mode1.h"
#include "States.h"

//void Cat::Load() {
//    sprite.Load("Assets/Cat.spt");
//    velocity = { 0,0 };
//    position = start_position;
//    // jumping = false;
//    // going_up = false;
//    flipped = false;
//    current_state = &state_idle;
//    current_state->Enter(this);
//}

//void Cat::Update(double dt) {
//    update_x_velocity(dt);
//    //if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
//    //    if (velocity.x >= 0)
//    //    {
//    //        velocity.x += x_acceleration * dt;
//    //        if (velocity.x >= max_velocity)
//    //        {
//    //            Engine::GetLogger().LogDebug("Reached max velocity while moving right");
//    //            velocity.x = max_velocity;
//    //        }
//    //        else
//    //        {
//    //            Engine::GetLogger().LogDebug("Accelerating right");
//    //        }
//    //    }
//    //    else
//    //    {
//    //        Engine::GetLogger().LogDebug("Skidding to the left");
//    //        velocity.x += x_drag * 2 * dt;
//    //    }
//    //    if (flipped == true)
//    //    {
//    //        flipped = false;
//    //    }
//    //}
//    //else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
//    //    if (velocity.x <= 0)
//    //    {
//    //        velocity.x += -x_acceleration * dt;
//    //        if (velocity.x <= -max_velocity)
//    //        {
//    //            Engine::GetLogger().LogDebug("Reached max velocity while moving left");
//    //            velocity.x = -max_velocity;
//    //        }
//    //        else
//    //        {
//    //            Engine::GetLogger().LogDebug("Accelerating left");
//    //        }
//    //    }
//    //    else
//    //    {
//    //        Engine::GetLogger().LogDebug("Skidding to the right");
//    //        velocity.x += -x_drag * 2 * dt;
//    //    }
//    //    if (flipped == false)
//    //    {
//    //        flipped = true;
//    //    }
//    //}
//    //else
//    //{
//    //    if (velocity.x > x_drag * dt)
//    //    {
//    //        Engine::GetLogger().LogDebug("Dragging while moving right");
//    //        velocity.x -= x_drag * dt;
//    //    }
//    //    else if (velocity.x < -x_drag * dt)
//    //    {
//    //        Engine::GetLogger().LogDebug("Dragging while moving left");
//    //        velocity.x += x_drag * dt;
//    //    }
//    //    else
//    //    {
//    //        if (velocity.x != 0)
//    //        {
//    //            Engine::GetLogger().LogDebug("Stopped");
//    //        }
//    //        velocity.x = 0;
//    //    }
//    //}
//    // Tutorial 3.1
//    //if (jumping == true)
//    //{
//    //    velocity.y -= Mode1::gravity * dt;
//    //    if (going_up == true && Engine::GetInput().KeyJustReleased(CS230::Input::Keys::Up))
//    //    {
//    //        Engine::GetLogger().LogDebug("Released Jump Early: " + std::to_string(position.y));
//    //        velocity.y = 0;
//    //        going_up = false;
//    //    }
//    //    if (going_up == true && velocity.y < 0)
//    //    {
//    //        Engine::GetLogger().LogDebug("Max Height: " + std::to_string(position.y));
//    //        going_up = false;
//    //    }
//    //}
//    //if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Up) && position.y == Mode1::floor)
//    //{
//    //    velocity.y = jump_velocity;
//    //    jumping = true;
//    //    going_up = true;
//    //    Engine::GetLogger().LogDebug("Starting Jump: " + std::to_string(position.y));
//    //}
//    //position += velocity * dt;
//    //if (jumping == true && position.y <= Mode1::floor)
//    //{
//    //    velocity.y = 0;
//    //    position.y = Mode1::floor;
//    //    jumping = false;
//    //    Engine::GetLogger().LogDebug("Landing: " + std::to_string(position.y));
//    //}
//    current_state->Update(this, dt);
//    sprite.Update(dt);
//    position += velocity * dt;
//    current_state->CheckExit(this);
//    // Tutorial 3.2
//    if (position.x - sprite.GetFrameSize().x / 2 < camera.GetPosition().x) {
//        position.x = camera.GetPosition().x + sprite.GetFrameSize().x / 2;
//        velocity.x = 0;
//    }
//    if (position.x + sprite.GetFrameSize().x / 2 > camera.GetPosition().x + Engine::GetWindow().GetSize().x) {
//        position.x = camera.GetPosition().x + Engine::GetWindow().GetSize().x - sprite.GetFrameSize().x / 2;
//        velocity.x = 0;
//    }
//    // Tutorial 4.1
//    object_matrix = Math::TranslationMatrix(position);
//    if (flipped == true) {
//        object_matrix *= Math::ScaleMatrix({ -1.0, 1.0 });
//    }
//}

//Cat::Cat(Math::vec2 start_position, const CS230::Camera& camera) : /*start_position(start_position), */position(start_position), camera(camera) {
//    sprite.Load("Assets/Cat.spt");
//    velocity = { 0,0 };
//    position = start_position;
//    flipped = false;
//    current_state = &state_idle;
//    current_state->Enter(this);
//}

//void Cat::Draw(Math::TransformationMatrix camera_matrix) {
//    sprite.Draw(camera_matrix * object_matrix);
//}

//void Cat::update_x_velocity(double dt) {
//    if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
//        velocity.x += x_acceleration * dt;
//        if (velocity.x > max_velocity) {
//            velocity.x = max_velocity;
//        }
//    }
//    else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
//        velocity.x -= x_acceleration * dt;
//        if (velocity.x < -max_velocity) {
//            velocity.x = -max_velocity;
//        }
//    }
//    else {
//        if (velocity.x > x_drag * dt) {
//            velocity.x -= x_drag * dt;
//        }
//        else if (velocity.x < -x_drag * dt) {
//            velocity.x += x_drag * dt;
//        }
//        else {
//            velocity.x = 0;
//        }
//    }
//}

//void Cat::Update(double dt) {
//    current_state->Update(this, dt);
//    sprite.Update(dt);
//    UpdatePosition(dt * GetVelocity());
//    current_state->CheckExit(this);
//
//    // Boundary Check
//    if (GetPosition().x < camera.GetPosition().x + sprite.GetFrameSize().x / 2.0) {
//        SetPosition({ camera.GetPosition().x + sprite.GetFrameSize().x / 2, GetPosition().y });
//        SetVelocity({ 0, GetVelocity().y });
//    }
//    if (GetPosition().x + sprite.GetFrameSize().x / 2.0 > camera.GetPosition().x + Engine::GetWindow().GetSize().x) {
//        SetPosition({ camera.GetPosition().x + Engine::GetWindow().GetSize().x - sprite.GetFrameSize().x / 2, GetPosition().y });
//        SetVelocity({ 0, GetVelocity().y });
//    }
//}

// State Log
//void Cat::change_state(State* new_state) {
//    Engine::GetLogger().LogDebug("Cat Leaving State: " + current_state->GetName());
//    Engine::GetLogger().LogDebug("Cat Entering State: " + new_state->GetName());
//    current_state = new_state;
//    current_state->Enter(this);
//}

//Cat::Cat(Math::vec2 start_position, const CS230::Camera& camera) :
//    GameObject(start_position),
//    start_y_position(start_position.y),
//    camera(camera)
//{
//    AddGOComponent(new CS230::Sprite("Assets/Cat.spt"));
//    change_state(&state_idle);
//    //sprite.Load("Assets/Cat.spt");
//}

Cat::Cat(Math::vec2 start_position, GameObject* first_platform) :
    GameObject(start_position),
    start_y_position(start_position.y),
    standing_on(first_platform)
{
    AddGOComponent(new CS230::Sprite("Assets/Cat.spt", this));
    change_state(&state_idle);
    hurt_timer = new CS230::Timer(0.0);
    AddGOComponent(hurt_timer);

    //AddGOComponent(new CS230::Sprite("Assets/Cat.spt"));
    //sprite.Load("Assets/Cat.spt");
}

void Cat::Update(double dt) {
    GameObject::Update(dt);
    CS230::RectCollision* collider = GetGOComponent<CS230::RectCollision>();
    // Boundary Check
    if (collider->WorldBoundary().Left() < Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().x) {
        UpdatePosition({ Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().x - collider->WorldBoundary().Left(), 0 });
        SetVelocity({ 0, GetVelocity().y });
    }
    if (collider->WorldBoundary().Right() > Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().x + Engine::GetWindow().GetSize().x) {
        UpdatePosition({ Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().x + Engine::GetWindow().GetSize().x-collider->WorldBoundary().Right(), 0});
        SetVelocity({ 0, GetVelocity().y });
    }

    //if (GetPosition().x < Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().x + GetGOComponent<CS230::Sprite>()->GetFrameSize().x / 2.0) {
    //    SetPosition({ Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().x + GetGOComponent<CS230::Sprite>()->GetFrameSize().x / 2.0, GetPosition().y });
    //    SetVelocity({ 0, GetVelocity().y });
    //}
    //if (GetPosition().x + GetGOComponent<CS230::Sprite>()->GetFrameSize().x / 2.0 > Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().x + Engine::GetWindow().GetSize().x) {
    //    SetPosition({ Engine::GetGameStateManager().GetGSComponent<CS230::Camera>()->GetPosition().x + Engine::GetWindow().GetSize().x - GetGOComponent<CS230::Sprite>()->GetFrameSize().x / 2.0, GetPosition().y });
    //    SetVelocity({ 0, GetVelocity().y });
    //}
}

void Cat::update_x_velocity(double dt) {
    if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
        SetVelocity({ GetVelocity().x + x_acceleration * dt , GetVelocity().y });
        if (GetVelocity().x > max_velocity) {
            SetVelocity({ max_velocity, GetVelocity().y});
        }
    }
    else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
        SetVelocity({ GetVelocity().x - x_acceleration * dt ,GetVelocity().y });
        if (GetVelocity().x < -max_velocity) {
            SetVelocity({ -max_velocity, GetVelocity().y });
        }
    }
    else {
        if (GetVelocity().x > x_drag * dt) {
            SetVelocity({ GetVelocity().x - x_drag * dt, GetVelocity().y });
        }
        else if (GetVelocity().x < -x_drag * dt) {
            SetVelocity({ GetVelocity().x + x_drag * dt, GetVelocity().y });
        }
        else {
            SetVelocity({ 0, GetVelocity().y });
        }
    }
}

bool Cat::CanCollideWith(GameObjectTypes other_object_type) {
    return other_object_type != GameObjectTypes::Particle;
}

void Cat::ResolveCollision(GameObject* other_object) {
    Math::rect cat_rect = GetGOComponent<CS230::RectCollision>()->WorldBoundary();
    Math::rect other_rect = other_object->GetGOComponent<CS230::RectCollision>()->WorldBoundary();

    //double crash_left = std::abs(cat_rect.Right() - other_rect.Left());
    //double crash_right = std::abs(cat_rect.Left() - other_rect.Right());

    switch (other_object->Type())
    {
    case GameObjectTypes::Floor: [[fallthrough]];
   //     if (current_state == &state_falling && cat_rect.Top() > other_rect.Top()) {
   //         SetPosition({ GetPosition().x, other_rect.Top() });
			//standing_on = other_object;
			//current_state->CheckExit(this);
   //     }
   //     break;
    case GameObjectTypes::Crates:
        if (current_state == &state_falling) {
            if (cat_rect.Top() > other_rect.Top()) {
                if (other_object->IsCollidingWith(GetPosition())) {
                    SetPosition({ GetPosition().x, other_rect.Top() });
                    standing_on = other_object;
                    current_state->CheckExit(this);
                    return;
                }
            }
        }
        if (cat_rect.Left() < other_rect.Left()) {
            UpdatePosition(Math::vec2{ (other_rect.Left() - cat_rect.Right()), 0.0 });
            SetVelocity({ 0, GetVelocity().y });
        }
        else {
            UpdatePosition(Math::vec2{ (other_rect.Right() - cat_rect.Left()), 0.0 });
            SetVelocity({ 0, GetVelocity().y });
        }

        //if (crash_left < crash_right) {
        //    UpdatePosition({ other_rect.Left() - cat_rect.Right(), 0 });
        //    SetVelocity({ 0, GetVelocity().y });
        //}
        //else {
        //    UpdatePosition({ other_rect.Right() - cat_rect.Left(), 0 });
        //    SetVelocity({ 0, GetVelocity().y });
        //}
        break;
    case GameObjectTypes::Robot:
        if (current_state == &state_falling && cat_rect.Top() > other_rect.Top() && hurt_timer->Remaining() == 0) {
            Engine::GetGameStateManager().GetGSComponent<CS230::ParticleManager<Particles::Smoke>>()->Emit(2, GetPosition(), { 0, 0 }, { 0, 100 }, 2 * PI / 3);
            SetPosition({ GetPosition().x, other_rect.Top() });
            SetVelocity({ GetVelocity().x, pop_velocity });
            other_object->ResolveCollision(this);
        }
        else {
            if (cat_rect.Left() < other_rect.Left()) {
                SetVelocity({ -hurt_acceleration, hurt_velocity });
            }
            else {
                SetVelocity({ hurt_acceleration, hurt_velocity });
            }
            change_state(&state_falling);
            hurt_timer->Set(hurt_time);

            //if (crash_left < crash_right) {
            //    UpdatePosition({ other_rect.Left() - cat_rect.Right(), 0 });
            //    SetVelocity({ -hurt_acceleration, hurt_velocity });
            //}
            //else {
            //    UpdatePosition({ other_rect.Right() - cat_rect.Left(), 0 });
            //    SetVelocity({ hurt_acceleration, hurt_velocity });
            //}
            //change_state(&state_falling);
            //hurt_timer->Set(hurt_time);
        }
        standing_on = nullptr;
        break;
    case GameObjectTypes::Asteroid:
        if (current_state == &state_falling && cat_rect.Top() > other_rect.Top() && hurt_timer->Remaining() == 0) {
            SetPosition({ GetPosition().x, other_rect.Top() });
            SetVelocity({ GetVelocity().x, bounce_velocity });
            other_object->ResolveCollision(this);
        }
        else {
            if (cat_rect.Left() < other_rect.Left()) {
                SetVelocity({ -hurt_acceleration, hurt_velocity });
            }
            else {
                SetVelocity({ hurt_acceleration, hurt_velocity });
            }
            change_state(&state_falling);
            hurt_timer->Set(hurt_time);

            //if (crash_left < crash_right) {
            //    UpdatePosition({ other_rect.Left() - cat_rect.Right(), 0 });
            //    SetVelocity({ -hurt_acceleration, hurt_velocity });
            //}
            //else {
            //    UpdatePosition({ other_rect.Right() - cat_rect.Left(), 0 });
            //    SetVelocity({ hurt_acceleration, hurt_velocity });
            //}
            //change_state(&state_falling);
            //hurt_timer->Set(hurt_time);
        }
        standing_on = nullptr;
        break;
    case GameObjectTypes::Portal: {
        static_cast<Portal*>(other_object)->GoToState();
        break;
        }
    }
}

void Cat::Draw(Math::TransformationMatrix camera_matrix) {
    if (hurt_timer->Remaining() == 0.0 || hurt_timer->TickTock() == true) {
        CS230::GameObject::Draw(camera_matrix);
    }
}

// Jumping
void Cat::State_Jumping::Enter(GameObject* object) {
    Cat* cat = static_cast<Cat*>(object);

    cat->GetGOComponent<CS230::Sprite>()->PlayAnimation(static_cast<int>(Animations::Jumping));
    cat->UpdateVelocity({ 0, Cat::jump_velocity });
    cat->standing_on = nullptr;
}
void Cat::State_Jumping::Update(GameObject* object, double dt) {
    Cat* cat = static_cast<Cat*>(object);

    cat->SetVelocity({ cat->GetVelocity().x, cat->GetVelocity().y - Engine::GetGameStateManager().GetGSComponent<Gravity>()->GetValue() * dt });
    cat->update_x_velocity(dt);
}
void Cat::State_Jumping::CheckExit(GameObject* object) {
    Cat* cat = static_cast<Cat*>(object);

    if (Engine::GetInput().KeyDown(CS230::Input::Keys::Up) == false) {
        cat->change_state(&cat->state_falling);
        cat->SetVelocity({ cat->GetVelocity().x, 0 });
    }
    else if (cat->GetVelocity().y <= 0) {
        cat->change_state(&cat->state_falling);
    }
}

//void Cat::State_Jumping::Enter(Cat* cat) {
//    cat->sprite.PlayAnimation(static_cast<int>(Animations::Jumping));
//    cat->velocity.y = Cat::jump_velocity;
//}
//void Cat::State_Jumping::Update(Cat* cat, double dt) {
//    cat->velocity.y -= Mode1::gravity * dt;
//    cat->update_x_velocity(dt);
//}
//void Cat::State_Jumping::CheckExit(Cat* cat) {
//    if (Engine::GetInput().KeyDown(CS230::Input::Keys::Up) == false) {
//        cat->change_state(&cat->state_falling);
//        cat->velocity.y = 0;
//    }
//    else if (cat->velocity.y <= 0) {
//        cat->change_state(&cat->state_falling);
//    }
//}

// Idle
void Cat::State_Idle::Enter(GameObject* object) {
    Cat* cat = static_cast<Cat*>(object);

    cat->GetGOComponent<CS230::Sprite>()->PlayAnimation(static_cast<int>(Animations::Idle));
}
void Cat::State_Idle::Update([[maybe_unused]] GameObject* object, [[maybe_unused]] double dt) {

}
void Cat::State_Idle::CheckExit(GameObject* object) {
    Cat* cat = static_cast<Cat*>(object);

    if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
        cat->SetScale({ -1.0, 1.0 });
        cat->change_state(&cat->state_running);
    }
    else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
        cat->SetScale({ 1.0, 1.0 });
        cat->change_state(&cat->state_running);
    }
    else if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Up)) {
        cat->change_state(&cat->state_jumping);
    }
}

// Falling
void Cat::State_Falling::Enter(GameObject* object) {
    Cat* cat = static_cast<Cat*>(object);

    cat->fall_start_y_position = cat->GetPosition().y;
    cat->GetGOComponent<CS230::Sprite>()->PlayAnimation(static_cast<int>(Animations::Falling));
}
void Cat::State_Falling::Update(GameObject* object, double dt) {
    Cat* cat = static_cast<Cat*>(object);

    cat->SetVelocity({ cat->GetVelocity().x, cat->GetVelocity().y - Engine::GetGameStateManager().GetGSComponent<Gravity>()->GetValue() * dt });
    cat->update_x_velocity(dt);
}
void Cat::State_Falling::CheckExit(GameObject* object) {
    Cat* cat = static_cast<Cat*>(object);

    if (cat->standing_on != nullptr) {
        double falling_height = cat->fall_start_y_position - cat->GetPosition().y;
        if (falling_height > LargeFallHeight) {
            Engine::GetGameStateManager().GetGSComponent<CS230::ParticleManager<Particles::Smoke>>()->Emit(2, cat->GetPosition(), { 0, 0 }, { 0, 100 }, PI / 2);
        }
        if (cat->GetVelocity().x > 0) {
            if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
                cat->change_state(&cat->state_skidding);
            }
            else {
                cat->change_state(&cat->state_running);
            }
        }
        else if (cat->GetVelocity().x < 0) {
            if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
                cat->change_state(&cat->state_skidding);
            }
            else {
                cat->change_state(&cat->state_running);
            }
        }
        else {
            cat->change_state(&cat->state_idle);
        }
        cat->SetVelocity({ cat->GetVelocity().x, 0 });
    }
    if (cat->GetPosition().y < -500) {
        Engine::GetGameStateManager().SetNextGameState(static_cast<int>(States::MainMenu));
    }

    //if (cat->GetPosition().y <= cat->start_y_position) {
    //    cat->SetVelocity({ cat->GetVelocity().x, 0 });
    //    cat->SetPosition({ cat->GetPosition().x, cat->start_y_position });
    //    if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
    //        cat->change_state(&cat->state_running);
    //    }
    //    else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
    //        cat->change_state(&cat->state_running);
    //    }
    //    else if (cat->GetVelocity().x == 0) {
    //        cat->change_state(&cat->state_idle);
    //    }
    //    else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
    //        if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
    //            cat->change_state(&cat->state_skidding);
    //        }
    //    }
    //    else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
    //        if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
    //            cat->change_state(&cat->state_skidding);
    //        }
    //    }
    //}
}

//void Cat::State_Falling::Update(Cat* cat, double dt) {
//    cat->velocity.y -= Mode1::gravity * dt;
//    cat->update_x_velocity(dt);
//}
//void Cat::State_Falling::CheckExit(Cat* cat) {
//    if (cat->position.y <= Mode1::floor) {
//        cat->velocity.y = 0;
//        cat->position.y = Mode1::floor;
//        if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
//            cat->change_state(&cat->state_running);
//        }
//        else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
//            cat->change_state(&cat->state_running);
//        }
//        else if (cat->velocity.x == 0) {
//            cat->change_state(&cat->state_idle);
//        }
//        else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
//            if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
//                cat->change_state(&cat->state_skidding);
//            }
//        }
//        else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
//            if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
//                cat->change_state(&cat->state_skidding);
//            }
//        }
//    }
//}

// Running
void Cat::State_Running::Enter(GameObject* object) {
    Cat* cat = static_cast<Cat*>(object);

    cat->GetGOComponent<CS230::Sprite>()->PlayAnimation(static_cast<int>(Animations::Running));
    if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right) && cat->GetVelocity().x > 0) {
        cat->SetScale({ 1.0, 1.0 });
    }
    else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left) && cat->GetVelocity().x < 0) {
        cat->SetScale({ -1.0, 1.0 });
    }
}
void Cat::State_Running::Update(GameObject* object, double dt) {
    Cat* cat = static_cast<Cat*>(object);

    cat->update_x_velocity(dt);
}
void Cat::State_Running::CheckExit(GameObject* object) {
    Cat* cat = static_cast<Cat*>(object);
    
    if (cat->GetVelocity().x == 0) {
        cat->change_state(&cat->state_idle);
    }
    else if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Up)) {
        cat->change_state(&cat->state_jumping);
    }
    else if (cat->GetVelocity().x < 0 && Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
        cat->change_state(&cat->state_skidding);
    }
    else if (cat->GetVelocity().x >= 0 && Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
        cat->change_state(&cat->state_skidding);
    }

    if (cat->standing_on != nullptr && cat->standing_on->IsCollidingWith(cat->GetPosition()) == false) {
        cat->standing_on = nullptr;
        cat->change_state(&cat->state_falling);
    }
}

//void Cat::State_Running::Enter(Cat* cat) {
//    cat->sprite.PlayAnimation(static_cast<int>(Animations::Running));
//    if (Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
//        cat->flipped = false;
//    }
//    else if (Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
//        cat->flipped = true;
//    }
//}

// Skidding
void Cat::State_Skidding::Enter(GameObject* object) {
    Cat* cat = static_cast<Cat*>(object);

    cat->GetGOComponent<CS230::Sprite>()->PlayAnimation(static_cast<int>(Animations::Skidding));

    Engine::GetGameStateManager().GetGSComponent<CS230::ParticleManager<Particles::Smoke>>()->Emit(2, cat->GetPosition(), { 0, 0 }, { 2 * cat->GetVelocity().x, 0 }, PI / 6);
}
void Cat::State_Skidding::Update(GameObject* object, double dt) {
    Cat* cat = static_cast<Cat*>(object);

    if (cat->GetVelocity().x >= 0) {
        cat->SetVelocity({ cat->GetVelocity().x - (x_drag + x_acceleration) * dt, cat->GetVelocity().y });
    }
    else if (cat->GetVelocity().x < 0) {
        cat->SetVelocity({ cat->GetVelocity().x + (x_drag + x_acceleration) * dt, cat->GetVelocity().y });
    }
}
void Cat::State_Skidding::CheckExit(GameObject* object) {
    Cat* cat = static_cast<Cat*>(object);

    if (cat->GetVelocity().x == 0) {
        cat->change_state(&cat->state_idle);
    }
    else if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Up)) {
        cat->change_state(&cat->state_jumping);
    }
    else if (cat->GetVelocity().x < 0 && Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
        cat->change_state(&cat->state_running);
    }
    else if (cat->GetVelocity().x >= 0 && Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
        cat->change_state(&cat->state_running);
    }
}

//void Cat::State_Skidding::CheckExit(Cat* cat) {
//    if (cat->velocity.x == 0) {
//        cat->change_state(&cat->state_idle);
//    }
//    else if (Engine::GetInput().KeyJustPressed(CS230::Input::Keys::Up)) {
//        cat->change_state(&cat->state_jumping);
//    }
//    else if (cat->velocity.x < 0 && Engine::GetInput().KeyDown(CS230::Input::Keys::Left)) {
//        cat->change_state(&cat->state_running);
//    }
//    else if (cat->velocity.x >= 0 && Engine::GetInput().KeyDown(CS230::Input::Keys::Right)) {
//        cat->change_state(&cat->state_running);
//    }
//}
