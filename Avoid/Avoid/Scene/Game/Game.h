#pragma once
#include "../Scene/Scene.h"
#include "../Game/GameController.h"

//�����̓V�[�����f�����Ƃ����s��Ȃ�
class Game : public Scene
{
public:
	bool Initialize() override;
	void Update()	    override;
	void Draw()        override;
	void Finalize()   override;
	GameController controller;	//�Q�[���𐶐�
};