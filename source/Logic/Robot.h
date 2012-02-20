//ROBERT'S CLASS


#ifndef ROBOT_H
#define ROBOT_H

#include "Model.h"
#include "Static/TeamNumberModel.h"

class Robot {
public:
	Robot();
	~Robot();
	void draw();
        void changeTop();
        void changeMiddle();
        void changeBottom();

private:
	Model* model;
        Model* currentMiddle;
        
        Model* head1;
        Model* head2;
        Model* head3;
        
        Model* middle1;
        Model* middle2;
        Model* middle3;

        Model* bottom1;
        Model* bottom2;
        Model* bottom3;
        
        TeamNumberModel teamNumberModel;
        int topCounter;
        int middleCounter;
        int bottomCounter;        
};

#endif