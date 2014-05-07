#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include "opencv2\opencv.hpp"
using namespace cv;

using namespace std;
#include <iostream>
#include <string.h>

class ItemList_Interface{
public:
	const vector <string >typeList = {"milk","coke","salt", "apple"};

	vector <string >xmlList = {"./milk.xml","./coke.xml","./salt.xml", "./apple.xml"};
			};
