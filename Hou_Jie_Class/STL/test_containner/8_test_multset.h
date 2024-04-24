#include <set>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
using namespace std;
void test_multiset(long& value)
{
	cout << "\ntest_multiset().......... \n";
	
multiset<string> c;  	
char buf[10];		
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
            int rand_num = static_cast<int>((static_cast<double>(rand()) / RAND_MAX) * 900000);
    		snprintf(buf, 10, "%d", rand_num);
        	c.insert(string(buf));     				
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;	
	cout << "multiset.size()= " << c.size() << endl;	
	cout << "multiset.max_size()= " << c.max_size() << endl;	//214748364
	
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

