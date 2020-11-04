 //умножение карацубы
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int strl(char*_s){
    int i=0;
    for(;*_s;++_s,i++);
    return i;
}
struct LongNumbers{
    int Size;
    int *Number;
    LongNumbers(){
        Size = 1;
        Number = new int[Size];
    }
    LongNumbers(int s){
        Size=s;
        Number = new int[Size];
        for(int i = 0; i < Size; i++){
            Number[i]=0;
        }
    }
    LongNumbers(const LongNumbers& C){
        Size = C.Size;
        Number = new int[Size];
        for(int i = 0; i < Size; i++){
            Number[i] = C.Number[i];
        }
    }
    LongNumbers& operator = (const LongNumbers& C){
        this->Size = C.Size;
        this->Number = new int[C.Size];
        for(int i = 0; i < C.Size; i++){
            this->Number[i] = C.Number[i];
        }
        return *this;
    }
    ~LongNumbers(){
        delete[]Number;
    }
};//ñòðóêòóðà äëÿ õðàíåíèÿ äëèííûé ÷èñåë â âèäå ìàññèâà çàïèñàííîãî â îáðàòíîì ïîðÿäêå
istream& operator>>(istream& in, LongNumbers& A){
    char num[256];
    in.getline(num,256);
    A.Size=strl(num);
    A.Number = new int[strl(num)];
    for(int i=strl(num)-1;i>=0;i--){
        A.Number[A.Size-1-i]=num[i]-'0';
    }
    return in;
}
ostream& operator<<(ostream& os,const LongNumbers& A){
    for(int i=A.Size-1;i>=0;i--){
        os<<A.Number[i];
    }
    return os;
}
LongNumbers sum(LongNumbers A,LongNumbers B){ //ñóììèðîâàíèå äâóõ ÷èñåë
    LongNumbers product;
    product.Size=A.Size+1;

    product.Number = new int[product.Size]{0};
    for(int i=0;i<A.Size;i++){
        if(i<B.Size){
            product.Number[i]=A.Number[i]+B.Number[i];
        }else{
            product.Number[i]=A.Number[i];
        }
    }
    int i=product.Size;
    for(;product.Number[i-1]==0;i--);
    product.Size=i;
    return product;
}
LongNumbers sub(LongNumbers a, LongNumbers b) { //âû÷èòàíèå äâóõ ÷èñåë
  for (int i = 0; i < b.Size; ++i)
    a.Number[i] -= b.Number[i];
  return a;
}
void Normalize(LongNumbers &A){         //ôóíêöèÿ ïî ïðèâåäåíèþ ÷èñëà ê íîðìàëüíîìó âèäó
    for(int i=0;i<A.Size-1;i++){

        if(A.Number[i]>=10){
            A.Number[i+1]+=A.Number[i]/10;
            A.Number[i]=A.Number[i]%10;
        }else if(A.Number[i]<0){
            A.Number[i+1]-=abs(A.Number[i]/10)+1;
            A.Number[i]+=(abs(A.Number[i]/10)+1)*10;
        }
    }
}
void DeleteUsefulNull(LongNumbers& A){//ôóíêöèÿ äëÿ óäàëåíèÿ íåçíà÷èìûõ íóëåé
    int i = A.Size;
    for(;A.Number[i-1]==0;i--);
    A.Size=i;
}
LongNumbers karatsuba(LongNumbers a,LongNumbers b){ //óìíîæåíèå Êàðàöóáû
    LongNumbers product(a.Size+b.Size);
    if(a.Size<=2){

        for(int i = 0 ; i < a.Size; i++){
            for(int j = 0; j < b.Size; j++){
                product.Number[i+j]+=a.Number[i]*b.Number[j];
            }
        }
    }
    else {
        LongNumbers a1((a.Size + 1) / 2); //ïåðâàÿ ÷àñòü ÷èñëà à
        for(int i = 0; i < a1.Size;i++){
            a1.Number[i]=a.Number[i];
        }

        LongNumbers a2(a.Size/2);
        for(int i = 0; i<a2.Size; i++){
            a2.Number[i]=a.Number[i+a1.Size];
        }

        LongNumbers b1((b.Size + 1) / 2); //ïåðâàÿ ÷àñòü ÷èñëà à
        for(int i = 0; i < b1.Size;i++){
            b1.Number[i]=b.Number[i];
        }

        LongNumbers b2(b.Size/2);
        for(int i = 0; i<b2.Size; i++){
            b2.Number[i]=b.Number[i+b1.Size];
        }
        LongNumbers SumAparts = sum(a1, a2); //ñóììà ÷àñòåé à
        Normalize(SumAparts);
        LongNumbers SumBparts = sum(b1, b2); //ñóììà ÷àñòåé b
        Normalize(SumBparts);
        LongNumbers PSP = karatsuba(SumAparts, SumBparts); //ïðîèçâåäåíèå ñòàðøåãî ÷ëåíà
        LongNumbers PfP = karatsuba(a1, b1);//ïðîèçâåäåíèå ïåðâûé ÷àñòåé ÷èñåë
        LongNumbers PsP = karatsuba(a2, b2);//ïðîèçâåäåíèå âòîðûõ ÷àñòåé ÷èñåë
        LongNumbers SMP = sub(sub(PSP,PfP),PsP);//ñðåäíèé ÷ëåí
        Normalize(SMP);
        memcpy(product.Number,PfP.Number,PfP.Size*sizeof(int));
        //êîïèðîâàíèå ìëàäøåãî ÷ëåíà â îêîí÷àòåëüíûé îáúåêò
        for(int i = 0; i < PsP.Size; i++){
            product.Number[i+a1.Size+b1.Size]+=PsP.Number[i];
        }//êîïèðîâàíèå ñòàðøåãî ÷ëåíà â îêîí÷àòåëüíûé îþúåêò
        for(int i = 0; i < SMP.Size; i++){//ñóììèðîâàíèå ñî ñðåäíèì ÷ëåíîì
            product.Number[a1.Size+i]+=SMP.Number[i];
        }
    }
    Normalize(product);
    return product;
}
int main()
{
    LongNumbers chislo1;
    cin>>chislo1;
    LongNumbers chislo2;
    cin>>chislo2;
    LongNumbers chislo3 = karatsuba(chislo1, chislo2);
    DeleteUsefulNull(chislo3);
    cout<<chislo3;
    return 0;
}
