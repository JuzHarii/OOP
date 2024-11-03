#include "BigInteger.h"

int main() 
{ 
    BigInteger snl1; 
    BigInteger snl2(44667733); 
    BigInteger snl3(5, 9); 
    BigInteger snl4(7, 30); 
    BigInteger snl5 = snl3 - snl2; 
    BigInteger snl6 = 1098765432 - snl2; 
    BigInteger snl7 = snl4 - snl3 + 123456789; 
    BigInteger snl8 = snl2 * snl3; 
    
    cout << snl1 << endl << snl2 << endl << snl3 << endl; 
    cout << snl4 << endl << snl5 << endl << snl6 << endl; 
    cout << snl7 << endl << snl8 << endl << endl; 
    return 0;
}