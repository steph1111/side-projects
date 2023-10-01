#include <iostream>
#include <unordered_map>
#include <utility>
#include <fstream>

const int MAX_LOG = 5;
const std::string FILE_NAME = "hash.txt";

void input(std::string* usr_email, std::string* usr_pass) {
  std::cout << "Email: ";
  std::cin >> *usr_email;
  std::cout << "Password: ";
  std::cin >> *usr_pass;
}

bool login(std::string* usr_email, std::string* usr_pass, std::unordered_map<std::string,std::string>* user_data) {
  int log_ct = 1;
  std::cout << "\nLOGIN\n";
  input(usr_email, usr_pass);
  
  while(user_data->find(*usr_email) != user_data->end() && user_data->find(*usr_email)->second != *usr_pass && log_ct < MAX_LOG) {
    std::cout << "Incorrect email or password\n\n";
    input(usr_email, usr_pass);
    log_ct++; 
  }
  return log_ct < MAX_LOG;
}

void read_f(std::unordered_map<std::string,std::string>* user_data) {
  std::fstream fin(FILE_NAME);
  std::string email, pass; 
  while (fin >> email && fin >> pass) {
    user_data->insert(std::make_pair(email, pass));
  }
}

void write_f(std::string usr_email, std::string usr_pass) {
  std::fstream fout(FILE_NAME, std::fstream::app);
  fout << usr_email << "\t" << usr_pass << std::endl;
}

int main() {
  std::string set_email, usr_email, set_pass_1, set_pass_2, set_pass, usr_pass;
  std::hash<std::string>hash_str;
  std::unordered_map<std::string, std::string>user_data;
  int choice;

  read_f(&user_data);

  do {
    std::cout << "WELCOME\n  1. New user\n  2. Existing user\nChoice (1-2): ";
    std::cin >> choice;
  } while (choice != 1 && choice != 2);
  
  if (choice == 1) {
    std::cout << "\nSIGNUP\n";
    std::cout << "Email: ";
    std::cin >> set_email;
    if (user_data.find(set_email) != user_data.end()) {
      std::cout << "Existing user, continuing to login\n";
      choice = 2;
    } else {
      do {
        std::cout << "Password: ";
        std::cin >> set_pass_1;
        std::cout << "Confirm password: ";
        std::cin >> set_pass_2;
        std::cout << std::endl;
      } while(set_pass_1 != set_pass_2);
      set_pass = set_pass_1;
      write_f(set_email, set_pass);
      std::cout << "Account created\n";
    }
  }
  if (choice == 2) {
    std::string msg = login(&set_email, &set_pass, &user_data) ? 
    "Welcome " + set_email + "!\n" : "Exceeded " + std::string((char)(MAX_LOG + '0'), 1) + " attempts.\n";
    std::cout << msg << std::endl;
  }

  return 0;
}