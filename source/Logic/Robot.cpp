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
#include "../Model/Buildings/FlagModel.h"
#include "../Helper/SoundHelper.h"


bool Robot::isARobotLightOn = false;
int Robot::robotIdCount = 0;

Robot::Robot() {
	rubble = (Model*)(new LightRubbleModel());
	flag = (Model*)(new FlagModel());
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
        
        groundplane[0] = 0.0f;
        groundplane[1] = 1.0f;
        groundplane[2] = 0.0f;
        groundplane[3] = 0.0f;
        
	robotIdCount++;
	robotId = robotIdCount;
	
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

	directionVector[0] = -1.0f;
	directionVector[1] = 0.0f;
	directionVector[2] = 0.0f;

	//BiPod is on
	isPartOn[0] = true;
	selectedIndex = 0;
	
	for(int i = 1; i < 8; i++){
		isPartOn[i]=false;
	}

	box = new BoundingBox(xPos,0.0f,zPos,xPos+1.0f,height,zPos+1.0f, true, this);
	ct = new CollisionTester;
	ct->staticBoxes.push_back(box);
	refreshRobot();

	isRobotBeingControlled = false;
	currentTime = clock();
	lastExplosion = clock();

	explosionSize = 0.5f;
	stop = false;

	isAlive = true;
	aiShootCount = 0;
	computerControlled = false;
}

Robot::Robot(GLfloat x, GLfloat y) {
	rubble = (Model*)(new LightRubbleModel());
	flag = (Model*)(new FlagModel());
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
        groundplane[0] = 0.0f;
        groundplane[1] = 1.0f;
        groundplane[2] = 0.0f;
        groundplane[3] = 0.0f;
	robotIdCount++;
	robotId = robotIdCount;	

	xPos = x;
	zPos = y;
	xDestination = x;
	zDestination = y;
	spinDegrees = SOUTH;
	spinDestination = SOUTH;
	pitchAngle = 90.0f;
	yawAngle = 90.0f;
	isMyLightOn = false;
	hasBox = false;
	robotLife = MAX_LIFE;

	directionVector[0] = -1.0f;
	directionVector[1] = 0.0f;
	directionVector[2] = 0.0f;

	//BiPod is on
	isPartOn[0] = true;
	selectedIndex = 0;

	for(int i = 1; i < 8; i++){
		isPartOn[i]=false;
	}

	turnIndexOn(1);
	turnIndexOn(3);
	//turnIndexOn(4);
	//turnIndexOn(5);
	//turnIndexOn(6);
	//turnIndexOn(7);

	//incrementSpinDegrees(true,180.0f);
	refreshRobot();

	ct = new CollisionTester;
	box = new BoundingBox(xPos,0.0f,zPos,xPos+1.0f,height,zPos+1.0f, true, this);
	hasBox = true;
	ct->staticBoxes.push_back(box);

	isRobotBeingControlled = false;
	shootBullet();
	currentTime = clock();
	lastExplosion = clock();

	explosionSize = 0.5f;
	stop = false;
	
	isAlive = true;
	aiShootCount = 0;
	computerControlled = false;
}

void Robot::shadowMatrix(GLfloat lightX, GLfloat lightY, GLfloat lightZ, GLfloat lightW)
{
    GLfloat dot;
    //Find dot product between light position vector and ground plane normal
    //From openGL.org
    dot =   groundplane[0]*lightX +
            groundplane[1]*lightY +
            groundplane[2]*lightZ +
            groundplane[3]*lightW;
    
    shadowMat[0] = dot-lightX*groundplane[0];
    shadowMat[4] = 0.0f-lightX*groundplane[1];
    shadowMat[8] = 0.0f-lightX*groundplane[2];
    shadowMat[12] = 0.0f-lightX*groundplane[3];
    
    shadowMat[1] = 0.0f-lightY*groundplane[0];
    shadowMat[5] = dot - lightY*groundplane[1]; 
    shadowMat[9] = 0.0f - lightY*groundplane[2];
    shadowMat[13] = 0.0f - lightY*groundplane[3];
    
    shadowMat[2] = 0.0f - lightZ*groundplane[0];
    shadowMat[6] = 0.0f - lightZ*groundplane[1];
    shadowMat[10] = dot - lightZ*groundplane[2];
    shadowMat[14] = 0.0f - lightZ*groundplane[3];
    
    shadowMat[3] = 0.0f - lightW*groundplane[0];
    shadowMat[7] = 0.0f - lightW*groundplane[1];
    shadowMat[11] = 0.0f - lightW*groundplane[2];
    shadowMat[15] = dot - lightW*groundplane[3];
    
    glMultMatrixf(shadowMat);
}

int Robot::returnClosestLight(GLfloat rows, GLfloat columns) {
    GLfloat len1 = sqrt((xPos-0)*(xPos-0)+(zPos-0)*(zPos-0));
    GLfloat len2 = sqrt((xPos-0)*(xPos-0)+(zPos-rows)*(zPos-rows));
    GLfloat len3 = sqrt((xPos-columns)*(xPos-columns)+(zPos-0)*(zPos-0));
    GLfloat len4 = sqrt((xPos-columns)*(xPos-columns)+(zPos-rows)*(zPos-rows));
    if (len1<len2 && len1<len3 && len1<len4)
        return 1;
    else if (len2<len1 && len2<len3 && len2<len4)
        return 2;
    else if (len3<len2 && len3<len1 && len3<len4)
        return 3;
    else
        return 4;
}

GLfloat Robot::calculateAlpha(GLfloat x, GLfloat z, GLfloat rows, GLfloat columns) {
    GLfloat alpha = 1-(sqrt((xPos-x)*(xPos-x)+(zPos-z)*(zPos-z))/((rows+columns)/4));
    if (alpha>=0.5)
        return 0.5f;
    if (alpha<=0.0)
        return 0.0f;
    else
        return alpha;
}
void Robot::applyShadow(GLfloat rows, GLfloat columns) {
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        glDisable(GL_LIGHTING);
         if (calculateAlpha(0, 0, rows, columns) >=0) {
             glPushMatrix();
                glEnable(GL_STENCIL_TEST);
                glStencilFunc(GL_EQUAL, 10, ~0);
                glStencilOp(GL_KEEP, GL_KEEP, GL_ZERO);
                glTranslatef(xPos, 0.02f, zPos); 
                TextureManager::getInstance()->toggleTextures();
                shadowMatrix(0-xPos, 12, 0-zPos, 1.0f);
                
                glColor4f(0.0, 0.0, 0.0, calculateAlpha(0, 0, rows, columns));
                model->draw();
                //draw();
                TextureManager::getInstance()->toggleTextures();
                
                 glDisable(GL_STENCIL_TEST); 
             glPopMatrix();
         }
            if (calculateAlpha(0, rows, rows, columns) >=0) {
            glPushMatrix();
                glEnable(GL_STENCIL_TEST);
                glStencilFunc(GL_EQUAL, 10, ~0);
                glStencilOp(GL_KEEP, GL_KEEP, GL_ZERO);
                glTranslatef(xPos, 0.02f, zPos); 
                TextureManager::getInstance()->toggleTextures();
                shadowMatrix(0-xPos, 12, rows-zPos, 1.0f);
                glColor4f(0.0, 0.0, 0.0, calculateAlpha(0, rows, rows, columns));
                model->draw();
                //draw();
                TextureManager::getInstance()->toggleTextures();
                glDisable(GL_STENCIL_TEST); 
             glPopMatrix();
            }
            if (calculateAlpha(columns, 0, rows, columns) >=0) {
            glPushMatrix();
                glEnable(GL_STENCIL_TEST);
                glStencilFunc(GL_EQUAL, 10, ~0);
                glStencilOp(GL_KEEP, GL_KEEP, GL_ZERO);
                glTranslatef(xPos, 0.02f, zPos); 
                TextureManager::getInstance()->toggleTextures();
                shadowMatrix(columns-xPos, 12, 0-zPos, 1.0f);
                glColor4f(0.0, 0.0, 0.0, calculateAlpha(columns, 0, rows, columns));
                model->draw();
                //draw();
                TextureManager::getInstance()->toggleTextures();
                glDisable(GL_STENCIL_TEST); 
             glPopMatrix();
            }
            if (calculateAlpha(columns, rows, rows, columns) >=0) {
            glPushMatrix();
                glEnable(GL_STENCIL_TEST);
                glStencilFunc(GL_EQUAL, 10, ~0);
                glStencilOp(GL_KEEP, GL_KEEP, GL_ZERO);
                glTranslatef(xPos, 0.02f, zPos); 
                TextureManager::getInstance()->toggleTextures();
                shadowMatrix(columns-xPos, 12, rows-zPos, 1.0f);
                glColor4f(0.0, 0.0, 0.0, calculateAlpha(columns, rows, rows, columns));
                model->draw();
                //draw();
                TextureManager::getInstance()->toggleTextures();
                glDisable(GL_STENCIL_TEST); 
             glPopMatrix();
            }
    //}
    //glDisable(GL_TEXTURE_2D);
                
                
                
                
                //glDisable(GL_STENCIL_TEST);  
       // glPopMatrix();
                    
        glEnable(GL_DEPTH_TEST);
        glDisable(GL_BLEND);
        glEnable(GL_LIGHTING);
        //glEnable(GL_COLOR_MATERIAL);
    //}
    
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
		//draw bounding box
		glPushMatrix();
			box->draw();
		glPopMatrix();

		//draw robot
		glPushMatrix();
			if (!isRobotBeingControlled){
				if(computerControlled){
					aiSetDestination();
				}
				goToDestination();
			}
		
			//Translate()
			glTranslatef(xPos,0.0f,zPos);
			
			//Spin()
			glTranslatef(0.5f, 0.0f, 0.5f);
			glRotatef(spinDegrees,0.0f,1.0f,0.0f);
			glTranslatef(-0.5f,0.0f,-0.5f);

			//Draw Headlight
			glPushMatrix();
				glTranslatef(0.0f,height-0.25f,0.0f);
				if(isMyLightOn){
					((HeadlightModel*)headlight)->whiteLight = true;
				}
				else{
					((HeadlightModel*)headlight)->whiteLight = false;
				}
				headlight->draw();
			glPopMatrix();

			//Draw Model
			model->draw();
		glPopMatrix();
	}
	else{
		GLUquadricObj *quadric = gluNewQuadric();
		gluQuadricTexture(quadric, true);

		if ((currentTime - lastExplosion) >= 200.0 && explosionSize <= 2.0f)
		{
			explosionSize+=.5f;
			lastExplosion = clock();
			if (explosionSize == 2.5f)
				stop = true;
		}

		if (!stop)
		{
			glPushMatrix();
				glColor3f(1.0f, 0.4f, 0.0f);
				glTranslatef(xPos, 0.0f, zPos);
				gluSphere(quadric, explosionSize+=.5f, 5, 5);
			glPopMatrix();
		}

		box->resize(box->size.x,0.1f,box->size.z);
		glPushMatrix();
			box->draw();
		glPopMatrix();
		glPushMatrix();
			//Translate()
			glTranslatef(xPos,0.0f,zPos);
			glColor3f(0.5f,0.5f,0.5f);
			rubble->draw();
		glPopMatrix();
		gluDeleteQuadric(quadric);
	}
}

//-------------------------------------------------------------
//						COMPONENT TOGGLING
//-------------------------------------------------------------

//Publics
void Robot::cycleIndex(){
	selectedIndex = (selectedIndex+1)%8;
}

void Robot::turnSelectedOn(){
	if(!isPartOn[selectedIndex]){
		turnIndexOn(selectedIndex);
	}
}

void Robot::turnSelectedOff(){
	if(isPartOn[selectedIndex]){
		turnIndexOn(selectedIndex);
	}
}

//Privates
void Robot::turnIndexOn(int index){

	switch(index){
		case 0: //bipod
			isPartOn[0] = true; 
			isPartOn[1] = false;
			isPartOn[2] = false;
			break;
		case 1: //tracks
			isPartOn[1] = true;
			isPartOn[0] = false;
			isPartOn[2] = false;
			break;
		case 2: //antigrav
			isPartOn[2] = true;
			isPartOn[0] = false;
			isPartOn[1] = false;
			break;
		case 3: case 4: case 5: case 6: case 7: 
	  //cannon  missile phaser  nuclear electronics
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
	//setup
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
	calculateHeight();
	if(hasBox){
		if(robotLife > 0){
			box->resize(box->size.x,height,box->size.z);
		}
		else{
			box->resize(box->size.x,0.01f,box->size.z);
		}
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
//						COORDINATE ACCESSORS
//-------------------------------------------------------------

GLfloat Robot::getEyeX(){
	//original position after translated to y-axis (-.2,0,0)
	//rotation + translation
	GLfloat rotatedPosX = -.2f*cos(spinDegrees*GL_PI/180.0f) + 0.5f;
	return xPos+rotatedPosX;
}

GLfloat Robot::getEyeY(){
	return height+0.15f;
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
	//pitched[1] = calculateHeight(8)+0.15f-cos(pitchAngle*GL_PI/180.0f);
	pitched[1] = height+0.15f-cos(pitchAngle*GL_PI/180.0f);
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
	//pitched[1] = calculateHeight(8)+0.15f-cos(70*GL_PI/180.0f);
	pitched[1] = height+0.15f-cos(70*GL_PI/180.0f);
	pitched[2] = 0.5f-0.5f;

	GLfloat* rotated = new GLfloat[3];
	rotated[0] = pitched[0]*cos(spinDegrees*GL_PI/180.0f)+ pitched[2]*sin(spinDegrees*GL_PI/180.0f) + 0.5f +xPos;
	rotated[1] = pitched[1];
	rotated[2] = pitched[0]*-sin(spinDegrees*GL_PI/180.0f)+ pitched[2]*cos(spinDegrees*GL_PI/180.0f) + 0.5f +zPos;
	
	return rotated;
}

GLfloat Robot::calculateHeight(){
	GLfloat h = 0.25f;
	for(int i = 0; i <= 7; i++){
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
	height = h;
	return h;
}
GLfloat Robot::calculateHeight(int index){
	GLfloat h = 0.25f; 
	for(int i = 0; i <= index; i++){
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
	directionVector[1] = 0.0f;
	directionVector[2] = 0.0f;
	directionVector[3] = 1.0f;
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

//-------------------------------------------------------------------------------
//							ROBOT-SPINNING
//-------------------------------------------------------------------------------
void Robot::incrementSpinDegrees(bool pos, GLfloat speed){

	if(pos){
		spinDegrees += speed; //true increases angle by one
	}
	else{
		spinDegrees -= speed;
	}

	spinDirectionVector();
	normalizeSpinDegrees();
	notifyCamera();
}

//used for mouse control
void Robot::incrementSpinDegrees(int x, int y)
{
	int diffX, centerX, centerY;

	centerX = glutGet(GLUT_WINDOW_WIDTH) / 2;
	centerY = glutGet(GLUT_WINDOW_HEIGHT) / 2;

	diffX = x - centerX;

	if (diffX != 0)
	{
		glutWarpPointer(centerX, centerY);
		incrementSpinDegrees(false, diffX * MOUSE_SENSITIVITY);
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

//-------------------------------------------------------------------------------
//							ROBOT-WALKING
//-------------------------------------------------------------------------------
void Robot::moveStrafe(bool pos)
{
	if (robotLife <= 0.0f)
		return; //for now

	if(pos){
		if(!robotCollisionTest(xPos - (GLfloat)directionVector[2]*ROBOT_STEP_SIZE, 0.0f,
			zPos + (GLfloat)directionVector[0]*ROBOT_STEP_SIZE)){

			xPos -= (GLfloat)directionVector[2]*ROBOT_STEP_SIZE;
			zPos += (GLfloat)directionVector[0]*ROBOT_STEP_SIZE;

			box->moveBox((GLfloat)-directionVector[2]*ROBOT_STEP_SIZE, 0.0f,
				(GLfloat)directionVector[0]*ROBOT_STEP_SIZE);
		}
	}
	else
	{
		if(!robotCollisionTest(xPos + (GLfloat)directionVector[2]*ROBOT_STEP_SIZE, 0.0f,
			zPos - (GLfloat)directionVector[0]*ROBOT_STEP_SIZE)){

			xPos += (GLfloat)directionVector[2]*ROBOT_STEP_SIZE;
			zPos -= (GLfloat)directionVector[0]*ROBOT_STEP_SIZE;

			box->moveBox((GLfloat)directionVector[2]*ROBOT_STEP_SIZE,0.0f,
				(GLfloat)-directionVector[0]*ROBOT_STEP_SIZE);
		}
	}

	notifyCamera();
	
}

void Robot::moveForward(bool pos)
{
	if (robotLife <= 0.0f)
		return;

	if(pos){
		if(!robotCollisionTest(xPos + (GLfloat)directionVector[0]*ROBOT_STEP_SIZE, 0.0f,
			zPos + (GLfloat)directionVector[2]*ROBOT_STEP_SIZE)){

			xPos += (GLfloat)directionVector[0]*ROBOT_STEP_SIZE;
			zPos += (GLfloat)directionVector[2]*ROBOT_STEP_SIZE;

			box->moveBox((GLfloat)directionVector[0]*ROBOT_STEP_SIZE,0.0f,
				(GLfloat)directionVector[2]*ROBOT_STEP_SIZE);
		}
	}
	else{
		if(!robotCollisionTest(xPos - (GLfloat)directionVector[0]*ROBOT_STEP_SIZE,0.0f,
			zPos - (GLfloat)directionVector[2]*ROBOT_STEP_SIZE))
		{

			xPos -= (GLfloat)directionVector[0]*ROBOT_STEP_SIZE;
			zPos -= (GLfloat)directionVector[2]*ROBOT_STEP_SIZE;

			box->moveBox(-(GLfloat)directionVector[0]*ROBOT_STEP_SIZE,0.0f,-(GLfloat)directionVector[2]*ROBOT_STEP_SIZE);
		}
	}

	notifyCamera();
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
	GLfloat minY = 0.0f;
	if(isPartOn[2]){
		minY = 0.1f;
	}
	if(pos){
		if(!robotCollisionTest(xPos+0.05f,minY,zPos)){
			xPos += 0.05f;
			box->moveBox(0.05f,0.0f,0.0f);
		}
	}
	else{
		if(!robotCollisionTest(xPos-0.05f,minY,zPos)){
			xPos -= 0.05f;
			box->moveBox(-0.05f,0.0f,0.0f);
		}
	}
	notifyCamera();
}

void Robot::incrementZPos(bool positive){
	GLfloat minY = 0.0f;
	if(isPartOn[2]){
		minY = 0.1f;
	}

	if(positive){
		if(!robotCollisionTest(xPos,minY,zPos+0.05f)){
			zPos += 0.05f;
			box->moveBox(0.0f,0.0f,0.05f);
		}
	}
	else{
		if(!robotCollisionTest(xPos,minY,zPos-0.05f)){
			zPos -= 0.05f;
			box->moveBox(0.0f,0.0f,-0.05f);
		}
	}
	notifyCamera();
}

//-------------------------------------------------------------------------------
//							DESTINATION-RELATED
//-------------------------------------------------------------------------------
void Robot::setDestination(GLfloat x, GLfloat z){
	xDestination = x;
	zDestination = z;
}

void Robot::goToDestination(){
	if(checkXDestination() && checkZDestination()){
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
}

bool Robot::checkXDestination(){
	//If difference in position -> spin towards left or right
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
	//If difference in position -> spin towards left or right
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

bool Robot::robotCollisionTest(GLfloat x, GLfloat y, GLfloat z){
	if(ct->collisionTest(x,y,z,box->movingBoxId)){
			return true;
		}
		if(ct->collisionTest(x+box->size.x, y, z,box->movingBoxId)){
			return true;
		}
		if(ct->collisionTest(x,	y,z+box->size.z,box->movingBoxId)){
			return true;
		}
		if(ct->collisionTest(x+box->size.x,	y,z+box->size.z,box->movingBoxId)){
			return true;
		}
		if(ct->collisionTest(x,	y+box->size.y, z,box->movingBoxId)){
			return true;
		}
		if(ct->collisionTest(x+box->size.x,	y+box->size.y,z,box->movingBoxId)){
			return true;
		}
		if(ct->collisionTest(x,	y+box->size.y,z+box->size.z,box->movingBoxId)){
			return true;
		}
		if(ct->collisionTest(x+box->size.x,	y+box->size.y,z+box->size.z,box->movingBoxId)){
			return true;
		}

		return false;
}

//For Robert and first person view movement
void Robot::spinDirectionVector(){
	directionVector[0] = -cos((spinDegrees)*DegreesToRadians);
	directionVector[2] = sin((spinDegrees)*DegreesToRadians);
}

void Robot::shootBullet(){
	SoundHelper::getInstance()->play("shoot.wav", 1, false);
	if(robotLife>0){
		spinDirectionVector();
		//check which component is highest
		int highestIndex = 0;
		for(int i = 3; i <= 5; i++){
			if(isPartOn[i]){
				highestIndex = i;
			}
		}
		GLfloat yPosition = calculateHeight(highestIndex);
		GLfloat bulletSpawnOffset[2];
		GLfloat bulletSpawnOffset2[2];
		//create bullet at spawn point
		switch(highestIndex){
		case 5:
			//rotate offset
			bulletSpawnOffset[0] = -.7f*cos((spinDegrees)*DegreesToRadians) + 0.5f;
			bulletSpawnOffset[1] = .7f*sin((spinDegrees)*DegreesToRadians) +0.5f;
			//Rotate
			bm->addBullet(xPos+bulletSpawnOffset[0],yPosition-0.3f,zPos+bulletSpawnOffset[1],directionVector[0],directionVector[1],directionVector[2], spinDegrees);
			break;
		case 4:
			//rotate offset
			bulletSpawnOffset[0] = -0.7f*cos((spinDegrees)*DegreesToRadians) - 0.35f*sin((spinDegrees)*DegreesToRadians) + 0.5f;
			bulletSpawnOffset[1] = 0.7f*sin((spinDegrees)*DegreesToRadians) - 0.35f*cos((spinDegrees)*DegreesToRadians) + 0.5f;
			bulletSpawnOffset2[0] = -0.7f*cos((spinDegrees)*DegreesToRadians) + 0.35f*sin((spinDegrees)*DegreesToRadians) + 0.5f;
			bulletSpawnOffset2[1] = 0.7f*sin((spinDegrees)*DegreesToRadians) + 0.35f*cos((spinDegrees)*DegreesToRadians) + 0.5f;

			//spawn point needs to accomodate rotation
			bm->addBullet(xPos+bulletSpawnOffset[0],yPosition-0.2f,zPos+bulletSpawnOffset[1],directionVector[0],directionVector[1],directionVector[2], spinDegrees);
			bm->addBullet(xPos+bulletSpawnOffset2[0],yPosition-0.2f,zPos+bulletSpawnOffset2[1],directionVector[0],directionVector[1],directionVector[2], spinDegrees);
			break;
		case 3:
			//offset facing south
			bulletSpawnOffset[0] = -0.85f*cos((spinDegrees)*DegreesToRadians) - 0.15f*sin((spinDegrees)*DegreesToRadians) + 0.5f;
			bulletSpawnOffset[1] = 0.85f*sin((spinDegrees)*DegreesToRadians) - 0.15f*cos((spinDegrees)*DegreesToRadians) + 0.5f;
			bulletSpawnOffset2[0] = -0.85f*cos((spinDegrees)*DegreesToRadians) + 0.15f*sin((spinDegrees)*DegreesToRadians) + 0.5f;
			bulletSpawnOffset2[1] = 0.85f*sin((spinDegrees)*DegreesToRadians) + 0.15f*cos((spinDegrees)*DegreesToRadians) + 0.5f;

			//spawn point needs to accomodate rotation
			bm->addBullet(xPos+bulletSpawnOffset[0],yPosition-.2f,zPos+bulletSpawnOffset[1],directionVector[0],directionVector[1],directionVector[2], spinDegrees);
			bm->addBullet(xPos+bulletSpawnOffset2[0],yPosition-.2f,zPos+bulletSpawnOffset2[1],directionVector[0],directionVector[1],directionVector[2], spinDegrees);
		default:
			break;
		}
	}
}

void Robot::takeDamage(GLfloat damage){
	robotLife -= damage;
}

V3 Robot::getUFOLockPosition(){
	V3 v3 = {xPos,height+0.5f,zPos};
	return v3;
}

int Robot::getRobotId(){
	return robotId;
}

//-----------------------------------------------------------------------------------------
//          randomize automated movements
//-----------------------------------------------------------------------------------------
void Robot::aiSetDestination(){
	//randomize shooting
	int randomNum = rand() % 15;
	if(randomNum == 7 || randomNum == 9){
		shootBullet();
	}
	//randomize destination
	if((checkXDestination() && checkZDestination())){
		int randomNum2 = rand() % 10;
		switch(randomNum2){
		case 0: case 1: case 2: case 3: case 4:
			if(checkXPos(false)){
				setDestination(xPos-ROBOT_LOOK_SIZE-1, zPos);
			}
			break;
		case 5: case 6:
			if(checkZPos(false)){
				setDestination(xPos, zPos-ROBOT_LOOK_SIZE);
			}
			break;
		case 8:
			if(checkZPos(true)){
				setDestination(xPos, zPos+ROBOT_LOOK_SIZE);
			}
			break;
		case 9:
			if(checkXPos(true)){
				setDestination(xPos+ROBOT_LOOK_SIZE, zPos);
			}
			break;
		default:
			break;
		}
		
	}
}

//used to help decide on a destination
bool Robot::checkXPos(bool pos){
	GLfloat minY = 0.0f;
	if(isPartOn[2]){
		minY = 0.1f;
	}
	if(pos){
		if(!robotCollisionTest(xPos+ROBOT_LOOK_SIZE,minY,zPos)){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		if(!robotCollisionTest(xPos-ROBOT_LOOK_SIZE-1,minY,zPos)){
			return true;
		}
		else{
			return false;
		}
	}
	notifyCamera();
}

//used to help decide on a destination
bool Robot::checkZPos(bool positive){
	GLfloat minY = 0.0f;
	if(isPartOn[2]){
		minY = 0.1f;
	}

	if(positive){
		if(!robotCollisionTest(xPos,minY,zPos+ROBOT_LOOK_SIZE)){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		if(!robotCollisionTest(xPos,minY,zPos-ROBOT_LOOK_SIZE)){
			return true;
		}
		else{
			return false;
		}
	}
	notifyCamera();
}
