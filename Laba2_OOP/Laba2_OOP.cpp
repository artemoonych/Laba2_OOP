#include <iostream>
#include <string>

class Line {
protected:
    std::string str;

public:
    Line() {};
    Line(std::string s) : str(s) {};
    ~Line() {};

    Line operator+(Line a) {
        return *this;
    }

    Line operator-(Line a) {
        return *this;
    }

    void print() {
        std::cout << str << "\n";
    }
};

class Integer : public Line {

public:
    Integer() {};
    Integer(std::string s) {
        str = s;
    };
    ~Integer() {};

    Integer operator+(Integer a) {
        std::string s;
        int temp = 0;
        int i = str.size() - 1;
        int j = a.str.size() - 1;
        while ( i >= 0 || j >= 0) {
            if (i >= 0) {
                if (j >= 0) {
                    if ((str[i] - '0') + (a.str[j] - '0') + temp > 9) {
                        s.push_back(static_cast<char>(((str[i] - '0') + (a.str[j] - '0') + temp) % 10 + '0'));
                        temp = 1;
                    }
                    else {
                        s.push_back(str[i] + (a.str[j] - '0') + temp);
                        temp = 0;
                    }
                }
                else {
                    s.push_back(str[i] + temp);
                    temp = 0;
                }
            }
            else {
                s.push_back(a.str[j] + temp);
                temp = 0;
            }
            i--;
            j--;
            
        }
        if (temp) {
            s.push_back('1');
        }
        std::reverse(s.begin(), s.end());
        this->str = s;
        return *this;
    }

    Integer operator-(Integer a) {
        std::string s;
        int temp = 0;
        int i = str.size() - 1;
        int j = a.str.size() - 1;

        while (i >= 0 || j >= 0) {
            if (i >= 0) {
                if (j >= 0) {
                    if ((str[i] - '0') - (a.str[j] - '0') - temp < 0) {
                        s.push_back(static_cast<char>((str[i] + 10) - (a.str[j] - '0') - temp));
                        temp = 1;
                    }
                    else {
                        s.push_back(str[i] - (a.str[j] - '0') - temp);
                        temp = 0;
                    }
                }
                else {
                    s.push_back(str[i] - temp);
                    temp = 0;
                }
            }
            else {
                s.push_back(10 + '0' - (a.str[j] - '0') - temp);
                temp = 1;
            }
            i--;
            j--;

        }
        if (temp) {
            std::string k;
            k.push_back(10 + '0' - (s[0] - '0'));
            for (int i = 1; i < a.str.size(); i++) {
                k.push_back('9' - (s[i] - '0'));
            }
            s = k;
            s.push_back('-');
        }
        std::reverse(s.begin(), s.end());
        this->str = s;
        return *this;
    }
};

class Row : public Line {

public:
    Row() {};
    Row(std::string s) {
        str = s;
    };
    ~Row() {};

    Row operator+(Row a) {
        this->str = this->str + a.str;
        return *this;
    }

    Row operator-(Row a) {
        int i = 0;
        while ( i < a.str.size()) {
            int j = 0;
            while (j < this->str.size()) {
                if (this->str[j] == a.str[i]) {
                    this->str.erase(j, 1);
                    break;
                }
                j++;
            }
            i++;
        }
        return *this;
    }  
};


int main()
{
    setlocale(LC_ALL, "RU");
    std::string as, bs;
    std::cout << "Введите строки :";
    std::cin >> as >> bs;
    Row a(as), b(bs);
    Row c = a + b;
    c.print();
    Row c1 = a - b;
    c1.print();

    std::string ah, bh;
    std::cout << "Введите инты  :";
    std::cin >> ah >> bh;
    Integer ai(ah), bi(bh);
    Integer c2 = ai + bi;
    c2.print();
    Integer c3 = ai - bi;
    c3.print();
}