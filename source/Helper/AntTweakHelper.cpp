#include "AntTweakHelper.h"

AntTweakHelper::AntTweakHelper() {
    TwInit(TW_OPENGL, NULL);

    bar = TwNewBar("Debugging");	
    TwWindowSize(500, 500);
    TwDefine(" Debugging size='250 500' alpha=150 ");
}

void AntTweakHelper::draw() {
  TwDraw();
}

void AntTweakHelper::bindCamera(Camera *c) {
	 TwAddVarRW(bar, "FOV Y", TW_TYPE_FLOAT, &(c->fovy), " group=Camera");
	 TwAddVarRW(bar, "Location X (B)", TW_TYPE_FLOAT, &(c->locX), " group=Location step=1 keyIncr=b keyDecr=B");
	 TwAddVarRW(bar, "Location Y (N)", TW_TYPE_FLOAT, &(c->locY), " group=Location step=1 keyIncr=n keyDecr=N");
	 TwAddVarRW(bar, "Location Z (M)", TW_TYPE_FLOAT, &(c->locZ), " group=Location step=1 keyIncr=m keyDecr=M");
   
   TwAddVarRW(bar, "Yaw (Z)", TW_TYPE_FLOAT, &(c->yaw), " group=Rotation step=1 keyIncr=z keyDecr=Z");
	 TwAddVarRW(bar, "Pitch (X)", TW_TYPE_FLOAT, &(c->pitch), " group=Rotation step=1 keyIncr=x keyDecr=X");
	 TwAddVarRW(bar, "Roll (C)", TW_TYPE_FLOAT, &(c->roll), " group=Rotation step=1 keyIncr=c keyDecr=C");

   TwDefine(" Debugging/Location group=Camera \n Debugging/Rotation group=Camera ");
}
