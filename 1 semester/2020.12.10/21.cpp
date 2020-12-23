#include <iostream>
using namespace std;
struct segments{
    int w;
    int pr;
};
int main() {
    int Wbag,count;
    cin >> count>>Wbag;
    int c[count][Wbag];
    struct segments seg[count];
    seg[0].w=0;
    seg[0].pr=0;
       for (int i = 1; i <= count; i++) {
            cin >> seg[i].w>>seg[i].pr;
    }
 for (int i=0; i<=count; i++)  {
    for (int j=0; j<=Wbag; j++){
        if ((i==0)||(j==0)) c[i][j]=0;
        else if (j-seg[i].w<0) c[i][j]=c[i-1][j];
        else c[i][j]=max(c[i-1][j], (c[i-1][j-seg[i].w]+seg[i].pr));
    }
 }
 cout<<c[count][Wbag];
}
