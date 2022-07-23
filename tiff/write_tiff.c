#include <stdlib.h>
#include <stdio.h>
#include <tiffio.h>
#include "tiff_proto.h"

void write_tiff(
 char *filename,
 unsigned char *data,
 int w,
 int h,
 int sampleperpixel
)
{
        uint32 row;
        unsigned char *line;
        int r;
	TIFF *tif = TIFFOpen(filename, "w");

        int bitspersample = 8; /* from 0 to 255 */

	TIFFSetField(tif, TIFFTAG_IMAGEWIDTH, w);
	TIFFSetField(tif, TIFFTAG_IMAGELENGTH, h);
	TIFFSetField(tif, TIFFTAG_SAMPLESPERPIXEL, sampleperpixel);
	TIFFSetField(tif, TIFFTAG_BITSPERSAMPLE, bitspersample);
	TIFFSetField(tif, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
	TIFFSetField(tif, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
        if ( sampleperpixel == 1 ) /* grayscale */
	 TIFFSetField(tif, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_MINISBLACK);
        if ( sampleperpixel == 4 ) /* rgb colors + alpha */
	 TIFFSetField(tif, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB);
	TIFFSetField(tif, TIFFTAG_COMPRESSION, COMPRESSION_NONE);

        for ( row= 0 ; row< h ; row++ ) {
           line= data + row*w*sampleperpixel;
           r = TIFFWriteScanline(tif,line,row,0);
        }

	TIFFClose(tif);
}
