#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int adjmat[21][21];
int size;
long long memo[1<<20];

unsigned numbits(unsigned i)
{
    const unsigned MASK1  = 0x55555555;
    const unsigned MASK2  = 0x33333333;
    const unsigned MASK4  = 0x0f0f0f0f;
    const unsigned MASK8  = 0x00ff00ff;
    const unsigned MASK16 = 0x0000ffff;

    i = (i&MASK1 ) + (i>>1 &MASK1 );
    i = (i&MASK2 ) + (i>>2 &MASK2 );
    i = (i&MASK4 ) + (i>>4 &MASK4 );
    i = (i&MASK8 ) + (i>>8 &MASK8 );
    i = (i&MASK16) + (i>>16&MASK16);

    return i;
}

int main() {cout<<numbits(8);
   memset(adjmat,0,sizeof(adjmat));
   ios_base::sync_with_stdio(false);
   int nT;
   cin >> nT;
   while (nT-- && cin >> size) {
      memset(adjmat,0,sizeof(adjmat));
      memset(memo,0,sizeof(memo));
      for (int i = 0; i < size; i++) {
         for (int j = 0; j < size; j++) {
            int val; cin >> val;
            adjmat[i][j] = val;
         }
      }
      memo[(1<<size)-1] = 1;
      for (int j = (1 << size)-1; j >= 0; j--) {
         int idx = numbits(j);
         for (int k = 0; k < size; k++) {
            if (adjmat[idx][k] == 0 || (j & (1 << k))) continue;
            memo[j] += memo[j | (1 << k)];
         }
      }
      cout << memo[0] << "\n";
   }
   return 0;
}
