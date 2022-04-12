#include<iostream>
#include<memory>
using namespace std;
class pointer
{
    int *num1,*num2;//pointer only declares
    public:
    pointer()
    {
        *num1=0;
        *num2=0;
    }

    pointer(int *n1,int *n2);
    ~pointer()
    {
        delete num1,num2;
        cout<<"Destructor Called";
    }

};
pointer::pointer(int *n1,int *n2)
    {
        num1=n1;
        num2=n2;
        cout<<"Global Parameterized Constructor"<<endl;
        cout<<*num1<<" "<<*num2<<endl;
    }

int main()
{
    pointer ptr (new int(33),new int(55));

    return 0;
}
