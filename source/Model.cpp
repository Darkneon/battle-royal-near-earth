#include "Model.h"
#include <cstdlib>


Model::~Model() {
   removeAllChildren();
}

void Model::draw() {
    render();

	//keep drawing until all the children are done
    vector<Model *>::iterator iter;
    
    for(iter = children.begin(); iter != children.end(); ++iter) {
        (*iter)->draw();
    }
}

void Model::removeAllChildren(){
	 vector<Model *>::iterator iter;
    
    for(iter = children.begin(); iter != children.end(); ++iter) {
		if (*iter != NULL) {
			delete *iter;
			*iter = NULL;
		}
    }

	children.clear();
}