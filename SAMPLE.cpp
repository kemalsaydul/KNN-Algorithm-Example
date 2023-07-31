#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "SAMPLE.h"
using namespace std;

static int i = 0;
static int y= 30;

SAMPLE::SAMPLE(int &K, int &numbers):k(K),number(numbers)
{
    randomTrainingSamples();      
}
void SAMPLE::randomTrainingSamples()
{
    setTrainingCategory();
    setTrainingXY();
}

void SAMPLE::setTrainingXY()
{
    srand(time(NULL));
    P temp[30];
    for(int i = 0; i<30; ++i){
        temp[i].x = (double)rand()/(RAND_MAX) +(rand()%10)-5;
        temp[i].y = (double)rand()/(RAND_MAX) +(rand()%10)-5;
        temp[i].distance=0;
        temp[i].category = getCategory(i);
        Point.insert(make_pair(i,temp[i]));
    }
}
void SAMPLE::setTrainingCategory()
{
    vector<int>temp(30,0);
    generate(temp.begin(),temp.end(),gTCategory);
    indexCategory = temp;
}
int SAMPLE::getCategory(int i) 
{
    return indexCategory[i];
}
//generate category
int SAMPLE::gTCategory(void)
{
    static int i = 0;
	int hold;
	if (i<10)
		hold=0;
	else if (i<20)
		hold=1;
	else 
		hold=2;
  	i++; 
	return hold; 
}
SAMPLE::~SAMPLE()
{
    //empty body destructor
}
void SAMPLE::setDistance(int i,double d)
{
    Point[i].distance = d;
}
double SAMPLE::getPointX(int i) 
{
    return Point[i].x;
}
double SAMPLE::getPointY(int i)
{
    return Point[i].y;
}
void SAMPLE::sortDistance()
{
    map<int, P> :: iterator it2;
    for (it2=Point.begin(); it2!=Point.end(); it2++)
        vec.push_back(make_pair(it2->first, it2->second));
    sort(vec.begin(),vec.end(),Compare);
	cout<<"The nearest points to Test point: "<<y<<endl;  
    printSortVec();
    y++; 
    vec.clear();
}
bool SAMPLE::Compare(const pair<int, P> &a, const pair<int, P> &b)
{
    return (a.second.distance < b.second.distance);
}
int SAMPLE::getPoint(int i)
{
    cout<<vec[i].second.category<<endl;
    return 0;
}
void SAMPLE::printPoint()
{
	cout<<"///////////// 30 Training Samples ////////////////////////////\n";
    for(int i = 0; i<30;i++)
    	cout<<"Index: "<<i<<" x: "<<Point[i].x<<"   y: "<<Point[i].y<<"    Category: "<<Point[i].category<<" Distance: "<<Point[i].distance<<endl;  
    cout<<endl;            
}

void SAMPLE::printSortVec()
{
    for(int i = 0; i<k;i++)
        cout<<"Index: "<<vec[i].first<<" x: "<<vec[i].second.x<<"   y: "<<vec[i].second.y<<"    Category: "<<vec[i].second.category<<" Distance: "<<vec[i].second.distance<<endl;
}
int SAMPLE::selectCategory()
{
    int freq1 = 0;     // Frequency of group 0
    int freq2 = 0;     // Frequency of group 1
    int freq3 = 0;     // Frequency of group 2
    if(vecSort.size()>0)
        vecSort.clear();
    for(int i=0;i<k;i++)vecSort.push_back(make_pair(vec[i].second.x,vec[i].second.y));

    for (int i = 0; i < getK(); i++)
    {
        if (vec[i].second.category == 0)
            freq1++;
        else if (vec[i].second.category  == 1)
            freq2++;
        else if (vec[i].second.category  == 2)
            freq3++;
    }  
    int enbuyuk = freq1;
    int c;
    if(enbuyuk<=freq2 && freq2>=freq3)
        c = 1;
    else if(enbuyuk<=freq3 && freq3>=freq2)
        c = 2;
    else 
        c = 0;
    cout<<"\nCategory 0: "<<freq1<<"\nCategory 1: "<<freq2<<"\nCategory 2:"<<freq3<<endl;
    cout<<"Test Sample "<<y-1<<"'s New Category is  ------>"<<c<<"\n\n";
	    
    return c;
}
double SAMPLE::vecSecondX(int i)
{
    return vecSort[i].first; 
}
double SAMPLE::vecSecondY(int i)
{
    return vecSort[i].second; 
}
void SAMPLE::vecSortClear()
{
    vecSort.clear();
}
int SAMPLE::getK()const
{
    return k;
}

