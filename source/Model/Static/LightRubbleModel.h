#ifndef LIGHTRUBBLE_H
#define	LIGHTRUBBLE_H

#include "Model.h"


class LightRubbleModel : Model
{
public:
	LightRubbleModel(void);
	void render();
private:
	void drawRock();
	void drawBRock();
	void renderGrass();
};

#endif	/* LIGHTRUBBLE_H */
