#include <iostream>
#include <string>
#include <limits>

#include "Queue.h"

using namespace std;

void printArrivalMessage(const int &number, const int &arrivalMinute);
void printDepartureMessage(const int &number, const int &departureMinute);
void printStats(const int& longestWait, const int& longestLine);
int generateRandomNumber(const int& x);

int main() {
    const int CLOSING_TIME = 720;

    int clock = 1;
    int maxWait = 0; //longest wait time
    int maxLine = 0; //longest line

    int serviceEnds; //When we finish serving the current customer
    int nextArrival; //When next customer arrives
    Queue line; //Customers must wait in line
    int count = 0; //How many customers are here

    //Prompt input for x
    int arrivalLimit, serviceLimit;
    cout << "Customers arrive at a random integer interval between 1 and x." << endl;
    cout << "Input Value for x: ";
    cin >> arrivalLimit;
    cout << "\nCustomers are serviced at a random integer interval between 1 and x." << endl;
    cout << "Input Value for x: ";
    cin >> serviceLimit;

    //1. rand num 1 to x (first customer arrival time)
    int firstCustArrival = generateRandomNumber(arrivalLimit);

    //2. first customer arrives. print arrival message
    count++; printArrivalMessage(count,firstCustArrival);

    //Customer is served
    serviceEnds = generateRandomNumber(arrivalLimit);

    // arrival time of next customer (current time + rand num)
    nextArrival = clock + generateRandomNumber(arrivalLimit);

    //Serve and acquire new Customers while store is open
    for(clock; clock <= CLOSING_TIME; clock++)
    {

        //customer arrival
        if(clock == nextArrival)
        {
            int& customerID = ++count;
            printArrivalMessage(customerID,clock);
            line.enqueue(nextArrival);
            nextArrival = clock + generateRandomNumber(arrivalLimit);

            //stats
            const int& size = line.getSize();
            if( size > maxLine)
                maxLine = size;
        }
        
        if(serviceEnds == -1){
            if(!line.isEmpty())
            {
                serviceEnds = clock + generateRandomNumber(serviceLimit);
                int waitTime = clock - line.dequeue();

                //stats
                if(maxWait < waitTime)
                    maxWait = waitTime;
            }
        }

        //Finished servicing a customer at cash register
        if(clock == serviceEnds)
        {
            int customerID = count - line.getSize();
            printDepartureMessage(customerID,clock);

            //Next Customer please step up
            if(!line.isEmpty())
            {
                serviceEnds = clock + generateRandomNumber(serviceLimit);
                int waitTime = clock - line.dequeue();

                //stats
                if(maxWait < waitTime)
                    maxWait = waitTime;
            }
            else
            {
                serviceEnds = -1;
            }
        }

    }
    cout << endl;
    cout << "-------------------" <<endl;
    cout << "Store is now closed" << endl << endl;
    printStats(maxWait,maxLine);
    cout << endl << endl;


    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //quick fix for newline getline bug



    //Handle if customers are sill in line when store closes
    if(!line.isEmpty()){
        cout << "There are still " << line.getSize() << " customers in line." << endl;

        bool flag = true;
        while(flag)
        {
            cout << "Do you want to finish serving this line?" << endl;
            string choice;
            cout << "y/n: "; getline(cin,choice);

            switch (choice[0])
            {
                case 'n':
                    flag = false;
                    break;
                case 'y':
                    flag = false;

                    //continue servicing until last customer is servered or line is empty
                    for (clock; serviceEnds != -1 || !(line.isEmpty()); clock++)
                    {
                        if(serviceEnds == -1)
                        {
                            if(!line.isEmpty())
                            {
                                serviceEnds = clock + generateRandomNumber(serviceLimit);
                                int waitTime = clock - line.dequeue();

                                //stats
                                if(maxWait < waitTime)
                                    maxWait = waitTime;
                            }
                        }

                        //Finished servicing a customer at cash register
                        if(clock == serviceEnds)
                        {
                            int customerID = count - line.getSize();
                            printDepartureMessage(customerID,clock);

                            //Next Customer please step up
                            if(!line.isEmpty())
                            {
                                serviceEnds = clock + generateRandomNumber(serviceLimit);
                                int waitTime = clock - line.dequeue();

                                //stats
                                if(maxWait < waitTime)
                                    maxWait = waitTime;
                            }
                            else
                            {
                                serviceEnds = -1;
                            }
                        }

                    }
                    cout << "Stayed " << clock - CLOSING_TIME << " minutes overtime to finish serving line" << endl;
                    cout << "\nHere are the updated stats\n" << endl;
                    printStats(maxWait,maxLine);
                    break;
                default:
                    cout << "Invalid choice: ";
            }
        }
    }

    cout << "GoodBye" << endl;
    return 0;
}

/**
 * Prints a customer arrival message
 *
 * @param number -
 * @param arrivalMinute
 */
void printArrivalMessage(const int &number, const int &arrivalMinute) {
    cout << "Customer " << number << " arrived at " << arrivalMinute << endl;
}

/**
 * Prints a customer departure message
 *
 * @param number -
 * @param arrivalMinute
 */
void printDepartureMessage(const int &number, const int &departureMinute) {
    cout << "Customer " << number << " left at " << departureMinute << endl;
}

/**
 * Help method for printing out stats at the end
 *
 * @param longestWait
 * @param longestLine
 */
void printStats(const int& longestWait, const int& longestLine){
    cout << "Longest line: " << longestLine << " customers" << endl;
    cout << "    Max wait: " << longestWait << " minutes" << endl;
}
/**
 * Generates a random number from 1 to x
 *
 * @param the upper limit
 * @return a random number from 1 to x
 */
int generateRandomNumber(const int& x){
    return rand() % x + 1;
}
