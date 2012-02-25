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
z --------------- toggle bird view (disabled for now)
arrows ---------- move camera around
page up/down ---- rotate
end ------------- reset rotation angle to 0
= --------------- zoom in
- --------------- zoom out
0 --------------- reset zoom
a --------------- toggle ambient light

The following keys interchange robot parts.
** The robot can be found near the bottom of the map around where the base and factory are**
t --------------- changes robot's head
y --------------- changes robot's body
u --------------- chanegs robot's legs

AntTweakBar is used (http://www.antisphere.com/Wiki/tools:anttweakbar) for the debugging window. The output in the makefile has been modified to accomodate our project structure 

Installation 
------------

OSX:
cd include/TweakAnt/src/
make -f Makefile.osx

Linux:
cd include/TweakAnt/src/
make
