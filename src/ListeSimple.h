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

    //Constructeur par copie
    ListeSimple(const ListeSimple& autre) : ListeSimple() {
       iterator iterateur = before_begin();
       const_iterator itAutre = autre.begin();

       while(itAutre != autre.end()) {
          insert_after(iterateur, *itAutre);
          ++iterateur;
          ++itAutre;
       }
    }

    //Destructeur
    ~ListeSimple() {
       while(avant_premier.suivant) {
          //erase_after(&avant_premier);
          pop_front();
       }
    }

    //Opérateur d'affectation
    ListeSimple& operator=(const ListeSimple<value_type>& autre) {
       if (this == &autre) {
          return *this;
       }
		 ListeSimple<value_type> temp(autre);
		 swap(temp);
		 return *this;
    }

    const_iterator end() const noexcept {
       return cend();
    }

    iterator end() noexcept {
       return iterator(nullptr);
    }

    const_iterator cend() const noexcept {
       return const_iterator(nullptr);
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

    reference front() noexcept {
      return *begin();
    }

	const_reference front() const noexcept {
		return *cbegin();
	}

    void insert_after(iterator pos, value_type valeur) {
		 if(pos.m){
          pos.m->suivant = std::move(new Maillon{valeur,pos.m->suivant});
		 }
    }

    void erase_after(iterator pos) {
//      Maillon* temp = next(pos,2);
		if(pos.m && pos.m->suivant){
			Maillon* temp = pos.m->suivant;
			pos.m->suivant = temp->suivant;
			delete temp;
		}
    }

    void splice_after(iterator pos, iterator listeDebut, iterator listeFin) {
       if (listeDebut == listeFin)
          return;

       Maillon* tmp = pos.m->suivant;
       pos.m->suivant = listeDebut.m->suivant;
       listeDebut.m->suivant = listeFin.m->suivant;
       listeFin.m->suivant = tmp;
    }

    void push_front(const_reference i) {
       insert_after(before_begin(), i);
    }

    void pop_front() {
       erase_after(before_begin());
    }

    void swap(ListeSimple& autre) noexcept {
		 std::swap(avant_premier, autre.avant_premier);
	 }

    void sort() {
       //Bubble, Selection ou insertion
       iterator plusPetit = before_begin();
       iterator iMin;

       for (iterator i = plusPetit; iterator(i.m->suivant) != end(); ++i) {
          iMin = i;
          for (iterator j = next(i); j != end(); ++j) {
             if (j.m->suivant && j.m->suivant->valeur < iMin.m->suivant->valeur)
                iMin = j;
          }
          if (iMin != i)
            splice_after(plusPetit, iMin, next(iMin));
          plusPetit = plusPetit.m->suivant;
       }
    }
};

#endif //LISTE_H
