# common

This repo contains code to create libraries used by other repos. In your directory structure, this repo should be at the same level as any other repo I offer. Otheriwse, you will have to change the Makefiles. 

Structure:

common/io\
common/jpeg\
common/math\
common/png\
common/tiff\
common/util

To compile the code (linux), simply "make -f Makefile_g/Makefile_O" in each sub-directory.

The following libraries (actually, it's just an object file) will be created:

io.o\
jpeg.o\
math.o\
png.o\
tiff.o\
util.o
