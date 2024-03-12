#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class CauhoiTN {
private:
    string content;
    string options[3];
    char correctAnswer;

public:
    void nhap() {
        cout << "Nhap noi dung cau hoi: ";
        cin.ignore(); 
        getline(cin, content);
        cout << "Nhap lua chon A: ";
        getline(cin, options[0]);
        cout << "Nhap lua chon B: ";
        getline(cin, options[1]);
        cout << "Nhap lua chon C: ";
        getline(cin, options[2]);
        cout << "Nhap dap an dung (A/B/C): ";
        cin >> correctAnswer;
        correctAnswer = toupper(correctAnswer);
    }

    void docfile(ifstream& f) {
        getline(f, content);
        getline(f, options[0]);
        getline(f, options[1]);
        getline(f, options[2]);
        f >> correctAnswer;
    }

    void ghifile(ofstream& f) {
        f << content << endl;
        f << options[0] << endl;
        f << options[1] << endl;
        f << options[2] << endl;
        f << correctAnswer << endl;
    }

    void kiemtra() {
        cout << content << endl;
        cout << "A. " << options[0] << endl;
        cout << "B. " << options[1] << endl;
        cout << "C. " << options[2] << endl;

        char response;
        cout << "Dap an cua ban la (A/B/C): ";
        cin >> response;
        response = toupper(response);
        if (response == correctAnswer) {
            cout << "Dung!" << endl;
        }
        else {
            cout << "Sai!" << endl;
        }
    }

    void xuat() {
        cout << content << endl;
        cout << "A. " << options[0] << endl;
        cout << "B. " << options[1] << endl;
        cout << "C. " << options[2] << endl;
        cout << "Dap an dung la: " << correctAnswer << endl;
    }

    friend bool giongnhau(CauhoiTN cau1, CauhoiTN cau2);
};

bool giongnhau(CauhoiTN cau1, CauhoiTN cau2) {
    if (cau1.content == cau2.content && cau1.options[0] == cau2.options[0] && cau1.options[1] == cau2.options[1] && cau1.options[2] == cau2.options[2] && cau1.correctAnswer == cau2.correctAnswer) {
        return true;
    }
    return false;
}

void menu() {
    cout << "     Xin chao! Chuc mot ngay moi tot lanh va may man.       " << endl;
    cout << "     Duoc viet boi SV 2251150052 - DANG VU THANH DUOC.      " << endl;
    cout << "************************************************************" << endl;
    cout << "*             CHAO MUNG DEN VOI CHUONG TRINH               *" << endl;
    cout << "* Vui long chon cac thao tac mong muon ben duoi            *" << endl;
    cout << "* 1. Them cau hoi.                                         *" << endl;
    cout << "* 2. Doc cau hoi tu File.                                  *" << endl;
    cout << "* 3. Ghi cau hoi vao File.                                 *" << endl;
    cout << "* 4. Kiem tra cau hoi sau thay doi.                        *" << endl;
    cout << "* 5. Xuat cau hoi.                                         *" << endl;
    cout << "* 6. Kiem tra hai cau hoi co giong nhau.                   *" << endl;
    cout << "* 0. Thoat chuong trinh.                                   *" << endl;
    cout << "* **********************************************************" << endl;

}

int main() {
  CauhoiTN cauhoi;
  int choice;
  ifstream inputFile;
  ofstream outputFile;

  do {
    menu();
    cout << "Nhap lua chon cua ban: ";
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "Nhap thong tin cau hoi:" << endl;
        cauhoi.nhap();
        break;
      case 2:
        inputFile.open("cauhoi.txt");
        if (!inputFile.is_open()) {
          cout << "Khong mo duoc file!" << endl;
        }
        break;
      // ... other cases ...
    }
  } while (choice != 0);

  return 0;
}

