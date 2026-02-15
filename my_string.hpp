class MyString {
private:
    char* str;
public:
    MyString();
    MyString(const char *s);
    ~MyString();
    MyString(const MyString &s);
    MyString& operator=(const MyString &s);
    char get(int i);
    void set(int i, char c);
    void set_new_string(const char *s);
    void print();
    void read_line();
};
