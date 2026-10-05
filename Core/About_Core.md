# Main, Game, PokemonBattle

Ces 3 classes sont celles qui décident du fil conducteurs du jeu.
Main sert uniquement à démarrer le jeu et initialiser le Pokedex.

Si vous suivez :
- Game::startGame()
- Game::startFight()

Vous aurez le fil directeur principal de l'enchaînement du jeu. Les fonctions qui masquent la
complexité ont été mis par soucis de clean code - vous voyez par le nom de la fonction ce qui
a été implémentée.

Techniquement tout aurais pu être mis dans le main mais ça aurait 
été extrêment illisible. (De même la raison pour laquelle Game et PokemonBattle sont séparés)

# SetOfPokemon, PokemonParty

À priori PokemonParty devrait uniquement porter les Pokemons d'une équipe (std::vector<Pokemon>).
Or j'ai rajouté : std::vector<BattleState> respective_BattleState, Item_Inventory inventory pour le 
rendre plus proche à ce qu'une pokemon partie ressemble dans les jeux Pokemons 
(On pourrait la renommer saccoche du joueur).

BattleState permet de savoir et désigner (avec sentPokemon()) quel Pokemon est en train de combattre.

# Pokemon

Gère la modification des attributs d'un Pokemon (dont évidemment l'initialisation), 
la mise en place des Placeholder (pour faire bref, pendant le pokemonBattle le std::vector 
des PokemonParty doivent rester de même taille sinon les pointers changent et ça SEG_FAULT).
Pour réécrire sans changer toute ma structure j'ai décidé de créer un Pokemon PLACEHOLDER qui 
sert juste à réserver de la place.

# Pokedex

Singleton avec un std::vector<Pokemon> à initialiser avant instanciation
par Initialize_Pokedex. En lisant pokemon.csv, on peut accéder avec :
- Pokemon *getPokemon_withName(std::string name);
- Pokemon *getPokemon_withId(int Id);
À des Pokemons "tout fait".