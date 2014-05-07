#include <iostream>
#include <cstddef>
#include "zbar.h"
#include "cv.h"
#include "highgui.h"

using namespace std;
using namespace zbar;
using namespace cv;

string getBarcode(string location){
    
	/* Initialise the scanner to scan the barcode */
	ImageScanner scanner;
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
	string RetString;
    
	/* Load the image from location */
	Mat frame = imread(location,0);
    
	/* Convert the Image to Gray scale */
	Mat grayScale;
	cvtColor(frame,grayScale,CV_GRAY2RGB);
    
	/* Get the width and height of the image to make it easier to scan */
	int width 				= frame.cols;
	int height 				= frame.rows;
	unsigned char *data 	= frame.data;
    
	/* Image scanner only supports the Y800 format, that is 8bpp Gray Scale format */
	/* Wrap the raw image date into Image object provided by zlib */
	Image image(width, height,"Y800",data, width * height);
    
	/* The function scans the image for a barcode; if no barcode is found it returns an empty string and flashes a warning */
	if (scanner.scan(image))
    {
        
		/* Extract the barcode */
		Image::SymbolIterator symbol = image.symbol_begin();
		RetString =  symbol->get_data();
        
		/* Clean up the image */
		image.set_data(NULL, 0);
	}
	else
	{
        
		cout << "WARNING: NO BARCODE FOUND!" << endl ;
	
    }
    
	return RetString;
}
