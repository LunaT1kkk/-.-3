#include "Noise.h"

void gen_noise(double* arr) {
    ofstream file;
    file.open("Noise.txt");
    double temp1 = 0, temp2 = 0;
    int k = 2;

    for (int i = 0; i < N; i++) {
        while (!temp1) 
            temp1 = ((double)rand() / ((double)RAND_MAX));                  //(0:32 767)/32 767 = (0:1) -> Ген от 0 до 1
        

        temp2 = cos((2.0 * (double)Pi) * rand() / ((double)RAND_MAX));      //Приведение к диапазону (-1:1)
        arr[i] = k + sqrt(-2.0 * log(temp1)) * temp2;                       //Обратное Гаусовское преобразование
        
        file << std::setprecision(R);
        file << arr[i] << endl;

        cout << arr[i] << endl;
    }

    file.close();
}

void DFT(double* arr, double* mas_dft) {
    double Re = 0, Im = 0, Arg = 0, Sum_Re = 0, Sum_Im = 0;
    for (int i = 0; i < N; i++) {
        Re = 0;
        Im = 0;
        for (int j = 0; j < N; j++) {
            Arg = 2 * Pi * i * j / N;
            Re += cos(Arg) * arr[j];
            Im -= sin(Arg) * arr[j];
        }
        /*
        if (i != 0)
            mas_dft[i] = (sqrt(pow(Re, 2) + pow(Im, 2))) * 2 / N;
        else
            mas_dft[i] = ((sqrt(pow(Re, 2) + pow(Im, 2))) / N) - 1.5;
        */
        if (i != 0)
            mas_dft[i] = (10 * log(pow(Re, 2) + pow(Im, 2))) / N;
        else
            mas_dft[i] = ((10 * log(pow(Re, 2) + pow(Im, 2))) / N) - 0.10;
        Sum_Re += Re;
        Sum_Im += Im;
        //cout << mas_dft[i] << endl;
    }
    std::cout << "Re = " << Sum_Re << ", Re / N = " << Sum_Re / N << std::endl;
    std::cout << "Im = " << Sum_Im << ", Im / N = " << Sum_Im / N << "\n\n";
}

void output(double* arr) {
    ofstream file1("noise1.txt");
    ofstream file2("noise2.txt");
    ofstream file3("noise3.txt");
    for (int i = 0; i < N; i++) {
        //file << std::setprecision(R);
        file1 << arr[i] << endl;

        file2 << std::setprecision(16);
        file2 << arr[i] << endl;

        file3 << std::setprecision(8);
        file3 << arr[i] << endl;
    }

    file1.close();
    file2.close();
    file3.close();
}
