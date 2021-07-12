#include <cstdio>
#include <iostream>
#include <vector>
#include <cerrno>
#include <cstring>
#include <fstream>
#include <vector>
#include <time.h>
/*
	C++ Essential Training  by Bill Weinman 
	linkedin Learning
	
	Following along in the course and taking on the challenge at the end of each ch win my implementation
*/


//ch 2 count elements
void countStringEle(char* str) {
	int count = 0;
	// For loop auto increment at the "post loop control"
	for (count = 0; str[count] !=0; count++);
	printf("The number of char is: %d\n", count);
}

//ch 3 library card catalog using structure
struct catalog{
	char * title;
	char * author;
	char * publisher;
	char * subject;
	//char * isbn;
	//char * worldCat;
	//int deweyDec;
	int yearPub;
	//int yearAcq;
	//int quantity;
	
	void print(){
		printf("The Tittle is : %s\n", title);
		printf("The Author is : %s\n", author);
		printf("The Publisher is : %s\n", publisher);
		printf("The Subject is : %s\n", subject);
		printf("Year Published is : %d\n", yearPub);
	}
};

//ch 4 Prime numbers      my implementation find prime up to n 
void prime(int n){
	bool prime = false;
	std::vector<int> primes;
	printf("Prime number are : ");
	for (int i =2; i <= n; i++){
		
		prime = true;
		for (int j : primes){
			if (i%j == 0){
				prime = false;
				break;
			}
		}
		if (prime) {
			primes.push_back(i);
			printf("%d ", i);	
		}
	}
}
	
//ch 5 Non-recursive factorial
int nfactorial(int num){
	int val = num;
	while(num !=1){
		num--;
		val *= num;
	}
	return val;
}

//ch 6 non-member operator
	/*
	make the challange ch 6 file compile and run.
	since it involves the course file it will not be included in this file.
	the principle is operator overloading 
		in the challange file it only takes in the right hand side, need to also pass in the left hand side
		the rest is the numberator add, subtract, multiply, divide given two rational numbers
	*/

//ch 7 template factorial given ch 5 sol
template<typename T>
T temp_factorial(T num){
	T val = num;
	while(num !=1){
		num--;
		val *= num;
		std::cout<<val<<std::endl;
	}
	return val;
}

//ch 8 transform a file

struct Item{
	int sku;
	char name[128];
	char desc[128];
};

size_t * two_tab_loc(const char *s, int len, char c){
	size_t index[2] = {0,0};
	for (int i = 0; i< len; i++){
		if (s[i] == c){
			if (index[0] == 0){
				index[0] = i;
			}
			else{
				index[1] = i;
			}
		}		
	}
	return index;
	
}
constexpr int maxstring = 1024;
void transform(FILE * file){
	char buf[maxstring];				// character array
	while(fgets(buf, maxstring, file)){ // store each line that ends with '\n' to buf with max size maxstring
		size_t * count= two_tab_loc(buf, strlen(buf), '\t');
		
		buf[count[0]] = buf[count[1]] = 0; // so when concat there is a place to stop
		
		Item temp;
		temp.sku = atoi(buf);
		strcpy(temp.name, buf + count[0]+1);	// buf start of char arry than point to location of the tab, plus 1 to skip that char
        strcpy(temp.desc, buf + count[1]+1);
        printf("sku: %d, name: %s, desc: %s", temp.sku, temp.name, temp.desc);
		
	}
	
}

//ch 9 Use STL for Problem in ch 8 
void ch_nine(std::ifstream & file){
	std::string line;
	while(getline(file,line)){
		std::string out ="sku: ";
		int count = 0;
		for (char i: line){
			if (i == '\n') break;
			if (i == '\t'){
				if (count == 0){
					out = out + ", name: "; 
				}
				else out = out + ", desc: "; 
				count++;
			}
			else
				out += i;
		}
		std::cout<< out<<std::endl;
	}
	
}

//ch 10 A deck of cards
class Deck{
	int num_cards = 52;
	std::vector<std::string> cards;
	
	public:
		void suffle_deck(){
			for (int i =0; i<cards.size();i++){
				int random = rand() % 51;
				std::string temp = cards[i];
				cards[i] = cards[random];
				cards[random] = temp;
			}
		}
		
		std::string deal(int amount){
			std::string err = "dealing more cards then available, skip this deal of: " + std::to_string(amount);
			try{
				std::string deals = "";
				if (amount > cards.size() || cards.empty()){
					throw err;
				}
				for (int i = 0; i< amount; i++){
				deals += cards.back()+ " ";
				cards.pop_back();
				num_cards--;
			
				}
				std::cout<< deals<<std::endl;
				return deals;
			}catch(std::string e){
				std::cout<<e<<std::endl;
				return e;
			}
		}
		
		Deck(){
			srand((unsigned) time(nullptr));
			rand();
			
			for (int i =1; i <= 13; i++){
				std::string c = std::to_string(i);
				if (i == 1) c = "A";
				if (i == 11) c = "J";
				if (i == 12) c = "Q";
				if (i == 13) c = "K";
				cards.push_back(c + "s"); // Spade
				cards.push_back(c + "h"); // heart
				cards.push_back(c + "d"); // diamonds
				cards.push_back(c + "c"); // clubs
			}
			std::cout<<cards[51]<<std::endl;
			suffle_deck();
		}
		
		void remain(){
			std::cout<<cards.size()<<std::endl;
		}
		
		
};

int main() {

	//ch 2 count elements	
	char* str = "This is a null-terminated String.";
	countStringEle(str);
	
	//ch 3 library card catalog 
	catalog c0 = {
		"Advantures of Sherlock Holmes" , "Arthur Conan", "Harper & Brothers", "Franklin Square", 1892
	};
	c0.print();

	//ch 4 Prime numbers
	prime(100);
	printf("\n");
	
	//ch 5 Non-recursive factorial
	int factorial = nfactorial(5);
	printf("factorial of 5 is: %d\n", factorial);
	
	//ch 6 non-member operator
	
	//ch 7 template factorial given ch 5 sol
	int tem_fac = temp_factorial(5.0);
	printf("Templated factorial of 5 is: %d\n", tem_fac);
	
	//ch 8 transform a file
	
	FILE * fr = fopen("./Ex_Files_C_Plus_Plus_EssT/Chap08/items.txt", "r");
	if(!fr){
		const char * errstr = strerror(errno);
		printf("cannot open file (%d):", errno, errstr);
		return 1;
	}
	transform(fr);
	
	//ch 9 Use STL for Problem in ch 8 
	printf("\n------ch 9 output below ------- same problem as ch 8 but use STL\n");
	std::ifstream infile("./Ex_Files_C_Plus_Plus_EssT/Chap08/items.txt");
	ch_nine(infile);
	infile.close();
	
	//ch 10 A deck of cards
	Deck deck;
	deck.remain();
	deck.deal(5);
	deck.deal(5);
	deck.deal(50);
	deck.remain();
	
}
