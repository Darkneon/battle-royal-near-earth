/* 
 * File:   model.h
 * Author: robert
 *
 * Created on January 19, 2012, 2:47 PM
 */

#ifndef MODEL_H
#define	MODEL_H
#include <cstdlib>

class Model {
public:
    Model() {
        parent = NULL;
        firstChild = NULL;
        nextChild = NULL;
    }
    
	virtual ~Model();

    virtual void render() = 0;
    
    void draw();
    
    Model* getParent() {
        return parent;
    }
    
    Model *getNextChild() {
        return nextChild;
    }
    
    void setParent(Model *value) {
        parent = value;
    }
    
    void setNextChild(Model *value) {
        nextChild = value;
    }
    
protected:
    Model *firstChild;
private:
    Model *parent;
    Model *nextChild;
};

#endif	/* MODEL_H */

