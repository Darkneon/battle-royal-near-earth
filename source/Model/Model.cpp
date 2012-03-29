#include "Model.h"
#include <cstdlib>


Model::~Model() {
   removeAllChildren();
   
   if (material != NULL) {
       delete material;
       material = NULL;
   }
}

void Model::draw() {
    if (material != NULL) {
       material->apply();
    }
    
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

void Model::eraseChildren(){
	if(children.size()>0){
		children.erase(children.begin());
	}
}
