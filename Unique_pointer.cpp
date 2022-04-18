#include<iostream>
#include<memory>
using namespace std;
class pointers1
{

public:
    int num1,num2;
    void setmethod(int a,int b)
    {
        cout<<"First_Child_Age: "<<endl;
        num1=a;
        num2=b;
    }
    pointers1 operator -(const pointers1 &obj)
    {
        pointers1 temp;
        temp.num1=obj.num2-num1-1;
        return temp;
    }

};
int main()
{
        int Birth_Year,Present_Year;
        cin>>Birth_Year>>Present_Year;
        cout<<"Find Twins Age"<<endl<<endl;
        unique_ptr<pointers1>ptr1(new pointers1);
        // cout<<ptr1.get();
        ptr1->setmethod(Birth_Year,Present_Year);
        cout<<"Birth Year: "<<(*ptr1).num1<<endl;
        cout<<"Present Year: "<<(*ptr1).num2<<endl;
        (*ptr1)=(*ptr1)-(*ptr1);
        cout<<"Age: "<<(*ptr1).num1<<endl<<endl;

        unique_ptr<pointers1>ptr2=move(ptr1);
        cout<<"Second_Chile_Age:"<<endl;
        cout<<"Birth Year: "<<(*ptr2).num1<<endl;
        cout<<"Age: "<<(*ptr2).num1<<endl<<endl;

        cout<<"Both Child Age is similar"<<endl;
return 0;
}
