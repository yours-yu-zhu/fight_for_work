#include <iostream>
#include <string>

using namespace std;

class Screen {
    public:
        using pos = std::string::size_type;
        inline Screen& move(pos r, pos c);
        inline Screen& set(char c);
        inline Screen& set(pos r, pos c, char ch);

        const Screen& display(std::ostream &os) const { do_display(os); return *this; }
        Screen& display(std::ostream &os) { do_display(os); return *this; }
        Screen() = default; // 1
        Screen(pos ht, pos wd):height(ht), width(wd), contents(ht*wd, ' '){ } // 2
        Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){ } // 3

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r*width+c]; }

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
        void do_display(std::ostream &os) const { os << contents; }
};

inline Screen& Screen::move(pos r, pos c)
{
    cursor = r*width + c;
    return *this;
}

inline Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
    contents[r*width+c] = ch;
    return *this;
}

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";

    return 0;
}