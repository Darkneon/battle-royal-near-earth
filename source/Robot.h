#include "ElectronicsModel.h"
#include "NuclearModel.h"

class Robot {
public:
	Robot();
	~Robot();
	void draw();
private:
	Model* model;
};