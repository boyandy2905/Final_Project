/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  ShowCollision.h
Project:    CS230 Engine
Author:     Jonathan Holmes, Sehoon Kim
Created:    May 17, 2025
*/

#pragma once
#include "../Engine/Component.h"
#include "../Engine/Engine.h"

namespace CS230 {
    class ShowCollision : public Component {
    public:
        ShowCollision();
        void Update(double dt) override;
        bool Enabled();
    private:
        bool enabled;
    };
}
