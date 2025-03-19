
#pragma comment (lib, "user32")
#define GetKey(X) (!!(GetAsyncKeyState(0[#X]) & 0x8000))

#include <stdio.h>
#include <Windows.h>
#include "Player.h"

// int APIENTRY
// WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
int main()
{
    Player* player = new Player();

    while (1)
    {
        player->Update();
    }

    delete player;

    return 0;
}

void
Player::Update()
{
	switch (m_CurrentState)
	{
		case PlayerState::EStandingState:
			if (GetKey(DOWN)) m_CurrentState = EDuckingState;
			if (GetKey(B)) m_CurrentState = EJumpingState;
			break;
		case PlayerState::EDuckingState:
			if (GetKey(DOWN)) m_CurrentState = EStandingState;
			break;
		case PlayerState::EJumpingState:
			if (GetKey(DOWN)) m_CurrentState = EDivingState;
			break;
	}

	printf("Current state ID: %i\n", m_CurrentState);
}
