#include "DxLib.h"
#include "../Input/Input.h"
#include "../Scene/SceneManager.h"
#include "../Scene/Game/Game.h"
#include "../Scene/Game/GameController.h"
void message_box() 
{
	int flag;
	flag = MessageBox(
		NULL,
		TEXT("�t���X�N���[�����[�h�ŋN�����܂����H"),
		TEXT("�X�N���[���ݒ�"),
		MB_YESNO | MB_ICONQUESTION);
	if (flag == IDNO)
		ChangeWindowMode(TRUE);
}
int SystemCheck()
{
	if (ScreenFlip() != 0) return -1;
	if (ProcessMessage() != 0) return -1;
	if (ClearDrawScreen() != 0) return -1;
	if (DxLib_IsInit() == FALSE) return -1;
	return 0;
}
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	
	//���O����
	SetOutApplicationLogValidFlag(FALSE);
	//�E�C���h�E�^�C�g����ύX
	SetMainWindowText("FlyingGhost");
	//��ʃT�C�Y�ύX
	SetGraphMode(GameController::Disp_Widih(), GameController::Disp_Height(), 32);
	//�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	message_box(), SetWindowIconID(222), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	auto manager = SceneManeger::GetInstance();

	manager->PushScene(new Game);

	while (SystemCheck() == 0 && !manager->isEmpty())
	{
		Updata_Key();
		manager->GetCurrentScene()->Update();
		manager->GetCurrentScene()->Draw();
		if (Key(KEY_INPUT_ESCAPE) == 1)
		{
			manager->GetCurrentScene()->Finalize();
			break;
		}
	}
	manager->GetCurrentScene()->Finalize();
	DxLib_End();
	return 0;
}