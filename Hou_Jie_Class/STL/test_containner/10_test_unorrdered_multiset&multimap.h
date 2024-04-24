#include <unordered_set>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
#include <unordered_map>


using namespace std;

void test_unordered_multiset(long& value)
{
	cout << "\ntest_unordered_multiset().......... \n";
     
unordered_multiset<string> c;  	
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
	cout << "unordered_multiset.size()= " << c.size() << endl;
	cout << "unordered_multiset.max_size()= " << c.max_size() << endl;	//357913941
	cout << "unordered_multiset.bucket_count()= " << c.bucket_count() << endl;	
	cout << "unordered_multiset.load_factor()= " << c.load_factor() << endl;	
	cout << "unordered_multiset.max_load_factor()= " << c.max_load_factor() << endl;	
	cout << "unordered_multiset.max_bucket_count()= " << c.max_bucket_count() << endl;				
  	for (unsigned i=0; i< 20; ++i) {
    	cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
  	}					
				
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

void test_unordered_multimap(long& value)
{
	cout << "\ntest_unordered_multimap().......... \n";
     
unordered_multimap<long, string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
            int rand_num = static_cast<int>((static_cast<double>(rand()) / RAND_MAX) * 900000);
    		snprintf(buf, 10, "%d", rand_num);
			//multimap 不可使用 [] 進行 insertion 
			c.insert(pair<long,string>(i,buf));
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;		
	cout << "unordered_multimap.size()= " << c.size() << endl;	
	cout << "unordered_multimap.max_size()= " << c.max_size() << endl;	//357913941	
	
long target = get_a_target_long();		
    timeStart = clock();		
auto pItem = c.find(target);								
	cout << "c.find(), milli-seconds : " << double(clock() - timeStart) / CLOCKS_PER_SEC * 1000 << endl;		 
	if (pItem != c.end())
    	cout << "found, value=" << (*pItem).second << endl;
  	else
    	cout << "not found! " << endl;		
}		