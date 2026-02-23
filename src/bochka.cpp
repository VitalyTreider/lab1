#include "bochka.hpp"
#include <iostream>
#include <cstring>

Bochka::Bochka() {
    volume = 0;
    p_water = 0;
    p_alch = 0;
    water = 0;
    alch = 0;
}

Bochka::Bochka(double vol, double p_a) {
    volume = vol;
    p_water = 100 - p_a;
    p_alch = p_a;
    water = volume * p_water / 100;
    alch = volume - water;
}

double Bochka::get_palch() {
    return p_alch;
}

double Bochka::get_alch() {
    return alch;
}

double Bochka::get_pwater() {
    return p_water;
}

double Bochka::get_water() {
    return water;
}

double Bochka::get_volume() {
    return volume;
}

void Bochka::set_volume(double v) {
    volume = v;
}

void Bochka::set_p_water(double p_w) {
    p_water = p_w;
}

void Bochka::set_p_alch(double p_a) {
    p_alch = p_a;
}

void Bochka::set_alch(double a) {
    alch = a;
}

void Bochka::set_water(double w) {
    water = w;
}

void Bochka::transfer(double vl, Bochka& b) {
    double p_w2 = b.get_pwater();
    double p_a2 = b.get_palch();
    double w_2 = vl * p_w2 / 100.0;
    double a_2 = vl * p_a2 / 100.0;
    water += w_2;
    alch += a_2;
    volume += vl;
    p_alch = alch * 100 / volume;
    p_water = 100 - p_alch;
    double v = b.get_volume() - vl;
    double a2 = b.get_alch() - a_2;
    double w2 = b.get_water() - w_2;
    b.set_volume(v);
    b.set_alch(a2);
    b.set_water(w2);
}


