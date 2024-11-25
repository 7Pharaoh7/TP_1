#include "keeper.h"
#include "hero.h"
#include "vilain.h"
#include "monster.h"
#include <iostream>
#include <fstream>

using namespace std;

void display_menu() {
    cout << "\nМеню:\n";
    cout << "1. Add an object to a container\n";
    cout << "2. Insert an object into a container by index\n";
    cout << "3. Remove an object from a container\n";
    cout << "4. Change object information\n";
    cout << "5. Overloaded operator !\n";
    cout << "6. Overloaded operator --\n";
    cout << "7. Display information about all objects\n";
    cout << "8. Save container to file\n";
    cout << "9. Load container from file\n";
    cout << "0. Exit\n";
    cout << "Select action: ";
}

int main() {
    Keeper keeper;
    int choice, index;

    while (true) 
        display_menu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "What object do you want to add?\n";
                cout << "1 - Heroes\n2 - Villain\n3 - Monster\n";
                int obj_choice;
                cin >> obj_choice;
                cin.ignore(); 

                Base* new_object = nullptr;
                switch (obj_choice) {
                    case 1: {
                        string name, weapon, skill;
                        cout << "Enter the hero's name: ";
                        getline(cin, name);
                        cout << "Enter the hero's weapon: ";
                        getline(cin, weapon);
                        cout << "Enter hero skill: ";
                        getline(cin, skill);
                        new_object = new Hero(name, weapon, skill);
                        break;
                    }
                    case 2: {
                        string name, weapon, crime, place, skill;
                        cout << "Enter the villain's name: ";
                        getline(cin, name);
                        cout << "Enter the villain's weapon: ";
                        getline(cin, weapon);
                        cout << "Enter the villain's crime: ";
                        getline(cin, crime);
                        cout << "Enter the location of the villain: ";
                        getline(cin, place);
                        cout << "Enter the location of the villain: ";
                        getline(cin, skill);
                        new_object = new Vilain(name, weapon, crime, place, skill);
                        break;
                    }
                    case 3: {
                        string name, description;
                        cout << "Enter monster name: ";
                        getline(cin, name);
                        cout << "Enter a description of the monster:";
                        getline(cin, description);
                        new_object = new Monster(name, description);
                        break;
                    }
                    default:
                        cout << "Incorrect choice of object.\n";
                        continue;
                }
                index = keeper.get_count();
                keeper.add(new_object, index);
                break;
            }

            case 2: {
                cout << "What object do you want to add?n";
                cout << "1 - Heroes\n2 - Villain\n3 - Monster\n";
                int obj_choice;
                cin >> obj_choice;
                cin.ignore(); 

                Base* new_object = nullptr;
                switch (obj_choice) {
                    case 1: {
                        string name, weapon, skill;
                        cout << "Enter the hero's name: ";
                        getline(cin, name);
                        cout << "Enter the hero's weapon: ";
                        getline(cin, weapon);
                        cout << "Enter hero skills: ";
                        getline(cin, skill);
                        new_object = new Hero(name, weapon, skill);
                        break;
                    }
                    case 2: {
                        string name, weapon, crime, place, skill;
                        cout << "Enter the villain's name: ";
                        getline(cin, name);
                        cout << "Enter the villain's weapon: ";
                        getline(cin, weapon);
                        cout << "Enter the villain's crime: ";
                        getline(cin, crime);
                        cout << "Enter the location of the villain: ";
                        getline(cin, place);
                        cout << "Enter the villain's skills: ";
                        getline(cin, skill);
                        new_object = new Vilain(name, weapon, crime, place, skill);
                        break;
                    }
                    case 3: {
                        string name, description;
                        cout << "Enter monster name: ";
                        getline(cin, name);
                        cout << "Enter a description of the monster: ";
                        getline(cin, description);
                        new_object = new Monster(name, description);
                        break;
                    }
                    default:
                        cout << "Incorrect choice of object.\n";
                        continue;
                }
                cout << "Введите индекс для вставки\n";
                cin >> index;
                cin.ignore();
                keeper.add(new_object, index);
                break;
            }

            case 3: {
                cout << "Введите индекс объекта для удаления: ";
                cin >> index;
                keeper.delete_element(index);
                break;
            }

            case 4: {
                cout << "Введите индекс объекта для изменения: ";
                cin >> index;
                keeper.edit_element(index);
                break;
            }

            case 5: {
                !keeper;
                break;
            }

            case 6: {
                keeper--;
                break;
            }

            case 7: {
                keeper.display_keeper();
                break;
            }

            case 8: {
                keeper.save("2.csv");
                cout << "Контейнер сохранен в файл.\n";
                break;
            }

            case 9: {
                keeper.load("1.csv");
                cout << "Контейнер загружен из файла.\n";
                break;
            }

            case 0:
                cout << "Выход из программы.\n";
                return 0;

            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
                break;
        }
    }
}
