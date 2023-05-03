#include <iostream>

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