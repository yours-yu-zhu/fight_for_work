#include <set>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
#include <map>


void test_set(long& value)
{
	cout << "\ntest_set().......... \n";
     
set<string> c;  	
char buf[10];

clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
            int rand_num = static_cast<int>((static_cast<double>(rand()) / RAND_MAX) * 32767);
    		snprintf(buf, 10, "%d", rand_num); 
			c.insert(string(buf));   					
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;		
	cout << "set.size()= " << c.size() << endl;
	cout << "set.max_size()= " << c.max_size() << endl;	   //214748364
		
string target = get_a_target_string();	
	{
    timeStart = clock();
auto pItem = find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多	
	cout << "std::find(), milli-seconds : " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;		
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}
 	
 	{
    timeStart = clock();		
auto pItem = c.find(target);		//比 std::find(...) 快很多							
	cout << "c.find(), milli-seconds : " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;		 
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}							
}		

void test_map(long& value)
{
	cout << "\ntest_map().......... \n";
     
map<long, string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
            int rand_num = static_cast<int>((static_cast<double>(rand()) / RAND_MAX) * 32767);
    		snprintf(buf, 10, "%d", rand_num); 
			c[i] = string(buf);  					
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;	
	cout << "map.size()= " << c.size() << endl;	
	cout << "map.max_size()= " << c.max_size() << endl;		//178956970
	
long target = get_a_target_long();		
    timeStart = clock();		
auto pItem = c.find(target);								
	cout << "c.find(), milli-seconds : " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;		 
	if (pItem != c.end())
    	cout << "found, value=" << (*pItem).second << endl;
  	else
    	cout << "not found! " << endl;			
    	
    c.clear();					
}					