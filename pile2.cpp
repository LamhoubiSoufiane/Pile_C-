#include "main.hpp"
#include "pile2.hpp"

pile2::pile2(int nbelm)
{
    //Initialisation de la variable membre maxelem avec la valeur nbelm
    this->maxelem=nbelm; 
    this->pile=NULL;//Initialisation du pointeur 
    //Allocation dynamique de la mémoire pour un tableau de taille nbelm
    this->pile=new int [nbelm];
    //Afficher un message d'erreur et quitter si l'allocation est mal faite
    if(!this->pile)
    {
        cout<<"erreur d allocation!!"<<endl;
        exit(1);
    }
    this->sommet=-1;//Initialisation de l'indice du sommet de la pile
}

pile2::pile2(pile2 &p)
{
    this->pile=NULL;//Initialisation du pointeur
    this->maxelem=p.maxelem;  
    this->pile=new int [this->maxelem];
    if(!this->pile)
    {
        cout<<"erreur d allocation!!"<<endl;
        exit(1);
    }
    int sommet_tmp=p.sommet;
    int *tabtmp=new int[p.sommet+1];
    int i=0;
    while(p.sommet >=0)
    {
        tabtmp[i]=p.pile[p.sommet--];
        i++;
    }
    i--;
    p.sommet=sommet_tmp;
    while(i >=0 ) 
    {
        this->pile[this->sommet]=tabtmp[i];
        this->sommet++;
    }
    delete[] tabtmp;
}

pile2::~pile2()
{
    delete[] this->pile;
}

void pile2::afficher(pile2 &p)
{
    int sommtmp=this->sommet;
    while(this->sommet >=0 ) 
    {
        cout<<this->pile[this->sommet]<<endl;
        this->sommet--;
    }
    this->sommet=sommtmp;
}

int pile2::pilesaturee()
{
    if(this->maxelem - 1 == this->sommet) return((int)1);
    return((int)0);
}

int pile2::pilevide()
{
    if(this->sommet == -1) return((int)1);
    return((int)0);
}
void pile2::operator<<(int x)
{
    if(this->pilesaturee()) 
    {
        cout<<"pile est saturee"<<endl;
        exit(1);
    }
    this->pile[++this->sommet] = x;
}

void pile2::operator>>(int &x)
{
    if(this->pilevide()) 
    {
        cout<<"la pile est vide"<<endl;
        exit(1);
    }
    x=this->pile[this->sommet--];
}

void pile2::operator=(pile2 &p)
{
    if(this->maxelem != p.maxelem)
    {
        cout<<"\nles deux piles n ont pas la meme taille!!"<<endl;
        exit(1);
    }
    this->sommet=p.sommet;
    int *tabtmp=new int[p.sommet + 1];
    int i=0;
    while(p.sommet >=0)
    {
        tabtmp[i]=p.pile[p.sommet--];
        i++;
    }
    p.sommet=this->sommet;
    this->sommet=0;
    i--;
    while(i >= 0 ) 
    {
        this->pile[this->sommet++]=tabtmp[i--];
    }
    this->sommet--;
    delete[] tabtmp;
}

pile2 &pile2::operator+(pile2 &p)
{
    pile2 *resultat=new pile2(this->maxelem + p.maxelem);
    int *tabtmp=new int [(this->sommet + p.sommet + 2)];
    int i=0;
    int sommettmp=p.sommet;
    while(p.sommet >= 0 )
    {
        tabtmp[i]=p.pile[p.sommet--];
        i++;
    }
    p.sommet=sommettmp;
    sommettmp=this->sommet;
    while(this->sommet >= 0 )
    {
        tabtmp[i]=this->pile[this->sommet--];
        i++;
    }
    this->sommet=sommettmp;
    i=this->sommet + p.sommet + 1;
    while(i >= 0)
    {
        resultat->operator<<(tabtmp[i--]);
    }
    delete[] tabtmp;
    return *resultat;
}