#include "Grass.h"


void CGrass::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_GRASS)->Render(x, y);
	/*RenderBoundingBox();*/
}

void CGrass::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	/*l = x - TREE_BBOX_WIDTH / 2;
	t = y - TREE_BBOX_HEIGHT / 2;
	r = l + TREE_BBOX_WIDTH;
	b = t + TREE_BBOX_HEIGHT;*/
}