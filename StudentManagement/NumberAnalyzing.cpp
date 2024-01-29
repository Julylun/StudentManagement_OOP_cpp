#include "NumberAnalyzing.h"

int countLigitsNumber(int number) {
	int returnValue = 0;
	if (number == 0) return 1;
	while (number != 0){
		returnValue++;
		number /= 10;
	}
	return returnValue;
}
int charToNumber(char character) {
	return int(character - 48);
}

int stringToNumber(std::string str) {
	try {
		int returnNumber(0);
		if (str.length() > 8) throw OutLigitsException();
		for (int i(0); i < str.length(); i++) {
			returnNumber *= 10;
			returnNumber += charToNumber(str[i]);
		}
		return returnNumber;
	}
	catch (OutLigitsException ole){
		std::cout << "\nOutLigitsException";
		return -150905;
	}
}

char numberToChar(int number) {
	return char(number + 48);
}

std::string numberToString(int number) {
	if(number >= 0 && number <= 9) return numberToChar(number)+"";
	else {
		std::string returnString = "";
		while (number > 0)
		{
			returnString = numberToChar(number%10) + returnString;
			number /= 10;
			//std::cout << "numberToString is looping: " << number << "\n";
		}
		return returnString;
	}
}