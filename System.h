#pragma once

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <cmath>
#include <cstring>

const int x_z = 50;         //Центр координат по x
const int y_z = 350;        //Центр координат по y
const int N = 1000;			//Длина по оси x / Кол-во отсчетов
const int M = 600;			//Длина по оси y
const double pix = 50;         //Кол-во пикселей на единицу измерения
const double pix_spm = 1.5;         //Кол-во пикселей на единицу измерения
const double Pi = 3.1415926;
static int Raz = 0;

void reading(double* noise, double* sin1, double* sin2, double* sin3);
void sys(double* arr1, double* arr2);
sf::VertexArray gen_graphic(int f, double* arr, double a);
int input(int a, int b);
void SPM(double* arr1, double* arr2);
void SNR(std::string name);
void output(double* arr, std::string name);