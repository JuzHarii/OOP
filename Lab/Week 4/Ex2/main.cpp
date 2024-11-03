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
    
    return 0;
}