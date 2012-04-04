Jonathan Bergeron	9764453
Jeffrey  How		9430954
Robert   Jakubowicz	6045707
Stefanie Lavoie		1951750
Addison  Rodomista	1967568

Compile Directions: 
1. In Microsoft Visual Studio, click on the project.
2. Click on Properties
3. Click on Debugging
4. Change Working Directory to $(SolutionDir)

This version works on windows, mac and linux?.

Key Bindings:
f1 --------------- cycle wireframe/smooth shading/flat shading
f2 --------------- mouse look (freelook)
f3 --------------- commander camera
f4 ---------------- toggle bird view
f5 --------------- side view camera
f6 --------------- toggle skins
f8 --------------- toggle splitscreen
f10 -------------- toggle team number
Alt-Enter -------- fullscreen
b ---------------- debugger
k ---------------- Toggle environmental mapping
[ ] -------------- roll camera
/ ---------------- reset roll/pitch
l ---------------- toggle light (in bird view)
t ---------------- toggle texture
arrows ----------- move camera around
page up/down ----- rotate
end -------------- reset rotation angle to 0
= ---------------- zoom in
- ---------------- zoom out
0 ---------------- reset zoom
p ---------------- toggle ambient light
1 --------------- camera of light 1
2 --------------- camera of light 2
3 --------------- camera of light 3
4 --------------- camera of light 4
5 --------------- on/off light 1
6 --------------- on/off light 2
7 --------------- on/off light 3
8 --------------- on/off light 4
9 --------------- on/off all lights

GamePlay:
Space ----------- levitate ufo
wasd ------------ move ufo in commander view… move robot in robot view
r --------------- set robot destination with ufo
f --------------- mate ufo with robot

Toggle robot components:
i --------------- cycle components
j --------------- turn component off
u --------------- turn component on


DeathMatch Controls:
player 1:
mouse move ------------look around
mouse left button ---- shoot / respawn
wasd ----------------- move around

player 2 (joystick):
arrows --------------- to move forwards/backwards and strafe
bumpers -------------- to turn left or right
a -------------------- to shoot /respawn


AntTweakBar is used (http://www.antisphere.com/Wiki/tools:anttweakbar) for the debugging window. The output in the makefile has been modified to accomodate our project structure 
Dirent API for windows http://www.softagalleria.net/dirent.php


Installation 
------------

OSX:
cd include/TweakAnt/src/
make -f Makefile.osx

Linux:
cd include/TweakAnt/src/
make
