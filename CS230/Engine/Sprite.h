/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Sprite.h
Project:    CS230 Engine
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 22, 2025
*/

#pragma once
#include <string>
#include <raylib.h>
#include "Vec2.h"
#include "Texture.h"
#include "Matrix.h"
#include "Animation.h"
#include "Component.h"
#include "GameObject.h"

namespace CS230 {
    class GameObject;

    class Sprite : public Component {
        friend class GameObject;
    public:
        Sprite();
        ~Sprite();
        Sprite(const std::filesystem::path& sprite_file, GameObject* given_object);

        void Update(double dt) override;
        void Load(const std::filesystem::path& sprite_file, GameObject* given_object);
        void Draw(Math::TransformationMatrix display_matrix);

        Math::ivec2 GetFrameSize() const; // const need or needless
        Math::ivec2 GetHotSpot(int index);

        void PlayAnimation(int animation);
        bool AnimationEnded();

        Sprite(const Sprite&) = delete;
        Sprite& operator=(const Sprite&) = delete;

        Sprite(Sprite&& temporary) noexcept;
        Sprite& operator=(Sprite&& temporary) noexcept;

        int CurrentAnimation() const;

        //void Load(const std::filesystem::path& texture_path);
        //void Load(const std::filesystem::path& texture_path, Math::ivec2 hotspot_position);
        //void Load(const std::filesystem::path& texture_path, std::initializer_list<Math::ivec2> spots);
        //void Draw(Math::vec2 position);
        //void ShowFrame(int index);
        //Math::ivec2 GetTextureSize();
        //std::vector<Math::ivec2> hotspots;
        //Sprite();
        //Sprite(const std::filesystem::path& sprite_file);
        //void Load(const std::filesystem::path& sprite_file);

    private:
        Math::ivec2 GetFrameTexel(int index) const;

        Texture* texture;
        std::vector<Math::ivec2> hotspots;

        int current_animation;
        Math::ivec2 frame_size;
        std::vector<Math::ivec2> frame_texels;
        std::vector<Animation*> animations;

        GameObject* object = nullptr;

        //Texture texture;
        //Math::ivec2 hotspot;
        //int current_frame;
    };
}
