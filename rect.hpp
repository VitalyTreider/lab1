class Rect {
private:
    int c1;
    int c2;
    int c3;
    int c4;
public:
    Rect();
    Rect(int c11, int c22, int c33, int c44);
    Rect(const Rect& r);
    ~Rect();
    int get_left();
    int get_right();
    int get_top();
    int get_bottom();
    void set_all(int left, int right, int top, int bottom);
    void inflate(int amount);
    void inflate(int dw, int dh);
    void inflate(int d_left, int d_right, int d_top, int d_bottom);
    void move(int x);
    void move(int x, int y);
    int get_width();
    int get_height();
    int get_square();
    void set_width(int wd);
    void set_height(int hg);
};

Rect bounding_rect(Rect r1, Rect r2);
void print_rect(Rect& r);

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

class Matrix {
private:
    int rows;
    int cols;
    double **matrix;
public:
    Matrix(int n);
    Matrix(int m, int n, double fill_value = 0);
    Matrix(Matrix &p);
    ~Matrix();    
};
