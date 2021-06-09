#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>

std::string itemIdMaker(std::string base, int size);
void register_user();
std::string log_in();
void menuRegisterAndLogin();
void addProduct();
std::string getProductId(std::string category);

#endif