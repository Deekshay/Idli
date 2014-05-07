#include <ItemList_Interface.h>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include "opencv2\opencv.hpp"
using namespace cv;

using namespace std;
#include <iostream>
#include <string.h>

class Item_detect_interface{
public:
	double scaleFactor;
	int minNeighbors;
	int flag;
	Size minSize;
	string type;
	string ClassifierFile;
	ItemList_Interface objList;
	Item_detect_interface ();
	Item_detect_interface (string tp);
	Item_detect_interface(string tp, string fileName);
};
 
