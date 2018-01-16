#include "../Figure/Figure.h"
#include "../Move/Move.h"
#include <iostream>
#include <memory>
class Blocks
{
private:

public:
	struct  Under		//地面オブジェクト
	{
		Box hit;			//あたり判定用矩形
		Box draw;		//描画用矩形
		Move move;	//スクロール
		int handle;
	} under;
	struct Bar
	{
		Box bottomHit;			//下のあたり判定
		Box topHit;				//上のあたり判定
		Move move;
		int handle;
		float speed;
		void SetBar();		//ランダムに配置されるバーの初期位置を設定する
	}bar;
	//std::unique_ptr<Bar>bar;		//バーは動的に生成する
	Blocks();
	
	void Update();		//全てのあたり判定を持ったオブジェクトの更新処理
	void Draw();			//全てのあたり判定を持ったオブジェクトの描画処理
};