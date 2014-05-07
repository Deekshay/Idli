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


void Item_Interface::weightupdate(float wt)
{
	status="back in";
	weight=wt;
	Timer=0;
}
void Item_Interface::statusupdate()
{
	status="gone out";
	time(&Timer);

}
void Item_Interface::Timerupdate()
{
	status="deleted";
}
void Item_Interface:: getrfid()D
{
cout<<"Enter rfid"<<endl;
cin>>rfid;
}
void Item_Interface::objectdetect ()
{
cout<<"Enter object name"<<endl;
//cin>>name;
name=detectAndDisplay();				//////HERE ONLY GIVE INPUT
}
void Item_Interface::getbarcode()
{
	cout<<"Enter barcode"<<endl;
cin>>barcode;
}
string Item_Interface::getname()
{
	return name;
}
void Item_Interface::getweight()
{
cout<<"enter the weight"<<endl;
cin>>weight;
}

void Item_Interface::display()
{
	  double diff;

                cout <<rfid <<endl;
                cout<<barcode<<endl;
                cout<<weight<<endl;
                cout<<name<<endl;

}


