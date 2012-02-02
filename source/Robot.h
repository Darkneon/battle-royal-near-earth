#include "ElectronicsModel.h"
#include "NuclearModel.h"

#include "Model.h"
#include "TeamNumberModel.h"

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