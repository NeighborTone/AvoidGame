#pragma once
#include "../Scene/Scene.h"
#include "../Game/GameController.h"

//ここはシーンを映すことしか行わない
class Game : public Scene
{
public:
	bool Initialize() override;
	void Update()	    override;
	void Draw()        override;
	void Finalize()   override;
	GameController controller;	//ゲームを生成
};