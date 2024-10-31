

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

struct Film_linear {
    char name[50];
    char budget[30];
    double price;
    int quantity;
    int age_limit;
};

int main()
{
    setlocale(LC_ALL, "ru");
    int f_move;
    cout << "[1] Добавить фильм\n[2] Посмотреть каталог фильмов\n[3] Поиск фильмов по атрибуту\n";
    cin >> f_move;
    int rows_count = 0;
    fstream rows;
    rows.open("rows.bin", ios::in | ios::binary);
    rows.read((char*)&rows_count, sizeof(int));
    rows.close();


    string sub_str;

    fstream add;
    fstream read;
    vector<Film_linear> films(rows_count);

    Film_linear film{};
    switch (f_move) {
    default:
        break;
    case 1:
        cout << "Введите название фильма: ";
        cin >> film.name;
        cout << "Введите бюджет фильма: ";
        cin >> film.budget;
        cout << "Введите цену билета: ";
        cin >> film.price;
        cout << "Введите количество свободных мест: ";
        cin >> film.quantity;
        cout << "Введите возрастное ограничение: ";
        cin >> film.age_limit;
        add.open("bin.bin", ios::out | ios::binary | ios::app);
        add.write((char*)&film, sizeof(Film_linear));
        add.close();
        rows_count++;
        rows.open("rows.bin", ios::out | ios::binary);
        rows.write((char*)&rows_count, sizeof(int));
        rows.close();
        break;
    case 2:
        read.open("bin.bin", ios::in | ios::binary);
    std::cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
    for (int i = 0; i < rows_count; i++) {
        Film_linear temp{};
        read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));
        std::cout << std::left << setw(20) << temp.name << "| " << setw(18) << temp.budget << "| " << setw(8) << temp.price << "| " << setw(8) << temp.quantity << "   | " << setw(8) << temp.age_limit << endl;
    }
    read.close();
        break;
    case 3:
        int s_move;
        cout << "[1] По совпадению с названием\n[2] По интервалу цены билета\n[3] По совпадению с описанием\n[4] По интервалу количества свободных мест\n[5] По интервалу возрастного ограничения\n";
        cin >> s_move;
        read.open("bin.bin", ios::in | ios::binary);
        string name;
        string sub_str;
        int a, b;
        switch (s_move) {
        default:
            break;
        case 1:
            cout << "Введите строковый атрибут: ";
            cin >> sub_str;
            for (int i = 0; i < rows_count; i++) {
                Film_linear temp{};

                read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));

                name = temp.name;

                std::cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
                if (name.find(sub_str) != std::string::npos) {
                    std::cout << std::left << setw(20) << temp.name << "| " << setw(18) << temp.budget << "| " << setw(8) << temp.price << "| " << setw(8) << temp.quantity << "   | " << setw(8) << temp.age_limit << endl;
                }
            }
            read.close();
            break;
        case 2:


            cout << "Введите первое значение интервала: ";
            cin >> a;
            cout << "Введите второе значение интервала: ";
            cin >> b;


            for (int i = 0; i < rows_count; i++) {
                Film_linear temp{};

                read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));

                std::cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
                if ((temp.price >= a) && (temp.price <= b)) {
                    std::cout << std::left << setw(20) << temp.name << "| " << setw(18) << temp.budget << "| " << setw(8) << temp.price << "| " << setw(8) << temp.quantity << "   | " << setw(8) << temp.age_limit << endl;
                }
            }
            read.close();
            break;
        case 3:
            cout << "Введите строковый атрибут: ";
            cin >> sub_str;
            for (int i = 0; i < rows_count; i++) {
                Film_linear temp{};

                read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));

                name = temp.budget;

                std::cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
                if (name.find(sub_str) != std::string::npos) {
                    std::cout << std::left << setw(20) << temp.name << "| " << setw(18) << temp.budget << "| " << setw(8) << temp.price << "| " << setw(8) << temp.quantity << "   | " << setw(8) << temp.age_limit << endl;
                }
            }
            read.close();
            break;
        case 4:


            cout << "Введите первое значение интервала: ";
            cin >> a;
            cout << "Введите второе значение интервала: ";
            cin >> b;


            for (int i = 0; i < rows_count; i++) {
                Film_linear temp{};

                read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));

                std::cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
                if ((temp.quantity >= a) && (temp.quantity <= b)) {
                    std::cout << std::left << setw(20) << temp.name << "| " << setw(18) << temp.budget << "| " << setw(8) << temp.price << "| " << setw(8) << temp.quantity << "   | " << setw(8) << temp.age_limit << endl;
                }
            }
            read.close();
            break;
        case 5:


            cout << "Введите первое значение интервала: ";
            cin >> a;
            cout << "Введите второе значение интервала: ";
            cin >> b;


            for (int i = 0; i < rows_count; i++) {
                Film_linear temp{};

                read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));

                std::cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
                if ((temp.age_limit >= a) && (temp.age_limit <= b)) {
                    std::cout << std::left << setw(20) << temp.name << "| " << setw(18) << temp.budget << "| " << setw(8) << temp.price << "| " << setw(8) << temp.quantity << "   | " << setw(8) << temp.age_limit << endl;
                }
            }
            read.close();
            break;
        }
    }
}
