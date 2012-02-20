//COMP 371
// made by Stefanie Lavoie 1951750

#ifndef BIPODMODEL_H
#define	BIPODMODEL_H

#include "Model.h"

class BipodModel : Model
{
public:
	BipodModel(void);
	void render();

private:
	void drawLeg();
};
#endif	/* BIPODMODEL_H */