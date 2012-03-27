/* 
 * File:   GrassModel.h
 * Author: robert
 *
 * Created on January 26, 2012, 1:35 PM
 */

#ifndef GRASSMODEL_H
#define	GRASSMODEL_H

#include "Model.h"


class GrassModel : public Model {
public:
    GrassModel();
    void render();
private:
	void build();
        void build(GLfloat x);
};

#endif	/* GRASSMODEL_H */

