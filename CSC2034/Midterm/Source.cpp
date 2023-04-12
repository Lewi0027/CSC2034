//*******************************************************
//This program computes the average of a group of scores.
//The scores are read from a file named scores.txt, formatted and written to an output file
//along with the average
//File Name:  exam_one_program.cpp
//Description: Program used as reference for questions on Exam One
//Last Changed: June 2014
//*****************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

int calculateStudentAverage(ifstream& inp, double& courseAvg);
//calculate the average of a group of scores and number of entries

void formatData(istream& inp, ostream& oup, int precision, double avg);
// Read numeric values from the original stream and write those numbers to the
// updated stream with the precision defined by precision.  Return the count of
// numbers read and the average value of the numbers

void setOutputFormat(ostream& out, int decimal_places);
// Set the number of decimal places in an output stream

void waitForUser();
// Hold the program on the screen until the user hits any character

int main()
{
    ifstream inF;
    ofstream outF;
    double avgValue;
    int valueCount = 0, blankCount = 0;

    cout << "CSC2034 Exam One Support Program" << endl;
    setOutputFormat(cout, 3);

    inF.open("scores.txt");
    if (!inF.fail())
    {
        outF.open("scores.out");
        if (!outF.fail())
        {
            valueCount = calculateStudentAverage(inF, avgValue);
            formatData(inF, outF, 3, avgValue);

            cout << "\n\nFormatting Completed: "
                << "\nInput File had "
                << valueCount
                << " values, with an average value of "
                << avgValue;
        }
        else
            cout << endl << endl << "Unable to open output file";
    }
    else
        cout << endl << endl << "Unable to open input file";

    inF.close();
    outF.close();
    waitForUser();
    return 0;
}

void setOutputFormat(ostream& out, int decimal_places)
{
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(decimal_places);
}


void formatData(istream& in, ostream& out, int decimalPlaces, double avg)
{
    double value = 0;

    setOutputFormat(out, decimalPlaces);

    in >> value;
    while (!in.eof())
    {
        out << value << endl;
        in >> value;
    }
    out << "Average is: " << avg << endl;

    return;
}


int calculateStudentAverage(ifstream& inp, double& courseAvg)
{
    double totalScore = 0.0;
    int numberOfStudents = 0;
    double score;

    inp >> score;
    numberOfStudents++;
    do
    {
        totalScore = totalScore + score;
        numberOfStudents++;
        inp >> score;
    } while (!inp.eof());

    totalScore += score;
    std::cout << "total score: " << totalScore << std::endl;

    if (totalScore > 0.0 && !(numberOfStudents == 0))
        courseAvg = totalScore / numberOfStudents;
    else
        courseAvg = 0;

    return numberOfStudents;
}//end calculate Average

void waitForUser()
{
    cout << endl << endl;
    system("PAUSE");
}
