#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include  "BinaryTree.h"
using namespace std;

int main() {

    setlocale(LC_ALL, "Turkish");

    const int sehirSayisi = 81;
    string dataSehir[sehirSayisi][2]; // �ehir verilerini tutacak iki boyutlu dizi
    int cityCount = 0; // Toplam �ehir say�s�

    ifstream inputFile("sehir_plaka_kodlari.txt");

    if (!inputFile) {
        cerr << "Dosya a��lamad�." << endl;
        return 1;
    }

    string line;

    while (getline(inputFile, line)) {
        string sehir�smi, plakaKodu;

        size_t pos = line.find(',');
        if (pos != string::npos) {
            sehir�smi = line.substr(0, pos);
            plakaKodu = line.substr(pos + 1);
            dataSehir[cityCount][0] = plakaKodu;
            dataSehir[cityCount][1] = sehir�smi;
            cityCount++;

            if (cityCount >= sehirSayisi) {
                cerr << "Maksimum �ehir say�s�na ula��ld�." << endl;
                break;
            }
        }
    }
    inputFile.close();

    // Plaka kodlar�yla ikili a�a� olu�turm
    TreeNode* root = nullptr;
    for (int i = 0; i < cityCount; i++) {
        �nsert(root, dataSehir[i][1]);
    }

    cout << "A�ac�n G�r�nt�s�:" << endl;
    display(root);

    cout << endl;
    int depth = treeDepth(root);
    cout << "A�ac�n Derinli�i: " << depth << endl;
    bool balanced = isBalanced(root);
    cout << "A�ac�n Dengeli Olup Olmad���: " << (balanced ? "Dengeli" : "Dengeli De�il") << endl;
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
        cout << "1. Plaka Kodu: " << plaka1 << " �ehir �smi : " << node1->cityName << " D�zey Fark� : " << abs(level1 - level2) << endl;
        cout << "2. Plaka Kodu: " << plaka2 << " �ehir �smi: " << node2->cityName << " D�zey Fark�: " << abs(level1 - level2) << endl;
    }
    else {
        cout << "Plaka kodlar� ge�ersiz." << endl;
    }

    cout << endl;

    cout << "Preorder S�ralama: ";
    preorder(root);
    cout << endl;

    cout << "Inorder S�ralama: ";
    inorder(root);
    cout << endl;

    cout << "Postorder S�ralama: ";
    postorder(root);
    cout << endl;
}
