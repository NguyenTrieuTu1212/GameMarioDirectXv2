#include "Coin.h"
#include "Mario.h"
#include "PlayScene.h"

void CCoin::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_COIN)->Render(x, y);

	//RenderBoundingBox();
}

void CCoin::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - COIN_BBOX_WIDTH / 2;
	t = y - COIN_BBOX_HEIGHT / 2;
	r = l + COIN_BBOX_WIDTH;
	b = t + COIN_BBOX_HEIGHT;
}


void CCoin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (!checkObjectInCamera(this)) return;
	if (!isCollect) vy += ay * dt;
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CCoin::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};


void CCoin::SetState(int state) {
	switch (state) {
	case COIN_SUMMON_STATE:
		vy = -OUT_BRICK;
		isCollect = false;
		break;

	case COIN_NOT_SUMMON_STATE:
		isCollect = true;
		break;
	}
	CGameObject::SetState(state);
}