#ifndef TEST_H
#define TEST_H
#include <string>
#include <map>
#include <vector>
#include "SAMPLE.h"
using namespace std;

class TEST:public SAMPLE{
private:
	struct Test{
        double x;/**<PTest x */
        double y;/**<PTest y */
        int category;/**<PTest category */
    };struct Test /**<struct Test,it is holding x,y and category*/;
    map<int,Test> PTest;/**< <index, PTest(x,y),category >, (Test struct)*/
    
    struct control
    {
       double x;/**<checkTest x */
       double y;/**<checkTest y */
       int k;/**<checkTest k */
    }; 
	control checkTest;/**<checkTest is holding x,y,k values*/
	vector<control> v_Point;/**<v_Point vector*/
	
    int K;/**<KNN  degree*/
    int randomNumber;
    
public:
/** TEST class constructor. 
*  int-k = neighborly relations for data point
*  int-How many points will be produced and tested for the KNN algorithm
*  int-k = neighborly relations for data point
*/
    TEST(int &, int &, int &);
/** This function writes the generated point x,y and k values into the struct and pushes them to the v_Point vector.
*  double a
*  double b
*/
    void setcontrolPoint(double,double);
    
/** This function calculates the distance between 2 points and processes the set_Distance function.
*  vector
*/
    void euclidean_distance(vector<control> p);
    
/** This function returns the x value of the tested value.
*  double
*/
    double getCheckTestX()const;
    
/** This function returns the y value of the tested value.
*  double
*/
    double getCheckTestY()const;
    
/** This function returns the k value of the tested value.
* @return double
*/
    int getCheckTestK()const;

/** This function calls setAttemptPoint(),sortDistance(),selectCategory() and printPointTest() functions .
*/
    void TestSample();
    
/** This function prints all the values of the map<int,Test> PTest.
*/    
    void printPointTest();
    
/** This function sets the required X and Y values of Test Samples.
*/     
    void setTestSamplesXY();
    
/** This function returns the k value of the TEST class.
*/
    int getK();
    
/** TEST class destructor.
*/
    ~TEST();
};
#endif
