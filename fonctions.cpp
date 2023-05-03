#include <iostream>
#include <array>


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



