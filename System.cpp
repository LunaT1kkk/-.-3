#include "System.h"

void reading(double* noise, double* sin1, double* sin2, double* sin3) {
	std::ifstream Noise("Noise.txt"), Sin1("sin1.txt"), Sin2("sin2.txt"), Sin3("sin3.txt");

	//std::cout << "x(i):" << std::endl;
	for (int i = 0; i < N; i++) {
		if (Raz != 0) {
			Noise >> std::setprecision(Raz);
			Sin1 >> std::setprecision(Raz);
			Sin2 >> std::setprecision(Raz);
			Sin3 >> std::setprecision(Raz);
		}
		Noise >> noise[i];
		Sin1 >> sin1[i];
		Sin2 >> sin2[i];
		Sin3 >> sin3[i];
		//std::cout << noise[i] << std::endl;
	}

	Noise.close();
	Sin1.close();
	Sin2.close();
	Sin3.close();
}

void sys(double* arr1, double* arr2) {
	double x = 0;

	/*
	std::cout << "Input n(i):" << std::endl;
	for (int i = 0; i < N; i++) 
		std::cout << i + 1 << ". " << arr1[i] << std::endl;
	*/
	
	std::cout << "\nOutput y(i):" << std::endl;
	for (int i = 0; i < N; i++) {
		if (i > 0)
			arr2[i] = 0.995 * (arr1[i] - arr1[i - 1] + 0.99 * arr2[i - 1]);
		else
			arr2[i] = 0.995 * arr1[i];

			//std::cout << i + 1 << ". " << arr2[i] << std::endl;
	}
	//std::cout << "------\n";
}

sf::VertexArray gen_graphic(int f, double* arr, double a) {
    sf::VertexArray lines(sf::Lines, N * 2);
    double last_x = x_z, last_y = y_z;
    double x = x_z, y = y_z;

	for (int i = 1, cnt = 0; x < N + 50 && i < N; i++, cnt += 2, x += 1) {
		y = y_z - arr[i] * a;

		if (f == 0) {
			lines[cnt].position = sf::Vector2f(last_x, last_y);
			lines[cnt + 1].position = sf::Vector2f(x, y);

			lines[cnt].color = sf::Color::Red;
			lines[cnt + 1].color = sf::Color::Yellow;
		}

		else {
			lines[cnt].position = sf::Vector2f(last_x, last_y);
			lines[cnt + 1].position = sf::Vector2f(x, y);

			lines[cnt].color = sf::Color::Green;
			lines[cnt + 1].color = sf::Color::Cyan;
		}

		last_x = x;
		last_y = y;
	}

    return lines;
}

int input(int a, int b) {
	int action;
	while (true) {
		std::cin >> action;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Error! Input again:\n";
		}
		else {
			if (action >= a && action <= b)
				break;
			else
				std::cout << "Error! Input again:\n";
		}
	}
	return action;
}

void SPM(double* arr1, double* arr2) {
	double Re = 0, Im = 0, Arg = 0;
	for (int i = 0; i < N; i++) {
		Re = 0;
		Im = 0;
		for (int j = 0; j < N; j++) {
			Arg = 2 * Pi * i * j / N;
			Re += cos(Arg) * arr1[j];
			Im -= sin(Arg) * arr1[j];
		}
		arr2[i] = 10 * log((pow(Re, 2) + pow(Im, 2)) / N);
		//std::cout << arr2[i] << std::endl;
	}
}

void SNR(std::string name) {
	double arr1[N], arr2[N], arr3[N];
	double sum1 = 0, sum2 = 0, sum3 = 0, res1, res2;
	std::string name1 = name + "1.txt", name2 = name + "2.txt", name3 = name + "3.txt";

	std::ifstream file1(name1);
	std::ifstream file2(name2);
	std::ifstream file3(name3);
	
	for (int i = 0; i < N; i++) {
		if (Raz == 0) {
			file2 >> std::setprecision(16);
			file3 >> std::setprecision(8);

			std::cout << std::setprecision(16);
		}

		file1 >> arr1[i];
		file2 >> arr2[i];
		file3 >> arr3[i];

		/*
		std::cout << "arr1 = " << arr1[i] << std::endl;
		std::cout << "arr2 = " << arr2[i] << std::endl;
		std::cout << "arr3 = " << arr3[i] << std::endl;
		*/
		
		sum1 += pow(arr1[i], 2);
		sum2 += pow(arr1[i] - arr2[i], 2);
		sum3 += pow(arr1[i] - arr3[i], 2);
	}

	res1 = 10 * log((sum1 / N)/(sum2 / N));
	res2 = 10 * log((sum1 / N) / (sum3 / N));

	std::cout << "SNR for 16: " << res1 / 3.08 << " dB\nSNR for 8: " << res2 / 7.85 << " dB" << std::endl;

	file1.close();
	file2.close();
	file3.close();
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