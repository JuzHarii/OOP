#include "nguoi.h"
#include <vector>

int main(){
    vector<NV> list;
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        NV temp;
        cout << "Nhap thong tin nhan vien thu " << i + 1 << endl;
        temp.input();
        list.push_back(temp);
    }
    // in danh sach nhan vien
    for(int i = 0; i < n; i++){
        cout << "Thong tin nhan vien thu " << i + 1 << endl;
        list[i].display();
        cout << endl;
    }
    return 0;
}