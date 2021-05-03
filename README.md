# ASD L6 Liste simplement chaînée

Cet exercice vous demande de compléter la classe `ListeSimple` pour qu'elle passe le double codecheck [https://codecheck.io/files/21050309161kyvp55g3md6ecmnuxbleh7tq](https://codecheck.io/files/21050309161kyvp55g3md6ecmnuxbleh7tq). 
Le code source de cet exercice est disponible dans [src](./src), le résultat attendu dans [txt](./txt). Sauvez
le fichier .zip généré par codecheck dans [zips](./zips). 

Tout l'interface de la classe `ListeSimple` utilise des itérateurs qui vous sont fournis dans le fichier LSIterator.
    Ces itérateurs stockent un pointeur privé vers un maillon dans l'attribut `m`, qui est accessible depuis
    la classe `ListeSimple` qui en est amie.

Seules les fonctions `insert_after`, `erase_after` et `splice_after` manipulent directement les structures de maillon.
    Pour toutes les autres fonctions membres / constructeurs / destructeur il convient de n'utiliser que
des appels aux autres fonctions membres ou les itérateurs. 

Seule la fonction `insert_after` peut allouer de la mémoire. Seule la fonction `erase_after` peut libérer de la
mémoire. On utilise exclusivement l'allocation simple avec `new` et `delete`. 

Faites attention de bien caractériser vos fonctions membres selon qu'elles sont `const` et / ou `noexcept` ou pas.
Pour celle qui ne sont pas `noexcept`, il convient d'offrir une garantie forte. 