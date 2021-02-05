#include "WAEP.h"

void init(int T) {

}

int janken(int P) {
	if (!P) {
		return 0;
	}
	else if (P == 2) {
		return 2;
	}
	else {
		return 5;
	}
}