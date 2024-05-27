#pragma once
#include <iostream>
#include "FlyEye.h"

class Menu {
private:
	int choice = 0;
public:
	Menu() {
		choice = 0;
		while (choice != 2) {
			system("cls");
			printMenu();
			setChoice();
			switchChoice();
			system("pause");
		}
	}

	void printMenu() {
		std::cout << "Ojo de mosca con movimiento" << std::endl;
		std::cout << "1. Imprimir ojo de mosca" << std::endl;
		std::cout << "2. Salir" << std::endl;
	}
	void setChoice() {
		choice = getValidInt();
	}
	void switchChoice() {
		switch (choice) {
		case 1: {
			FlyEye flyeye;
			break;
		}
		case 2: {
			std::cout << "Hasta Luego :)" << std::endl;
			break;
		}
		default:
			std::cout << "Opción no valida. Intente de nuevo" << std::endl;
			break;
		}
	}
	static int getValidInt() {
		int number;

		while (!(std::cin >> number)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return 0;
		}

		return number;
	}

};

