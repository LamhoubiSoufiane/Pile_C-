#ifndef SRC_PILE2_H_
#define SRC_PILE2_H_

class pile2
{
    private:
        int maxelem;     //la capacité maximale de la pile
        int *pile;      // Un pointeur vers un tableau dynamique
        int sommet;     //indice du sommet
    public:
        pile2(int nbelm);   //Constructeur
        ~pile2();           //Destructeur
        pile2(pile2 &);     //Constructeur de copie
        void afficher(pile2 &); // Méthode pour afficher le contenu de la pile
        int pilesaturee();      // Méthode pour vérifier si la pile est pleine
        int pilevide();         // Méthode pour vérifier si la pile est vide
        void operator<<(int x); // Surcharge de l'opérateur << pour empiler un élément
        void operator>>(int &x);// Surcharge de l'opérateur >> pour dépiler et retourner la valeur dans x
        void operator=(pile2 &);// Surcharge de l'opérateur = pour copier le contenu d'une pile dans une autre
        pile2 &operator+(pile2 &);// Surcharge de l'opérateur + pour fusionner deux piles
};
#endif