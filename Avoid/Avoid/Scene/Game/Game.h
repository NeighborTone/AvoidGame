#pragma once
#include "../Scene/Scene.h"

class Game : public Scene
{
public:
	bool Initialize() override;
	void Update()	  override;
	void Draw()       override;
	void Finalize()   override;


};