#pragma once
#include "../Scene/Scene.h"
#include "../Game/GameController.h"
#include "Player.h"
//‚±‚±‚ÍƒV[ƒ“‚¾‚¯‚ğˆµ‚¤‚±‚Æ‚É‚·‚é
class Game : public Scene
{
public:
	bool Initialize() override;
	void Update()	    override;
	void Draw()        override;
	void Finalize()   override;
	GameController controller;
};