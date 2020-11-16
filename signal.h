#include <string>
namespace oop3 {
      struct sig{
          int signal;
          int time;
      };
    class signal {
    private:
       struct sig signals[100];
       int max_time;
       int num_of_signals;
    public:
        signal();
        signal(unsigned char,int);
        signal( char *);
        friend std::ostream& operator << (std::ostream& out, const signal& ) ;
        friend int operator + ( signal& , signal&);
        signal &operator()(signal&, int);
        signal &operator>>=( int);
        signal &operator<<=( int);
        friend std::istream& operator >> (std::istream& in, signal& ) ;

    };
    int check(int);

}

