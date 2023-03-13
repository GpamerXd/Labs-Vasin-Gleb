// ����������� ������������� ����� ������ ����
#include "WordGame.h"

// ����������� �� ���������
WordGame::WordGame()
{
	/*
	������������ "�����������" start_game
	*/
}

// ���������� �� ���������
WordGame::~WordGame()
{

	delete[] this->scores;
	// ������� ������� �������������� ����
	this->words_used.clear();
}


// ������ ���� (�������� �����, ���������� �������)
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


// ������� ��� (�������� �����)
bool WordGame::make_move(std::string selected_word)
{
	if (selected_word.size() == 0) return false;
	if (selected_word == "0") return false;
	if (std::count(
		// ��������� ��������
		this->words_used.begin(),
		// �������� ��������
		this->words_used.end(),
		// �������� �����
		selected_word)) {
		return false;
	}
	else {
		// ���� �������� ����� ������ ��� ��������
		// �������� ������ ����� ��������� �����
		for (int i = 0; i < selected_word.size(); i++) {
			// ���� ��� �������� ������� �����
			bool flag = false;
			// �� ������� � ������� �����
			for (int j = 0; j < this->game_word.size(); j++) {
				if (selected_word[i] == this->game_word[j]) {
					flag = true;
				}
			}
			if (!flag) return false;
		}
		// ���� �������� ����� ������� ������ ��� ��������,
		// �� ��������� ��� � ������
		this->words_used.push_back(selected_word);
		return true;
	}
}


// ������(). � ���� ���������� �������� ����� make_move
void WordGame::play()
{
	std::cout << "\n���� ��������\n";
	while (true) {
		// ���������� ��� ��������� �����
		std::string input_word = "";
		std::cout << "\n\n����� ����� " << this->current_player + 1;
		std::cout << "\n������� ����� >>> ";
		std::cin >> input_word;
		if (make_move(input_word)) {
			std::cout << "\n����� "
				<< this->current_player + 1
				<< " �������� ���� ����";
			this->scores[this->current_player] += 1;
			std::cout << "\n������� ���� > " << this->scores[this->current_player];
		}
		// ���� ��� �� ��������
		else {
			int max = 0;
			int max_id = 0;
			for (int i = 0; i < this->number_of_players; i++) {
				std::cout << "\n����� " << i + 1
					<< " ������ "
					<< this->scores[i]
					<< " �����";
				// �������� �� ����������
				if (this->scores[i] > max) {
					max = this->scores[i];
					max_id = i;
				}
			}
			// ����� ���������� � ����������
			std::cout << "\n\n������� ����� " << max_id + 1
				<< " �� ������ " << max;
			break;
		}
		this->current_player = (this->current_player + 1) % this->number_of_players;
	}
	std::cout << "\n���� ��������\n";
}
