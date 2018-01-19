#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include <iostream>
#include <array>

/*�Q�[�����̓����蔻�����������Q��*/
class Obstacle
{
public:
	enum{interval = 250};
	struct  Under		//�n�ʃI�u�W�F�N�g
	{
		Box hit;			//�����蔻��p��`
		Box draw;		//�`��p��`
		Move move;		//�X�N���[��
		int handle;
		explicit Under();
	} under;
	struct Bar					//�㉺�̃o�[
	{
		Box bottomHit;			//���̂����蔻��
		Box topHit;				//��̂����蔻��
		Move move;
		int handle;
		float speed;
		explicit Bar();
		void SetBar();		//�����_���ɔz�u�����o�[�̏����ʒu��ݒ肷��
		
	};
	std::array<Bar,4> bar;
	struct Ice					//�ォ�痎������
	{
		Triangle tri;
		int handle;
		float fallspeed;
		bool isDraw;
		explicit Ice();
		void MoveIce();
		void SetIce(const POS player);
	} ice;
	Obstacle();
	~Obstacle() { InitGraph(); };
	void Update();		
	void Draw();		
};