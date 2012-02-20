#ifndef HILLSMODEL_H
#define	HILLSMODEL_H

#include "Model.h"

class HillsModel : Model
{
public:
	HillsModel(void);
	void render();
private:    
    void drawPeak();
};

#endif	/* HILLSMODEL_H */