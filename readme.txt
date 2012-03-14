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

Key bindings:

f1 --------------- toggle wireframe/smooth shading/flat shading
f2 --------------- mouse look (freelook)
f3 --------------- commander camera (toggle light with 'l')
f5 --------------- robot camera (need to attach robot first, with 't')
z --------------- toggle bird view (disabled for now)
o --------------- toggle textures
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
s --------------- Toggle SkyBox/SkySphere
h --------------- help
o --------------- toggle textures

Robot View buttons:
arrows L/R ------ spin robot
arrows U/D ------ pitch
page up/down ---- yaw
l --------------- light

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

Texture Credits:
Fence: http://vortex-x.deviantart.com/art/green-white-metal-wall-118983148
Mountain: http://www.pixelperfectdigital.com/free_stock_photos/showfull.php?photo=7419
Floor: http://www.mb3d.co.uk/mb3d/Metal_Rusty_and_Patterned_Seamless_and_Tileable_High_Res_Textures.html
Team Number: http://free4illustrator.com/2009/04/seamless-reptile-textures-and-photoshop-patterns/
Player: http://www.psdgraphics.com/textures/brushed-gold-metal-texture/
MetalVerticalLines: www.webtexture.net/textures/6-high-resolution-metal-texture/
Concrete_bare, Dirt, Ink, Marble, Metal1, Metal2, Metal 3, Metal4: www.cgtextures.com
Lightpost: http://media.moddb.com/legacy/images/tutorials/30/308/gallery/t_508.jpg
Camo: http://farm4.static.flickr.com/3324/3628571124_51e7bbdff6.jpg
smooth_metal.bmp: http://hhh316.deviantart.com/art/Seamless-metal-texture-smooth-164165216
skull: http://bestpooltablesreview.blogspot.com/2011/04/buy-2d-glitter-skull-flights-100-micron.html
Titanium: http://www.jbdesign.it/idesignpro/metal.html
mechanical: http://www.svgopen.org/2003/papers/UsingSVGFor2DContentInMobile3DGames/index.html
energy: http://www.123rf.com/photo_9298276_glowing-energy-streaks-abstract-seamless-background-texture.html
earth and moon : http://frank.mtsu.edu/~njsmith/astr/lab02.shtml
sun: http://www.dailymail.co.uk/sciencetech/article-1290919/First-photo-planet-circling-distant-sun-outside-solar-system.html
nebula: http://cs.astronomy.com/asycs/media/p/474777.aspx
stars1.bmp: http://www.khilafatworld.com/2012/01/poem-look-in-stars.html
stars2.bmp: http://www.therealfun.com/Stars-in-night-10535.html
milky way: http://www.moonphases.info/the-stars.html

