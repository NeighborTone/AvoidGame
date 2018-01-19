#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include <iostream>
#include <array>

/*ゲーム内の当たり判定を持った障害物*/
class Obstacle
{
public:
	enum{interval = 250};
	struct  Under		//地面オブジェクト
	{
		Box hit;			//あたり判定用矩形
		Box draw;		//描画用矩形
		Move move;		//スクロール
		int handle;
		explicit Under();
	} under;
	struct Bar					//上下のバー
	{
		Box bottomHit;			//下のあたり判定
		Box topHit;				//上のあたり判定
		Move move;
		int handle;
		float speed;
		explicit Bar();
		void SetBar();		//ランダムに配置されるバーの初期位置を設定する
		
	};
	std::array<Bar,4> bar;
	struct Ice					//上から落ちるつらら
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