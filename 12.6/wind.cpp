#include<bits\stdc++.h>
using namespace std;
#include"QUEUE.h"
const int MIN_PER_HR = 60;

//13.5 大概在17-18之间
//13.6 大概在50之间

bool newcustomer(double x);		//is there a new customer?

int main()
{
//setting things up
	srand(time(0));				//random initializing of rand()

	cout << "Case study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue1: ";
	int qs1;
	cin >> qs1;
	Queue line1(qs1);				//line queue holds up to qs people

	cout << "Enter maximum size of queue2: ";
	int qs2;
	cin >> qs2;
	Queue line2(qs2);

	cout << "Enter the number of simulation hours: ";
	int hours;					//hours of simulation
	cin >> hours;

	//simulation will run 1 cycle per minute # of cycle
	long cyclelimit = MIN_PER_HR * hours;

	cout << "Enter the average number of customers per hour: ";
	double perhour;				//average of arrival per hour
	cin >> perhour;
	double min_per_cust;		//average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;					//new customer data
	long turnaways = 0;			//turned away by full queue
	long customers = 0;			//joined the queue
	long served = 0;			//served during the simulation
	long sum_line = 0;			//cumulative line length
	int wait_time1 = 0;			//time until autoteller is free
	int wait_time2 = 0;
	long line_wait1 = 0;		//cumulative time in line
	long line_wait2 = 0;

//running the simulation
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))				// have new customer!
		{
			if (line1.isfull()&&line2.isfull())
				turnaways++;
			else if(line1.queuecount()<line2.queuecount())
			{
				customers++;
				temp.set(cycle);					//cycle = time of arrival
				line1.enqueue(temp);				//add new customer to line
			}
			else
			{
				customers++;
				temp.set(cycle);				
				line2.enqueue(temp);
			}
		}
		if (wait_time1 <= 0 && !line1.isempty())
		{
			line1.dequeue(temp);					//attend next customer
			wait_time1 = temp.ptime();				//for wait_tiime minutes
			line_wait1 += cycle - temp.when();	
			served++;
		}
		if (wait_time2 <= 0 && !line2.isempty())
		{
			line2.dequeue(temp);					
			wait_time2 = temp.ptime();			
			line_wait2 += cycle - temp.when();
			served++;
		}
		if (wait_time1 > 0)
			wait_time1--;
		if (wait_time2 > 0)
			wait_time2--;
		sum_line += line1.queuecount() + line2.queuecount();
	}

	//reporting results
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << "   customer served: " << served << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: " << (double)(line_wait1+line_wait2)/ served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";


	system("pause");
	return 0;
}

//x = average_time,in minutes,between customers
//return value is true if customers shows up this minute
bool newcustomer(double x)
{
	return ((rand() * x / RAND_MAX) < 1);
}