#include "Info.h"

Info::Info()
{
}

Info::~Info()
{
}

void Info::Information()
{
    system("cls");
    std::cout << '\n' << '\n' << '\n' << '\n';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << "                                  _______________________________ "<< '\n';
    std::cout << "                                /                                 *."<< '\n';
    std::cout << "                               |  |                                 |."<< '\n';
    std::cout << "                                {_|  1. El juego consta de 5 jefes. |."<< '\n';
    std::cout << "                                  |  2. Para matarlos se necesitan  |."<< '\n';
    std::cout << "                                  |  las dos armas(Lanza y Daga).   |."<< '\n';
    std::cout << "                                  |  3. Para matar al vampiro se    |."<< '\n';
    std::cout << "                                  |  necesita una lanza.            |."<< '\n';
    std::cout << "                                  |  4. Para matar al ghoul se      |."<< '\n';
    std::cout << "                                  |  necesita una daga.             |."<< '\n';
    std::cout << "                                  |  5. Las pociones recuperan la   |."<< '\n';
    std::cout << "                                  |  vida.                          |."<< '\n';
    std::cout << "                                  |  6. Disfruta del juego.         |."<< '\n';
    std::cout << "                                  |                                 |." << '\n';
    std::cout << "                                  |  *Para pasar el juego es neces- |."<< '\n';
    std::cout << "                                  |  ario usar las habilidades e    |." << '\n';
    std::cout << "                                  |  invertir los puntos de experi- |." << '\n';
    std::cout << "                                  |  encia de forma sabia.          |." << '\n';
    std::cout << "                                  |                                 |." << '\n';
    std::cout << "                                  |         Te sorprenderas!!       |."<< '\n';
    std::cout << "                                  |   ______________________________|___"<< '\n';
    std::cout << "                                  |  /                                 /."<< '\n';
    std::cout << "                                  {_/_________________________________/."<< '\n';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("pause");
}
