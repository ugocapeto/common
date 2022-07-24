# common

Written and tested on Ubuntu 22.04.

This repo contains code to create libraries used by my other repos. In your directory structure, this repo should be at the same level as my other repos. Otherwise, you will have to change the Makefiles. 

Structure:

common/io

common/jpeg

common/math

common/png

common/tiff

common/util

To compile the code, simply use "make -f Makefile_g/Makefile_O" in each sub-directory.

The following libraries (actually, just object files) will be created:

io.o

jpeg.o

math.o

png.o

tiff.o

util.o

Dependencies (check the Makefile):

libjpeg-dev

libpng-dev

libtiff-dev
