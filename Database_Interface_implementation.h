#include<Item_Interface.h>
#include<Item_Interface.h>
#include<Item_Interface_detect_constructors.h>
#include<Item_Interface_detect_interface.h>
#include<Item_Interface_detect_implementation.h>
#include <Objectdetect.h>
#include "rc.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <ctime>
#include <sys/time.h>
#include <queue>
#include <map>
#include <thread>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include "opencv2\opencv.hpp"

using namespace cv;
using namespace std;

void Database_Interface:: add(Item_Interface stuff)
{
	static int i=0;
	char c;
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		{
			if(it->second.rfid==stuff.rfid)
				cout<<"RFID Exists do u want to rem-ove "<<it->second.getname()<<"from the list (Y OR N)";
				cin>>c;
				switch(c)
				{
				case 'Y':
					it->second.Timerupdate();
					mymap.erase(it);
					break;
				case 'N':
					cout<<"try another rfid";
					cin>>stuff.rfid;
					add(stuff);
					break;
				}
		}
	//mymap.insert ( std::pair<int,Item_Interface> (i,stuff) );
		mymap[i]=stuff;
	i++;
}

void Database_Interface :: find(int rfid)
{
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	{
		if(it->second.rfid==rfid)
			it->second.statusupdate();
	}
}


void Database_Interface :: update(int rfid, float weight)
{
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		{
			if(it->second.rfid==rfid)
				it->second.weightupdate(weight);
		}



