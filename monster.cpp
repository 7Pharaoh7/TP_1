#include "monster.h"

Monster::Monster() : name(""), description("") {cout << "Monster: Конструктор без параметров\n";}

Monster::Monster(string& n, string& d) : name(n), description(d) {cout << "Monster: Конструктор с параметрами\n";}

Monster::Monster(const Monster& other) : name(other.name), description(other.description) {cout << "Monster: Конструктор копирования\n";}

Monster::~Monster() {cout << "Monster: Деструктор\n";}

void Monster::set_name(string n) {
    name = n;
}

void Monster::set_description(string d) {
    description = d;
}

string Monster::get_name() {
    return name;
}

string Monster::get_description() {
    return description;
}

void Monster::print_info() {
    cout << "Монстер\n"<< "Имя: " << name << "\n"
         << "Описание: " << description << endl;
}

void Monster::change_info() {
    string newName, newDescription;
    cout << "Введите новое имя: ";
    getline(cin, newName);
    set_name(newName);
    
    cout << "Введите новое описание: ";
    getline(cin, newDescription);
    set_description(newDescription);
}

void Monster::save(ostream& out) {
    out << "Monster\n";
    out << name << '\n' << description << '\n';
}

void Monster::load(istream& in) {
    getline(in, name);
    getline(in, description);
}
