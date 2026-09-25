#include <iostream>
#include <cstring>
using namespace std;
class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[20];
    static int trainCount;

public:
    Train()
    {
        trainCount++;
    }
    Train(int n, char name[], char s[], char des[], char ti[])
    {
        this->trainNumber = n;
        strcpy(this->trainName, name);
        strcpy(this->source, s);
        strcpy(this->destination, des);
        strcpy(this->trainTime, ti);
        trainCount++;
    }
    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> this->trainNumber;
        cout << "Enter Train Name: ";
        cin >> this->trainName;
        cout << "Enter Train Source: ";
        cin >> this->source;
        cout << "Enter Train Destination: ";
        cin >> this->destination;
        cout << "Train Time: ";
        cin >> this->trainTime;
        cout << endl;
    }
    void displayTrainDetails()
    {
        cout << "Train Number: " << this->trainNumber << endl
             << "Train Name: " << this->trainName << endl
             << "Train Source: " << this->source << endl
             << "Train Destination: " << this->destination << endl
             << "Train Time: " << this->trainTime << endl << endl;
    }
    static int getTrainCount()
    {
        return trainCount;
    }
    int getTrainNumber()
    {
        return this->trainNumber;
    }
    ~Train()
    {
        trainCount--;
    }
};
class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = 0;
    }
    void addTrain()
    {
        int n;
        cout << "Enter Number of Data You Want to Add: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Train Details: " << endl << endl;
            this->trains[totalTrains].inputTrainDetails();
            totalTrains++;
        }
    }
    void displayAllTrains()
    {
        cout << "Train Details: " << endl;
        for (int i = 0; i < totalTrains; i++)
        {
            this->trains[i].displayTrainDetails();
        }
    }
    void searchTrainByNumber(int number)
    {
        for (int i = 0; i < totalTrains; i++)
        {
            if (this->trains[i].getTrainNumber() == number)
            {
                cout << "Searched Train Details: " << endl << endl;
                this->trains[i].displayTrainDetails();  
                return;
            }
        }
        cout << "Train Data Not Found" << endl;
    }
};
int Train::trainCount = 0;
int main()
{
    RailwaySystem r;
    while (1)
    {
        int choice;
        cout << "Press 1: to Add new Train" << endl;
        cout << "Press 2: to Display All Train Records" << endl;
        cout << "Press 3: to Searh Train by Number" << endl;
        cout << "Press 4: Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            r.addTrain();
        }
            break;
        case 2:
        {
            r.displayAllTrains();
            cout << endl
                 << endl;
        }
            break;

        case 3:
        {
            int n;
            cout << "Enter Train Number: ";
            cin >> n;
            cout << endl;
            r.searchTrainByNumber(n);
            break;
        }
        case 4:
            return 0;
            break;
        default:
            return 0;
            break;
        }
    }
}