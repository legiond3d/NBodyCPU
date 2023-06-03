#ifndef __HEADER__
#define __HEADER__

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<memory>
#include<clocale>
#include<cmath>
#include<ctime>
using namespace std;

#define PI 3.1415926535897
#define G 1.0 //6.67259e-11 
#define SIGMA 0.001 //1e-8
#define THETA 0.5
#define HEAD_INDEX 0

typedef double real;

enum Dimension
{
	dimX = 1,
	dimY = 2,
	dimZ = 3
};

#endif
