#include "ElectronicsModel.h"
#include "NuclearModel.h"

class Robot {
public:
	Robot();
	~Robot();
	void draw();
    void changeTop();
private:
	Model* model;
    Model* head1;
    Model* head2;
};

#endif