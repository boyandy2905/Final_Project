/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Texture.h
Project:    CS230 Engine
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 22, 2025
*/

#pragma once
#include "Vec2.h"
#include "Matrix.h"
#include <filesystem>
#include <raylib.h>

namespace CS230 {
    class TextureManager;
    class Font;

    class Texture {
        friend class TextureManager;
        friend class Font;
    public:
        Math::ivec2 GetSize() const;

        Texture();
        ~Texture();
        Texture(const Texture&) = delete;
        Texture& operator=(const Texture&) = delete;
        Texture(Texture&& temporary) noexcept;
        Texture& operator=(Texture&& temporary) noexcept;

        void Draw(Math::TransformationMatrix display_matrix, unsigned int color = 0xFFFFFFFF) const; // const need or needless
        void Draw(Math::TransformationMatrix display_matrix, Math::ivec2 texel_position, Math::ivec2 frame_size, unsigned int color = 0xFFFFFFFF) const; // const need or needless

        //void Draw(Math::vec2 location) const;
        //void Draw(Math::TransformationMatrix display_matrix) const;
        //void Draw(Math::TransformationMatrix display_matrix, Math::ivec2 texel_position, Math::ivec2 frame_size) const;
        //void Load(const std::filesystem::path& file_name);

    private:
        Texture(Texture2D given_texture);
        Texture(const std::filesystem::path& file_name);
        Texture2D texture;

        //Texture2D texture;
    };
}
