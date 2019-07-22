#include "And.h"

using namespace std;

//constructors
And::And(): Connector() {}
And::And(Base *left, Base *right): Connector(left,right) {}

bool And::execute() {
	bool var = true;
    	if(left->execute()){
		if(right->execute()){
           	var = true;
		}	
       		else { // if right child doesnt execute properly
           	var = false;
		}
        }
    	else { 
 		var = false;
        }

	return var;
}

