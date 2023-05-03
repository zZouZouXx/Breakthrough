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