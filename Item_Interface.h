#include<Item_detect_constructors.h>
#include<Item_detect_interface.h>
#include<Item_detect_implementation.h>
#include <Objectdetect.h>
#include<string>
#include<iostream>
using namespace std;
#include<thread>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include "opencv2\opencv.hpp"
using namespace cv;
class Item_Interface :Item_detect_implementation
{
public:
    int barcode;
	string name;
	float weight;
	string status;
	time_t Timer;
	int rfid;

	virtual void weightupdate(float);
	virtual void statusupdate();
	virtual void Timerupdate();
	virtual void objectdetect ();
	virtual void getbarcode();
	virtual string getname();
	virtual void getweight();
	virtual void display();
	virtual void getrfid();

};






