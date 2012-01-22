#include "Model.h";
#include <cstdlib>


Model::~Model() {
    vector<Model *>::iterator iter;
    
    for(iter = children.begin(); iter != children.end(); ++iter) {
        delete *iter;
    }
}

void Model::draw() {
    render();

	//keep drawing until all the children are done
    vector<Model *>::iterator iter;
    
    for(iter = children.begin(); iter != children.end(); ++iter) {
        (*iter)->draw();
    }
}
