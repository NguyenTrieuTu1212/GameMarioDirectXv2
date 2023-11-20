#include "Platform.h"

void CPlatform::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if(GetModel()== TYPE_PLATFORM_1)
		animations->Get(ID_ANI_PLATFORM)->Render(x, y);
	/*RenderBoundingBox();*/
}


void CPlatform::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	/*l = x - PLATFROM_BBOX_WIDTH / 2 ;
	t = y - PLATFROM_BBOX_HEIGHT / 2 ;
	r = l + PLATFROM_BBOX_WIDTH;
	b = t + PLATFROM_BBOX_HEIGHT;*/
}



