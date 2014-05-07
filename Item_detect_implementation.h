#include<Item_detect_constructors.h>
#include<Item_detect_interface.h>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include "opencv2\opencv.hpp"
using namespace cv;
using namespace std;
#include <iostream>
#include <string.h>



class Item_detect_implementation : Item_detect_interface
{
	public:
	virtual int detectAndDisplay( string inputImage, bool Cameracapture );
}
