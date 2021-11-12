#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

#include <cstdlib>
#include <cmath>
#include <cerrno>

template<typename _DisplayedType>
void displayInformation(std::string name, _DisplayedType value) {
	std::cout << name << ": " << value << std::endl;
}

template<>
void displayInformation(std::string name, float value) {
	std::cout << std::setprecision(50) << name << ": " << value;

	if (value - static_cast<int>(value) == 0) {
		std::cout << ".0";
	}
	std::cout << "f" << std::endl;
}

template<>
void displayInformation(std::string name, double value) {
	std::cout << std::setprecision(50) << name << ": " << value;

	if (value - static_cast<int>(value) == 0) {
		std::cout << ".0";
	}
	std::cout << std::endl;
}

template<typename _TargetType, typename _SourceType>
void tryCast(std::string name, _SourceType from) {
	if (from < -(std::numeric_limits<_TargetType>::max()) || from > std::numeric_limits<_TargetType>::max()) {
		displayInformation(name, "impossible");
	} else {
		displayInformation(name, static_cast<_TargetType>(from));
	}
}

void sigh(const std::string &str) {
	if (str == "-inff" || str == "-inf") {
		displayInformation("float", "-inff");
		displayInformation("double", "-inf");
	} else if (str == "+inff" || str == "+inf") {
		displayInformation("float", "+inff");
		displayInformation("double", "+inf");
	} else {
		displayInformation("float", "nanf");
		displayInformation("double", "nan");
	}
}

bool convDouble(const std::string &str, double &value) {
	const char *strBegin = str.c_str();
	char *strEnd;

	value = std::strtod(strBegin, &strEnd);

	if (value == 0 && strEnd == strBegin) {
		return false;
	} else if (strEnd[0] != '\0' && (strEnd[0] != 'f' || strEnd[1] != '\0')) {
		return false;
	} else if (value == HUGE_VAL && errno == ERANGE) {
		return false;
	}
	return true;
}

void handleParam(std::string str) {
	for (std::size_t i = 0; i < str.size(); ++i) {
		str[i] = std::tolower(str[i]);
	}

	if (str.length() == 1 && (str[0] < '0' || str[0] > '9')) {
		char c = str[0];

		displayInformation("char", std::string("'") + c + "'");
		displayInformation("int", static_cast<int>(c));
		displayInformation("float", static_cast<float>(c));
		displayInformation("double", static_cast<double>(c));
	} else if (str == "-inff" || str == "+inff" || str == "nanf" ||
				str == "-inf" || str == "+inf" || str == "nan") {
		displayInformation("char", "impossible");
		displayInformation("int", "impossible");
		sigh(str);
	} else {
		double value;

		if (!convDouble(str, value)) {
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

			tryCast<int>("int", value);
			tryCast<float>("float", value);
			tryCast<double>("double", value);
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
