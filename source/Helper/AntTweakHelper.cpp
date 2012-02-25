#include "AntTweakHelper.h"
#include "Robot/TracksModel.h"

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

void AntTweakHelper::bindLightPosts(LightPost *l1, LightPost *l2, LightPost *l3, LightPost *l4) { 
    TwAddVarRW(bar, "Spot 1", TW_TYPE_DIR3F, &(l1->spotDir), " group='Light 1' label='Spot Direction' ");
    TwAddVarRW(bar, "X1", TW_TYPE_FLOAT, &(l1->posX), " group='Light 1/Location'");
    TwAddVarRW(bar, "Y1", TW_TYPE_FLOAT, &(l1->posY), " group='Light 1/Location'");
    TwAddVarRW(bar, "Z1", TW_TYPE_FLOAT, &(l1->posZ), " group='Light 1/Location'");
    
    
    TwAddVarRW(bar, "Spot 2", TW_TYPE_DIR3F, &(l2->spotDir), " group='Light 2' label='Spot Direction'");
    TwAddVarRW(bar, "X2", TW_TYPE_FLOAT, &(l2->posX), " group='Light 2/Location'");
    TwAddVarRW(bar, "Y2", TW_TYPE_FLOAT, &(l2->posY), " group='Light 2/Location'");
    TwAddVarRW(bar, "Z2", TW_TYPE_FLOAT, &(l2->posZ), " group='Light 2/Location'");       

    TwAddVarRW(bar, "Spot 3", TW_TYPE_DIR3F, &(l3->spotDir), " group='Light 3' label='Spot Direction'");
    TwAddVarRW(bar, "X3", TW_TYPE_FLOAT, &(l3->posX), " group='Light 3/Location'");
    TwAddVarRW(bar, "Y3", TW_TYPE_FLOAT, &(l3->posY), " group='Light 3/Location'");
    TwAddVarRW(bar, "Z3", TW_TYPE_FLOAT, &(l3->posZ), " group='Light 3/Location'"); 
    
    TwAddVarRW(bar, "Spot 4", TW_TYPE_DIR3F, &(l4->spotDir), " group='Light 4' label='Spot Direction'");
    TwAddVarRW(bar, "X4", TW_TYPE_FLOAT, &(l4->posX), " group='Light 4/Location'");
    TwAddVarRW(bar, "Y4", TW_TYPE_FLOAT, &(l4->posY), " group='Light 4/Location'");
    TwAddVarRW(bar, "Z4", TW_TYPE_FLOAT, &(l4->posZ), " group='Light 4/Location'"); 
        
    TwDefine(" Debugging/'Light 1' group='Lights Posts' \n Debugging/'Light 2' group='Lights Posts' ");
    TwDefine(" Debugging/'Light 3' group='Lights Posts' \n Debugging/'Light 4' group='Lights Posts' ");
    TwDefine(" Debugging/'Light 1/Location' group='Light 1' \n Debugging/'Light 2/Location' group='Light 2' ");
    TwDefine(" Debugging/'Light 3/Location' group='Light 3' \n Debugging/'Light 4/Location' group='Light 4' ");
}
