#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_LUCKY_BLOCK 21000	

#define	BlOCK_WIDTH 16
#define BlOCK_BBOX_WIDTH 16
#define BlOCK_BBOX_HEIGHT 16

class CLuckyBlock : public CGameObject {
public:
	CLuckyBlock(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
};