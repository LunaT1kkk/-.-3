#include "Sin.h"

int main() {
    srand(time(NULL));
    std::cout << std::setprecision(R);
    std::cout << "Fd = " << Fd << " Hz" << std::endl;
    double arr1[N], arr2[N], arr3[N];
    double dft1[N], dft2[N], dft3[N];

    gen_sin(arr1, f1);
    gen_sin(arr2, f2);
    gen_sin(arr3, f3);

    output(arr1, "Sin100_");
    output(arr2, "Sin70_");
    output(arr3, "Sin15_");

    DFT(f1, arr1, dft1);
    DFT(f2, arr2, dft2);
    DFT(f3, arr3, dft3);

    sf::RenderWindow window(sf::VideoMode(N+100, M), "Sin");
    sf::RenderWindow window2(sf::VideoMode(1200, 700), "Sin (DFT)");

    sf::RectangleShape line_x(sf::Vector2f(N, 2.f));
    line_x.move(x_z, y_z);

    sf::RectangleShape line_y(sf::Vector2f(M - 100, 2.f));
    line_y.move(x_z, y_z + 400);
    line_y.rotate(270.f);

    sf::VertexArray lines1(sf::Lines, N * 2);
    sf::VertexArray lines2(sf::Lines, N * 2);
    sf::VertexArray lines3(sf::Lines, N * 2);

    sf::VertexArray DFT1(sf::Lines, N * 2);
    sf::VertexArray DFT2(sf::Lines, N * 2);
    sf::VertexArray DFT3(sf::Lines, N * 2);
    
    lines1 = gen_graphic(f1, arr1);
    lines2 = gen_graphic(f2, arr2);
    lines3 = gen_graphic(f3, arr3);

    DFT1 = gen_dft(f1, dft1);
    DFT2 = gen_dft(f2, dft2);
    DFT3 = gen_dft(f3, dft3);
     
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(line_x);
        window.draw(line_y);
        window.draw(lines1);
        window.draw(lines2);
        window.draw(lines3);
        window.display();
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
        window2.draw(DFT1);
        window2.draw(DFT2);
        window2.draw(DFT3);
        window2.display();
    }
    return 0;
}