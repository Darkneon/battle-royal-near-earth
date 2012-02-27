//COMP 371
// made by Stefanie Lavoie 1951750
#ifndef ANTIGRAVMODEL_H
#define	ANTIGRAVMODEL_H

#include "Model.h"
#include "Static/TeamNumberModel.h"

class AntiGravModel : Model
{
public:
	AntiGravModel(void);
	void render();

private:
	void drawMachineCube();
	TeamNumberModel *teamNumber;
};

#endif	/* ANTIGRAVMODEL_H */