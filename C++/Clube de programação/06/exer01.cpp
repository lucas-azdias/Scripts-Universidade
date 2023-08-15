#include <stack>
#include <string>
#include <iostream>


int main() {
	std::stack<std::string> values;
	std::string last;

	while (true)
	{
		std::string cmd;

		std::cout << "Digite o comando: ";
		std::cin >> cmd;

		if (cmd == "inserir") {
			std::string text;
			std::cout << "Digite o texto: ";
			std::cin >> text;
			values.push(text);
		}
		else if (cmd == "apagar") {
			last = values.top();
			values.pop();
		}
		else if (cmd == "desfazer" and last != "") {
			values.push(last);
			last = "";
		}
		else if (cmd == "kill") {
			break;
		}

		std::cout << "\n";
		// Show
		std::stack<std::string> copy = values;
		while (!copy.empty()) {
			std::cout << copy.top() << " ";
			copy.pop();
		}
		std::cout << "\n\n";
	}

	return 0;
}
