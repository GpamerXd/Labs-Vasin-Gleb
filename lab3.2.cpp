#include <iostream>
void input(int*& arr, int& size) {
	if (arr != nullptr) {
		delete[] arr;//возвращает выделенную память оператора new
	}
	std::cout << "Введите размер массива: ";
	std::cin >> size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		std::cout << "Введите число № " << i + 1 << "-> ";
		std::cin >> arr[i];
	}
}
void output(int* arr, int n) {
	std::cout << "{ ";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "}";
}
int funcsum(int a1) {
	int sum1 = 0;
	while (a1 != 0) {
		sum1 += (a1 % 100) % 10;
		a1 /= 100;
	}
	return sum1;
}
int sort1(int* arr, int k) {
	std::cout << std::endl;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k - 1; j++) {
			if (funcsum(arr[j]) > funcsum(arr[j + 1])) {
				int b = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = b;
			}
		}
	}
	std::cout << "Сортировка выполнена \n";
	return *arr;
}
int sort2(int* arr, int k) {
	std::cout << std::endl;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k - 1; j++) {
			if (arr[j] % 10 > arr[j + 1] % 10) {
				int b = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = b;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k - 1; j++) {
			if (arr[j] < arr[j + 1] and arr[j] % 10 == arr[j + 1] % 10) {
				int b = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = b;
			}
		}
	}
	return *arr;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int choice, n;
	int* arr = nullptr;
	while (true) {
		std::cout << "Что вы хотите выполнить? \n"
			<< "1. Ввод массива\n"
			<< "2. Вывод массива\n"
			<< "3. Сортировка по сумме цифр, стоящих на чётных местах\n"
			<< "4. Сортировка массива вначале по возрастанию последней цифры, а при сопадении последних цирф - по убыванию\n"
			<< "5. Выход\n";
		std::cin >> choice;
		switch (choice) {// выбор задания
		case 1: {
			input(arr, n);
			break;
		}
		case 2: {
			output(arr, n);
			break;
		}
		case 3: {
			sort1(arr, n);
			break;
		}
		case 4: {
			sort2(arr, n);
			break;
		}
		default: {//при выборе цифры вне () возвращает в начало выбора
			delete[] arr;
			return 0;
		}
		}
	}
}