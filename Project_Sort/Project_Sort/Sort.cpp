#include <iostream>

int main(int argc, const int* argv[]) {
	if (argc < 2) {
		std::cout << "le tableau est déjà trié, il ne contient qu'un élément" << std::endl;
		return 1;
	}


	// Créer un tableau d'entiers avec les arguments passés
	int taille = argc - 1;  // Le nombre d'éléments à trier (argc - 1, car argv[0] est le nom du programme)
	int* tableau = new int[taille];

	// Remplir le tableau avec les arguments (convertis en entier)
	for (int i = 0; i < taille; i++) {
		tableau[i] = *argv[i + 1];
	}

	for (int i = 0; i < taille - 1; i++) {
		// Trouver l'index du plus petit élément dans le sous-tableau non trié
		int minIndex = i;
		for (int j = i + 1; j < taille; j++) {
			if (tableau[j] < tableau[minIndex]) {
				minIndex = j;
			}
		}
		// Échanger l'élément actuel avec le plus petit élément trouvé
		if (minIndex != i) {
			int temp = tableau[i];
			tableau[i] = tableau[minIndex];
			tableau[minIndex] = temp;
		}
	}



	for (int i = 0; i < argc; i = i + 1) {
		std::cout << tableau[i] << "";
	}
	std::cout << std::endl;
	return 0;

}