#include "Mushroom.h"
#include "Mario.h"
#include "PlayScene.h"

void CMushroom::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_REDMUSHRO0M)->Render(x, y);
	RenderBoundingBox();
}

void CMushroom::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - RED_MUSHROOM_BBOX_WIDTH / 2;
	t = y - RED_MUSHROOM_BBOX_HEIGHT / 2;
	r = l + RED_MUSHROOM_BBOX_WIDTH;
	b = t + RED_MUSHROOM_BBOX_HEIGHT;
}


void CMushroom::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

	if (state == MUSHROOM_RUN_STATE) {
		vx += ax * dt;
		vy += ay * dt;
	}
	else if (state == MUSHROOM_OUT_BLOCK_STATE) {
		if (startY - y < RED_MUSHROOM_BBOX_HEIGHT) {
			vy = MUSHROOM_UN_GRAVITY_OUT_BRICK;
			vx = 0;
		}else SetState(MUSHROOM_RUN_STATE);
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CMushroom::OnNoCollision(DWORD dt) {
	x += vx * dt;
	y += vy * dt;
}

void CMushroom::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CMushroom*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CMushroom::SetState(int state) {
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	switch (state)
	{
	case MUSHROOM_RUN_STATE: 
		if (x < mario->GetX()) vx = -MUSHROOM_SPEED;
		else vx = MUSHROOM_SPEED;
		break;
	}
	CGameObject::SetState(state);
}