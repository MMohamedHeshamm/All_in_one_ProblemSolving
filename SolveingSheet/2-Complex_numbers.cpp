
#include<iostream>
#include<complex>
using namespace std;


void Add_complex(complex<double> num1, complex<double> num2)
{
    int real_result= num1.real()+num2.real();
    int imag_result= num1.imag()+num2.imag();
    cout<<"real_result="<<real_result<<" and imag_result= "<<imag_result<<endl;
    cout <<"the addition="<<num1+num2;

}
int main()
{
    //complex<double>num1,num2;
    double real1,real2,imag1,imag2;
    cout<<"enter the real part and imag part of number 1:";
    cin>>real1>>imag1;
    cout<<"enter the real part and imag part of number 2:";
    cin>>real2>>imag2;
//   num1=complex<double>(real1,imag1);
   complex<double>num1(real1,imag1);
   complex<double>num2(real2,imag2);

   Add_complex(num1,num2);
    return 0;
}




/*
int main() {
    complex<double> c1, c2;
    double real1, imag1, real2, imag2;
    
    cout << "Enter the first complex number (real imaginary): ";
    cin >> real1 >> imag1;
    c1 = complex<double>(real1, imag1);
    
    cout << "Enter the second complex number (real imaginary): ";
    cin >> real2 >> imag2;
    c2 = complex<double>(real2, imag2);
    
    // Perform operations
    complex<double> sum = c1 + c2;
    complex<double> difference = c1 - c2;
    complex<double> product = c1 * c2;
    complex<double> quotient = c1 / c2;
    
    // Output results
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << quotient << endl;
    
    return 0;
}

*/
