/* 
 * File:   BulletModel.h
 * Author: Jeff
 *
 * Created on March 30, 2012
 */

#ifndef BULLET_MODEL_H
#define	BULLET_MODEL_H

#define BULLET_RADIUS 0.1f
#include "Model.h"
class BulletModel :public Model
{
public:
	BulletModel(void);
	virtual ~BulletModel(void);
	void render();
};
#endif
