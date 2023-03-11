#include <iostream>
#include <cstring>
#include <string>//заголовки стандартных библиотек
#include <fstream>//работа с внешними файлами
#include <bitset>//контейнер для хранения битов


using std::cin;
using std::cout;
using std::endl;
using std::string;



string file_format(const string file_path_full) {
	return file_path_full.substr(file_path_full.rfind("."), -1);
}


string file_name(const string file_path_full) {
	return file_path_full.substr(file_path_full.rfind("\\"), file_path_full.rfind("."));
}

string file_path(const string file_path_full) {
	return file_path_full.substr(0, file_path_full.rfind("\\"));
}

string file_disc(const string file_path_full) {
	return file_path_full.substr(0, file_path_full.rfind(":"));
}

bool file_rename(string file_path_full) {
	setlocale(LC_ALL, "Russian");
	string f;
	string new_name;
	cin >> new_name;

	f = file_path(file_path_full) + "\\" + new_name + "." + file_format(file_path_full);
	cout << f;
	return 1;

}

bool file_copy(string file_path_full) {
	std::ifstream fin(file_path_full);//для работы с файлами
	string copy = file_path(file_path_full) + '\\' + file_name(file_path_full) + "_copy" + "." + file_format(file_path_full);
	std::ofstream fout(copy);
	char temp;
	if (!fin && !fout) {
		cout << "Файлы не открыты";
	}
	else {
		while (!fin.eof()) {
			fin >> temp;//ввод
			fout << temp;//вывод из файлов
		}
	}
	fin.close();
	fout.close();
	return 1;
}


int main() {
	setlocale(LC_ALL, "Russian");
	string file_path_full = "C:\\Users\\Gamepro4sv\\Desktop\\папка\\for4.2.txt";

	while (true) {
		int m;
		cin >> m;
		switch (m) {
		case 1: {
			cout << file_format(file_path_full) << endl;
			break;
		}
		case 2: {
			cout << file_name(file_path_full) << endl;
			break;
		}
		case 3: {
			cout << file_path(file_path_full) << endl;
			break;
		}
		case 4: {
			cout << file_disc(file_path_full) << endl;
			break;
		}
		case 5: {
			file_rename(file_path_full);
			break;
		}
		case 6: {
			file_copy(file_path_full);
		}
		}
	}
}