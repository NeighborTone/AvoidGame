#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include <iostream>
#include <memory>
class Blocks
{
private:

public:
	struct  Under		//�n�ʃI�u�W�F�N�g
	{
		Box hit;			//�����蔻��p��`
		Box draw;		//�`��p��`
		Move move;	//�X�N���[��
		int handle;
	} under;
	struct Bar
	{
		Box bottomHit;			//���̂����蔻��
		Box topHit;				//��̂����蔻��
		Move move;
		int handle;
		float speed;
		void SetBar();		//�����_���ɔz�u�����o�[�̏����ʒu��ݒ肷��
	}bar;
	//std::unique_ptr<Bar>bar;		//�o�[�͓��I�ɐ�������
	Blocks();
	
	void Update();		//�S�Ă̂����蔻����������I�u�W�F�N�g�̍X�V����
	void Draw();			//�S�Ă̂����蔻����������I�u�W�F�N�g�̕`�揈��
};