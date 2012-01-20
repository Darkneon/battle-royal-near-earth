#include "Model.h";
#include <cstdlib>

Model::~Model() {
	Model *current = firstChild;
    Model *temp;

    while (current != NULL) {
		temp = current->nextChild;
        delete current;
        current = temp;
    }
}

void Model::draw() {
    render();
    Model *current = firstChild;
    
	//keep drawing until all the children are done
    while (current != NULL) {
        current->draw();
        current = current->nextChild;
    }    
}
