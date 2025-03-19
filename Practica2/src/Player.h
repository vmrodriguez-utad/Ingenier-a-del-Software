
#pragma once

enum
PlayerState
{
	EStandingState = 0,
	EDuckingState = 1,
	EJumpingState = 2,
	EDivingState = 3
};

class
Player
{
	PlayerState m_CurrentState;

public:

	void Update();

	inline PlayerState getState() const { return m_CurrentState; };
};
