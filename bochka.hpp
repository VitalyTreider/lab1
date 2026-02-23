class Bochka {
private:
    double volume;
    double p_water;
    double p_alch;
    double water;
    double alch;
public:
    Bochka();
    Bochka(double vol, double p_a);
    double get_palch();
    double get_pwater();
    double get_volume();
    double get_alch();
    double get_water();
    void set_p_water(double p_w);
    void set_p_alch(double p_a);
    void set_volume(double v);
    void set_alch(double a);
    void set_water(double w);
    void transfer(double vl, Bochka& b);
};


