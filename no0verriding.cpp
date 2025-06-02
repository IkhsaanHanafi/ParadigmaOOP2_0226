#include <iostream>
using namespace std;

class baseClass 
{
    public:
        virtual void perkenalan() final
        (
            cout << "Hallo saya function dari base Class";
        )
};

class deriveClass : public baseClass
{
    public: 
        void perkenalan()
        (
            cout << "Hallo saya function dari derive Class";
        )
};

int main()
{
    deriveClass a;
    a.perkenalan();

    return 0;
}