#include<iostream>
#include<memory>
using namespace std;
class pointers1
{

  public:
        int num1,num2,num3=0;
        void setmethod(int a,int b)
        {
        cout<<"First_Child_Age: "<<endl;
        num1=a;
        num2=b;

        }
        pointers1 operator -(const pointers1 &obj)
        {

        shared_ptr<pointers1>temp(new pointers1);
        temp->num1=obj.num2-num1;
        return (*temp);
        }
        ~pointers1()
        {
        cout<<endl<<"Memory is deallocated"<<endl<<endl;

        }

};
int main()
{
        int Birth_Year,Present_Year,a,b;
        cin>>Birth_Year>>Present_Year;
        cout<<"Find Twins Age"<<endl<<endl;
        shared_ptr<pointers1>ptr1(new pointers1);
        cout<<"Before the local scope Ref count is: "<<ptr1.use_count()<<endl;
        ptr1->setmethod(Birth_Year,Present_Year);
        a=(*ptr1).num1;
        cout<<"Birth Year: "<<a<<endl;
        b=(*ptr1).num2;
        cout<<"Present Year: "<<b<<endl;
        (*ptr1)=(*ptr1)-(*ptr1);//after this operator overloading memory is deallocating two times becoz 
                                //it should comes out of two scope overloader scope and class scope...
        cout<<"Age: "<<(*ptr1).num1<<endl<<endl;
{

        shared_ptr<pointers1>ptr2(ptr1);
        cout<<"Second_Chile_Age:"<<endl;
        cout<<"Birth Year: "<<a<<endl;
        cout<<"Age: "<<b<<endl<<endl;
        cout<<"Reference is: "<<ptr2.use_count()<<endl<<endl;
        ptr2.reset();
        cout<<"After Reduced Ptr2:"<<ptr2.get()<<endl;
}
        cout<<"Both Child Age is similar"<<endl;
        cout<<"Ptr1 Reference after the scope is: "<<ptr1.use_count()<<endl<<endl;
        //until ref count is less than 1 object is deallocate so it invoke the destructor
        ptr1.reset(); //this line reference count is reduce to zero so after this line memory is deallocating
        cout<<"After Reduced Ptr2:"<<ptr1.get()<<endl;
        cout<<"After deallocating Reference is: "<<ptr1.use_count()<<endl<<endl;
        return 0;
}
