/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Camera.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 29, 2025
*/

#include "Camera.h"

//void CS230::Camera::Update(const Math::vec2& player_position) {
//    if (player_position.x > player_zone.top_right.x + position.x) {
//        position.x = player_position.x - player_zone.top_right.x;
//    }
//    if (player_position.x - position.x < player_zone.bottom_left.x) {
//        position.x = player_position.x - player_zone.bottom_left.x;
//    }
//
//    if (position.x < limit.bottom_left.x) {
//        position.x = limit.bottom_left.x;
//    }
//    if (position.x > limit.top_right.x) {
//        position.x = limit.top_right.x;
//    }
//    if (position.y < limit.bottom_left.y) {
//        position.y = limit.bottom_left.y;
//    }
//    if (position.y > limit.top_right.y) {
//        position.y = limit.top_right.y;
//    }
//}

void CS230::Camera::Update(const Math::vec2& player_position) {
    if (player_position.x > player_zone.Right() + position.x) {
        position.x = player_position.x - player_zone.Right();
    }
    if (player_position.x - position.x < player_zone.Left()) {
        position.x = player_position.x - player_zone.Left();
    }

    if (position.x < limit.Left()) {
        position.x = limit.Left();
    }
    if (position.x > limit.Right()) {
        position.x = limit.Right();
    }
    if (position.y < limit.Bottom()) {
        position.y = limit.Bottom();
    }
    if (position.y > limit.Top()) {
        position.y = limit.Top();
    }
}

CS230::Camera::Camera(Math::rect player_zone) :
    player_zone(player_zone), position({ 0,0 }) {

}

void CS230::Camera::SetPosition(Math::vec2 new_position) {
    position = new_position;
}

const Math::vec2& CS230::Camera::GetPosition() const {
    return { position };
}

void CS230::Camera::SetLimit(Math::irect new_limit) {
    limit = new_limit;
}

Math::TransformationMatrix CS230::Camera::GetMatrix() {
    return Math::TranslationMatrix(-position);
}
