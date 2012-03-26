#ifndef LIGHTRUBBLE_H
#define	LIGHTRUBBLE_H

#include "Model.h"
#include "StaticModel.h"

class LightRubbleModel : StaticModel
{
public:
	LightRubbleModel(void);
	void render();
private:
	void drawRock();
	void drawBRock();
};

#endif	/* LIGHTRUBBLE_H */
