#include "Connector.h"
#include <iostream>

using namespace std;

Connector::Connector()  {
    	this->left = NULL;
    	this->right = NULL;
}

Connector::Connector(Base* left, Base* right) {
    	this->left = left;
    	this->right = right;
}

