//COMP 371
// made by Stefanie Lavoie 1951750

#ifndef TRACKMODEL_H
#define	TRACKMODEL_H

#include "Model.h"
#include "TeamNumberModel.h"
#include <math.h>

class TracksModel : Model
{
public:
	TracksModel(void);
	void render();

private:
	void drawTrack();
	void drawCircle(float radius);
	TeamNumberModel *teamNumber;
};
#endif	/* TRACKMODEL_H */

