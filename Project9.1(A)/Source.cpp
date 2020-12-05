#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>

using namespace std;

#pragma pack(push, 1)

enum Speciality { KN, IT, ME, FI ,T};
string speciality_str[] = { "KN","IT", "ME","FI", "T" };
//KN-компютерні науки(програмування), IT- інформатика(чисельні методи), ME-математика та економіка(педагогіка)
//FI- фізика та інформатика(педагогіка), T-трудове навчання(педагогіка)
struct Students
{
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
    int grade_IT;

};

#pragma pack(pop)

void Create(Students* S, const int N);
double Avarage_marks(Students* S, const int i);
void Print(Students* S, const int N);
double Percentage_4or5(Students* S, const int N);
void Print_first(Students* S, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: "; cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print_first(S, N);
    Print(S, N);
    cout << "Процент студентів, які мають 5 або 4 з фізики: " << setprecision(2) << Percentage_4or5(S, N) << "%";

    return 0;
}
void Create(Students* S, const int N)
{
    for (int i = 0; i < N; i++)
    {
        int speciality;
        cout << "Номер студента: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "Прізвище: "; getline(cin, S[i].surname); cout << endl;
        cout << "Курс: "; cin >> S[i].course; cout << endl;
        cout << "Спеціальність(0 - KN, 1 - IT, 2 - ME,";
        cout << "\n3 - FI, 4 - T): ";
        cin >> speciality;
        S[i].speciality = (Speciality)speciality;
        cout << "Оцінка з фізики: "; cin >> S[i].grade_physics; cout << endl;
        cout << "Оцінка з математики: "; cin >> S[i].grade_math; cout << endl;
        cout << "Оцінка з інформатики: "; cin >> S[i].grade_IT; cout << endl;
        cout << endl;
    }

}
double Avarage_marks(Students* S, const int i)
{
    return (S[i].grade_math * 1. + S[i].grade_physics * 1. + S[i].grade_IT * 1.) / 3.;
}
void Print_first(Students* S, const int N)
{
    cout << "=========================================================================================" << endl;
    cout << "|  №  | Прізвище |  Курс  |  Спеціальність  |  Фізика  |  Математика  |  Інформатика  |" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(4) << S[i].surname << setw(7);
        cout << "|" << setw(5) << S[i].course << setw(5);
        cout << "|" << setw(9) << speciality_str[S[i].speciality] << setw(9);
        cout << "|" << setw(6) << S[i].grade_physics << setw(6);
        cout << "|" << setw(6) << S[i].grade_math << setw(6);
        cout << "|" << setw(6) << S[i].grade_IT << setw(6) << "|" << endl;
    }
    cout << "=========================================================================================" << endl << endl;
}
void Print(Students* S, const int N)
{
    cout << fixed;
    cout << "=====================================" << endl;
    cout << "|  №  |  Прізвище  |  Середній бал  |" << endl;
    cout << "-------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(5) << S[i].surname << setw(4);
        cout << "|" << setw(7) <<  setprecision(2) << Avarage_marks(S, i) << setw(8) << "|";
        cout << endl;
    }
    cout << "=====================================" << endl;
}
double Percentage_4or5(Students* S, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (S[i].grade_physics == 5 || S[i].grade_physics == 4)
            k++;
    return k / (N * 1.0) * 100;
}