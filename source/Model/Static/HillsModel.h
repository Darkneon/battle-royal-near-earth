#ifndef HILLSMODEL_H
#define	HILLSMODEL_H

#include "Model.h"
#include "StaticModel.h"

class HillsModel : StaticModel
{
public:
	HillsModel(void);
	void render();
};

#endif	/* HILLSMODEL_H */