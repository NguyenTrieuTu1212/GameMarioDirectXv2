#include "Lucky_Block.h"
#include "debug.h"
#include "Mario.h"
#include "PlayScene.h"


void CLuckyBlock::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (!checkObjectInCamera(this)) return;
	int idAnim = ID_ANI_LUCKY_BLOCK_NOT_COLLECT;


	if (state == BLOCK_COLLETED_STATE) idAnim = ID_ANI_LUCKY_BLOCK_COLLECTED;


	animations->Get(idAnim)->Render(x, y);
	/*RenderBoundingBox();*/
}


void CLuckyBlock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BlOCK_BBOX_WIDTH / 2;
	t = y - BlOCK_BBOX_HEIGHT / 2;
	r = l + BlOCK_BBOX_WIDTH;
	b = t + BlOCK_BBOX_HEIGHT;
}

void CLuckyBlock::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vy += ay * dt;
	if (y <= minY) vy = LUCKY_BLOCK_SPEED_DOWN;
	if (y > StartY + BlOCK_BBOX_HEIGHT - OFFSET) {
		y = StartY;
		vy = 0;
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CLuckyBlock::OnNoCollision(DWORD dt) {
	y += vy * dt;
}

void CLuckyBlock::SetState(int state) {
	CGameObject::SetState(state);
	switch (state)
	{
	case BLOCK_COLLETED_STATE:
		vy = -LUCKY_BLOCK_SPEED_UP;
		break;
	}
}
