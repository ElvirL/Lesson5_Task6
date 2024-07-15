/*
������� 6. �������� ���������������
��� ����� �������
�������� ��������� ��� �������, ������� �� ����� �������.

�������:
���������� ������ � ��� � �������� ������ ����.
�������� ��������� ��� �������, ������� �� ����� �������, ����� �� �������� ���� �������� ���������� � ������� ���� ����������, 
����� ��� ��������� �������� ��� ���.
��������� ������ ��������� ������ ����������� ���� � ���� �������� ����������, ����� ���� ��������: ������ ��� ��������.
������, ��� � ���� ����������������� �������� ��������� ���������� ��� ������, � ��� �� ��������� ���� ����� ����� � ��� �����.

������ � ������������
� ��������� ������ �������� � ����� ����� � �� ������ ���� ��������� � ����������� ����.
� ������������ ������� ���� ��������� �� ����������� ����������.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> get_date(const string& string_date){
    vector<int> v;
    string day_year;

    for (char elem: string_date){
        if (elem != '.'){
            day_year+=elem;
        }
        else {
            if (day_year[0] != '0'){
                v.push_back(static_cast<int>(day_year[0]) *10 + static_cast<int>(day_year[1]));
            } 
            else{
                v.push_back(static_cast<int>(static_cast<int>(day_year[1])));
            }
             day_year.clear();
        }
    }
    v.push_back(static_cast<int>(day_year[0])*1000 + static_cast<int>(day_year[1])*100 + static_cast<int>(day_year[2])*10 + static_cast<int>(day_year[3]));
    return v;
}

int main(){
    setlocale(LC_ALL, "Russian");
    string date_birth, date_today;
    cout << "������� ���� �������� (� ������� - 01.01.2000): ";
    cin >> date_birth;
    cout << "������� ����������� ���� (� ������� - 01.01.2024): ";
    cin >> date_today;

    vector<int> date_birth_int = get_date(date_birth);
    vector<int> date_today_int = get_date(date_today);

    if (date_today_int[2] - date_birth_int[2] > 18){
        cout << "�����" << endl;
    }
    else if (date_today_int[2] - date_birth_int[2] < 18){
        cout << "������" << endl;
    }
    else if (date_today_int[2] - date_birth_int[2] == 18){
        if (date_today_int[1] > date_birth_int[1]){
            cout << "�����" <<  endl;
        }
        else if (date_today_int[1] < date_birth_int[1]){
            cout << "������" << endl;
        }
        else if (date_today_int[1] == date_birth_int[1]){
            if (date_today_int[0] > date_birth_int[0]){
                cout << "�����" << endl;
            }
            else if (date_today_int[0] <= date_birth_int[0]){
                cout << "������" << endl;
            }
        }
    }
   
}