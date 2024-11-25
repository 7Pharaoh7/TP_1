#include "hero.h"

Hero::Hero() : name(""), weapon(""), skills(nullptr), size(0), capacity(0) {cout << "Hero: Конструктор без параметров\n";}

Hero::Hero(string& n, string& w, string skill) 
    : name(n), weapon(w), size(0), capacity(1) {
    skills = new string[capacity];
    add_skill(skill);
    cout << "Hero: Конструктор с параметрами\n";
}

Hero::Hero(const Hero& other) 
    : name(other.name), weapon(other.weapon), size(other.size), capacity(other.capacity) {
    skills = new string[capacity];
    for (int i = 0; i < size; ++i) {
        skills[i] = other.skills[i];
    }
    cout << "Hero: Конструктор копирования\n";
}

Hero::~Hero() {
    delete[] skills;
    cout << "Hero: Деструктор\n";
}

void Hero::set_name(string n) {
    name = n;
}

void Hero::set_weapon(string w) {
    weapon = w;
}

void Hero::set_skills(string s) {
    add_skill(s);
}

string Hero::get_name() {
    return name;
}

string Hero::get_weapon() {
    return weapon;
}

string Hero::get_skills() {
    string allSkills;
    for (int i = 0; i < size; ++i) {
        allSkills += skills[i];
        if (i < size - 1) {
            allSkills += ", ";
        }
    }
    return allSkills;
}

void Hero::print_info() {
    cout << "Герой\n" << "Имя: " << name << "\n"
         << "Оружие: " << weapon << "\n"
         << "Навыки: " << get_skills() << endl;
}

void Hero::change_info() {
    string newName, newWeapon, newSkill;
    cout << "Введите новое имя: ";
    getline(cin, newName);
    set_name(newName);
    
    cout << "Введите новое оружие: ";
    getline(cin, newWeapon);
    set_weapon(newWeapon);
    
    cout << "Введите новый навык: ";
    getline(cin, newSkill);
    set_skills(newSkill);
}

void Hero::save(ostream& out) {
    out << "Hero\n";
    out << name << '\n' << weapon << '\n' << size << '\n';
    for (int i = 0; i < size; ++i) {
        out << skills[i] << '\n';
    }
}

void Hero::load(istream& in) {
    getline(in, name);
    getline(in, weapon);
    in >> size;
    in.ignore();
    delete[] skills;
    skills = new string[size];
    for (int i = 0; i < size; ++i) {
        getline(in, skills[i]);
    }
}

void Hero::add_skill(const string& skill) {
    if (size >= capacity) {
        resize();
    }
    skills[size++] = skill;
}

void Hero::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    string* newSkills = new string[capacity];
    for (int i = 0; i < size; ++i) {
        newSkills[i] = skills[i];
    }
    delete[] skills;
    skills = newSkills;
}
