#pragma once

#include <SDL.h>
#include "Screen.h"

class Sprite
{

public:

	enum class Flip
	{
		NoFlip = SDL_FLIP_NONE,
		HorzFlip = SDL_FLIP_HORIZONTAL,
		VertFlip = SDL_FLIP_VERTICAL
	};

	Sprite();
	~Sprite() {}

	void IsAnimated(bool flag);
	void IsLooping(bool flag);

	void SetImageCel(int column, int row);
	void SetAnimationSpeed(float speed);
	SDL_Point GetSpriteDimension();
	void SetSpriteDimension(int width, int height);
	void SetImageDimension(int columns, int rows, int width, int height);

	bool Load(const std::string& filename);
	void Unload();

	void Update();
	void Render(int xPos, int yPos, double angle, Sprite::Flip flip = Sprite::Flip::NoFlip);

private:

	int m_imageCel{ 0 };
	float m_animationSpeed = 0.0f;

	bool m_isAnimated;
	bool m_isAnimationDone;
	bool m_isLooping;

	Flip m_imageFlip{ Flip::NoFlip };
	SDL_Texture* m_image;
	SDL_Point m_celDimension;
	SDL_Point m_imageDimension;
	SDL_Point m_spriteDimension;

};