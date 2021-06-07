#include <iostream>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;   // максимальное количество вершин

struct WAY{
	double weight;
	double pheromone;
};

struct ANT{
int* was_town;
vector <int> town;
};

int GetRandomNumber(){
int num = 1+ rand() % 1000;
return num; 
}

int main(){
srand(time(0));
int N;
cin >> N;
WAY D[N][N];
double minfer=3;//потом считать можно будет
for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
		D[j][i].weight=0;	
	}
}
for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
	D[i][j].pheromone=minfer;
 	if (j==i) {D[i][j].weight=0;}
	else if ((D[i][j].weight==0)) {
		cout << "Введите расстояние между пунктами " << (i+1) << " "  << (j+1) << " ";
		cin>>D[i][j].weight;
		D[j][i].weight=D[i][j].weight;
		
	}
}
}
double alpha, beta, e, length, minlength;
cout<< "Введите альфа и бета";
cin >> alpha >> beta;
//у нас N муравьев
cout<< "Введите ферамон, оставляемый муравьем, и интенсивность испарения";
cin >> e;
int tmax;//количество итераций алгоритма
vector <int> minway;
double P=0;
cout << "введите количестов итераций";
cin >> tmax;
minlength=10000000000;
double* p=new double[N];
for (int i=0; i<tmax; i++){//проход по всем итерациям
	for (int j=0; j<N; j++){//муравей начнет ходить из каждого город	
		ANT ant;
		ant.was_town= new int[N];
		for (int w=0; w<tmax; w++){
			ant.was_town[w]=0;
		}
		ant.was_town[j]=1;
		int m=j;
		ant.town.push_back(j);
		do {    P=0;
			for(int w=0; w<N; w++){//проверка наличия пути из данного города в город, где мы не были
				if (ant.was_town[w]==0){ 
					p[w]=pow(D[m][w].pheromone, alpha)*pow(1/D[m][w].weight, beta);
					P+=p[w];
					}
					else p[w]=0;
				}
				int s=0;//составим все числа на отрезке от одного до 1000
				if (P!=0){
				for (int u=0; u<N; u++) {
					p[u]/=P;
					p[u]=p[u]*1000;
					p[u]=(int)p[u]+s;
					s=p[u];
				}
				int randnum;
				randnum=GetRandomNumber();
				if (randnum<=p[0]) {
					ant.town.push_back(0);//нашли следующий город, передали его выше, теперь путь от него
					m=0;
					ant.was_town[0]=1;
				}
				for (int w=1; w<N; w++) {
					if ((randnum>p[w-1])&&(randnum<=p[w])){ 							
						ant.town.push_back(w);//нашли следующий город, передали его выше, теперь путь от него
						m=w;
						ant.was_town[w]=1;
					}
				}	
				}	
			} while (P!=0);
		if (ant.town.size()==N){//путь был по всем вершинам
			length=0;
			for (int w=0; w<(N-1); w++){
				length+=D[ant.town[w]][ant.town[w+1]].weight;
			}
			length+=D[ant.town[N-1]][ant.town[0]].weight;
			if (minlength>=length){
				minway.clear();
				for (int b=0; b<ant.town.size(); b++){
					minway.push_back(ant.town[b]);
}
				minlength=length;
			}
		}
	}

for (int j=0; j<N; j++){
	for (int w=1; w<N; w++){
	D[j][w].pheromone=(1-e)*D[j][w].pheromone;
	}
}
for (int w=0; w<(N-1); w++){
				D[minway[w]][minway[w+1]].pheromone+=1/D[minway[w]][minway[w+1]].weight;
			}
			D[minway[N-1]][minway[0]].pheromone+=1/D[minway[N-1]][minway[0]].weight;
}
cout<< minlength;
}

