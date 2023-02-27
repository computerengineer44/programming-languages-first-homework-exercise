//Bu�ra Enhar Elbir 02200201072    �rg�n ��retim
#include<bits/stdc++.h>
using namespace std;

//Toplam Fonksiyonu Yazıldı
string toplamiBul(string birinciSayi, string ikinciSayi)
{
    if (birinciSayi.length() > ikinciSayi.length())
        swap(birinciSayi, ikinciSayi);
    string str = "";


    int n1 = birinciSayi.length(), n2 = ikinciSayi.length();

    reverse(birinciSayi.begin(), birinciSayi.end());
    reverse(ikinciSayi.begin(), ikinciSayi.end());

    int geciciEleman = 0;
    for (int i=0; i<n1; i++)
    {

        int sum = ((birinciSayi[i] - '0') + (ikinciSayi[i] - '0') + geciciEleman);
        str.push_back(sum%10 + '0');

        geciciEleman = sum / 10;
    }


    for (int i=n1; i<n2; i++)
    {
        int sum = ((ikinciSayi[i] - '0') + geciciEleman);
        str.push_back(sum%10 + '0');
        geciciEleman = sum / 10;
    }


    if (geciciEleman)
        str.push_back(geciciEleman + '0');

    reverse(str.begin(), str.end());

    return str;
}
//Negatif değer sonucu yazdırmamak adına girilen sayılardan büyüklük küçüklük kıyası yapıldı

bool kucukSayiyiBul(string birinciSayi, string ikinciSayi)
{

    int n1 = birinciSayi.length(), n2 = ikinciSayi.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (birinciSayi[i] < ikinciSayi[i])
            return true;
        else if (birinciSayi[i] > ikinciSayi[i])
            return false;

    return false;
}
//Fark fonksiyonu yazıldı
string sayilariCikar(string birinciSayi, string ikinciSayi)
{

    if (kucukSayiyiBul(birinciSayi, ikinciSayi))
        swap(birinciSayi, ikinciSayi);

    string str = "";

    int n1 = birinciSayi.length(), n2 = ikinciSayi.length();

    reverse(birinciSayi.begin(), birinciSayi.end());
    reverse(ikinciSayi.begin(), ikinciSayi.end());

    int geciciEleman = 0;


    for (int i = 0; i < n2; i++) {

        int cikan
                = ((birinciSayi[i] - '0') - (ikinciSayi[i] - '0') - geciciEleman);

        if (cikan < 0) {
            cikan = cikan + 10;
            geciciEleman = 1;
        }
        else
            geciciEleman = 0;

        str.push_back(cikan + '0');
    }


    for (int i = n2; i < n1; i++) {
        int cikan = ((birinciSayi[i] - '0') - geciciEleman);


        if (cikan < 0) {
            cikan = cikan + 10;
            geciciEleman = 1;
        }
        else
            geciciEleman = 0;

        str.push_back(cikan + '0');
    }

    reverse(str.begin(), str.end());

    return str;
}
//Çarpım fonksiyonu yazıldı
string sayilariCarp(string birinciSayi, string ikinciSayi)
{
    int len1 = birinciSayi.size();
    int len2 = ikinciSayi.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    vector<int> sonuc(len1 + len2, 0);

    int gecici_n1 = 0;
    int gecici_n2 = 0;

    for (int i=len1-1; i>=0; i--)
    {
        int geciciEleman = 0;
        int n1 = birinciSayi[i] - '0';


        gecici_n2 = 0;


        for (int j=len2-1; j>=0; j--)
        {

            int n2 = ikinciSayi[j] - '0';


            int toplam = n1 * n2 + sonuc[gecici_n1 + gecici_n2] + geciciEleman;

            geciciEleman = toplam / 10;

            sonuc[gecici_n1 + gecici_n2] = toplam % 10;

            gecici_n2++;
        }

        if (geciciEleman > 0)
            sonuc[gecici_n1 + gecici_n2] += geciciEleman;


        gecici_n1++;
    }

    int i = sonuc.size() - 1;
    while (i>=0 && sonuc[i] == 0)
        i--;


    if (i == -1)
        return "0";


    string s = "";

    while (i >= 0)
        s += std::to_string(sonuc[i--]);

    return s;
}

int main()
{
    string birinciSayi;
    string ikinciSayi;
    int secim;

    cout<<"Lutfen ilk sayiyi giriniz: ";
    cin >> birinciSayi;
    cout<<"Lutfen ikinci sayiyi giriniz: ";
    cin >> ikinciSayi;
    cout<<"Lutfen yapmak istediginiz islemi secin\n"
          "1.Toplama\n"
          "2.Cikarma\n"
          "3.Carpma\n";
    cin>>secim;
    if(secim==1) {
        string s1 = toplamiBul(birinciSayi, ikinciSayi);
        int uzunluk = 0;
        for(int i = 0; s1[i]  != '\0'; i++)
            uzunluk++;
        for(int i = 0; i < uzunluk; i++) {
            cout << s1[i] << " ";
        }
    }
    else if(secim==2) {
        string s1 = sayilariCikar(birinciSayi, ikinciSayi);
        int uzunluk = 0;
        for(int i = 0; s1[i]  != '\0'; i++)
            uzunluk++;
        for(int i = 0; i < uzunluk; i++) {
            cout << s1[i] << " ";
        }
    }
    else if(secim==3) {
        if((birinciSayi.at(0) == '-' || ikinciSayi.at(0) == '-') &&
           (birinciSayi.at(0) != '-' || ikinciSayi.at(0) != '-' ))
            cout<<"-";


        if(birinciSayi.at(0) == '-')
            birinciSayi = birinciSayi.substr(1);

        if(ikinciSayi.at(0) == '-')
            ikinciSayi = ikinciSayi.substr(1);

        string s1 = sayilariCarp(birinciSayi, ikinciSayi);
        int uzunluk = 0;
        for(int i = 0; s1[i]  != '\0'; i++)
            uzunluk++;
        for(int i = 0; i < uzunluk; i++) {
            cout << s1[i] << " ";
        }
    }
    else {
        cout<<"Gecersiz islem";
    }


    return 0;
}


