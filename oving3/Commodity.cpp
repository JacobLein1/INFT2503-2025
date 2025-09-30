#include <iostream>
#include <string>
#pragma once
using namespace std;

const double mva = 1.25;

class Commodity {
public:
  Commodity(const string &name, int id, double price);

  const string &get_name() const;
  double get_price() const;
  double get_price(double quantity) const;
  int get_id() const;
  void set_price(double new_price);
  double get_price_with_sales_tax(double quantity) const;

private:
  string name;
  double price;
  int id;
};

Commodity::Commodity(const string &name_, int id_, double price_)
    : name(name_), price(price_), id(id_) {}

int Commodity::get_id() const {
  return id;
}

const string &Commodity::get_name() const {
  return name;
}

double Commodity::get_price() const {
  return price;
}

double Commodity::get_price(double quantity) const {
  return price * quantity;
}

void Commodity::set_price(double new_price) {
  price = new_price;
}

double Commodity::get_price_with_sales_tax(double quantity) const {
  return get_price(quantity) * mva;
}
