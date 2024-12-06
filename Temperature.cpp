#include <iostream>

using namespace std;




int main()

{

    float fahr, cel;

    char a;



    cout << "Fahrenheit-Celsius(F-C(1)) or Celcius-Fahrenheit(C-F(2)) (1/2): ";

    cin >> a;

    if (a == '1')

    {

        cout << "Enter Temperature: ";

        cin >> fahr;



        cel = (fahr-32)/1.8;

        cout << "Temperature in Celcius is: " << cel << "C" << end1;



    }

    else if (a == '2')

    {

        cout << "Enter Temperature: ";

        cin >> cel;



        fahr = (cel*1.8) + 32;

        cout << "Temperature in Fahrenheit is: " << fahr << "F"<< end1;

    }

    else

       cout << "Error." << end1;



    return 0;

}
