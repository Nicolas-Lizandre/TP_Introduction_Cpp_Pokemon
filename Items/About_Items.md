# Items

Items est une state commune à tous les objets d'un inventaire.
Cela permet de les stoker dans un std::vector<Item*> items_types commun
dans Item_Inventory et rendant le code facilement modifiable.

La grande idée de ce directory est qu'au lieu de créer plusieurs fois un
même objet pour simuler une quantité. On va réserver à chaque objet un
respective_items_quantity. En outre si on est pas sûr ou ayant oublié la
position de cet Item, on peut le retrouver avec isNameInItems_Types(std::string name).

Cet architecture permet en outre de transformer chacun de nos objets en
Singleton ce qui nous donne d'intéressants degré de liberté si continuation du projet
(ressource partagé si jeu en ligne = gain de mémoire).


Lisez la description des Items pour plus de détails.
