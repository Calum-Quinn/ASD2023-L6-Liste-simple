#ifndef LISTE_H
#define LISTE_H

#include "LSIterator.h"
#include <utility> // std::swap;

template <typename T>
class ListeSimple {
public:
    using value_type = T;
    using reference = T &;
    using const_reference = T const &;

private:
    struct Maillon {
        value_type valeur;
        Maillon* suivant;
    };

    Maillon avant_premier;

public:
    using iterator = LSIterator<value_type>;
    friend iterator;

    using const_iterator = LSConstIterator<value_type>;
    friend const_iterator;

    const_iterator cbegin() const noexcept { return const_iterator(avant_premier.suivant); }
    iterator begin() noexcept { return iterator(avant_premier.suivant); }
    const_iterator begin() const noexcept { return cbegin(); }

    ListeSimple() : avant_premier{value_type{}, nullptr} {}

    // A compléter pour fournir ...
    //
    // end, cend, before_begin, cbefore_begin, empty, front
    // insert_after, erase_after, splice_after, push_front, pop_front,
    // swap, sort, ainsi que constructeur, opérateur d'affectation et destructeur

    ListeSimple(const ListeSimple& other) : avant_premier(other.avant_premier) {}

    ~ListeSimple();

    ListeSimple& operator=(const ListeSimple& autre) {
       if (this != &autre) {
          return *this;
       }
    }


    iterator end() noexcept{

       Maillon actuel = avant_premier;

       return actuel.valeur;
    }
    const_iterator cend() const noexcept{
       Maillon actuel = avant_premier;

       while(actuel.suivant != nullptr){
          actuel = *actuel.suivant;
       }

       return (iterator)(&actuel);
    }

    iterator before_begin() {
       return iterator(&avant_premier);
    }

    const_iterator cbefore_begin() const {
      return const_iterator(&avant_premier);
    }

    bool empty() {
       return !avant_premier.suivant;
    }

    value_type front(){
      return *begin();
    }

    void insert_after(iterator pos, value_type valeur) {
       Maillon* temp = pos.m->suivant;
       pos.m->suivant = new Maillon(valeur);
       pos.m->suivant->suivant = temp;
    }
    /*fonction insérer_après(M,val)
 alerter si M == ⌀
 M.suivant ← nouveau Maillon(val,M.suivant)
     */

    void erase_after(iterator pos) {
      Maillon* temp = next(pos,2);
      delete next(pos);
      pos.suivant = temp;
    }

    void splice_after(iterator pos, iterator listeDebut, iterator listeFin) {
       if (listeDebut == listeFin)
          return;

       listeFin->next = pos->next;
       pos->next = listeDebut;
    }

    void push_front(value_type i) {
       insert_after(before_begin(), i);
      // Maillon tmp;
       //tmp.valeur = i;
       //tmp.suivant = avant_premier.suivant;
       //avant_premier.suivant = &tmp;

       /*
        *
        * fonction insérer_au_début(premier, valeur)
    tmp ← nouveau Maillon
    tmp.valeur ← valeur
    tmp.suivant ← premier
    retourner tmp
        */
    }

    void pop_front() {
       erase_after(before_begin());

       //Maillon tmp;
       //tmp = avant_premier.suivant->suivant;
       //avant_premier.suivant = &tmp;

       /*fonction supprimer_au_début(premier)
    alerter si premier == ⌀
    tmp ← premier.suivant
    effacer premier
    retourner tmp
   premier ← supprimer_au_début(premier)*/
    }

    void swap();
    void sort() {
      //Bubble, Selection ou insertion
      iterator plusPetit = before_begin();
       while(next(plusPetit,2) != end()){
           iterator iMin = plusPetit;
           iterator i = next(plusPetit);

           while(next(i) != end()){
              if(*i < *iMin){
                 iMin = i;
              }
              ++i;
           }

          splice_after(plusPetit, iMin, iMin);
          ++plusPetit;
       }
    }
};

#endif //LISTE_H
