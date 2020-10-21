#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <stdexcept>

using std::exception;
using std::string;

// 選手の基本クラス
class Character {
  private:
    string name_;
    int position_;
    int number_;
    int muscle_;
    int agile_;
    int technique_;
    int evolving_;
    int spirit_;

  public:
    string name() const;
    void name(string name);

    int position() const;
    void position(int position);

    int number() const;
    void number(int number);

    int muscle() const;
    void muscle(int muscle);

    int agile() const;
    void agile(int agile);

    int technique() const;
    void technique(int technique);

    int evolving() const;
    void evolving(int evolving);

    int spirit() const;
    void spirit(int spirit);
};

#endif // CHARACTER_CHPP