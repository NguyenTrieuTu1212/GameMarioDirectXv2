#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_LUCKY_BLOCK_NOT_COLLECT 21000
#define ID_ANI_LUCKY_BLOCK_COLLECTED 22000

#define	BlOCK_WIDTH 16
#define BlOCK_BBOX_WIDTH 16
#define BlOCK_BBOX_HEIGHT 16

#define BLOCK_NOT_COLLECT_STATE 100
#define BLOCK_COLLETED_STATE 200

#define LUCKY_BLOCK_STATE_UP 300
#define LUCKY_BLOCK_SPEED_UP 0.04f
#define LUCKY_BLOCK_SPEED_DOWN 0.04f


#define TYPE_OBJECT_COIN 11
#define TYPE_OBJECT_MUSHROOM 12

#define OFFSET 13



class CLuckyBlock : public CGameObject {
	float ay;
	float StartY;
	float minY;
	int typeSpawn;
	
public:
	CLuckyBlock(float x, float y, int typeSpawn) : CGameObject(x, y) {

		this->ay = 0;
		this->x = x;
		this->y = y;
		this->StartY = y;
		this->minY = y - BlOCK_BBOX_HEIGHT + OFFSET;
		this->typeSpawn = typeSpawn;
	}
	
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);

	// Loại mà block spawn ra (hiện tại gồm 2 vật Coin và Mushroom)
	void SetTypeSpawn(int typeSpawn) { this->typeSpawn = typeSpawn; }
	int GetTypeSpawn() { return typeSpawn; }

	virtual void OnNoCollision(DWORD dt);
	virtual void SetState(int state);


};