#include <map>
#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>
#include "SAMPLE.h"
#include "TEST.h"
#include <fstream>
#include <cstdlib>
using namespace std;

TEST::TEST(int &K_temp,int &number,int &K_):SAMPLE(K_temp,number)
{
    K = K_;
    printPoint();
    setTestSamplesXY();
    cout<<"////////////////// 10 Test Samples ///////////////////////\n";
    printPointTest();
}
void TEST::setcontrolPoint(double a,double b)
{
    checkTest.x = a;
    checkTest.y = b;
    checkTest.k = K;
    v_Point.push_back(checkTest);
    euclidean_distance(v_Point);
    v_Point.clear();

}
void TEST::setTestSamplesXY(){
	
    Test temp2[10];
    for(int i = 0; i<10; ++i){
        temp2[i].x = (double)rand()/(RAND_MAX) +(rand()%10)-5;
        temp2[i].y = (double)rand()/(RAND_MAX) +(rand()%10)-5;
        temp2[i].category = 99;
        PTest.insert(make_pair(i,temp2[i]));
    }
}

void TEST::printPointTest()
{
    for(int i = 30; i<40;i++)
        cout<<"Index: "<<i<<" x: "<<PTest[i-30].x<<"   y: "<<PTest[i-30].y<<"    Category: "<<PTest[i-30].category<<endl;  
    cout<<endl;    
}
void TEST::euclidean_distance(vector<control> p)
{

    for (int i = 0; i < 30; i++){
        double temp_distance = sqrt((getPointX(i) - p[0].x) * (getPointX(i) -  p[0].x) +(getPointY(i) -  p[0].y) * (getPointY(i) -  p[0].y));
        setDistance(i,temp_distance);
    } 
}
double TEST::getCheckTestX()const
{
    return checkTest.x;
}

double TEST::getCheckTestY()const
{
    return checkTest.y;
}

int TEST::getCheckTestK()const
{
    return checkTest.k;
}
void TEST::TestSample()
{
    srand(time(NULL) );
    
	for(int i=0;i<10;i++){
		setcontrolPoint(PTest[i].x,PTest[i].y);
		sortDistance();
		int category = selectCategory();
    	PTest[i].category=category;
	}  
    cout<<endl<<endl;
    cout<<"///////////After KNN , Test Samples With New Categories  /////////////////\n";
    printPointTest();
    
}
int TEST::getK()
{
    return K;
}

TEST::~TEST()
{
    //empty body destructor
}

