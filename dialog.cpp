#include <iostream>
#include <map>
#include "signal.h"
#include "getnum.h"
#include <limits>
namespace oop3{
     void dialog() {
         std::map<std::string, signal> table;
         std::map<std::string, signal>::iterator cur;
         while (true) {
             if (table.size() > 0) {
                 std::cout << "current table is -> " ;
                 std::cout << cur->first;
             }
             std::cout << "" << std::endl;
             std::cout << "0. Выход" << std::endl;
             std::cout << "1. Создать пустой таблицу " << std::endl;
             std::cout << "2. Создать табицу с одний сигналом" << std::endl;
             std::cout << "3. Создать с ASCI" << std::endl;
             std::cout << "4. Вывод" << std::endl;
             std::cout << "5. Сложение" << std::endl;
             std::cout << "6. Смена" << std::endl;
             std::cout << "7. Сдвиг вправо " << std::endl;
             std::cout << "8. Сдвиг влево " << std::endl;
             std::cout << "9. Смена с определенного времеи" << std::endl;
             std::cout << "10. Ввод таблицы" << std::endl;

             int pt;
             pt = getNum<int>();
             if (pt < 0 || pt > 11) {
                 std::cout << "wrong number" << std::endl;
                 throw std::invalid_argument("wrong input");
                 continue;
             }
             if (pt == 0) {
                 break;
             }

             if (pt == 2) {
                 char cond;
                 std::cout << "Введи имя таблицы " << std::endl;
                 std::string name;
                 std::cin >> name;
                 std::map<std::string, signal>::iterator t1;
                 if ((t1 = table.find(name)) != table.end()) {
                     std::cout << "name is wrong" << std::endl;
                 } else {
                     std::cout << " Введите сигнал" << std::endl;
                     cond = getNum<char>();
                     std::cout << "Введите время" << std::endl;
                     int time = 0;
                     time = getNum<int>();
                     signal newsig(cond, time);
                     table.insert(make_pair(name, newsig));
                     t1 = table.find(name);
                     cur = t1;
                 }
             }


             if (pt == 3) {
                 std::cout << "Введи имя таблицы " << std::endl;
                 std::string name;
                 std::cin >> name;
                 std::map<std::string, signal>::iterator t1;
                 if ((t1 = table.find(name)) != table.end()) {
                     std::cout << "name is wrong" << std::endl;
                 } else {
                     char buf[200];
                     int j = 0;
                     std::cout << "Введите строку" << std::endl;
                     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                     for (int i = 0; i < 100 && buf[i] != '\n'; i++) {
                         buf[i] = std::getchar();
                         if (buf[i] == '\n') {
                             buf[i] = '\0';
                             break;
                         }
                     }
                     signal newsig(buf);
                     table.insert(make_pair(name, newsig));
                     t1 = table.find(name);
                     cur = t1;
                 }


             }
             if (pt == 4) {
                 std::cout << cur->second;
             }


             if (pt == 5) {
                 std::cout << "Введи имя алфавита " << std::endl;
                 std::string name;
                 std::cin >> name;
                 std::map<std::string, signal>::iterator t1;
                 if ((t1 = table.find(name)) == table.end()) {
                     std::cout << "name is wrong" << std::endl;
                 } else {
                    signal a;
                     t1->second+ cur->second;

                     std::cout << "Успех" <<std::endl;
                 }


             }

             if (pt == 1) {
                 std::cout << "Введи имя таблицы " << std::endl;
                 std::string name;
                 std::cin >> name;
                 std::map<std::string, signal>::iterator t1;
                 if ((t1 = table.find(name)) != table.end()) {
                     std::cout << "name is wrong" << std::endl;
                 } else {
                     signal newsig;
                     table.insert(make_pair(name, newsig));
                     t1 = table.find(name);
                     cur = t1;
                 }
             }

             if (pt == 6) {
                 std::cout << " Введите имя первого алфавита"<<std::endl;
                 std::string  name;
                 std::cin >> name;
                 std::map<std::string, signal>::iterator t1;
                 if ((t1 = table.find(name)) == table.end()) {
                     std::cout << "name is wrong" << std::endl;
                 }
                 else{
                     cur = t1;
                 }
             }

             if(pt == 7){
                 int time;
                 std::cout << "Введи время"<<std::endl;
                 time = getNum<int>();
                 cur->second  >>= time ;
             }


             if(pt == 8){
                 int time;
                 std::cout << "Введи время"<<std::endl;
                 time = getNum<int>();
                 cur->second  <<= time ;
                 }


             if(pt == 9){
                 std::cout << "Введи имя алфавита " << std::endl;
                 std::string  name;
                 std::cin >> name;
                 std::map<std::string, signal> ::iterator t1;
                 if((t1 = table.find(name)) == table.end()) {
                     std::cout << "name is wrong" << std::endl;
                 }
                 else{
                     int time;
                     std::cout << "Введи время"<<std::endl;
                     time = getNum<int>();
                     cur->second = cur->second.operator()(t1->second,time);
                     std::cout << cur->second;
                 }
             }
             if(pt == 10 ){
                 std::cout << "Введи имя таблицы " << std::endl;
                 std::string  name;
                 std::cin >> name;
                 std::map<std::string, signal> ::iterator t1;
                 if((t1 = table.find(name)) == table.end()) {
                     std::cout << "name is wrong" << std::endl;
                 }
                 else{
                     t1 = table.find(name);
                     std::cin >> t1->second;
                     cur = t1;
                 }
             }

         }
     }
}
