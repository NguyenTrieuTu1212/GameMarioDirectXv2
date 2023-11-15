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

class CLuckyBlock : public CGameObject {
public:
	CLuckyBlock(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};