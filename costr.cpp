#include<iostream>
using namespace std;
class tit {
    public:
    tit(string s,string n,string sal) {
        name=n;
        salary=sal;
        subject=s;
    }

        string name;
        string salary;
        string subject;

        void getinfo() {
            cout<<"name:"<<name<<endl;
            cout<<"subject"<<subject<<endl;
            cout<<"salary"<<salary<<endl;
        }
    };
    int main() {
        tit t1("harshada","cs","250000");
        t1.getinfo();
        return 0;
    }