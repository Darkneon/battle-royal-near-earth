//COMP 371
// made by Stefanie Lavoie 1951750

#ifndef TRACKMODEL_H
#define	TRACKMODEL_H

#include "Model.h"
#include <math.h>

class TracksModel : Model
{
public:
	TracksModel(void);
	void render();

private:
	void drawTrack();
	void drawCircle(float radius);
};
#endif	/* TRACKMODEL_H */

