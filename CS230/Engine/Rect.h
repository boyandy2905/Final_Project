/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Rect.h
Project:    CS230 Engine
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 29, 2025
*/

#pragma once
#include "Vec2.h"
#include <cmath>
#include <iostream>

namespace Math {
    struct [[nodiscard]] rect {
        Math::vec2 point_1{ 0.0, 0.0 };
        Math::vec2 point_2{ 0.0, 0.0 };
        Math::vec2 Size() const noexcept { return { Right() - Left(), std::abs(Top() - Bottom()) };
        }

        double Left() const noexcept;
        double Right() const noexcept;
        double Bottom() const noexcept;
        double Top() const noexcept;
    };
    struct [[nodiscard]] irect {
        Math::ivec2 point_1{ 0, 0 };
        Math::ivec2 point_2{ 0, 0 };
        Math::ivec2 Size() const noexcept { return { Right() - Left(), std::abs(Top() - Bottom())};
        }

        int Left() const noexcept;
        int Right() const noexcept;
        int Bottom() const noexcept;
        int Top() const noexcept;
    };

    //struct [[nodiscard]] rect {
    //    Math::vec2 bottom_left{ 0.0, 0.0 };
    //    Math::vec2 top_right{ 0.0, 0.0 };
    //    Math::vec2 Size() const noexcept { return { top_right.x - bottom_left.x, std::abs(top_right.y - bottom_left.y) };
    //    }
    //};
    //struct [[nodiscard]] irect {
    //    Math::ivec2 bottom_left{ 0, 0 };
    //    Math::ivec2 top_right{ 0, 0 };
    //    Math::ivec2 Size() const noexcept { return { top_right.x - bottom_left.x, std::abs(top_right.y - bottom_left.y) };
    //    }
    //};

    //struct rect {
    //    Math::vec2 bottom_left{ 0.0, 0.0 };
    //    Math::vec2 top_right{ 0.0, 0.0 };
    //};
    //struct irect {
    //    Math::ivec2 bottom_left{ 0, 0 };
    //    Math::ivec2 top_right{ 0, 0 };
    //};
}
