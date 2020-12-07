#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;
enum Specialnist { KOMPUTERNI_NAUKY, INFORMATYKA, MATEMATYKA_TA_EKONOMIKA, PHISYKA_TA_INFORMATYKA, KIBERBEZPEKA};
string specialnistStr[] = { "КН", "інформатика", "мат&екон", "фіз&інф", "кібербезпека" };
struct Student
{
    string prizv;
    unsigned kurs;
    Specialnist specialnist;
    unsigned physics;
    unsigned math;
    unsigned informatics;
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Kilkist_otsinok(Student* p, const int N);
double five_four(Student* p, const int N);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "Введіть N: "; cin >> N;
    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);
    Kilkist_otsinok(p, N);
    five_four(p, N);
    return 0;
}
void Create(Student* p, const int N)
{
    int specialnist;

    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << " прізвище: "; getline(cin, p[i].prizv);
        cout << " курс: "; cin >> p[i].kurs;
        cout << " спеціальність (0 - комп'ютерні науки, 1 - інформатика, 2 - математика та економіка, 3 - фізика та інформатика, 4 - кібербезпека):";
        cin >> specialnist;
        cout << " оцінка з фізики: "; cin >> p[i].physics;
        cout << "оцінка з математики: "; cin >> p[i].math;
        cout << "оцінка з інформатики: "; cin >> p[i].informatics;
        p[i].specialnist = Specialnist(specialnist);
    }
}
void Print(Student* p, const int N)
{
    cout << "=========================================================================="
        << endl;
    cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Інформатика |"
        << endl;
    cout << "--------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(1) << right << i + 1 << " ";
        cout << "| " << setw(10) << left << p[i].prizv
            << "| " << setw(2) << right << p[i].kurs << " "
            << "| " << setw(15) << left << specialnistStr[p[i].specialnist]
            << "| " << setw(6) << right << p[i].physics << " "
            << "| " << setw(10) << left << p[i].math << " "
            << "| " << setw(11) << right << p[i].informatics << " " << "|";
        cout << endl;
    }
    cout << "=========================================================================="
        << endl;
    cout << endl;
}
void Kilkist_otsinok(Student* p, const int N)
{
    int k = 0;
    int m = 0;
    int t = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].physics == 3)
            k++;
        if (p[i].math == 3)
            m++;
        if (p[i].informatics == 3)
            t++;
    }
    cout << "кількість оцінок задовільно з фізики: " << k << endl;
    cout << "кількість оцінок задовільно з математики: " << m << endl;
    cout << "кількість оцінок задовільно з інформатики: " << t << endl;

}
double five_four(Student* p, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (p[i].physics == 5 || p[i].physics == 4)
            if (p[i].math == 5 || p[i].math == 4)
            {
                k++;
                cout << "Студенти, які мають 4 або 5 з математики та фізики: " << p[i].prizv << endl;
                return 0;
            }
}