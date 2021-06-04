#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iomanip>

//using namespace std;

const int N = 1800;
const int M = 900;
const double Pi = 3.14159265;
const int Pix = 300;
const int pix = 40;

const int f1 = 100, f2 = 70, f3 = 15, f4 = 10;

const double x_z = 50;
const double y_z = 450;
const int Fd = 36000;
const int R = 16;

void gen_sin(double* arr, int f);
sf::VertexArray gen_graphic(int f, double* arr);
void DFT(int f, double* arr, double* mas_dft);
sf::VertexArray gen_dft(int f, double* arr);

void output(double* arr, std::string name);
