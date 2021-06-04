#include "Noise.h"

int main() {
    std::cout << std::setprecision(R);
    srand(time(NULL));

    double arr[N];
    double mas_dft[N];
    gen_noise(arr);
    DFT(arr, mas_dft);
    output(arr);

    sf::RenderWindow window1(sf::VideoMode(1200, 700), "White Noise");
    sf::RenderWindow window2(sf::VideoMode(1200, 700), "White Noise (DFT)");

    sf::RectangleShape line_x(sf::Vector2f(N + 50, 2.f));
    line_x.move(x_z, y_z);

    sf::RectangleShape line_y(sf::Vector2f(M, 2.f));
    line_y.move(x_z, y_z + M / 2);
    line_y.rotate(270.f);
    
    sf::VertexArray lines1(sf::Lines, N * 2);
    sf::VertexArray lines2(sf::Lines, N * 2);

    int x = x_z + 2;
    int y;
    int x_last = x_z;
    int y_last = y_z;
    float sum = 0;

    for (int i = 0, cnt = 0; i < N && x < N + 100; i++, cnt+=2) {
        y = y_z - arr[i] * pix;

        lines1[cnt].position = sf::Vector2f(x_last, y_last);
        lines1[cnt + 1].position = sf::Vector2f(x, y);

        lines1[cnt].color = sf::Color::Blue;
        lines1[cnt + 1].color = sf::Color::Blue;

        x_last = x;
        y_last = y;
        /*
        
        
        */
        y = y_z - mas_dft[i] * pix * 30;

        lines2[cnt].position = sf::Vector2f(x, y_z);
        lines2[cnt + 1].position = sf::Vector2f(x, y);

        //cout << x << ", " << y_z << " - " << x << ", " << y << endl;

        lines2[cnt].color = sf::Color::Blue;
        lines2[cnt + 1].color = sf::Color::Blue;

        x += 2;
    }

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
        window2.draw(lines2);
        window2.display();
    }

    return 0;
}