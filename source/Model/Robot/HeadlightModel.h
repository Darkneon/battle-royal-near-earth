
#include "Model.h"
class HeadlightModel : public Model
{
public:
	bool whiteLight;
	HeadlightModel(void);
	void render();
private:
	void drawSquare();
	void drawCube();
};

