/*
Задание 6. Грустное совершеннолетие
Что нужно сделать
Напишите программу для бармена, который не умеет считать.

Условие:
Посетитель пришёл в бар и попросил кружку пива.
Напишите программу для бармена, который не умеет считать, чтобы по заданной дате рождения посетителя и текущей дате определить, можно ему продавать алкоголь или нет.
Программа должна попросить ввести сегодняшнюю дату и дату рождения покупателя, после чего ответить: «можно» или «нельзя».
Учтите, что в день восемнадцатилетия алкоголь продавать посетителю ещё нельзя, а вот на следующий день после этого — уже можно.

Советы и рекомендации
• Программа должна работать с любым годом и не должна быть привязана к определённой дате.
• Постарайтесь сделать свою программу по возможности лаконичнее.
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
    cout << "Введите дату рождения (в формате - 01.01.2000): ";
    cin >> date_birth;
    cout << "Введите сегодняшюю дату (в формате - 01.01.2024): ";
    cin >> date_today;

    vector<int> date_birth_int = get_date(date_birth);
    vector<int> date_today_int = get_date(date_today);

    if (date_today_int[2] - date_birth_int[2] > 18){
        cout << "Можно" << endl;
    }
    else if (date_today_int[2] - date_birth_int[2] < 18){
        cout << "Нельзя" << endl;
    }
    else if (date_today_int[2] - date_birth_int[2] == 18){
        if (date_today_int[1] > date_birth_int[1]){
            cout << "Можно" <<  endl;
        }
        else if (date_today_int[1] < date_birth_int[1]){
            cout << "Нельзя" << endl;
        }
        else if (date_today_int[1] == date_birth_int[1]){
            if (date_today_int[0] > date_birth_int[0]){
                cout << "Можно" << endl;
            }
            else if (date_today_int[0] <= date_birth_int[0]){
                cout << "Нельзя" << endl;
            }
        }
    }
   
}