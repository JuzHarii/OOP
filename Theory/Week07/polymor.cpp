#include <iostream >

using namespace std;

class Fish {
public:
    void Swim() {
    cout << "Fish swims!" << endl;
    }
};

class Tuna:public Fish {
public:
// override Fish::Swim
    void Swim() {
    cout << "Tuna swims!" << endl;
    }
};

// InputFish đang được gọi theo giao diện/interface của lớp base
// Đó gọi là
void MakeFishSwim(Fish& InputFish) {
    // calling Fish::Swim
    InputFish.Swim();
}
// Phụ thuộc vào "Tuna&"
void MakeFishSwim(Tuna& InputFish){
    InputFish.Swim();
}

// ? How to avoid it?
// ! We use "virtual function"


int main() {
    Tuna myDinner;
    // calling Tuna::Swim
    myDinner.Swim();
    // sending Tuna as Fish
    MakeFishSwim(myDinner);
    return 0;
}