// Подключение библиотеки ввода-вывода
#include <iostream>
// Подключение класса игры
#include "WordGame.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Экзаменационный проект. Дата написания 13 03 2023.\n"
        << "Автор: Глеб Васин Алексеевич\n"
        << "Группа: 221-352\n";
    WordGame my_game;
    std::string word;
    int number_of_players;
    std::cout << "\nВведите слово для игры >>> ";
    std::cin >> word;
    std::cout << "\nВведите количество игроков >>> ";
    std::cin >> number_of_players;
    my_game.start_game(word, number_of_players);
    my_game.play();
}
