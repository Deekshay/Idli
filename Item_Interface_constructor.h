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


Item_Interface :: Item_Interface()
{
	Item_Interface Item_Interface;
	int choice, rfout,temp_weight;
   while(1)
    {

		cout<<"what do you want to do"<<endl;
		cout<<"Put new stuff in fridge 1 "<<endl;
		cout<<"take stuff 2"<<endl;
		cout<<"put back stuff 3"<<endl;
        cout<<"display"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"enter the details of Item_Interface"<<endl;
					Item_Interface.getbarcode();
					Item_Interface.getrfid();
					Item_Interface.getweight();
					Item_Interface.objectdetect();
					add(Item_Interface);
					break;
		case 2:
			cout<<"which Grocery do u want to take out"<<endl;
			cin>>rfout;
			find(rfout);
			break;

		case 3:
			cout<<"which Grocery do u want to put in"<<endl;
			cin>>rfout;
			cout<<"what is the weight now"<<endl;
			cin>>temp_weight;
			update(rfout,temp_weight);
			break;
        case 4:
        for (it=mymap.begin(); it!=mymap.end(); ++it)
        it->second.display();
        break;
		}
    }

}

