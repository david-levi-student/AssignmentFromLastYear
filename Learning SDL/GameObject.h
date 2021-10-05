#pragma once

#include "Vector2D.h"
#include <string>
#include "Screen.h"
#include "Input.h"

class GameObject
{

public:
	
	GameObject();
	~GameObject();

	const std::string& GetTag() const;
	void SetTag(const std::string& tag);

	virtual void Render(Screen& screen) = 0;
	virtual void Update(const Input& input);

	void SetPosition(int x, int y);
	void SetPosition(const Vector2D& position);
	const Vector2D& GetPosition() const;

	void SetSize(int width, int height);
	void SetSize(const Vector2D& size);
	const Vector2D& GetSize() const;

	bool isAlive() const;
	bool isActive() const;
	bool isVisible() const;

	void isAlive(bool flag);
	void isActive(bool flag);
	void isVisible(bool flag);

	void SetAngle(float angle);
	float GetAngle() const;


protected:

	float m_angle;

	std::string m_tag;

	bool m_isActive;
	bool m_isVisible;
	bool m_isAlive;

	Vector2D m_size;
	Vector2D m_position;

};