/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  TextureManager.cpp
Project:    CS230 Engine
Author:     Jonathan Holmes, Sehoon Kim
Created:    April 28, 2025
*/

#pragma once
#include "TextureManager.h"
#include "Texture.h"
#include "Engine.h"

namespace {
	RenderTexture2D s_render_texture = {};
}

CS230::Texture* CS230::TextureManager::Load(const std::filesystem::path& file_name) {
	auto texture = textures.find(file_name);

	if (texture != textures.end()) {
		return texture->second;
	}

	Engine::GetLogger().LogEvent("Loading Texture: " + file_name.string());

	Texture* new_texture = new Texture(file_name);
	textures[file_name] = new_texture;
	return new_texture;
}

void CS230::TextureManager::Unload() {
	for (auto& d_texture : textures) {
		Engine::GetLogger().LogEvent("Unloading Texture: " + d_texture.first.string());
		delete d_texture.second;
	}
	textures.clear();
}

void CS230::TextureManager::StartRenderTextureMode(int width, int height) {
	s_render_texture = LoadRenderTexture(width, height);
	BeginTextureMode(s_render_texture);
	rlClearColor(0, 0, 0, 0);
	rlClearScreenBuffers();
}

CS230::Texture* CS230::TextureManager::EndRenderTextureMode() {
	EndTextureMode();
	const auto window_size = Engine::GetWindow().GetSize();
	rlSetFramebufferWidth(window_size.x);
	rlSetFramebufferHeight(window_size.y);
	rlUnloadFramebuffer(s_render_texture.id);
	const auto result = new Texture{ s_render_texture.texture };
	rendered_textures.push_back(result);
	return result;
}
