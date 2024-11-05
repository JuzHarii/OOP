#include "BigInteger.h"

int main() 
{ 
    BigInteger snl1; 
    BigInteger snl2(44667733); 
    BigInteger snl3(5, 9); 
    BigInteger snl4(7, 30); 
    
    cout << snl1 << endl;
    cout << snl2 << endl;
    cout << snl3 << endl;
    cout << snl4 << endl;
    
    // BigInteger temp1(11);
    // BigInteger temp2(10);
    // BigInteger test = 100 - temp2;
    // cout << test << endl;

    // BigInteger snl5 = snl3 - snl2;
    // cout << snl5 << endl;

    // BigInteger snl6 = 1098765432 - snl2;
    // cout << snl6 << endl;
    
    BigInteger snl7 = snl4 - snl3 + 123456789; 
    cout << snl7 << endl;

    return 0;
}