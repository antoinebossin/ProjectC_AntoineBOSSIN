//< >
#include <iostream>
#include <string> 
struct IntStack5 {
	int a;
	int b;
	int c;
	int d;
	int e;

	void ini() {
		this->a = 1000; this->b = 1000; this->c = 1000; this->d = 1000; this->e = 1000; //on initialise à un nombre grand idéalement +l'infini
	};

	void print() {

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		std::cout << e << std::endl;

	};

	int pop() {
		// on identifie le dernier élément de la pile on le remet à +l'infini et on retourne sa valeur 
		if (e == 1000) {
			if (d == 1000) {
				if (c == 1000) {
					if (b == 1000) {
						int res = 0;
						res = a;
						a = 1000;
						return res;
					}
					else {
						int res = 0;
						res = b;
						b = 1000;
						return res;
					}
				}
				else {
					int res = 0;
					res = c;
					c = 1000;
					return res;
				}
			}
			else {
				int res = 0;
				res = d;
				d = 1000;
				return res;
			}

		}
	else {
		int res = 0;
		res = e;
		e = 1000;
		return res;
	}
	};

	void push(int valeur) {
		// on identifie le dernier élément de la pile et on ajoute la valeur donnée à celui du dessus
		if (e == 1000) {
			if (d == 1000) {
				if (c == 1000) {
					if (b == 1000) {
						if (a == 1000) {
							a = valeur;
							
							std::cout << "La valeur " + std::to_string(a) + " a été ajoutée" << std::endl;
						}
						else {
							b = valeur;
							
							std::cout << "La valeur " + std::to_string(b) + " a été ajoutée" << std::endl;
						}
					
					}
					else {
						c = valeur;
						
						std::cout << "La valeur " + std::to_string(c) + " a été ajoutée" << std::endl;
					}
				}
				else {
					d = valeur;
					
					std::cout << "La valeur " + std::to_string(d) + " a été ajoutée" << std::endl;
				}
			}
			else {
				e = valeur;
				
				std::cout << "La valeur " + std::to_string(e) + " a été ajoutée" << std::endl;
			
			}

		}
		else {
			std::cout << "stack pleine" << std::endl;
		}
	};

	
	void full() {
		if (a != 1000 && b != 1000 && c != 1000 && d != 1000 && e != 1000) {
		std::cout << "stack pleine" << std::endl;
		}
	
	std::cout << "stack non pleine" << std::endl;
	};
	void empty() {
		if (a == 1000 && b == 1000 && c == 1000 && d == 1000 && e == 1000) {
			
			std::cout << "stack vide" << std::endl;
		}
		
		std::cout << "stack non vide" << std::endl;
	};
};




int main() {

	IntStack5 stack;
	stack.ini() ;
	
	stack.push(1);
	stack.push(2);
	stack.push(3);

	stack.print();
	stack.full();
	stack.pop();
	stack.print();


}