//COMP 371
// made by Stefanie Lavoie 1951750

#ifndef TRACKMODEL_H
#define	TRACKMODEL_H

#include "Model.h"
#include "Static/TeamNumberModel.h"
#include <math.h>

class TracksModel : Model
{
public:
	TracksModel(void);
	void render();

private:
	void drawTrack();
	TeamNumberModel *teamNumber;
};
#endif	/* TRACKMODEL_H */

