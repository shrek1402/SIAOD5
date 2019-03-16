/******************************************************************************

                              СИАОД C++ C2019.

*******************************************************************************/

#include "pch.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int A[1300], n, Mt;
float Ct;
void FillRand(int n)
{
    int i;
    for (i = 0; i < n; i++) {
        A[i] = rand() % 100;
    }
}
void FillInc(int n)
{
    int i;
    for (i = 0; i < n; i++) {
        A[i] = i;
    }
}
void FillDec(int n)
{
    int i;
    for (i = 0; i < n; i++) {
        A[i] = n - i;
    }
}
void PrintMas(int n)
{
    int i;
    for (i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
void CheckSum(int n)
{
    int sum = 0, i;
    printf("ChecSum: ");
    for (i = 0; i < n; i++) {
        sum += A[i];
    }
    cout << sum << endl;
}
void RunNumber(int n)
{
    int i, s = 0;
    printf("RunNumber: ");
    for (i = 0; i < n; i++) {
        if (A[i] > A[i + 1])
            s++;
    }
    cout << s << endl;
}
int SelectSort(int n)
{
    int min, temp, i, j, C = 0, M = 0;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            C++;
            if (A[j] < A[min]) {

                min = j;
            }
        }
        if (i != min) {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
            M += 3;
        }
    }
    return M + C;
}

void SelectSort_Count(int n)
{
    int M = 0, C = 0;
    Mt = 3 * (n - 1);
    Ct = ((n * n) - n) / 2;
    cout << "M=" << M << " C=" << C << endl;
    cout << "Mt=" << Mt << " Ct=" << Ct << endl;
    if (M > Mt)
        cout << "M>Mt and ";
    else
        cout << "M<Mt and ";
    if (C > Ct)
        cout << "C>Ct";
    else
        cout << "C<Ct";
}
int BubbleSort(int n)
{
    int i, j, C = 0;
    int M = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            C++;
            if (A[j] > A[j + 1]) {
                A[j] ^= A[j + 1] ^= A[j] ^= A[j + 1];
                M += 3;
            }
        }
    }
    return (M + C);
}
void BubbleSort_Count(int n)
{
    int C = 0, M = 0;
    double Ct, Mt;
    Ct = (n * n - n) / 2;
    Mt = (3 * (n * n - n)) / 4;
    cout << "M=" << M << " C=" << C << endl;
    cout << "Mt=" << Mt << " Ct=" << Ct << endl;
    if (M > Mt)
        cout << "M>Mt and ";
    else
        cout << "M<Mt and ";
    if (C > Ct)
        cout << "C>Ct";
    else
        cout << "C<Ct";
}
int ShakerSort(int N, int* a)
{
    int L = 0, R = N - 1, k = N, i = 0, temp = 0, C = 0, T = 0, M = 0, C1 = 0,
        M1 = 0, T1 = 0;
    while (L < R) {
        for (i = R; i > L; i--) {
            C++;
            if (a[i] < a[i - 1]) {
                temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
                M = M + 3;
                k = i;
            }
        }
        L = k;
        for (i = L; i < R; i++) {
            C++;
            if (a[i] > a[i + 1]) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                M = M + 3;
                k = i;
            }
        }
        R = k;
    }

    return M + C;
}
int InsertSort(int N)
{
    int C = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i; j > 0 && A[j - 1] > A[j]; j--) {
            C++;
            int tmp = A[j - 1];
            A[j - 1] = A[j];
            A[j] = tmp;
        }
    }
    return C * 4;
}

int main()
{
    srand(time(NULL));
    int n;
    /*FillRand(n);
	PrintMas(n);
	CheckSum(n);
	RunNumber(n);
	cout « endl;
	BubbleSort(n);
	PrintMas(n);
	CheckSum(n);
	RunNumber(n);
	BubbleSort_Count(n);*/
    cout << "==========================================" << endl;
    cout << "|  N | Select | Bubble | Shaker | Insert |" << endl;
    cout << "==========================================" << endl;

    for (n = 100; n <= 1300; n += 100) {
        printf("|%3d |", n);
        FillRand(n);
        printf("%7d |", SelectSort(n));
        FillRand(n);
        printf("%7d |", BubbleSort(n));
        FillRand(n);
        printf("%7d |", ShakerSort(n, A));
        FillRand(n);
        printf("%7d |", InsertSort(n));
        cout << endl;
        cout << "-----+--------+--------+--------+--------+" << endl;
    }
    sf::Font font;

    sf::Text text;

	font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setString(L"0");
    text.setCharacterSize(24);
    text.setPosition(30.f, 560.f);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

	sf::Text textN;

    textN.setFont(font);
    textN.setString(L"N, ед.");
    textN.setCharacterSize(24);
    textN.setPosition(1200.f, 560.f);
    textN.setFillColor(sf::Color::White);
    textN.setStyle(sf::Text::Bold);

	sf::Text textTN;

    textTN.setFont(font);
    textTN.setString(L"T(N), тыс.");
    textTN.setCharacterSize(24);
    textTN.setPosition(65.f, 5.f);
    textTN.setFillColor(sf::Color::White);
    textTN.setStyle(sf::Text::Bold);

	sf::Text text200;

    text200.setFont(font);
    text200.setString(L"200");
    text200.setCharacterSize(24);
    text200.setPosition(2, 482.f);
    text200.setFillColor(sf::Color::White);
    text200.setStyle(sf::Text::Bold);

	sf::Text text75;
	text75.setFont(font);
    text75.setString(L"75");
    text75.setCharacterSize(24);
    text75.setPosition(112.f, 560.f);
    text75.setFillColor(sf::Color::White);
    text75.setStyle(sf::Text::Bold);

    sf::RenderWindow window(sf::VideoMode(1280, 640), "Graphics");
    sf::VertexArray pointInsert(sf::LinesStrip, 1215);
    sf::VertexArray pointShaker(sf::LinesStrip, 1215);
    sf::VertexArray pointBubble(sf::LinesStrip, 1215);
    sf::VertexArray pointSelect(sf::LinesStrip, 1215);

    sf::VertexArray X(sf::Lines, 32);
    int j = 0;
    for (int p = 51; p < 1270; p++) {
        if ((p - 50) % 75 == 0) {
            X[j].position = sf::Vector2f(p, 545);
            X[j + 1].position = sf::Vector2f(p, 555);
            X[j].color = sf::Color::White;
            j += 2;
        }
    }

    sf::VertexArray Y(sf::Lines, 20);
    j = 0;
    for (int p = 50; p < 550; p += 50) {
        Y[j].position = sf::Vector2f(45, p);
        Y[j + 1].position = sf::Vector2f(55, p);
        Y[j].color = sf::Color::White;
        j += 2;
    }

    sf::VertexArray coord(sf::Lines, 4);

    coord[0].position = sf::Vector2f(50, 550);
    coord[1].position = sf::Vector2f(1265, 550);
    coord[2].position = sf::Vector2f(50, 550);
    coord[3].position = sf::Vector2f(50, 15);

    coord[0].color = sf::Color::White;
    coord[1].color = sf::Color::White;
    coord[2].color = sf::Color::White;
    coord[3].color = sf::Color::White;

    sf::VertexArray triangleX(sf::Triangles, 3);
    triangleX[0].position = sf::Vector2f(1248, 556);
    triangleX[1].position = sf::Vector2f(1265, 550);
    triangleX[2].position = sf::Vector2f(1248, 544);
    triangleX[0].color = sf::Color::White;
    triangleX[1].color = sf::Color::White;
    triangleX[2].color = sf::Color::White;

    sf::VertexArray triangleY(sf::Triangles, 3);
    triangleY[0].position = sf::Vector2f(44, 32);
    triangleY[1].position = sf::Vector2f(50, 15);
    triangleY[2].position = sf::Vector2f(56, 32);
    triangleY[0].color = sf::Color::White;
    triangleY[1].color = sf::Color::White;
    triangleY[2].color = sf::Color::White;

    for (size_t i = 50; i < 1265; i++) {
        FillRand(i);
        pointInsert[i - 50].position = sf::Vector2f(i, 550 - InsertSort(i) / 4000);
        //if (i != 50)
        pointInsert[i - 50].color = sf::Color::Red;
        FillRand(i);

        pointShaker[i - 50].position = sf::Vector2f(i, 550 - ShakerSort(i, A) / 4000);
        //if (i != 50)
        pointShaker[i - 50].color = sf::Color::Blue;

        FillRand(i);
        pointBubble[i - 50].position = sf::Vector2f(i, 550 - BubbleSort(i) / 4000);
        //if (i != 50)
        pointBubble[i - 50].color = sf::Color::Green;

        FillRand(i);
        pointSelect[i - 50].position = sf::Vector2f(i, 550 - SelectSort(i) / 4000);
        //if (i != 50)
        pointSelect[i - 50].color = sf::Color::Yellow;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(pointInsert);
        window.draw(pointShaker);
        window.draw(pointBubble);
        window.draw(pointSelect);
        window.draw(coord);
        window.draw(X);
        window.draw(Y);
        window.draw(text);
        window.draw(textN);
        window.draw(textTN);
        window.draw(text200);
        window.draw(text75);
        window.draw(triangleX);
        window.draw(triangleY);
        window.display();
    }
}
