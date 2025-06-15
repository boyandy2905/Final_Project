/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Background.cpp
Project:    CS230 Game
Author:     Jonathan Holmes, Sehoon Kim
Created:    March 30, 2025
*/

#include "Background.h"
#include "../Engine/Engine.h"
#include "Mode1.h"

//void Background::Draw(const CS230::Camera& camera) {
//	for (int i = 0; i < backgrounds.size(); i++)
//	{
//		double scale = camera.GetPosition().x * backgrounds[i].speed;
//		backgrounds[i].texture.Draw(Math::vec2(0 - scale, 0 - camera.GetPosition().y));
//		backgrounds[i].texture.Draw(Math::TranslationMatrix(scale));
//	}
//}

//void Background::Draw(Math::TransformationMatrix &camera_matrix) {
//	for (int i = 0; i < backgrounds.size(); i++)
//	{
//		Math::TranslationMatrix scale_x = Math::TranslationMatrix(Math::vec2(camera_matrix[0][2] * backgrounds[i].speed, camera_matrix[1][2] * backgrounds[i].speed));
//		backgrounds[i].texture.Draw(scale_x);
//	}
//}

//void Background::Draw(Math::TransformationMatrix &camera_matrix) {
//	for (auto&background : backgrounds)
//	{
//		Math::TranslationMatrix scale_x = Math::TranslationMatrix(Math::vec2(camera_matrix[0][2] * background.speed, camera_matrix[1][2] * background.speed));
//		background.texture.Draw(scale_x);
//	}
//}

void Background::Add(const std::filesystem::path& texture_path, double speed) {
	backgrounds.push_back(ParallaxLayer{ Engine::GetTextureManager().Load(texture_path), speed });
	//backgrounds.push_back(ParallaxLayer({ texture_path, speed }));
}

void Background::Unload() {
	backgrounds.clear();
}

void Background::Draw(const CS230::Camera& camera) {
	for (ParallaxLayer& background : backgrounds) {
		Math::vec2 inverted_position = -Math::vec2{ camera.GetPosition().x * background.speed, camera.GetPosition().y };
		Math::TranslationMatrix new_matrix = Math::TranslationMatrix(inverted_position);
		background.texture->Draw(new_matrix);
		//background.texture.Draw(new_matrix);
	}
}

Math::ivec2 Background::GetSize() {
	return backgrounds[backgrounds.size() - 1].texture->GetSize();
	//return backgrounds[backgrounds.size() - 1].texture.GetSize();
}