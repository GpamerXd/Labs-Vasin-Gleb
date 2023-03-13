// Подключение библиотеки ввода-вывода
#include <iostream>
// Подключение поддержки вектора
#include <vector>

// Создание класса игры
class WordGame
{
// Защищенная область
private:
	std::string game_word;
	int* scores;
	std::vector<std::string> words_used;
	int number_of_players;
	int current_player;

// Открытая область
public:
	WordGame();
	~WordGame();

	void start_game(std::string word, int number_of_players);
	bool make_move(std::string selected_word);
	void play();
};

