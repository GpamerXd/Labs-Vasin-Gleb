#include <iostream>
#include <locale.h>
#include <string>

void task_1() {
    std::cout << "You chose the task number 1" << std::endl;
    int nn;
    std::cout << "Enter the number: ";
    std::cin >> nn;
    std::cout << "Your number is " << nn << std::endl;
    std::string n = "";
    for (int t = 0; t <= nn; t++) {
        n = n + std::to_string(t);
        std::cout << n << std::endl;
    }
    std::cout << "Enter the number of the next task: ";
    std::cin >> num_1;
}

void task_2() {
    std::setlocale(LC_ALL, "ru");
    std::cout << "You chose the task number 2" << std::endl;
    int b;
    std::cout << "Введите число n биномиальные коэфициенты которого вы хотите расчитать" << std::endl;
    std::cin >> b;
    std::cout << "Ваши биномиальные коэфициенты" << std::endl;
    int n;
    long double Cnk = 1;


    for (int k = 1; k <= b + 1; ++k) {
        std::cout << Cnk << std::endl;
        Cnk = Cnk * (b + 1 - k) / k;
    }
    std::cout << "Enter the number of the next task: ";
    std::cin >> num_1;
}

void task_3() {
    std::setlocale(LC_ALL, "ru");
    std::cout << "You chose the task number 3" << std::endl;
    bool t = true;
    int sum = 0;
    int iterator = 0;
    while (t) {
        int numbers;
        std::cin >> numbers;
        sum = sum + numbers;
        iterator++;
        if (numbers == 0) {
            t = false;
        }
    } long double ans = double(sum) / double(iterator - 1);
    std::cout << "Среднее арифметическое равно: " << ans << std::endl;
}

int main() {
    std::cout << "Vasin Gleb Alekseevich 221-352" << std::endl;
    std::cout << "Menu" << std::endl;
    int num_1;
    std::cout << "Enter task number: \n";
    std::cout << "Enter 0 to exit: ";
    std::cin >> num_1;
        if (num_1 == 1) {
            task_1();
       }
        if (num_1 == 2) {
            task_2();
        }
        if (num_1 == 3) {
            
            task_3();
        }
        if (num_1 == 0) {
            break;
        }
        return 0;
}
    
