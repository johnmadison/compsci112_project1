//  main.cpp
//  Program #1
//  Created by John Madison on 1/21/15.
//  For Dr. Payne's Compsci 112
//  Colorado Mesa University

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
const int maxp = 50;

//Initialize your structs.

struct teachtype
{
    string first, last, department;
    int salary;
};

//He's fluent in over 6 million forms of communiction, but if you see his name the output, you probably messed up.

const teachtype initrec = {"Cee","Three-Pee-Oh","UnderwaterBasketWeaving",0};

void initem (teachtype P[], int maxp)

{
    for (int i = 0; i < maxp; i++) P[i] = initrec;
}

//Read the contents of your data file into the array.

void readem (teachtype P[], int &nump, int &totalsalary)
{
    ifstream inf("input.txt");
    for (int i=0; !inf.eof(); i++)
    {
        inf >> P[i].first >> P[i].last >> P[i].department >> P[i].salary;
        
//Accumulate totalsalary and nump here. We'll need both later to get the average Salary.
        
        totalsalary += P[i].salary;
        nump ++;
    }
}

//Draw some pretty graphics to wow and amaze your professor.

void prettyline (char ch, int n, ofstream &outf)
{
    for (int i=0; i < n; i++) outf << ch; outf << endl;
}

void prettytitle (ofstream &outf)
{
    prettyline('*', 43, outf);
    outf <<"*                                         *"<< endl;
    outf <<"*    M   M   A   RR   V   V EEEEE L       *"<< endl;
    outf <<"*    MM MM  A A  R  R V   V E     L       *"<< endl;
    outf <<"*    M M M A   A R  R V   V E     L       *"<< endl;
    outf <<"*    M   M AAAAA RRR  V   V EEEEE L       *"<< endl;
    outf <<"*    M   M A   A R R   V V  E     L       *"<< endl;
    outf <<"*    M   M A   A R  R   V   EEEEE LLLLL   *"<< endl;
    outf <<"*                                         *"<< endl;
    prettyline('*', 43, outf);
    outf <<"*       MARVEL COLLEGE STAFF PAYROLL      *" << endl;
    prettyline('*', 43, outf);
}

//Print that data

void printem (teachtype P[], int nump, ofstream &outf)
{
    outf << setw(20) << left <<"NAME (LAST, FIRST)"<< setw(12)
    <<"DEPARTMENT"<< right << setw(11) <<"SALARY(USD)"<< endl;
    prettyline('*', 43, outf);
    for (int i = 0 ; i < nump; i++)
    {
        outf << setw(20) << left << P[i].last + ", " + P[i].first << setw(12)
             << P[i].department << right << setw(11) << P[i].salary << endl;
    }
    prettyline('*', 43, outf);
}

//Get some averages.

void salaryaverage (teachtype P[], int nump, int totalsalary, ofstream &outf)
{
    double averagesalary = totalsalary / nump;
    outf <<left << setw(35) <<  "Average Salary = " <<right<< averagesalary;
    outf << endl;
}

//Swap the structs around by department.

void swapem (teachtype &a, teachtype &b)
{
    teachtype temp;
    temp = a;
    a = b;
    b = temp;
}

void sortem (teachtype P[], int nump, ofstream &outf)
{
    int j, i;
    for (j = 0; j <nump ; j++)
        for (i = 0; i <nump; i++)
            if (P[i].department > P[i+1].department) swapem(P[i], P[i+1]);
    outf << endl;
    outf << setw(31) << "SORTED BY DEPARTMENT" << endl;
    outf << endl;
}

//Now finally, write a nice clean main.

int main()
{
    teachtype P[maxp];
    int nump = 0;
    int totalsalary = 0;
    initem(P, maxp);
    readem(P, nump, totalsalary);
    ofstream outf("output.txt");
    outf.setf(ios::fixed);
    outf.precision(2);
    prettytitle(outf);
    printem(P, nump, outf);
    salaryaverage(P, nump, totalsalary, outf);
    sortem(P, nump, outf);
    printem(P, nump, outf);
    return 0;
}



