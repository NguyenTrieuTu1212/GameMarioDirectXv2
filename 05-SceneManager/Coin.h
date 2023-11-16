#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_COIN 11000	

#define	COIN_WIDTH 10
#define COIN_BBOX_WIDTH 10
#define COIN_BBOX_HEIGHT 16


#define COIN_SUMMON_STATE	100
#define COIN_NOT_SUMMON_STATE	200

#define COIN_GRAVITY 0.0003f
#define COIN_MAX_SPEED_FALL 0.1f


#define OUT_BRICK 0.2f;

class CCoin : public CGameObject {
	float ay;
	int state;
	bool isCollect;
public:
	CCoin(float x, float y) : CGameObject(x, y) {
		state = COIN_SUMMON_STATE;
		ay = COIN_GRAVITY;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
	bool getValueIsCollected() { return isCollect; }
	void setValueIsCollected(bool isCollect) { this->isCollect = isCollect;}

	virtual void OnNoCollision(DWORD dt);

	void SetState(int state);
};