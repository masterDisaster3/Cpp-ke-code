#include <iostream>



class A{
    int a, b;

    public: 
    A(int a, int b): a(a), b(b){}

    int sum(){
        std::cout<<"A wala add hora hai \n";
        return this->a + this->b;
    }
};

class B : public A{
    public:
    B(int ab, int bb) : A(ab, bb){}

    int sum(){
        std::cout<<"A ke sath B wala add hora hai \n";
        return A::sum() + 10;
    }
};

int main(){

    B* child = new B(1, 2);

    std::cout<<child->sum()<<std::endl;


    A* childA = new A(3, 4);

    std::cout<<childA->sum();

}