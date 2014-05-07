#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include "opencv2\opencv.hpp"
using namespace cv;

using namespace std;
#include <iostream>
#include <string.h>

class itemList{
public:
	const vector <string >typeList = {"milk","coke","salt", "apple"};
	vector <string >xmlList = {"./milk.xml","./coke.xml","./salt.xml", "./apple.xml"};
};

class item{
public:
	double scaleFactor;
	int minNeighbors;
	int flag;
	Size minSize;
	string type;
	string ClassifierFile;
	itemList objList;

	/*Default constructor*/
	item ():
		scaleFactor{1.1}, minNeighbors{4},
		flag{0}, minSize{Size(10,40)},
		type{},ClassifierFile {} {}

		/*If the type is specified initialize the variables according to the string specified*/
		item (string tp) {
			if(tp == "milk")
			{
				scaleFactor     = 1.1;
				minNeighbors    = 4;
				flag 		    = 0;
				minSize 	    = Size(10,40);
				type 		    = objList.typeList[0];
				ClassifierFile  = "./milk.xml";
			}
			else if(tp =="coke"){
				scaleFactor 	= 1.1;
				minNeighbors 	= 4;
				flag 			= 0;
				minSize 		= Size(10,40);
				type 			= objList.typeList[1];
				ClassifierFile 	= "./coke.xml";
			}
			else if(tp == "salt"){
				scaleFactor 	= 1.5;
				minNeighbors 	= 4;
				flag 			= 0;
				minSize 		= Size(40,200);
				type 			= objList.typeList[2];
				ClassifierFile 	= "./salt.xml";
			}
			else if(tp == "apple"){
				scaleFactor 	= 1.3;
				minNeighbors 	= 4;
				flag 			= 0;
				minSize 		= Size(50,50);
				type 			= objList.typeList[3];
				ClassifierFile 	= "./apple.xml";
			}

			else
			{
				cout << "Unknown object specified. Default initialization will be done \n";
				scaleFactor     = 1.1;
				minNeighbors    = 4;
				flag 		    = 0;
				minSize 	    = Size(100,100);
				type 		    = "";
				ClassifierFile  = "";
			}

		}

		/*If the location of the xml is specified then the initilize using the xml file*/
		item (string tp, string fileName) {
			if(tp == objList.typeList[0])
			{
				scaleFactor = 1.1;
				minNeighbors = 4;
				flag = 0;
				minSize = Size(10,40);
				type = objList.typeList[0];
				ClassifierFile = fileName;
			}
			if(tp == objList.typeList[1]){
				scaleFactor = 1.1;
				minNeighbors = 4;
				flag = 0;
				minSize = Size(10,40);
				type = objList.typeList[1];
				ClassifierFile = fileName;
			}
			if (tp == objList.typeList[2]){
				scaleFactor = 1.5;
				minNeighbors = 4;
				flag = 0;
				minSize = Size(40,200);
				type = objList.typeList[2];
				ClassifierFile = fileName;
			}
			if (tp == objList.typeList[3]){
				scaleFactor = 1.1;
				minNeighbors = 4;
				flag = 0;
				minSize = Size(40,200);
				type = objList.typeList[3];
				ClassifierFile = fileName;
			}

		}
};

//* Function Headers



string window_name = "Capture - Milk detection";

// * @function main

//* @function detectAndDisplay
int detectAndDisplay( string inputImage, bool Cameracapture )
{

	CascadeClassifier cascade;
	itemList l;
	std::vector<Rect> object;
	unsigned int i = 0;
	CvCapture* capture;


	Mat frame;

	//-- 2. Read the video stream
	if (Cameracapture)
	{
		capture = cvCaptureFromCAM( -1 );
		if( capture )
		{
			frame = cvQueryFrame( capture );
		}
	}
	else
		frame = imread(inputImage);

	//-- 3. Apply the classifier to the frame
	if(!frame.empty())
	{
		while(i < l.typeList.size())
		{
			item item1(l.typeList[i]);
			if( !item1.ClassifierFile.empty())
			{
				if( !cascade.load( item1.ClassifierFile ) ){
					printf("--(!)Error loading\n");
					return -1;
				}
				else
				{
					cout << "loading classifier for " << item1.type << endl;
				}
			}
			else
			{
				cout << "No classifier specified. Exiting!!";
				return -1;
			}


			//-- Detect item
			cascade.detectMultiScale( frame, object,item1.scaleFactor, item1.minNeighbors, item1.flag|CV_HAAR_SCALE_IMAGE, item1.minSize );


			if(object.size() != 0)
			{
				int max = 0, i = 0;
				for( size_t j = 0; j < object.size(); j++ )
				{
					if(max < object[j].width*object[j].height){
						max = object[i].width*object[i].height;
						i = j;
					}
				}

				{
					Point pt1, pt2;
					pt1.x = object[i].x;
					pt1.y = object[i].y;
					pt2.x = object[i].x + object[i].width;
					pt2.y = object[i].y + object[i].height;
					cout << object[i].x << "   "<< object[i].y << "  " <<endl;
					rectangle( frame, pt1, pt2, 4, 2, 0 );

					Mat faceROI = frame( object[i] );
				}

				//-- Show what you got
				imshow( window_name, frame );

				// to extract file name onto string s
				std::istringstream f(inputImage);
				std::string s;
				while (std::getline(f, s, '/')) ;

				//find the location of the input image
				unsigned pos = inputImage.find(s);
				std::string str2 = inputImage.substr (0,pos);
				//save the result in the same folder as the input
				imwrite(str2 +"o"+s,frame);
			}
			else
			{
				imshow( window_name, frame );
				cout <<"No object detected \n" << endl;
			}
			waitKey(0);
			i++;
		}
		return 1;

	}
	else
	{
		printf("No image");
		return -1;
	}
}

