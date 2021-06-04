#include "System.h"

int main(int argc, char* argv[]) {
    bool flag = true;
    int action = 0;    

    std::cout << "Select an action:\n1. Double\n2. 16\n3. 8\n" << std::endl;
    action = input(1, 3);

    switch (action) {
    case 1:
        break;
    case 2:
        std::cout << std::setprecision(16);
        Raz = 8;
        break;
    case 3:
        std::cout << std::setprecision(8);
        Raz = 16;
        break;
    }

    double noise[N], sin1[N], sin2[N], sin3[N];
    double res_noise[N], res_sin1[N], res_sin2[N], res_sin3[N];
    double SPM1[N], SPM2[N];

    reading(noise, sin1, sin2, sin3);

	sf::RectangleShape line_x(sf::Vector2f(N + 50, 2.f));
	line_x.move(x_z, y_z);

	sf::RectangleShape line_y(sf::Vector2f(M, 2.f));
	line_y.move(x_z, y_z + M / 2);
	line_y.rotate(270.f);

	sf::VertexArray lines1(sf::Lines, N * 2);
	sf::VertexArray lines2(sf::Lines, N * 2);

    sf::VertexArray spm1(sf::Lines, N * 2);
    sf::VertexArray spm2(sf::Lines, N * 2);

    while (flag) {
        std::cout << "Select an action:\n1. Noise\n2. Sin 100 Hz\n3. Sin 70 Hz\n4. Sin 15 Hz\n5. Exit" << std::endl;
        action = input(1, 5);

        switch (action) {
        case 1:
            sys(noise, res_noise);

            if(Raz == 16)
                output(res_noise, "noise_out");

            SPM(noise, SPM1);            
            SPM(res_noise, SPM2);

            std::cout << "\nNoise input:\n";
            SNR("noise");

            std::cout << "\nNoise output:\n";
            SNR("noise_out");


            lines1 = gen_graphic(0, noise, pix);
            lines2 = gen_graphic(1, res_noise, pix);

            spm1 = gen_graphic(0, SPM1, pix_spm);
            spm2 = gen_graphic(1, SPM2, pix_spm);
            break;
        case 2:
            sys(sin1, res_sin1);
            if (Raz == 16)
                output(res_sin1, "Sin100_out");

            SPM(sin1, SPM1);
            SPM(res_sin1, SPM2);

            std::cout << "\nSin 100 Hz input:\n";
            SNR("Sin100_");

            std::cout << "\nSin 100 Hz output:\n";
            SNR("Sin100_out");

            lines1 = gen_graphic(0, sin1, pix);
            lines2 = gen_graphic(1, res_sin1, pix);

            spm1 = gen_graphic(0, SPM1, pix_spm);
            spm2 = gen_graphic(1, SPM2, pix_spm);
            break;
        case 3:
            sys(sin2, res_sin2);
            if (Raz == 16)
                output(res_sin2, "Sin70_out");

            SPM(sin2, SPM1);
            SPM(res_sin2, SPM2);

            std::cout << "\nSin 70 Hz input:\n";
            SNR("Sin70_");

            std::cout << "\nSin 70 Hz output:\n";
            SNR("Sin70_out");

            lines1 = gen_graphic(0, sin2, pix);
            lines2 = gen_graphic(1, res_sin2, pix);

            spm1 = gen_graphic(0, SPM1, pix_spm);
            spm2 = gen_graphic(1, SPM2, pix_spm);
            break;
        case 4:
            sys(sin3, res_sin3);
            if (Raz == 16)
                output(res_sin3, "Sin15_out");

            SPM(sin3, SPM1);
            SPM(res_sin3, SPM2);

            std::cout << "\nSin 15 Hz input:\n";
            SNR("Sin15_");

            std::cout << "\nSin 15 Hz output:\n";
            SNR("Sin15_out");

            lines1 = gen_graphic(0, sin3, pix);
            lines2 = gen_graphic(1, res_sin3, pix);

            spm1 = gen_graphic(0, SPM1, pix_spm);
            spm2 = gen_graphic(1, SPM2, pix_spm);
            break;
        default:
            flag = false;
            break;
        }

        if (flag) {
            sf::RenderWindow window1(sf::VideoMode(1200, 700), "Signal");
            sf::RenderWindow window2(sf::VideoMode(1200, 700), "SPM input");
            sf::RenderWindow window3(sf::VideoMode(1200, 700), "SPM output");

            while (window1.isOpen()) {
                sf::Event event;
                while (window1.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window1.close();
                }

                window1.clear();
                window1.draw(line_x);
                window1.draw(line_y);
                window1.draw(lines1);
                window1.draw(lines2);
                window1.display();
            }


            while (window2.isOpen()) {
                sf::Event event;
                while (window2.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window2.close();
                }

                window2.clear();
                window2.draw(line_x);
                window2.draw(line_y);
                window2.draw(spm1);
                window2.display();
            }

            while (window3.isOpen()) {
                sf::Event event;
                while (window3.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window3.close();
                }

                window3.clear();
                window3.draw(line_x);
                window3.draw(line_y);
                window3.draw(spm2);
                window3.display();
            }

            system("pause");
            system("cls");
        }
    }
	return 0;
}