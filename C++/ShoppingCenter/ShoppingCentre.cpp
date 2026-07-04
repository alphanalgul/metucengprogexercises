
#include <iostream>
#include <cstring>
#include "ShoppingCentre.h"
#include "Restaurant.h"
#include "Shop.h"

ShoppingCentre::ShoppingCentre() {
    name = new char[strlen("Undefined") + 1];
    strcpy(name, "Undefined");

    businessCount = 0;

    for (int i = 0; i < 50; i++) {
        businesses[i] = nullptr;
    }
}

ShoppingCentre::ShoppingCentre(char *sname) {
    name = new char[strlen(sname) + 1];
    strcpy(name, sname);

    businessCount = 0;

    for (int i = 0; i < 50; i++) {
        businesses[i] = nullptr;
    }
}

ShoppingCentre::~ShoppingCentre() {
    delete[] name;

    for (int i = 0; i < businessCount; i++) {
        delete businesses[i];
        businesses[i] = nullptr;
    }
}

ShoppingCentre::ShoppingCentre(const ShoppingCentre& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    businessCount = other.businessCount;

    for (int i = 0; i < 50; i++) {
        businesses[i] = nullptr;
    }

    for (int i = 0; i < businessCount; i++) {
        if (other.businesses[i] != nullptr) {
            if (other.businesses[i]->getType() == 0) {
                businesses[i] = new Restaurant(*(Restaurant*)other.businesses[i]);
            }
            else {
                businesses[i] = new Shop(*(Shop*)other.businesses[i]);
            }
        }
    }
}

ShoppingCentre& ShoppingCentre::operator=(const ShoppingCentre& other) {
    if (this != &other) {
        delete[] name;

        for (int i = 0; i < businessCount; i++) {
            delete businesses[i];
            businesses[i] = nullptr;
        }

        for (int i = 0; i < 50; i++) {
            businesses[i] = nullptr;
        }

        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        businessCount = other.businessCount;

        for (int i = 0; i < businessCount; i++) {
            if (other.businesses[i] != nullptr) {
                if (other.businesses[i]->getType() == 0) {
                    businesses[i] = new Restaurant(*(Restaurant*)other.businesses[i]);
                }
                else {
                    businesses[i] = new Shop(*(Shop*)other.businesses[i]);
                }
            }
        }
    }

    return *this;
}

void ShoppingCentre::setShoppingCentreName(char *sname) {
    delete[] name;

    name = new char[strlen(sname) + 1];
    strcpy(name, sname);
}

char *ShoppingCentre::getShoppingCentreName() {
    return name;
}

int ShoppingCentre::getNumberofBusiness() {
    return businessCount;
}

Business* ShoppingCentre::getBusinessAt(int index) {
    if (index >= 0 && index < businessCount) {
        return businesses[index];
    }

    return nullptr;
}

void ShoppingCentre::addBusiness() {
    if (businessCount >= 50) {
        std::cout << "Shopping centre is full. Cannot add more businesses." << std::endl;
        return;
    }

    int type;
    int businessSize;
    int seatNo;

    char *businessName = new char[100];

    std::cout << "\nEnter business type (0: Restaurant, 1: Clothing, 2: Technology, "
                 "3: Accessories, 4: Beauty):" << std::endl;
    std::cin >> type;

    std::cin.ignore();

    std::cout << "Enter business name:" << std::endl;
    std::cin.getline(businessName, 100);

    std::cout << "Enter business size (m2):" << std::endl;
    std::cin >> businessSize;

    if (type == 0) {
        std::cout << "Enter number of seats:" << std::endl;
        std::cin >> seatNo;

        Restaurant *r = new Restaurant();

        r->setBusinessName(businessName);
        r->setBusinessSize(businessSize);
        r->setSeatNum(seatNo);

        businesses[businessCount] = r;
        businessCount++;

        std::cout << "Business " << businessName << " added" << std::endl;
    }
    else if (type == 1 || type == 2 || type == 3 || type == 4) {
        Shop *s = new Shop();

        s->setBusinessName(businessName);
        s->setBusinessSize(businessSize);
        s->setShopType(type);

        businesses[businessCount] = s;
        businessCount++;

        std::cout << "Business " << businessName << " added" << std::endl;
    }
    else {
        std::cout << "Invalid business type." << std::endl;
    }

    delete[] businessName;
}

void ShoppingCentre::printBusinesses() {
    int i = 0;

    while (i < businessCount) {
        businesses[i]->printBusiness();
        i++;
    }
}

void ShoppingCentre::printBusinessesEmployees() {
    int i = 0;

    while (i < businessCount) {
        businesses[i]->printBusinessEmployees();
        i++;
    }
}

void ShoppingCentre::printShopsStatistics() {
    int clothingCount = 0;
    int technologyCount = 0;
    int accessoriesCount = 0;
    int beautyCount = 0;

    int i = 0;

    while (i < businessCount) {
        if (businesses[i]->getType() == 1) {
            clothingCount++;
        }
        else if (businesses[i]->getType() == 2) {
            technologyCount++;
        }
        else if (businesses[i]->getType() == 3) {
            accessoriesCount++;
        }
        else if (businesses[i]->getType() == 4) {
            beautyCount++;
        }

        i++;
    }

    std::cout << "\nClothing Shops: " << clothingCount << std::endl;
    std::cout << "Technology Shops: " << technologyCount << std::endl;
    std::cout << "Accessories Shops: " << accessoriesCount << std::endl;
    std::cout << "Beauty Shops: " << beautyCount << std::endl;
}

void ShoppingCentre::printShopsByType(int type) {
    int i = 0;

    while (i < businessCount) {
        if (businesses[i]->getType() == type) {
            businesses[i]->printBusiness();
        }

        i++;
    }
}

void ShoppingCentre::printSuitableRestaurants(int seat_no) {
    int i = 0;

    while (i < businessCount) {
        if (businesses[i]->getType() == 0) {
            Restaurant *r = (Restaurant*)businesses[i];

            if (r->checkSuitability(seat_no)) {
                r->printBusiness();
            }
        }

        i++;
    }
}

void ShoppingCentre::searchByEmployeeName(char *keyword) {
    int i = 0;

    while (i < businessCount) {
        businesses[i]->searchByName(keyword);
        i++;
    }
}

void ShoppingCentre::printLargestBusiness() {
    if (businessCount == 0) {
        std::cout << "There are no businesses in the shopping centre." << std::endl;
        return;
    }

    int maxSize = businesses[0]->getBusinessSize();

    int i = 1;

    while (i < businessCount) {
        if (businesses[i]->getBusinessSize() > maxSize) {
            maxSize = businesses[i]->getBusinessSize();
        }

        i++;
    }

    int j = 0;

    while (j < businessCount) {
        if (businesses[j]->getBusinessSize() == maxSize) {
            businesses[j]->printBusiness();
        }

        j++;
    }
}
