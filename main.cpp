/**
 * ... Kemal Saydul Lab Final Code ... 		
 */
#include <iostream>
#include <ctime>
#include "SAMPLE.h"
#include "TEST.h"
#include <cstdlib>
#include <stdexcept>

using namespace std;

int main()
{
    int KNN=-1; /**<KNN Value*/
    int Number = 30;/**<Training samples are 30 amounts.*/
    
    while(KNN <= 0){
    	cout<<"Enter the KNN number --> k: ";
    	cin>>KNN;
    	if(KNN <= 0)
    		throw invalid_argument("The KNN value is must be greater than 0\n");
	}
    	
    cout<<endl;
    TEST test(KNN,Number,KNN); /**<Calling the TEST class*/
    for(int i = 0;i<1;i++)
    {
        test.TestSample();/**<Running the TestSample() function in the TEST class*/
    }
   
    return 0;
}
