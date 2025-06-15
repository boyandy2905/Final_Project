/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Input.h
Project:    CS230 Engine
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 17, 2025
*/

#pragma once
#include <vector>

namespace CS230 {
    class Input {
    public:
        enum class Keys {
            A, B, C, D, E, F, G, H, I, J, K, L, M,
            N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
            Space, Enter, Left, Up, Right, Down, Tab, Left_Shift,
            Count
        };

        Input();
        void Update();
        void SetKeyDown(Keys, bool);
        bool KeyDown(Keys);
        bool KeyJustPressed(Keys);
        bool KeyJustReleased(Keys);

    private:
        std::vector<bool> keys_down;
        std::vector<bool> previous_keys_down;
    };
}