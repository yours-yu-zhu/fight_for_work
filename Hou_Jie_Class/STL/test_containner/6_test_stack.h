#include <stack>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 

using namespace std;

void test_stack(long& value)
{
	cout << "\ntest_stack().......... \n";
     
stack<string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.push(string(buf));    			 		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;
			abort();
		}
	}
	cout << "milli-seconds : " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;	
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;	
	c.pop();
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;	

    	
	{
        cout << "以 list 為底層.......... \n";
        timeStart = clock();
stack<string, list<string>> c;		//以 list 為底層 
    for(long i=0; i< value; ++i) {
    		snprintf(buf, 10, "%d", rand());
        	c.push(string(buf));    			 		
	}
    cout << "milli-seconds : " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;	
	c.pop();
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;	
    }	
	
	{
        cout << "以 vector 為底層.......... \n";
        timeStart = clock();
stack<string, vector<string>> c;	//以 vector 為底層 
    for(long i=0; i< value; ++i) {
    		snprintf(buf, 10, "%d", rand());
        	c.push(string(buf));    			 		
	}
    cout << "milli-seconds : " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;	
	c.pop();
	cout << "stack.size()= " << c.size() << endl;
	cout << "stack.top()= " << c.top() << endl;	
    }

	
}	