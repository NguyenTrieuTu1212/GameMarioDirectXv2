#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"


#define ID_ANI_PLATFORM 21110


#define PLATFROM_BBOX_WIDTH 48
#define PLATFROM_BBOX_HEIGHT 48


#define TYPE_PLATFORM_1 10
#define TYPE_PLATFORM_2 20


class CPlatform : public CGameObject
{
	int model;

public: 
	CPlatform(float x, float y,int model) : CGameObject(x, y) {
		this->model = model;
	}

	int GetModel() { return model; }
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);

};



