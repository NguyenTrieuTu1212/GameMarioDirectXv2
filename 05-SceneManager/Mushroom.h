#pragma once


#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_REDMUSHRO0M 9000
#define RED_MUSHROOM_WIDTH 16
#define RED_MUSHROOM_BBOX_WIDTH 16
#define RED_MUSHROOM_BBOX_HEIGHT 16

#define MUSHROOM_GRAVITY 0.002f
#define MUSHROOM_UN_GRAVITY_OUT_BRICK -0.016f
#define MUSHROOM_SPEED 0.05f


#define MUSHROOM_OUT_BLOCK_STATE 90
#define MUSHROOM_RUN_STATE 91
#define MUSHROOM_DIE_STATE 92




class CMushroom : public CGameObject
{
	float ay;
	float ax;
	float startY;

	virtual int IsCollidable() { return 1; }
	virtual int IsBlocking() { return 1; }
public:
	CMushroom(float x, float y) : CGameObject(x, y) {
		this->ay = MUSHROOM_GRAVITY;
		this->ax = 0;
		this->startY = y;
		vy = MUSHROOM_GRAVITY;
		SetState(MUSHROOM_OUT_BLOCK_STATE);
	}
	void Render();
	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void SetState(int state);
};

