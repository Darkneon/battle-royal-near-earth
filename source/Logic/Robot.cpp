#include "Robot.h"
#include "Robot/PhaserModel.h"
#include "Robot/CannonModel.h"
#include "Robot/BipodModel.h"
#include "Robot/TracksModel.h"
#include "Robot/AntiGravModel.h"
#include "Robot/MissileLauncherModel.h"
#include "Robot/ElectronicsModel.h"
#include "Robot/NuclearModel.h"
#include "Robot/HeadlightModel.h"
#include "../Model/Static/LightRubbleModel.h"

bool Robot::isARobotLightOn = false;

Robot::Robot() {
	rubble = (Model*)(new LightRubbleModel());
    nuclearM = (Model*)(new NuclearModel()); 
    electronicsM = (Model*)(new ElectronicsModel()); 
    phaserM = (Model*)(new PhaserModel);
    cannonM = (Model*)(new CannonModel); 
    missileM = (Model*)(new MissileLauncherModel); 
    bipodM = (Model*)(new BipodModel); 
    tracksM = (Model*)(new TracksModel); 
    antiGravM = (Model*)(new AntiGravModel); 
	headlight = (Model*)(new HeadlightModel);
    model = bipodM;
	roboCam = NULL;
	
	xPos = 0.0f;
	zPos = 0.0f;
	xDestination = 0.0f;
	zDestination = 0.0f;
	spinDegrees = SOUTH;
	spinDestination = SOUTH;
	pitchAngle = 90.0f;
	yawAngle = 90.0f;
	isMyLightOn = false;

	robotLife = MAX_LIFE;

	//BiPod is on
	isPartOn[0] = true;
	selectedIndex = 0;

	for(int i = 1; i < 8; i++){
		isPartOn[i]=false;
	}

	refreshRobot();
}

Robot::Robot(GLfloat x, GLfloat y) {
	rubble = (Model*)(new LightRubbleModel());
    nuclearM = (Model*)(new NuclearModel()); 
    electronicsM = (Model*)(new ElectronicsModel()); 
    phaserM = (Model*)(new PhaserModel);
    cannonM = (Model*)(new CannonModel); 
    missileM = (Model*)(new MissileLauncherModel); 
    bipodM = (Model*)(new BipodModel); 
    tracksM = (Model*)(new TracksModel); 
    antiGravM = (Model*)(new AntiGravModel); 
	headlight = (Model*)(new HeadlightModel);
    model = bipodM;
	roboCam = NULL;
	
	xPos = x;
	zPos = y;
	xDestination = 5.0f;
	zDestination = 5.0f;
	spinDegrees = SOUTH;
	spinDestination = SOUTH;
	pitchAngle = 90.0f;
	yawAngle = 90.0f;
	isMyLightOn = false;

	robotLife = MAX_LIFE;

	//BiPod is on
	isPartOn[0] = true;
	selectedIndex = 0;

	for(int i = 1; i < 8; i++){
		isPartOn[i]=false;
	}

	turnIndexOn(1);
	turnIndexOn(3);
	refreshRobot();
}

Robot::~Robot() {
    //Deleting the head frees up its children as well 
    /*if (head1 != NULL) {
        delete head1;
        head1 = NULL;
    }
    
    if (head2 != NULL) {
        delete head2;
        head2 = NULL;
    } */
}

void Robot::draw() {
	if(robotLife > 0){
		glPushMatrix();
			goToDestination();
			//Translate()
			glTranslatef(xPos,0.0f,zPos);
		
			//Spin()
			glTranslatef(0.5f, 0.0f, 0.5f);
			glRotatef(spinDegrees,0.0f,1.0f,0.0f);
			glTranslatef(-0.5f,0.0f,-0.5f);

			//Draw Headlight
			glPushMatrix();
				glTranslatef(0.0f,calculateHeight(8),0.0f);
				headlight->draw();
			glPopMatrix();

			//Draw Model
			model->draw();
		glPopMatrix();
	}
	else{
		glPushMatrix();
			//Translate()
			glTranslatef(xPos,0.0f,zPos);
			rubble->draw();
		glPopMatrix();
	}
	robotLife = robotLife -0.5f;

}

//-------------------------------------------------------------
//						COMPONENT TOGGLING
//-------------------------------------------------------------

//Publics
void Robot::cycleIndex(){
	selectedIndex = (selectedIndex+1)%8;
}

void Robot::turnSelectedOn(){
	turnIndexOn(selectedIndex);
}

//Privates
void Robot::turnIndexOn(int index){

	switch(index){
		case 0:
			isPartOn[0] = true;
			isPartOn[1] = false;
			isPartOn[2] = false;
			break;
		case 1:
			isPartOn[1] = true;
			isPartOn[0] = false;
			isPartOn[2] = false;
			break;
		case 2:
			isPartOn[2] = true;
			isPartOn[0] = false;
			isPartOn[1] = false;
			break;
		case 3: case 4: case 5: case 6: case 7: 
			if(isPartOn[index]){
				isPartOn[index] = false;
			}
			else{
				isPartOn[index] = true;
			}
			break;
		default:
			break;
	}
	refreshRobot();
}

void Robot::refreshRobot(){
	
	clearChildren();
	//setup base
	if(isPartOn[0]){
        model = bipodM;
	}
	else if (isPartOn[1]){
        model = tracksM;
	}
	else if (isPartOn[2]){
        model = antiGravM;
	}

	Model* temp = NULL;
	Model* tempChild = NULL;
	bool childExists = false;
	bool grandChildExists = false;
	for(int i = 7; i > 2; i--){
		if(isPartOn[i]){
			if(childExists){
				grandChildExists = true;
			}
			childExists = true;
			tempChild = temp;
			switch(i){
				case 3:
					temp = cannonM;
					break;
				case 4:
					temp = missileM;
					break;
				case 5:
					temp = phaserM;
					break;
				case 6:
					temp = nuclearM;
					break;
				case 7:
					temp = electronicsM;
					break;
				default:
					break;
			}
			if(grandChildExists){
				temp->setNextChild(tempChild);
			}
		}
	}
	if(childExists){
		model->setNextChild(temp);
	}
	notifyCamera();
}

void Robot::clearChildren(){
	nuclearM->eraseChildren();
    missileM->eraseChildren();
    cannonM->eraseChildren();
    phaserM->eraseChildren();
    antiGravM->eraseChildren();
    tracksM->eraseChildren();
    bipodM->eraseChildren(); 
	model->eraseChildren();
}

//-------------------------------------------------------------
//						ROBOT TRANSFORMATIONS
//-------------------------------------------------------------

void Robot::translate(GLfloat xDist, GLfloat zDist){
	xPos += xDist;
	zPos += zDist;
}

void Robot::translateTo(GLfloat xDestination, GLfloat zDestination){
	xPos = xDestination;
	zPos = zDestination;
}

void Robot::spin(GLfloat degrees){
	spinDegrees += degrees;
	normalizeSpinDegrees();
}

void Robot::incrementSpinDegrees(bool pos){

	if(pos){
		spinDegrees++; //true increases angle by one
	}
	else{
		spinDegrees--;
	}

	normalizeSpinDegrees();
	notifyCamera();
}

//-------------------------------------------------------------
//						COORDINATE ACCESSORS
//-------------------------------------------------------------

GLfloat Robot::getEyeX(){
	//original position after translated to y-axis (-.2,0,0)
	//rotation + translation
	GLfloat rotatedPosX = -.2f*cos(spinDegrees*GL_PI/180.0f) + 0.5f;
	return xPos+rotatedPosX;
}

GLfloat Robot::getEyeY(){
	return calculateHeight(8)+0.15f;
}

GLfloat Robot::getEyeZ(){
	//original position after translated to y-axis (-.2,0,0)
	//rotation + translation
	GLfloat rotatedPosZ = .2f*sin(spinDegrees*GL_PI/180.0f)+0.5f;
	return zPos+rotatedPosZ;
}

GLfloat* Robot::getLookAt(){
	GLfloat pitched[3];
	//Adjust for pitch & yaw
	pitched[0] = 0.3f-sin(pitchAngle*GL_PI/180.0f)-sin(yawAngle*GL_PI/180.0f)-0.5f;
	pitched[1] = calculateHeight(8)+0.15f-cos(pitchAngle*GL_PI/180.0f);
	pitched[2] = 0.5f+cos(yawAngle*GL_PI/180.0f)-0.5f;
	GLfloat* rotated = new GLfloat[3];
	rotated[0] = pitched[0]*cos(spinDegrees*GL_PI/180.0f)+ pitched[2]*sin(spinDegrees*GL_PI/180.0f) + 0.5f +xPos;
	rotated[1] = pitched[1];
	rotated[2] = pitched[0]*-sin(spinDegrees*GL_PI/180.0f)+ pitched[2]*cos(spinDegrees*GL_PI/180.0f) + 0.5f +zPos;
	
	return rotated;
}

GLfloat* Robot::getLightLookAt(){
	GLfloat pitched[3];
	//Adjust for pitch & yaw
	pitched[0] = 0.3f-sin(70*GL_PI/180.0f)-0.5f;
	pitched[1] = calculateHeight(8)+0.15f-cos(70*GL_PI/180.0f);
	pitched[2] = 0.5f-0.5f;

	GLfloat* rotated = new GLfloat[3];
	rotated[0] = pitched[0]*cos(spinDegrees*GL_PI/180.0f)+ pitched[2]*sin(spinDegrees*GL_PI/180.0f) + 0.5f +xPos;
	rotated[1] = pitched[1];
	rotated[2] = pitched[0]*-sin(spinDegrees*GL_PI/180.0f)+ pitched[2]*cos(spinDegrees*GL_PI/180.0f) + 0.5f +zPos;
	
	return rotated;
}

GLfloat Robot::calculateHeight(int index){
	GLfloat h = 0; 
	for(int i = 0; i < index; i++){
		if(isPartOn[i]){
			switch(i){
				case 0:
					h += BIPOD_HEIGHT;
					break;
				case 1:
					h += TRACKS_HEIGHT;
					break;
				case 2:
					h += ANTIGRAV_HEIGHT;
					break;
				case 3:
					h += CANNON_HEIGHT;
					break;
				case 4:
					h += MISSILE_LAUNCHER_HEIGHT;
					break;
				case 5:
					h += PHASER_HEIGHT;
					break;
				case 6:
					h += NUCLEAR_HEIGHT;
					break;
				case 7:
					h += ELECTRONICS_HEIGHT;
					break;
				default:
					break;
			}
		}
	}
	return h;
}

//-------------------------------------------------------------
//				CAMERA ATTACHMENT AND SYNCH
//-------------------------------------------------------------

void Robot::attachToCamera(RobotCamera* r){
	roboCam = r;
}

void Robot::notifyCamera(){
	if(roboCam != NULL)
		roboCam->update();
	refreshLight();
}

//-------------------------------------------------------------
//					ORIENTATION
//-------------------------------------------------------------
void Robot::incrementPitchAngle(bool pos){
	GLfloat sum;
	if(pos){
		sum = pitchAngle + 1;
	}
	else{
		sum = pitchAngle - 1;
	}
	if(sum <= 110 && sum >= 70){
		pitchAngle = sum;
	}
	else if(sum > 110){
		pitchAngle = 110;
	}
	else if(sum < 70){
		pitchAngle = 70;
	}
	notifyCamera();
}

void Robot::incrementYawAngle(bool pos){
	GLfloat sum;
	if(pos){
		sum = yawAngle + 1;
	}
	else{
		sum = yawAngle - 1;
	}

	if(sum > 120){
		yawAngle = 120;
	}
	else if(sum < 60){
		yawAngle = 60;
	}
	else{
		yawAngle = sum;
	}
	notifyCamera();
}

void Robot::resetOrientation(){
	spinDegrees = 0.0f;
	pitchAngle = 90.0f;
	yawAngle = 90.0f;
	notifyCamera();
}


//-------------------------------------------------------------
//							LIGHTING
//-------------------------------------------------------------
void Robot::toggleLight(){
	if(isMyLightOn){
		//turn off
		glDisable(GL_LIGHT5);
		isMyLightOn = false;
		isARobotLightOn = false;
	}
	else if(!isARobotLightOn){
		//turn on
		isMyLightOn = true;
		isARobotLightOn = true;
		refreshLight();
	}
}

void Robot::refreshLight(){
		
	if(isMyLightOn){
		GLfloat eyeTemp[3];
		eyeTemp[0] = getEyeX();
		eyeTemp[1] = getEyeY();
		eyeTemp[2] = getEyeZ();
		GLfloat* lookTemp = getLightLookAt();

		GLfloat light8_position[] = { eyeTemp[0], eyeTemp[1], eyeTemp[2], 1.0f };
		GLfloat light8_direction[] = { lookTemp[0]-eyeTemp[0], lookTemp[1]-eyeTemp[1], lookTemp[2]-eyeTemp[2]};

		glLightfv(GL_LIGHT5, GL_AMBIENT, light8_ambient);
		glLightfv(GL_LIGHT5, GL_DIFFUSE, light8_diffuse);
		glLightfv(GL_LIGHT5, GL_SPECULAR, light8_specular);
		glLightfv(GL_LIGHT5, GL_POSITION, light8_position);
		glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, light8_direction);
		glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, 20.0f);
		glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 10.0f); 
	
		glEnable(GL_LIGHT5);

		delete [] lookTemp;
	}
}

//checks angle between spinDestination and spinDegrees
GLfloat Robot::calcDestinationAngle(){
	GLfloat angle;
	if(spinDestination >= spinDegrees){
		angle = spinDestination - spinDegrees;
	}
	else{
		angle = 360.0f - spinDegrees + spinDestination;
	}
	return angle;
}

//Makes angles within 0 to 360 degrees
void Robot::normalizeSpinDegrees(){
	while(spinDegrees >= 360){
		spinDegrees -= 360;
	}
	while(spinDegrees < 0){
		spinDegrees += 360;
	}
}

//Makes angles within 0 to 360 degrees
void Robot::normalizeSpinDestination(){
	while(spinDestination >= 360){
		spinDestination -= 360;
	}
	while(spinDestination < 0){
		spinDestination += 360;
	}
}

//spins over time (as called by render)
void Robot::timedSpin(){
	//takes direction of shortest angle
	if(calcDestinationAngle() == 0){
		return;
	}
	else if(calcDestinationAngle()<=180){
		incrementSpinDegrees(true);
	}
	else{
		incrementSpinDegrees(false);
	}
}

//walks in X-direction, returns true if walking
bool Robot::timedXWalk(){
	GLfloat xDistance = xDestination - xPos;
	if(xDistance == 0){
		return false;
	}
	else if(xDistance > 0){
		incrementXPos(true);
		return true;
	}
	else{
		incrementXPos(false);
		return true;
	}
}

bool Robot::timedZWalk(){
	GLfloat zDistance = zDestination - zPos;
	if(zDistance == 0){
		return false;
	}
	else if(zDistance > 0){
		incrementZPos(true);
		return true;
	}
	else{
		incrementZPos(false);
		return true;
	}
}

void Robot::incrementXPos(bool pos){
	if(pos){
		xPos += 0.05f;
	}
	else{
		xPos -= 0.05f;
	}
}

void Robot::incrementZPos(bool pos){
	if(pos){
		zPos += 0.05f;
	}
	else{
		zPos -= 0.05f;
	}
}

void Robot::setDestination(GLfloat x, GLfloat z){
	xDestination = x;
	zDestination = z;
}

void Robot::goToDestination(){
	if(checkXDestination() && checkZDestination()){
		return;
	}

	//Orient
	if(!checkXDestination()){
		if(spinDestination != spinDegrees){
			//Spins until facing correct angle
			timedSpin();
		}
		else{
			//translates east or west
			if(spinDegrees == EAST){
				incrementXPos(true);
			}
			else{
				incrementXPos(false);
			}
		}
		return;
	}
	
	if(!checkZDestination()){
		if(spinDestination != spinDegrees){
			//Spins until facing correct angle
			timedSpin();
		}
		else{
			//translates north or south
			if(spinDegrees == SOUTH){
				incrementZPos(true);
			}
			else{
				incrementZPos(false);
			}
		}
		return;
	}
}

bool Robot::checkXDestination(){
	GLfloat diff = xDestination - xPos;
	if(diff > -0.05f && diff < 0.05f){
		xPos = xDestination;
		return true;
	}
	else if(diff > 0){
		spinDestination = EAST;
		return false;
	}
	else{
		spinDestination = WEST;
		return false;
	}

}

bool Robot::checkZDestination(){
	GLfloat diff = zDestination - zPos;
	if(diff > -0.05f && diff < 0.05f){
		zPos = zDestination;
		return true;
	}
	else if(diff > 0){
		spinDestination = SOUTH;
		return false;
	}
	else{
		spinDestination = NORTH;
		return false;
	}
}

