// S112 Kowata Class Statistics.cpp 
// Author: Michael Kowata
// Goal: Read student grades, calculate max, min, count, avg, std
//       Each grade must be between 0...100.
// --------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

int getGrade(int low, int high);
void experiment1();
double calculateAverage(int scores[], int counter);
double calculateStandardDeviation(int scores[], int counter, double avg);

int main()
{
    experiment1();
}

//---------------------------------
//USER-DEFINED OPERATIONS
//---------------------------------
void experiment1() 
{
    int grade;
    int low = 0;
    int high = 100;
    const int N = 40;

    int scores[N]; //at most 40 students
    int i = 0;
    int counter = 0;
    char response;

    do {
    grade = getGrade(low, high);
//  cout << "You entered: " << grade << endl;
    scores[i] = grade;
    counter++;
    i++;
    cout << "More data (y/n)? ";
    cin >> response;
    if (response != 'y' && response != 'Y')
    {
        break;
    }
    } while (response = 'y' && i < N - 1);

    ////DEBUGGING
    //for (int i = 0; i < counter; i++);
    //{
    //    cout << "score[" << i << "] =" << scores[i] << endl;
    //}


    double avg = calculateAverage(scores, counter);
    cout << "The average of the sample is: " << avg << endl;
    double stdev = calculateStandardDeviation(scores, counter, avg);
    cout << "The standard deviation is: " << stdev; 

}
int getGrade(int low, int high)
{
    int result = 0;
    do {
        cout << "Enter a grade [" << low << "," << high << "]: ";
        cin >> result;
        if (result >= low && result <= high)
        {
            return result;
        }
        else
        {
            cout << "Invalid data - out of range - Try again\n";
        }
    } while (true);
}

//----------------------------------------------------------------------
double calculateAverage(int scores[], int counter)
{
    double result = 0;
    for (int i = 0; i < counter; i++)
    {
        result += scores[i];
    }
    return (result / counter);
}

//-----------------------------------------------------------------------
double calculateStandardDeviation(int scores[], int counter, double avg)
{
      double result = 0;
      for (int i = 0; i < counter; i++)
      {
          result = pow(scores[i] - avg, 2);

      }
      return sqrt(result / counter);
}
