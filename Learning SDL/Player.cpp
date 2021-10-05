#include "Player.h"
#include "Input.h"

Player::Player(Screen& screen)
{
	m_speed = 0;
	m_state = IDLE;
	m_facingDirection = RIGHT;
	m_jumpDirection = NONE;
	m_image[IDLE].Load("Assets/Images/protag.png", screen); //downloaded for free from OpenGameArt.org
	for (int i = 0; i < TOTAL_STATES; i++)
	{
		m_image[i].SetSpriteDimension(400, 24);
		m_image[i].SetImageDimension(22, 1, 400, 24);

		m_image[i].IsAnimated(true);
		m_image[i].SetAnimationSpeed(3.5f);

		if (i == JUMP)
		{
			m_image[i].IsLooping(false);
		}
		else
		{
			m_image[i].IsLooping(true);
		}
	}

	m_footstep.Load("Assets/Audio/Sounds/Footsteps.wav");
}

Player::~Player()
{
	m_image[m_state].Unload();
}

void Player::SetSpeed(int speed)
{
	m_speed = speed;
}

void Player::SetState(State state)
{
	m_state = state;
}

/*const BoxCollide& Player::GetCollider() const
{
	return m_collider;
}*/

const SphereCollide& Player::GetCollider() const
{
	return m_collide;
}

void Player::Render(Screen& screen)
{
	if (m_isVisible)
	{
		if (m_facingDirection == RIGHT)
		{
			m_image[m_state].Render(m_position.x, m_position.y, m_angle, screen, Sprite::NO_FLIP);
		}
		else
		{
			m_image[m_state].Render(m_position.x, m_position.y, m_angle, screen, Sprite::HORZ_FLIP);
		}
	}
}

void Player::Update(Input& input)
{
	//==========================Key Inputs============================
	if (input.GetKeyDown() == SDL_SCANCODE_LEFT)
	{
		m_state = RUN;
		m_facingDirection = LEFT;
		m_footstep.Play();
	}

	else if (input.GetKeyDown() == SDL_SCANCODE_RIGHT)
	{
		m_state = RUN;
		m_facingDirection = RIGHT;
		m_footstep.Play();
	}

	else if (input.GetKeyDown() == SDLK_SPACE)
	{
		m_state = JUMP;
		m_jumpDirection = UP;
	}
	
	else
	{
		m_direction.x = 0;
		m_direction.y = 0;
		m_state = IDLE;
	}

	//==============================Checks=================================

	if (m_state == RUN)
	{
		if(m_facingDirection == LEFT)
		{
			m_direction.x = -1;
			m_direction.y = 0;
		}
		else
		{
			m_direction.x = 1;
			m_direction.y = 0;
		}
	}

	else if (m_state == JUMP)
	{
		if (m_position.y >= 20 && m_jumpDirection == UP)
		{
			m_direction.x = 0;
			m_direction.y = -1;
		}
		else
		{
			m_direction.x = 0;
			m_direction.y = 1;
			m_jumpDirection = DOWN;
		}
	}

	//=====================================================================

	m_direction = m_direction.Scale(m_speed);
	m_position = m_position.Add(m_direction);

	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.SetDimension(m_size.x, m_size.y);
	m_collider.Update();

	m_image[m_state].Update();

	m_collide.SetRadius(m_size.x / 2);
	m_collide.SetPosition(m_position.x, m_position.y);
}