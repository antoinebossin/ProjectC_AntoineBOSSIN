#include <iostream>

int main(int argc, const int* argv[]) {
	if (argc < 2) {
		std::cout << "le tableau est d�j� tri�, il ne contient qu'un �l�ment" << std::endl;
		return 1;
	}


	// Cr�er un tableau d'entiers avec les arguments pass�s
	int taille = argc - 1;  // Le nombre d'�l�ments � trier (argc - 1, car argv[0] est le nom du programme)
	int* tableau = new int[taille];

	// Remplir le tableau avec les arguments (convertis en entier)
	for (int i = 0; i < taille; i++) {
		tableau[i] = *argv[i + 1];
	}

	for (int i = 0; i < taille - 1; i++) {
		// Trouver l'index du plus petit �l�ment dans le sous-tableau non tri�
		int minIndex = i;
		for (int j = i + 1; j < taille; j++) {
			if (tableau[j] < tableau[minIndex]) {
				minIndex = j;
			}
		}
		// �changer l'�l�ment actuel avec le plus petit �l�ment trouv�
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