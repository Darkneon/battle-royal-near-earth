Jonathan Bergeron	9764453
Jeffrey  How		9430954
Robert   Jakubowicz	6045707
Stefanie Lavoie		1951750
Addison  Rodomista	1967568

This version works on windows, mac and linux.

Key bindings:

f1 --------------- toggle wireframe/smooth shading
f2 --------------- mouse look (freelook)
f3 --------------- commander camera
f5 --------------- robot camera (need to attach robot first, with 't')
z --------------- toggle bird view (disabled for now)
arrows ---------- move camera around
page up/down ---- rotate
end ------------- reset rotation angle to 0
= --------------- zoom in
- --------------- zoom out
0 --------------- reset zoom
a --------------- toggle ambient light
1 --------------- camera of light 1
2 --------------- camera of light 2
3 --------------- camera of light 3
4 --------------- camera of light 4
5 --------------- on/off light 1
6 --------------- on/off light 2
7 --------------- on/off light 3
8 --------------- on/off light 4
9 --------------- on/off all lights

The following keys interchange robot parts.
** The robot can be found near the bottom of the map around where the base and factory are**
t --------------- attach robot to Robot camera
y --------------- cycle through selection of robot parts
u --------------- toggle selected robot part

Robot View buttons:
arrows L/R ------ spin robot
arrows U/D ------ pitch
page up/down ---- yaw
l --------------- light

AntTweakBar is used (http://www.antisphere.com/Wiki/tools:anttweakbar) for the debugging window. The output in the makefile has been modified to accomodate our project structure 

Installation 
------------

OSX:
cd include/TweakAnt/src/
make -f Makefile.osx

Linux:
cd include/TweakAnt/src/
make
