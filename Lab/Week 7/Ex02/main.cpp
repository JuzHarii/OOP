#include "soPhuc.h"

int main(){
    SP1 s1;
    s1.input();
    s1.display();
    cout << endl;
    SP1 s2;
    s2.input();
    s2.display();
    cout << endl;
    cout << "----------------" << endl;
    SP2 s3;
    SP2 s4;
    cout << "Nhap so phuc 1: " << endl;
    cin >> s3;
    cout << "Nhap so phuc 2: " << endl;
    cin >> s4;

    // em dung if ma khong dung else if la de het de kiem tra nhieu phep so sanh khac nhau
    if(s3 == s4){
        cout << "Hai so phuc bang nhau" << endl;
    }
    if(s3 != s4){
        cout << "Hai so phuc khac nhau" << endl;
    }
    if(s3 > s4){
        cout << "So phuc 1 lon hon so phuc 2" << endl;
    }
    if(s3 < s4){
        cout << "So phuc 1 nho hon so phuc 2" << endl;
    }
    if(s3 >= s4){
        cout << "So phuc 1 lon hon hoac bang so phuc 2" << endl;
    }
    if(s3 <= s4){
        cout << "So phuc 1 nho hon hoac bang so phuc 2" << endl;
    }

    cout << "Phep cong: " << s3 + s4 << endl;
    cout << "Phep tru: " << s3 - s4 << endl;
    cout << "Phep nhan: " << s3 * s4 << endl;
    cout << "Phep chia: " << s3 / s4 << endl;
    return 0;
}