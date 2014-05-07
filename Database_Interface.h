#include<Item_Interface.h>
#include<Item_Interface.h>
#include<Item_Interface_detect_constructors.h>
#include<Item_Interface_detect_interface.h>
#include<Item_Interface_detect_implementation.h>
#include <Objectdetect.h>
#include "rc.h"
#include<iostream>
#include<stdio.h>
#include <string>
#include <time.h>
#include<ctime>
#include<sys/time.h>
#include<queue>
#include<map>
#include<thread>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include "opencv2\opencv.hpp"
using namespace cv;
using namespace std;



class Database_Interface:Item_Interface
{
public:
	map <int,Item_Interface> mymap;
	map <int, Item_Interface> :: iterator it;
	virtual void add(Item_Interface stuff);
	virtual void find(int rfid);
	virtual void update(int rfid, float weight);
};





