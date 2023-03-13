// Подключение заголовочного файла класса игры
#include "WordGame.h"

// Конструктор по умолчанию
WordGame::WordGame()
{
	/*
	Используется "конструктор" start_game
	*/
}

// Деструктор по умолчанию
WordGame::~WordGame()
{

	delete[] this->scores;
	// Очистка массива использованных слов
	this->words_used.clear();
}


// Начать игру (исходное слово, количество игроков)
void WordGame::start_game(std::string word, int number_of_players)
{
	this->game_word = word;
	this->number_of_players = number_of_players;
	this->scores = new int[number_of_players];
	for (int i = 0; i < number_of_players; i++) {
		scores[i] = 0;
	}
	this->words_used.clear();
	this->current_player = 0;
}


// Сделать ход (введённое слово)
bool WordGame::make_move(std::string selected_word)
{
	if (selected_word.size() == 0) return false;
	if (selected_word == "0") return false;
	if (std::count(
		// Начальный итератор
		this->words_used.begin(),
		// Конечный итератор
		this->words_used.end(),
		// Введённое слово
		selected_word)) {
		return false;
	}
	else {
		// Если введённое слово прошло все проверки
		// Проверка каждой буквы введённого слова
		for (int i = 0; i < selected_word.size(); i++) {
			// Флаг для контроля наличия буквы
			bool flag = false;
			// На наличие в игровом слове
			for (int j = 0; j < this->game_word.size(); j++) {
				if (selected_word[i] == this->game_word[j]) {
					flag = true;
				}
			}
			if (!flag) return false;
		}
		// Если введённое слово успешно прошло все проверки,
		// то добавляем его в вектор
		this->words_used.push_back(selected_word);
		return true;
	}
}


// Играть(). В ходе выполнения вызывает метод make_move
void WordGame::play()
{
	std::cout << "\nИгра началась\n";
	while (true) {
		// Переменная для введённого слова
		std::string input_word = "";
		std::cout << "\n\nХодит игрок " << this->current_player + 1;
		std::cout << "\nВведите слово >>> ";
		std::cin >> input_word;
		if (make_move(input_word)) {
			std::cout << "\nИгрок "
				<< this->current_player + 1
				<< " получает одно очко";
			this->scores[this->current_player] += 1;
			std::cout << "\nТекущий счет > " << this->scores[this->current_player];
		}
		// Если ход не возможен
		else {
			int max = 0;
			int max_id = 0;
			for (int i = 0; i < this->number_of_players; i++) {
				std::cout << "\nИгрок " << i + 1
					<< " набрал "
					<< this->scores[i]
					<< " очков";
				// Проверка на победителя
				if (this->scores[i] > max) {
					max = this->scores[i];
					max_id = i;
				}
			}
			// Вывод информации о победителе
			std::cout << "\n\nПобедил Игрок " << max_id + 1
				<< " со счётом " << max;
			break;
		}
		this->current_player = (this->current_player + 1) % this->number_of_players;
	}
	std::cout << "\nИгра окончена\n";
}
