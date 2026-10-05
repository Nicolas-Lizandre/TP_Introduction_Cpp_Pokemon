# Code review par Pierre MAZUCCA, le 17/09/2026.

# Au niveau de l'organisation générale :

**Le projet ne compile pas !** :
Plusieurs problèmes en sont la cause : 
- La structure pomme, sur laquelle on reviendra plus tard, cause une erreur à la compilation "error : 'POMME' does not name a type".
- Des points virgules semblent manquer dans Pokedex.h
- "#include "C:\Users\nicol\Documents\Repositoires Github\TP Introduction_C++_Pokemon\Pokemon.h"" est un chemin personnel, qui empêche donc à toute personne utilisant un autre PC de compiler le projet. Il faudrait changer ce path. On peut à priori mettre irectement "#include "pokemon.h"" puisqu'ils sont dans le même fichier, ou, dans le cas où on est organisés correctement en /src et /inc, on peut utiliser ..\ ou \\.

**Absence d'organisation en /src et /inc :** 
les headers doivent être placés dans un dossier "included" (/inc), tandis que le reste des fichiers sources doivent être placés dans un dossier "source" (/src), pour faciliter la lecture du code et l'organisation générale. Accessoirement les fichiers données comme le pokedex peuvent être rangés dans un /data.

**Les fichiers headers sont nommés en .h au lieu de .hpp :**
bien que cela ne pose pas de problème particulier à la compilation, il est tout de même préférable pour un projet en C++ d'utiliser l'extension .hpp, surtout quand les fichiers sources ont une extension en .cpp

**Les paths ne sont pas relatifs:**
Comme dit plus tôt, le projet ne peux pas compiler si les paths restent personnels.

**Les commentaires sont brouillons et redondants:**
Beaucoup des commentaires présents sont brouillons. Certains d'entres eux sont des restes de codes non fonctionnels ou en WIP, d'autres sont des annotations assez longues et peu compréhensives. Un commit ne devrait pas être fait avec ce genre de lignes de codes encore présentes, et devrait rester le plus propre possible pour éviter un encombrement et un manque de lisibilité du code.

# PokemonParty :

**PokemonParty.cpp est vide:**
Apparemment c'est pour en faire un design pattern state qui n'a pas encore été fait, cependant il aurait été plus judicieux de ne pas push ce code là si il n'était pas prêt. Accessoirement, mieux séparer les méthodes entre elles (les Getter sont au milieu des méthodes) permettrait une meilleure lisibilité.

**BattleState et PokemonState:**
Définir BATTLESTATE et POKEMONSTATE directement dans le fichier Header viole la règle ODR (One Definition Rule) en C++. Si le header est inclu ailleurs que dans PokemonParty, cela causera des erreurs de duplication/définition multiple. en C++17, on peut utiliser le mot-clé "inline" pour corriger ça, indiquant que la variable est un seul et même objet en mémoire.

# SetOfPokemon : 

**SetOfPokemon.h :**
Les commentaires ne sont pas pertinents. Ils ne décrivent pas les méthodes ou leur fonctionnement, et sont plutôt des annotations pour le développeur les ayant écrites.

**SetOfPokemon.cpp :**
Sauf erreur de ma part, les getters sont définis dans le .h mais pas détaillés dans le .cpp.

# Pokedex : 
là encore, les commentaires sont soit des annotations personnelles, soit des commentaires qui ont l'air pertinent (expliquant par exemple certaines décisions prises) mais qui dans la manière dont ils sont écrits finissent par être difficile à comprendre pour un relecteur. Le code bénificierai en général de pavés d'explications avec plus de cohésions en début de code ou de méthode, pour mieux détailler ce qui va s'y passer

Rien à dire sur le code en lui même. La méthode FillSetOfPokemon est un peu lourde en elle même et bénificierai peut-être d'une subdivision en méthodes secondaires, ainsi que des explications plus claires sur son fonctionnement interne.

# Pokeball : 
Apparemment inutile/non implémenté d'après les premiers commentaires dans le header donc pas vraiment d'intérêt à commit, encore une fois il est judicieux de choisir correctement les fichiers à commit pour éviter un encombrement du github, surtout sur des projets où plusieurs personnes travaillent en même temps.

# main : 
Peut-être le plus grand questionnement de cette review, à quoi sert la structure pomme ?
J'ai cherché dans les différents fichiers mais la seule réference qui est faite à ce sujet est un code mis en commentaire donc ignoré.
Accessoirement, définir une structure dans un main est rarement judicieux et devrait être évité. C'est un fichier principalement fait pour l'execution de code principal et il ne devrait pas y avoir de grosse définitions de structures dedans.
J'ai d'ailleurs essayé de comprendre ce que faisais la structure sans réussir. Je suppose peut être qu'il s'agit d'un système d'objets utilisables par les Pokémons, comme dans le jeu de base. 

En dehors de ça, pas grand chose à dire. Attention aux PATHs utilisés dans Pokemdex_GetInstance qui sont encore une fois locaux et non relatifs, ça donnerait une erreur sur mon PC.
Le reste du main me paraît correct.

# KO : 
Pourquoi avoir mis l'entiereté de ces fichiers dans un dossier States ? C'est un peu étrange, surtout que les headers et les sources sont encore une fois confondus.

KO.h et KO.cpp ne me semblent pas contenir de grosse erreurs, si ce n'est un peu compliqués à comprendre pour une classe de (supposément) gestion de KO.

# InShape :
De même qu'au dessus, ça me semble être un ensemble de classe pour gérer ce qui se passe selon l'état du Pokemon mais je n'ai pas l'impression que ça fonctionne vraiment

# Abstract_BattleState.h et Abstract_Pokemon_State.h : 

Superbes headers qui ne font donc pas grand chose sans leur .cpp respectif, il y a de l'idée dans ce qui est proposé (notamment avec un check pour savoir si le pokémon vient juste d'arriver, certaines attaques ou effets ayant un effet à l'arrivée sur le terrain ça peut être une très bonne feature du jeu), mais pour l'instant rien de concret.

# Méthode supplémentaire proposée : 

Si je devais suggérer une méthode ou une classe qui pourrait être intéressante, je verrais bien l'inclusion d'un système de gestion d'item (un seul item, ne faisons pas trop compliqué) comme une **pomme** par exemple (clin d'oeil), qui permettrait à un pokémon de se soigner si il la tient pendant un combat. ça me semble pas particulièrement compliqué à coder et ça pourrait être un bon troisième système d'inventaire avec celui de la Party et du PC.





