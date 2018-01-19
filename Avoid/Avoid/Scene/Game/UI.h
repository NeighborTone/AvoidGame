#include "DxLib.h"
#include "../Figure/Figure.h"
class UI
{
public:
	struct Titlelogo
	{
	private:
		bool flag;
	public:
		POS pos;
		int handle;
		Titlelogo();
		void Hide();
		void Show();
		bool OnOff();
	}logo;
	struct Retry
	{
	private:
		bool flag;
	public:
		POS pos;
		int handle;
		Retry();
		void Hide();
		void Show();
		bool OnOff();
	}retry;

	UI();
	~UI();
	void Draw();
};