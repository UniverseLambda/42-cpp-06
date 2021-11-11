#include <iostream>
#include <string>

#include <cstdlib>

template<typename _DisplayedType>
void displayInformation(std::string name, _DisplayedType value) {
	std::cout << name << ": " << value << std::endl;
}

template<typename _DisplayedType>
void displayInformation(std::string name, _DisplayedType value) {
	std::cout << name << ": " << value << std::endl;
}

void sigh(const std::string &str) {
	if (str == "-inff" || str == "-inf") {
		displayInformation("float", "-inf");
		displayInformation("double", "-inf");
	} else if (str == "+inff" || str == "+inf") {
		displayInformation("float", "+inf");
		displayInformation("double", "+inf");
	} else {
		displayInformation("float", "nan");
		displayInformation("double", "nan");
	}
}

void handleParam(std::string str) {
	for (std::size_t i = 0; i < str.size(); ++i) {
		str[i] = std::tolower(str[i]);
	}

	if (str.length() == 1 && (str[0] < '0' || str[0] > '9')) {
		char c = str[0];

		displayInformation("char", c);
		displayInformation("int", static_cast<int>(c));
		displayInformation("float", static_cast<float>(c));
		displayInformation("double", static_cast<double>(c));
	} else if (str == "-inff" || str == "+inff" || str == "nanf" ||
				str == "-inf" || str == "+inf" || str == "nan") {
		displayInformation("char", "impossible");
		displayInformation("int", "impossible");
		sigh(str);
	} else {
		const char *strBegin = str.c_str();
		char *strEnd;

		double value = std::strtod(strBegin, &strEnd);

		if (value == 0 && strEnd == strBegin) {
			displayInformation("char", "impossible");
			displayInformation("int", "impossible");
			displayInformation("float", "impossible");
			displayInformation("double", "impossible");
		} else {
			char charValue = static_cast<char>(value);



			if (!std::isprint(charValue)) {
				displayInformation("char", "non printable");
			} else {
				displayInformation("char", std::string("'") + charValue + "'");
			}

			displayInformation("int", static_cast<int>(value));
			displayInformation("float", static_cast<float>(value));
			displayInformation("double", static_cast<double>(value));
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << "Missing parameter" << std::endl;
		return 1;
	}

	if (argc > 2) {
		std::cerr << "Too much parameter" << std::endl;
		return 1;
	}

	if (argv[1][0] == '\0') {
		std::cerr << "Empty parameter" << std::endl;
		return 1;
	}

	handleParam(argv[1]);

	return 0;
}
