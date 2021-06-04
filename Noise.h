#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iomanip>

using namespace std;

const int x_z = 50;         //Центр координат по x
const int y_z = 350;        //Центр координат по y
const int N = 1000;         //Длина по оси x
const int M = 600;			//Длина по оси y
const int pix = 20;         //Кол-во пикселей на единицу измерения
const double Pi = 3.1415926;
const int R = 16;


void gen_noise(double* arr);
void DFT(double* arr, double* mas_dft);
void output(double* arr);