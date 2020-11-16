#include "signal.h"
#include <cmath>
#include <iostream>

namespace oop3 {
    signal::signal() {
        this->num_of_signals = 0;
         this->max_time =0;

    }

  signal::signal(unsigned char signal,int mtime) {
      this->max_time = mtime  ;
      this->num_of_signals =1;
      if (check((int)signal)) {
          this->signals[num_of_signals].signal = (int) signal;
          this->signals[num_of_signals].time = this->max_time; //сигнал один и  определен на всем времени
      }
      else
          throw std::invalid_argument("invalid signal!");
  }

    signal::signal(char *buf) {
        this->num_of_signals = 0;
        int mtime = 0;
        int s = 0;
        int i = 0;
        while (buf[i] != '\0') {
            this->num_of_signals += 1;

            s = (10 * (buf[i] - '0')) + (buf[i + 1] - '0');
            i = i + 2;
            if (buf[i] != ' ' && buf[i] != '\0') {
               throw std::invalid_argument("wrong signal detected");
            }

            if (!check(s)) {
                throw std::invalid_argument("invalid signal!");
        }
        this->signals[this->num_of_signals].signal = s;
        i++;
        int j = 0;
        while (buf[i] != ' ' && buf[i] != '\0') {
            i++;
            j++;
        }
            this->signals[this->num_of_signals].time = 0;
            while (j > 1) {
            int time[2];
            time[0] = (buf[i - j] - '0');
            time[1] = buf[i-(j-1)] - '0';
            int t = (10 * time[0]) + (time[1]);
            this->signals[this->num_of_signals].time += pow(10,(j-1)/2) * (t -48);
            j = j-2;

        }

        mtime += this->signals[this->num_of_signals].time;
        i++;
    }
        this->max_time = mtime;
    }

int check(int sig){
      if((sig == 48) || (sig == 49) || (sig == 88))
          return 1;
      else
          return 0;
    }


    std::ostream& operator << (std::ostream& out, const signal& sig) {

        for (int i = 1; i <= sig.num_of_signals; i++) {
            out << "Signal - > ";
            out << (char)sig.signals[i].signal;
            out << " time = ";
            out << sig.signals[i].time;
            out << "\n";
        }
        out << "max time  = " ;
        out <<sig.max_time;
        out << "\n";
        out << "number of  = " ;
        out << sig.num_of_signals;
        out << "\n";

        return out;

    }




    int operator + ( signal& tab, signal &tab2){
    if((tab2.num_of_signals + tab.num_of_signals) < 100){
            int j = 1;
            for(int i = tab2.num_of_signals +1; j <= tab.num_of_signals; i++){
                tab2.signals[i].signal = tab.signals[j].signal;
                tab2.signals[i].time = tab.signals[j].time;
                j++;
            }
           tab2.max_time += tab.max_time;
           tab2.num_of_signals +=tab.num_of_signals;
            return 1 ;
        }
        else{
            throw std::invalid_argument("overflow");
        }
    }

    signal &signal::operator()(signal &tab, int t) {
        if (t > this->max_time) {
             throw std::invalid_argument("wrong time");
        }
        if (t > tab.max_time)
            throw std::invalid_argument("wrong time");
        int that= 0;
        int after = 0;
        int time = 0;
        for (int i = 1; time <= t; i++) {
           time += this->signals[i].time;
           that = i;
        }
        this->signals[that].time= this->signals[that].time -(time - t);
        int that2 =0;
        int time2 =0;
        for (int i = 1; time2 <= t; i++) {
            time2 += tab.signals[i].time;
            that2 = i;
        }
        tab.signals[that2].time = time2 - t;
        this->signals[that + 1].signal = tab.signals[that2].signal;
        this->signals[that + 1].time = tab.signals[that2].time;
        int newtime = this->max_time - t;
        for (int i = 1; i < tab.num_of_signals - that2; i++) {
            that = that +1;
            this->signals[that].signal = tab.signals[that2 + i].signal;
            this->signals[that].time = tab.signals[that2 + i].time;
            newtime += tab.signals[that+i].time;
            this->num_of_signals++;
        }
        return tab;
    }

    signal &signal::operator>>=(int t) {
        if (t > this->max_time) {
            throw std::invalid_argument("wrong time");
        }

        else{
            int that= 0;
            int time = 0;
            for (int i = 1; time <= t; i++) {
                time += this->signals[i].time;
                that = i;
            }
            int that2 = that;
            this->signals[1].signal = this->signals[that].signal;
            this->signals[1].time = time -t;
            for (int i = 2; i <= this->num_of_signals ; i++) {
                that++;
                this->signals[i].signal = this->signals[that].signal;
                this->signals[i].time = this->signals[that].time;
            }
            this->num_of_signals = this->num_of_signals - (that2-1);
            this->max_time = max_time - t;
        }
        return *this;
    }

    signal &signal::operator<<=(int t) {
        if (t > this->max_time) {
            throw std::invalid_argument("wrong time");
        }
        int t2 = t;
        t= this->max_time - t;
        int time =0;
        int that =0;
        for (int i = 1; time <= t; i++) {
            time += this->signals[i].time;
            that = i;
        }

        this->signals[that].time = this->signals[that].time -  t2;
        this->max_time = t;
        this->num_of_signals = that;
        return *this;
    }








    std::istream& operator >> (std::istream& in, signal& alf) {
        std::cout << "Введите колличество элементов"<<std::endl;
        int num;
        int mtime =0 ;
        in >> num;
        if (num < 1 || num> 100) {
            throw std::invalid_argument("invalid number!");
        }
        std::cout << "Введите сигнал"<<std::endl;
        for (int i = 1; i <= num; i++) {
            std::cout << "Введите сигнал н. "<< i << std::endl;
            unsigned char signal;
            in >> signal;
            if( !check(int(signal))){
                 throw std::invalid_argument("invalid signal!");
             }

             else {
                alf.signals[i].signal = (int)signal;
                std::cout << "Введите время  сигнала "<< i << std::endl;
                in >> alf.signals[i].time;
                if (alf.signals[i].time < 0){
                    throw std::invalid_argument("invalid time!");
                }
                mtime += alf.signals[i].time;

             }

             }
         alf.max_time = mtime;
         alf.num_of_signals = num;
        return in;
    }









}