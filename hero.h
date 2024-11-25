#pragma once
#include "base.h"

class Hero: public Base 
{
    private:
        string name;
        string weapon;
        string* skills;
        int size;
        int capacity;
    public:
        Hero();
        Hero(string& n, string& w, string skill); 
        Hero(const Hero& other);
        ~Hero();

        void set_name(string n);
        void set_weapon(string w);
        void set_skills(string s);

        string get_name();
        string get_weapon();
        string get_skills();

        void print_info() override;
        void change_info() override;
        void save(ostream&) override;
        void load(istream&) override;

        void add_skill(const string& skill);
        void resize();
    
};