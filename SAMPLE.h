#ifndef SAMPLE_H
#define SAMPLE_H
#include <map>
#include <vector>
using namespace std;

class SAMPLE{
	
private:
    struct P{
        double x;/**<Point x */
        double y;/**<Point y */
        int category;/**<Point category */
        double distance;/**<Point distance ,default 0*/
    };struct P /**<struct P,it is holding x,y,category and distance*/;
    map<int,P> Point;/**< <index, Point(x,y),category and distance> , (P struct)*/
    
    int number;/**<SAMPLE class point number*/
    int k;/**<k = neighborly relations for points*/
    
    vector<int> indexCategory;/**<Category is the vector that holding the values 0,1 and 2*/
    vector<pair<int, P> > vec;/**<Point vector is the vector that will keep the sorting process according to the distance results according to the training value given.*/
    vector<pair<double,double> > vecSort;/**<Point vector is the vector that keeps how many points will be taken according to the k value after the distance sorting.*/

/** This function sets the X and Y values of Training Samples.
*/  	
    void setTrainingXY();
	    
/** This function sets the category of the Training Samples.
*   category 0, category 1, category 2
*/    
    void setTrainingCategory();

public:
	
/** SAMPLE class constructor.
* k-neighborly relations for data point
* number-How many points 
*/
    SAMPLE(int &,int &);
    
    
/** This function returns the desired x value of the generated Point data.
*int index for example; 1,2,3,4...
*double 
*/
    double getPointX(int) ;
    
/** This function returns the desired y value of the generated Point data.
*int index for example; 1,2,3,4...
*double 
*/
    double getPointY(int) ;
    
/** This function returns the desired category value of the generated Point data.
*int index for example; 1,2,3,4...
*int 
*/
    int getCategory(int) ;
    
/** This function performs a random Training Samples for the user to run on data consisting of random values. 
 * This function executes setTrainingCategory() and setTrainingXY() functions.
*/
    void randomTrainingSamples();
    
/** This function is the function that updates the Point distance value after the distance calculation is made. 
 * The distance calculation between 2 points was made in the SAMPLE class.
 * int index for example; Point[1],2,3,4
 *double distance = sqrt((x2-x1)^2 +(y2-y1)^2)
*/
    void setDistance(int,double);
    
/** This function is a function that will compare the algorithm "sort" function. Returns true and false.
 * pair const pair<int, P>
 * pair const pair<int, P>
 * bool 1 or 0
*/
    static bool Compare(const pair<int, P> &a,const pair<int, P> &b);
    
/** This function is the function that returns the category part of the algorithm generate function.
 * void
*/
    static int gTCategory(void);

/** This function is written for algorithm accuracy by performing the count function.
 * int cout<<vec[i].second.category<<endl;
 * 0
*/
    int getPoint(int) ;
    
/** This function is the part where the sort short function operations are made.
*/
    void sortDistance();
    
/** This function counts the lowest k values according to the given neighborhood level.
 *  This function results in a value of up to 0.1 or 2.
*  int
*/
    int selectCategory();
    
/** This function prints all the values of the map<int,P> Point.
*/
    void printPoint();
    
/** This function displays the vector retained after the sort operation of the map<int,P> Point.
 *  This function prints amounts of k in the  sort Point.
*/    
    void printSortVec();

/** This function returns the first value of the sort vector.
 * int index for example 1,2,3,4...
 * double 
*/
    double vecSecondX(int);

/** This function returns the second (x,y,distance etc...) value of the sort vector.
 * int index for example 1,2,3,4...
 * double 
*/
    double vecSecondY(int);
   
/** This function clears the dating vector. Since values will be calculated for each different sample, 
 * 30 sample values of the vector need to be deleted.
*/   
    void vecSortClear();

/** SAMPLE class destructor.
*/ 
    ~SAMPLE();
    
/** This function returns K value
 * int
*/ 
    int getK()const;

};
#endif
