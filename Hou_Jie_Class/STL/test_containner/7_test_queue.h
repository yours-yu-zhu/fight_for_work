#include <queue>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 

void test_queue(long& value)
{
	cout << "\ntest_queue().......... \n";
     
queue<string> c;  	
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
	cout << "queue.size()= " << c.size() << endl;
	cout << "queue.front()= " << c.front() << endl;	
	cout << "queue.back()= " << c.back() << endl;		
	c.pop();
	cout << "queue.size()= " << c.size() << endl;
	cout << "queue.front()= " << c.front() << endl;	
	cout << "queue.back()= " << c.back() << endl;	
}