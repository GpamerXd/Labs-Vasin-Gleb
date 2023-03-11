#include <iostream>
#include <cstring>
int sizemas = 0;
void encrypt(char* std_for_encrypt, int key) {
	int size = strlen(std_for_encrypt);//возвращает длинну строки оканчивающиеся нулевым символом(нулевой симво/0)
	for (int i = 0; i < size; i++) {
		if (std_for_encrypt[i] != ' ') {
			std_for_encrypt[i] = std_for_encrypt[i] + (key % 26); //цикличность
		}
		else {
			std_for_encrypt[i] = ' ';
		}
	}
}
bool Palindrom(char* str) {
	int size = strlen(str);
	bool flag = true;//допустимые значения тру фол
	for (int i = 0, j = size - 1; i < size, i < j; i++, j--) {
		if (str[i] >= 'A' and str[i] <= 'Z') {
			str[i] += 'a' - 'A';
		}
		if (str[j] >= 'A' and str[j] <= 'Z') {
			str[j] += 'a' - 'A';
		}
		if (str[i] != str[j]) {
			flag = false;
			std::cout << flag << std::endl;
			break;
		}

	}
	return flag;
}
int find_substring1(const char* str_for_search_in, const char* substring, int start_position) {
	int size = strlen(str_for_search_in);
	int size1 = strlen(substring);
	int j = 0;
	for (int i = start_position; i < size; i++) {
		if (str_for_search_in[i] == substring[j]) {
			j++;
		}
		else {
			j = 0;
		}
		if (j == size1 - 1) {
			return i - j + 1;
		}
	}
	return 0;
}
int* find_substring2(const char* str_for_search_in, const char* substring) {
	sizemas = 0;
	int size = strlen(str_for_search_in);
	int size1 = strlen(substring) + 1;
	int j = 0;
	int q = 0;
	int* arr = new int[size];//new выделение динамической памяти
	for (int i = 0; i < size; i++) {
		if ((str_for_search_in[i] == substring[j]) and (j < size1)) {
			j++;
		}
		else {
			j = 0;
		}
		if (j == size1 - 1) {
			sizemas++;
			arr[q] = i - size1 + 1;
			q++;
			j = 0;
		}
	}
	return arr;
}
void names(char* str) {
	bool flag = false;
	int size = strlen(str);
	char a[255] = { '\0' };//char символьные переменные
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (flag == true and str[i] != '\"' and str[i] != '<' and str[i] != '>') {
			a[j] = str[i];
			j++;
		}
		if (str[i] == '\"' or str[i] == '<' or str[i] == '>') {
			if (flag == true) {
				std::cout << " | ";
				for (int q = 0; q < j; q++) {
					std::cout << a[q];
				}
				j = 0;
				char a[255] = { '\0' };
				flag = false;
			}
			else {
				flag = true;
			}
		}
	}
	std::cout << " |";
}
int main() {
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	while (true) {
		std::cout << "\nЧто вы хотите выполнить? \n"
			<< "1. Проверка на полиндром\n"
			<< "2. Поиск подстроки в строке\n"
			<< "3. Шифрование сдвигами (шифр Цезаря)\n"
			<< "4. Введите текст, в котором нужно найти названия\n"
			<< "5. Выход\n";
		std::cin >> choice;
		switch (choice) {
		case 1: {
			//start Polyndrom
			char pol[255] = { '\0' };
			std::cout << "Введите строку для проверки её на полиндром: ";
			std::cin.ignore();
			std::cin.getline(pol, 255);
			if (Palindrom(pol) == 1) {
				std::cout << "Palindrom\n";
			}
			else {
				std::cout << "Not Palindrom\n";
			}
			//A Santa dog lived as a devil god at NASA
			break;
			//end Polyndrom
		}
		case 2: {
			//start find_substring1
			std::cout << "Введите строку, в которой будем осуществлять поиск: ";
			char str_for_search_in[255] = { '\0' };
			std::cin.ignore();
			std::cin.getline(str_for_search_in, 255);// вывод данных из потока
			std::cout << "Введите строку, которую будем искать: ";
			char substring[255];
			std::cin.getline(substring, 255);
			std::cout << "Введите начальную позицию: ";
			int start;
			std::cin >> start;
			if (find_substring1(str_for_search_in, substring, start) == 0) {
				std::cout << "Вхождения не найдено\n";
			}
			else {
				std::cout << "Индекс: " << find_substring1(str_for_search_in, substring, start) << '\n';
			}
			//end find_substring1
			//start find_substring2
			std::cout << "Введите строку, в которой будем осуществлять поиск: ";
			char str_for_search_in1[255] = { '\0' };
			std::cin.ignore();
			std::cin.getline(str_for_search_in1, 255);
			std::cout << "Введите строку, которую будем искать: ";
			char substring1[255];
			std::cin.ignore();
			std::cin.getline(substring1, 255);
			std::cout << "Индексы вхождения:";
			if (find_substring2(str_for_search_in1, substring1) != 0) {
				int* pointer = find_substring2(str_for_search_in1, substring1);
				for (int i = 0; i < sizemas; i++) {
					std::cout << pointer[i] << " ";
				}
			}
			else {
				std::cout << "Вхождения не найдено";
			}
			break;
			//end find_substring2
		}
		case 3: {
			//start encrypt
			char text[255];
			int key;
			std::cout << "Введите строку для шифровки: ";
			std::cin.ignore();
			std::cin.getline(text, 255);
			std::cout << '\n' << "Введите сдвиг: ";//конец строки /n
			std::cin >> key;
			encrypt(text, key);
			std::cout << '\n' << text;
			break;
			//end encrypt*/
		}
		case 4: {
			char str[255];
			std::cout << "Введите строку: ";
			std::cin.ignore();
			std::cin.getline(str, 255);
			names(str);
			break;
		}
		default: {
			return 0;
		}
		}
	}
}