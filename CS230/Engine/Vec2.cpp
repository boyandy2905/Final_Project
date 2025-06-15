/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Vec2.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 20, 2025
*/

#include "Vec2.h"

// vec2
bool Math::vec2::operator==(const vec2& v) {
    return ( x == v.x && y == v.y );
}

bool Math::vec2::operator!=(const vec2& v) {
    return !( x == v.x && y == v.y );
}

Math::vec2 Math::vec2::operator+(const vec2& v) {
    return { x + v.x, y + v.y };
}

Math::vec2& Math::vec2::operator+=(const vec2& v) {
    x += v.x;
    y += v.y;
    return *this;
}

Math::vec2 Math::vec2::operator-(const vec2& v) {
    return { x - v.x, y - v.y };
}

Math::vec2& Math::vec2::operator-=(const vec2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

Math::vec2 Math::vec2::operator*(double scale) {
    return { x*scale, y*scale };
}

Math::vec2& Math::vec2::operator*=(double scale) {
    x *= scale;
    y *= scale;
    return *this;
}

Math::vec2 Math::vec2::operator/(double divisor) {
    return { x/divisor, y/divisor };
}

Math::vec2& Math::vec2::operator/=(double divisor) {
    x /= divisor;
    y /= divisor;
    return *this;
}

Math::vec2 Math::vec2::operator-() const {
    return vec2( - x, -y );
}

Math::vec2 Math::vec2::Normalize() const {
    double square = x * x + y * y;
    double length = sqrt(square);

    if (length == 0.0) {
        return vec2{ 0.0, 0.0 };
    }
    return vec2{ x / length, y / length };
}

//ivec2
bool Math::ivec2::operator==(const ivec2& v) {
    return (x == v.x && y == v.y);
}

bool Math::ivec2::operator!=(const ivec2& v) {
    return !(x == v.x && y == v.y);
}

Math::ivec2 Math::ivec2::operator+(const ivec2& v) {
    return { x + v.x, y + v.y };
}

Math::ivec2& Math::ivec2::operator+=(const ivec2& v) {
    x += v.x;
    y += v.y;
    return *this;
}

Math::ivec2 Math::ivec2::operator-(const ivec2& v) {
    return { x - v.x, y - v.y };
}

Math::ivec2& Math::ivec2::operator-=(const ivec2& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

Math::ivec2 Math::ivec2::operator*(int scale) {
    return { x * scale, y * scale };
}

Math::ivec2& Math::ivec2::operator*=(int scale) {
    x *= scale;
    y *= scale;
    return *this;
}

Math::ivec2 Math::ivec2::operator/(int divisor) {
    return { x / divisor, y / divisor };
}

Math::ivec2& Math::ivec2::operator/=(int divisor) {
    x /= divisor;
    y /= divisor;
    return *this;
}

Math::vec2 Math::ivec2::operator*(double scale) {
    return { x * scale, y * scale };
}

Math::vec2 Math::ivec2::operator/(double divisor) {
    return { x / divisor, y / divisor };
}

Math::ivec2 Math::ivec2::operator-() const {
    return ivec2(-x, -y);
}

// direct namespace
Math::vec2 Math::operator*(double scale, const vec2& v) {
    return { v.x * scale, v.y * scale };
}
