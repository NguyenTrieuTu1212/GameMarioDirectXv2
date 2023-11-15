#include "Lucky_Block.h"

void CLuckyBlock::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_LUCKY_BLOCK)->Render(x, y);
	RenderBoundingBox();
}

void CLuckyBlock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BlOCK_BBOX_WIDTH/2;
	t = y - BlOCK_BBOX_HEIGHT/2;
	r = l + BlOCK_BBOX_WIDTH;
	b = t + BlOCK_BBOX_HEIGHT;
}
