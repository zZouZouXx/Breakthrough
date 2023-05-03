#include <iostream>
#include <array>

const int Nmax = 100;
using Tab =std::array<char,Nmax>;
using Matrice =std::array<Tab,Nmax>;


void init (Matrice & M, const char N, const char B,const char V, int x){
    if (x < 8){
        for (int i = 1; i<x-1; ++i){
            M[i][1] = N;
            M[i][x-2] = B;
        }
        for (int i = 3; i<x-1; ++i){
            for(int y = 1; y<x-1; ++y){
                M[y][i] = V;
            }
        }
        for (int i = 1; i<x-1; ++i){
            M[i][0] = '_';
            M[0][i] = '#';
            M[x-1][i] = "#";
            M[i][x-1] = '_';
        }
        M[0][0] = ' ';
        M[0][x-1] = ' ';
        M[x-1][0] = ' ';
        M[x-1][x-1] = ' ';
    }
    else{
        int z=0;
        for (int i = 1; i<x-1; ++i){
            M[i][1] = N;
            M[i][2] = N;
            M[i][x-2] = B;
            M[i][x-3] = B;
        }
        for (int i = 3; i<x-1; ++i){
            for(int y = 1; y<x-1; ++y){
                M[y][i] = V;
            }
        }
        for (int i = 1; i<x-1; ++i){
            M[i][0] = '_';
            M[0][i] = '#';
            M[x-1][i] = "#";
            M[i][x-1] = '_';
        }
        M[0][0] = ' ';
        M[0][x-1] = ' ';
        M[x-1][0] = ' ';
        M[x-1][x-1] = ' ';
    }
}

struct coup{
    int c0;
    int l0;
    int c1;
    int l1;
};

void affichage(Matrice M, const char V, int x){
    for (int i = 0; i<x; ++i){
        for (int y = 0; y<x; ++y){
            if (M[y][i]==V){
                std::cout<<'-';
                std::cout<<" ";
            }
            else{
                std::cout<<M[y][i];
                std::cout<<" ";
            }
        }
    std::cout<<std::endl;
    }
}

int compteur_blanc(Matrice M, const char B)
{
    int x=0;
    for(int i=0; i<Nmax; ++i)
    {
        for(int j=0; j<Nmax; ++j)
        {
            if(M[i][j]==B)
                x=x+1;
        }
    }
    return x;
}

int compteur_noir(Matrice M, const char N)
{
    int y =0;
    for(int i=0; i<Nmax; ++i)
    {
        for(int j=0; j<Nmax; ++j)
        {
            if(M[i][j]==N)
                y=y+1;
        }
    }
    return y;
}


void fairecoup(Matrice &M, coup &C, const char B, const char N, const char V){
    if (M[C.l0][C.c0] == B){
        M[C.l0][C.c0] = V;
        M[C.l1][C.c1] = B;
    }
    else{
        M[C.l0][C.c0] = V;
        M[C.l1][C.c1] = N;
    }
}

bool verifligne(Matrice M,int x, const char B, const char N){
    for(int i=1; i<x-1; ++i){
        if (M[i][1] == B){
            std::cout<<"les blancs ont gagné"<<std::endl;
            return true;
        }
        if (M[i][x-2] == N){
            std::cout<<"les noirs ont gagné"<<std::endl;
            return true;
        }
    }
}
    
bool partiefini(Matrice M, const char B, const char N, int x){
    if(compteur_blanc == 0){
        std::cout<<"les noirs ont gagné"<<std::endl;
        return true;
    }
    else if (compteur_noir == 0){
        std::cout<<"les blancs ont gagné"<<std::endl;
        return true;
    }
    if (verifligne(M,x,B,N)==true)
        return true;
    else
        return false;
}


void quel_coup(coup &C)
{
    std::cout<<"Quel pion voulez-vous jouer?"<<std::endl;
    std::cin>>C.l0;
    std::cin>>C.c0;
    std::cout<<"Où voulez-vous le déplacer?"<<std::endl;
    std::cin>>C.l1;
    std::cin>>C.c1;
}

bool estjouable(Matrice M, coup C, const char B, const char N, const char V, bool equipe){
    if (equipe == false){
        if (M[C.l0][C.c0] != B){
            std::cout<<"Veuillez sélectionner un autre pion car il ne fais pas partie de votre équipe."<<std::endl;
            return false;
        }
        if (M[C.l1][C.c1] != M[C.l0+1][C.c0-1] and M[C.l1][C.c1] != M[C.l0-1][C.c0-1] and M[C.l1][C.c1] != M[C.l0][C.c0-1]){
            std::cout<<"Veuillez sélectionner un autre déplacemnt car le coup n'est pas possible."<<std::endl;
            return false;
        }
        if (M[C.l1][C.c1] == B){
            std::cout<<"Veuillez sélectionner un autre pion car il y a déjà un pion de votre équipe sur cette case."<<std::endl;
            return false;
        }
        if (M[C.l1][C.c1] != V and M[C.l1][C.c1] != N){
            std::cout<<"Veuillez sélectionner un autre pion car la case est une bordure."<<std::endl;
            return false;
        }
        else{
            return true;
        }
    }
    else{
        if (M[C.l0][C.c0] != N){
            std::cout<<"Veuillez sélectionner un autre pion."<<std::endl;
            return false;
        }
        if (M[C.l1][C.c1] != M[C.l0+1][C.c0+1] and M[C.l1][C.c1] != M[C.l0-1][C.c0+1] and M[C.l1][C.c1] != M[C.l0][C.c0+1]){
            std::cout<<"Veuillez sélectionner un autre déplacemnt car le coup n'est pas possible."<<std::endl;
            return false;
        }
        if (M[C.l1][C.c1] == N){
            std::cout<<"Veuillez sélectionner un autre pion car il y a déjà un pion de votre équipe sur cette case."<<std::endl;
            return false;
        }
        if (M[C.l1][C.c1] != V and M[C.l1][C.c1] != B){
            std::cout<<"Veuillez sélectionner un autre pion car la case est une bordure."<<std::endl;
            return false;
        }
        else{
            return true;
        }
    }
}



void encore_pions(Matrice M, bool & BB, bool & BN)
{
    BB=false;
    BN=false;
    for (int i=1; i<Nmax; ++i)
    {
        for(int y=1; y<Nmax; ++y)
        {
            if(M[y][i]=='B')
                BB=true;
            else if(M[y][i]=='N')
                BN=true;
        }
    }
}



void tour(bool & equipe)
{
    if(equipe==true)
        equipe=false;
    else if(equipe==false)
        equipe=true;
}


int main(){
    Matrice M;
    coup C;
    bool equipe;
    int x; //taille du plateau
    std::cout<<"donner la taille du plateau"<<std::endl;
    std::cin>>x;
    x = x+2;
    const char N='N';
    const char B='B';
    const char V='V';
    init(M,N,B,V,x);
    equipe=false;
    while(partiefini(M,B,N,x)==false)
    {
        affichage(M,V,x);
        std::cout<<compteur_blanc(M,B)<<std::endl;
        std::cout<<compteur_noir(M,N)<<std::endl;
        if (equipe == false)
            std::cout<<"Au tours des blancs :"<<std::endl;
        else if(equipe==true)
            std::cout<<"Au tours des noirs :"<<std::endl;
        quel_coup(C);
        while(estjouable(M,C,B,N,V,equipe)==false)
        {
            quel_coup(C);
            estjouable(M,C,B,N,V,equipe);
        }
        fairecoup(M,C,B,N,V);
        tour(equipe);
    }
    return 0;
}