
#include "Model.h"
class HeadlightModel : public Model
{
public:
	HeadlightModel(void);
	void render();
private:
	void drawSquare();
	void drawCube();
};

