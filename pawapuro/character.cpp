#include "./character.hpp"
#include <iostream>
#include <stdexcept>

using std::exception;
using std::string;

// character
string Character::name() const { return name_; }
void Character::name(string name) { name_ = name; }

int Character::position() const { return position_; }
void Character::position(int position) {
    if(1 <= position && position <= 9) {
        position_ = position;
    }
    throw;
}

int Character::number() const { return number_; }
void Character::number(int number) { number_ = number; }

int Character::muscle() const { return muscle_; }
void Character::muscle(int muscle) { muscle_ = muscle; }

int Character::agile() const { return agile_; }
void Character::agile(int agile) { agile_ = agile; }

int Character::technique() const { return technique_; }
void Character::technique(int technique) { technique_ = technique; }

int Character::evolving() const { return evolving_; }
void Character::evolving(int evolving) { evolving_ = evolving; }

int Character::spirit() const { return spirit_; }
void Character::spirit(int spirit) { spirit_ = spirit; }

// 選手の基本クラス
/*
class Picher : public Character {
  private:
    int ball_;
    int control_;
    int stamina_;
    int slider_;
    int curve_;
    int fork_;

    int ball() const { return ball_; }
    void ball(int ball) { ball_ = ball; }

    int control() const { return control_; }
    void control(int control) { control_ = control; }

    int stamina() const { return stamina_; }
    void stamina(int stamina) { stamina_ = stamina; }

    int slider() const { return slider_; }
    void slider(int slider) { slider_ = slider; }

    int curve() const { return curve_; }
    void curve(int curve) { curve_ = curve; }

    int fork() const { return fork_; }
    void fork(int fork) { fork_ = fork; }
};
*/
