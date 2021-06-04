#include "Sin.h"

void gen_sin(double* arr, int f) {
    std::ofstream fout;
    if(f == f1)
        fout.open("sin1.txt");
    else if(f == f2)
        fout.open("sin2.txt");
    else
        fout.open("sin3.txt");

    for (int i = 0; i < N; i++) {
        arr[i] = sin(2 * Pi * f * i / Fd);
        fout << std::setprecision(R);
        fout << arr[i] << std::endl;
    }

    fout.close();
}

void DFT(int f, double* arr, double* mas_dft) {
    double Re = 0, Im = 0, Arg = 0, Sum_Re = 0, Sum_Im = 0;
    for (int i = 0; i < N; i++) {
        Re = 0;
        Im = 0;
        for (int j = 0; j < N; j++) {
            Arg = 2 * Pi * i * j / N;
            Re += cos(Arg) * arr[j];
            Im -= sin(Arg) * arr[j];
        }
        Sum_Re += Re;
        Sum_Im += Im;
        mas_dft[i] = (sqrt(pow(Re, 2) + pow(Im, 2))) * 2 / N;

        //std::cout << mas_dft[i] << std::endl;
    }
    std::cout << "Freq = " << f << " Hz:\n" << "Re = " << Sum_Re << ", Re / N = " << Sum_Re / N << std::endl;
    std::cout << "Im = " << Sum_Im << ", Im / N = " << Sum_Im / N << "\n\n";
}

sf::VertexArray gen_graphic(int f, double* arr) {
    sf::VertexArray lines(sf::Lines, N * 2);
    double last_x = x_z, last_y = y_z;
    double x = x_z, y = y_z;

    std::cout << "f = " << f << std::endl;

    for (int i = 1, cnt = 0; x < N + 50 && i < N; i++, cnt += 2) {
        x++;
        y = 450 - arr[i] * Pix;

        //cout << x << " " << y << endl;

        if (f == f1) {
            lines[cnt].position = sf::Vector2f(last_x, last_y);
            lines[cnt + 1].position = sf::Vector2f(x, y);

            lines[cnt].color = sf::Color::Blue;
            lines[cnt + 1].color = sf::Color::Blue;
        }

        if (f == f2) {
            lines[cnt].position = sf::Vector2f(last_x, last_y);
            lines[cnt + 1].position = sf::Vector2f(x, y);

            lines[cnt].color = sf::Color::Red;
            lines[cnt + 1].color = sf::Color::Yellow;
        }

        if (f == f3) {
            lines[cnt].position = sf::Vector2f(last_x, last_y);
            lines[cnt + 1].position = sf::Vector2f(x, y);

            lines[cnt].color = sf::Color::Cyan;
            lines[cnt + 1].color = sf::Color::Green;
        }

        last_x = x;
        last_y = y;
    }

    return lines;
}

sf::VertexArray gen_dft(int f, double* arr) {
    sf::VertexArray lines(sf::Lines, N * 2);
    double last_x = x_z, last_y = y_z;
    double x = x_z, y = y_z;

    for (int i = 1, cnt = 0; x < N + 50 && i < N; i++, cnt += 2) {
        x += 2;
        y = 450 - arr[i] * Pix;

        if (f == f1) {
            lines[cnt].position = sf::Vector2f(x, y_z);
            lines[cnt + 1].position = sf::Vector2f(x, y);

            lines[cnt].color = sf::Color::Blue;
            lines[cnt + 1].color = sf::Color::Blue;
        }

        if (f == f2) {
            lines[cnt].position = sf::Vector2f(x, y_z);
            lines[cnt + 1].position = sf::Vector2f(x, y);

            lines[cnt].color = sf::Color::Red;
            lines[cnt + 1].color = sf::Color::Yellow;
        }

        if (f == f3) {
            lines[cnt].position = sf::Vector2f(x, y_z);
            lines[cnt + 1].position = sf::Vector2f(x, y);

            lines[cnt].color = sf::Color::Cyan;
            lines[cnt + 1].color = sf::Color::Green;
        }
    }

    return lines;
}

void output(double* arr, std::string name) {
    std::ofstream file1(name + "1.txt");
    std::ofstream file2(name + "2.txt");
    std::ofstream file3(name + "3.txt");
    for (int i = 0; i < N; i++) {
        file1 << arr[i] << std::endl;

        file2 << std::setprecision(16);
        file2 << arr[i] << std::endl;

        file3 << std::setprecision(8);
        file3 << arr[i] << std::endl;

    }

    file1.close();
    file2.close();
    file3.close();
}