/* 
 * File:   model.h
 * Author: robert
 *
 * Created on January 19, 2012, 2:47 PM
 */

#ifndef MODEL_H
#define	MODEL_H

#ifdef __APPLE__
	#include <Glut/glut.h>
#else
    #define FREEGLUT_STATIC
    #include <GL/glut.h>
#endif

#include <cstdlib>
#include <vector>

#include "Helper/GeoHelper.h"
#include "Material/DefaultMaterial.h"

using namespace std;

class Model {
public:
    Model() {
        parent   = NULL;
        material = (Material*)(new DefaultMaterial());        
    }
    
    Model(Material *m) {   
        parent   = NULL;
        material = m;
    }
       
    virtual ~Model();

    virtual void render() = 0;
    
    void draw();
    
    Model* getParent() {
        return parent;
    }
    
    vector<Model *> getChildren() {
        return children;
    }
    
    void setChildren(vector<Model*> value) {
        children = value;
    }
    
    void setParent(Model *value) {
        parent = value;
    }
    
    void setNextChild(Model *value) {
        children.push_back(value);
    }
    
    Model* getFirstChild() {
        if (children.size() > 0) {
            return children.front();
        }
        else {
            return NULL;
        }
    }
    
	void removeAllChildren();
	void eraseChildren();


protected:
    Material *material;
    
private:
    Model *parent;
    vector<Model *> children;
    
};

#endif	/* MODEL_H */

