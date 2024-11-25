#include "vilain.h"

Vilain::Vilain() : name(""), weapon(""), crime(""), place(""), skills(nullptr), size(0), capacity(0) {cout << "Vilain: Конструктор без параметров\n";}

Vilain::Vilain(string& n, string& w, string& c, string& p, string skill) 
    : name(n), weapon(w), crime(c), place(p), size(0), capacity(1) {
    skills = new string[capacity];
    add_skill(skill);
    cout << "Vilain: Конструктор с параметрами\n";
}

Vilain::Vilain(const Vilain& other) 
    : name(other.name), weapon(other.weapon), crime(other.crime), place(other.place), size(other.size), capacity(other.capacity) {
    skills = new string[capacity];
    for (int i = 0; i < size; ++i) {
        skills[i] = other.skills[i];
    }
    cout << "Vilain: Конструктор копирования\n";
}

Vilain::~Vilain() {
    delete[] skills;
    cout << "Vilain: Деструктор\n";
}

void Vilain::set_name(string n) {
    name = n;
}

void Vilain::set_weapon(string w) {
    weapon = w;
}

void Vilain::set_crime(string c) {
    crime = c;
}

void Vilain::set_place(string p) {
    place = p;
}

void Vilain::set_skills(string s) {
    add_skill(s);
}

string Vilain::get_name() {
    return name;
}

string Vilain::get_weapon() {
    return weapon;
}

string Vilain::get_crime() {
    return crime;
}

string Vilain::get_place() {
    return place;
}

string Vilain::get_skills() {
    string allSkills;
    for (int i = 0; i < size; ++i) {
        allSkills += skills[i];
        if (i < size - 1) {
            allSkills += ", ";
        }
    }
    return allSkills;
}

void Vilain::print_info() {
    cout << "Злодей\n" << "Имя: " << name << "\n"
         << "Оружие: " << weapon << "\n"
         << "Преступление: " << crime << "\n"
         << "Место: " << place << "\n"
         << "Навыки: " << get_skills() << endl;
}

void Vilain::change_info() {
    string newName, newWeapon, newCrime, newPlace, newSkill;
    cout << "Введите новое имя: ";
    getline(cin, newName);
    set_name(newName);
    
    cout << "Введите новое оружие: ";
    getline(cin, newWeapon);
    set_weapon(newWeapon);
    
    cout << "Введите новое преступление: ";
    getline(cin, newCrime);
    set_crime(newCrime);
    
    cout << "Введите новое место: ";
    getline(cin, newPlace);
    set_place(newPlace);
    
    cout << "Введите новый навык: ";
    getline(cin, newSkill);
    set_skills(newSkill);
}

void Vilain::save(ostream& out) {
    out << "Vilain\n";
    out << name << '\n' << weapon << '\n' << crime << '\n' << place << '\n' << size << '\n';
    for (int i = 0; i < size; ++i) {
        out << skills[i] << '\n';
    }
}

void Vilain::load(istream& in) {
    getline(in, name);
    getline(in, weapon);
    getline(in, crime);
    getline(in, place);
    in >> size;
    in.ignore();
    delete[] skills;
    skills = new string[size];
    for (int i = 0; i < size; ++i) {
        getline(in, skills[i]);
    }
}

void Vilain::add_skill(const string& skill) {
    if (size >= capacity) {
        resize();
    }
    skills[size++] = skill;
}

void Vilain::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    string* newSkills = new string[capacity];
    for (int i = 0; i < size; ++i) {
        newSkills[i] = skills[i];
    }
    delete[] skills;
    skills = newSkills;
}
