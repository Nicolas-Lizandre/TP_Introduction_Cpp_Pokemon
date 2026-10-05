# Pokemon State

Ce repositoire contient tous les codes enfants du state : Pokemon State.

Un Pokemon peut avoir que 3 états :
- InShape : Être en forme (peut être mis sur le terrain sans soucis)
- MagicSickness : Maladie magique (permet de donner une dimension stratégique en ajoutant une sorte de poison dont le potentiel et plus élevé qu'une attaque classique [moitié de spAtk-spDef_adverse mais la chance de le garder est de 2/3])
- KO : Hors d'état de combat (ne peut plus être rentrer sur le terrain et doit en sortir - cet état est déclenclenché pour hitPoint = 0)

Les fonctions communes à la classe permettent de leur poser des questions : 
Le pokemon peut être envoyé (état KO) ? Est-il altéré (état MagicSickness) ?

Techniquement getName() suffirait mais demanderais un switch case à chaque utilisation, ce qui n'est pas idéal. 

Cette classe s'ocuupe aussi de mettre les dégâts d'altérations échellonnés à sickness_strength.

