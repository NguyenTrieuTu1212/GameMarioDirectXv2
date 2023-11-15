#include "Lucky_Block.h"

void CLuckyBlock::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int idAnim = ID_ANI_LUCKY_BLOCK_NOT_COLLECT;
	if (state == BLOCK_COLLETED_STATE) idAnim = ID_ANI_LUCKY_BLOCK_COLLECTED;
	animations->Get(idAnim)->Render(x, y);
	/*RenderBoundingBox();*/
}

void CLuckyBlock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BlOCK_BBOX_WIDTH/2;
	t = y - BlOCK_BBOX_HEIGHT/2;
	r = l + BlOCK_BBOX_WIDTH;
	b = t + BlOCK_BBOX_HEIGHT;
}

void CLuckyBlock::SetState(int state) {
	CGameObject::SetState(state);
	switch (state)
	{
	case QUESTION_BRICK_STATE_UP:
		vy = -QUESTION_BRICK_SPEED_UP;
		break;

	}
}