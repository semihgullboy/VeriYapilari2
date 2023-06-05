#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include  "BinaryTree.h"
using namespace std;

int main() {

    setlocale(LC_ALL, "Turkish");

    const int sehirSayisi = 81;
    string dataSehir[sehirSayisi][2]; // Þehir verilerini tutacak iki boyutlu dizi
    int cityCount = 0; // Toplam þehir sayýsý

    ifstream inputFile("sehir_plaka_kodlari.txt");

    if (!inputFile) {
        cerr << "Dosya açýlamadý." << endl;
        return 1;
    }

    string line;

    while (getline(inputFile, line)) {
        string sehirÝsmi, plakaKodu;

        size_t pos = line.find(',');
        if (pos != string::npos) {
            sehirÝsmi = line.substr(0, pos);
            plakaKodu = line.substr(pos + 1);
            dataSehir[cityCount][0] = plakaKodu;
            dataSehir[cityCount][1] = sehirÝsmi;
            cityCount++;

            if (cityCount >= sehirSayisi) {
                cerr << "Maksimum þehir sayýsýna ulaþýldý." << endl;
                break;
            }
        }
    }
    inputFile.close();

    // Plaka kodlarýyla ikili aðaç oluþturm
    TreeNode* root = nullptr;
    for (int i = 0; i < cityCount; i++) {
        ýnsert(root, dataSehir[i][1]);
    }

    cout << "Aðacýn Görüntüsü:" << endl;
    display(root);

    cout << endl;
    int depth = treeDepth(root);
    cout << "Aðacýn Derinliði: " << depth << endl;
    bool balanced = isBalanced(root);
    cout << "Aðacýn Dengeli Olup Olmadýðý: " << (balanced ? "Dengeli" : "Dengeli Deðil") << endl;
    cout << endl;

    string plaka1, plaka2;
    cout << "Aranacak 1. Plaka Kodunu Girin: ";
    cin >> plaka1;
    cout << "Aranacak 2. Plaka Kodunu Girin: ";
    cin >> plaka2;

    TreeNode* node1 = search(root, plaka1);
    TreeNode* node2 = search(root, plaka2);

    if (node1 != nullptr && node2 != nullptr) {
        int level1 = getLevel(root, plaka1, 0);
        int level2 = getLevel(root, plaka2, 0);

        cout << endl;
        cout << "1. Plaka Kodu: " << plaka1 << " Þehir Ýsmi : " << node1->cityName << " Düzey Farký : " << abs(level1 - level2) << endl;
        cout << "2. Plaka Kodu: " << plaka2 << " Þehir Ýsmi: " << node2->cityName << " Düzey Farký: " << abs(level1 - level2) << endl;
    }
    else {
        cout << "Plaka kodlarý geçersiz." << endl;
    }

    cout << endl;

    cout << "Preorder Sýralama: ";
    preorder(root);
    cout << endl;

    cout << "Inorder Sýralama: ";
    inorder(root);
    cout << endl;

    cout << "Postorder Sýralama: ";
    postorder(root);
    cout << endl;
}
