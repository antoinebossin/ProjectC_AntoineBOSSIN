//< >
//liste chainé
//transformer la stack en liste 
#include <iostream>

struct Shape {
	int nature;
	virtual float area() {
		std::cout << "fonction virtuelle Shape" << std::endl;
		return 0;
	};
	virtual ~Shape() {};
	
};

struct Circle : public Shape {
	float radius;
	int nature;



	Circle() {         //opérateur init qui def un cercle de rayon 0 
		nature = 0;
		radius = 1;
	};

	float area() {
		float A = 3.14 * radius;
		std::cout << "Le calcul d'aire du cercle donne" << A << std::endl;
		return A;
	};

};

struct Square : public Shape {
	float x;
	int nature;

	Square() {
		nature = 1;
		x = 1;

	}

	float area() {
		float A = x * x;
		std::cout << "le calcul d'aire donne" << A << std::endl;
		return A;
	}
};

struct IntStack {
	Shape ** tab;
	int top;
	int size;

	void push(Shape valeur) {
		tab[top] = & valeur;
		top += 1;
	};

	Shape * pop() {
		Shape* s = tab[top];
		tab[top] = 0 ; // pointeur nul 
		top -= 1;
		return s;
	};

	bool empty() {
		if (top = 0) {
			return true;
		}
		else {
			return false;
		};
	};

	
	void print() {
		for (int i = 0; i < top; i = i + 1) {
			std::cout << "la nature de l'object" << i + 1 << "est un" << ((*((this->tab)[i])).nature) << std::endl;
		};
	}; 
	
	
	IntStack(int new_size) {   //nouveau constructeur par défaut 
		
		top = 0;
		size = new_size;
		try {        //utilisation horrible de try car ce n'est pas un cas rare
			tab = new Shape * [size];


			for (int i = 0; i < size; i = i + 1) {
				tab[i] = 0;
			};
			std::cout << "par défaut" << std::endl;
			throw 1;
		}
		catch(...) {
			std::cout << "got an error" << std::endl;
		}
	};

	IntStack(const IntStack& other) {   // constructeur de copie 
		size = other.size;
		top = other.top;
		tab = new Shape * [size];
		for (int i = 0; i <= top; i++) { 
			*tab[i] = *other.tab[i];
		};
		std::cout << "op de copie utilisé" << std::endl;
		
	};
	

	IntStack& operator= (const IntStack& other) {
		delete[] tab;
		size = other.size;
		top = other.top;
		tab = new Shape * [size];
		for (int i = 0; i <= top; i++) {
			*tab[i] = *other.tab[i];
		};
		std::cout << "op = utilisé" << std::endl;
		return *this;
	};

	~IntStack() {
		delete tab;
		std::cout << "destructeur appelé" << std::endl;
	};

	Shape * operator -- () {
		Shape* s = this->tab[top];
		this->tab[top] = 0;
		this->top -= 1;
		std::cout << "opérateur pop appelé" << std::endl;
		return s;
	};

	void Sarea() {
		float area = 0;
		for (int i = 0; i <= top; i += 1) {
			area += (*(tab[i])).area();
		};
		std::cout << area << std::endl;
	};

	void operator + (Shape a) {
		this->tab[top] = &a;
		this->top += 1;
		std::cout << "opérateur push appelé" << std::endl;
	};
};






int main() {
	//définition des formes
	Circle a1;
	Circle a2;
	Circle a3;
	Circle a4;

	Square s1;
	Square s2;
	Square s3;
	Square s4;

	a1.radius = 5;
	a2.radius = 2;
	a4.radius = 0.5;

	s2.x = 3;
	s3.x = 0.1;
	s4.x = 10;

	IntStack stack(6);
	
	stack.push(a3);
	stack.push(s1);
	stack.push(a2);
	stack.push(a4);

	(stack).operator+ (s4);
	stack.print();

	
	stack.pop();
	(stack).operator-- ();
	//stack.print();

	IntStack aux = stack;
	aux.pop();
	//aux.print();

	IntStack a(8);
	a = stack;
	//a.print();

	s3.area();
	a1.area();

	Shape* A = &s3;
	s3.area(); //garde en tête que s3 est un carré car on a def une fonction virtuelle

	// somme des aires 
	/*
	double area1 = 0.0;
	while (!stack.empty()) {
		Shape* x = stack.pop();
		area1 += (*x).area();
	};
	std::cout << 
	*/

	stack.Sarea();   //Pb à régler 

	std::shared_ptr<IntStack> ptr1 = std::make_shared<IntStack>(10);

}


