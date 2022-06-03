#include <iostream>
#include <set>
#include <unordered_set>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

//Task 1

template<class T>
void PrintContainer(const T& cont) {
	size_t size = cont.size();
	for_each(cont.begin(), cont.end(), [count = 0, &size](const auto& i)mutable {
		count++;
		cout << i;
		if (count != size) { cout << ", "; }

	});
	cout << endl << endl;
}

template <class T, class Iterator>
void PrintUnique(const Iterator& begin, const Iterator& end) {
	unordered_set<T>set;
	copy(begin, end, inserter(set, set.end()));
	copy(set.begin(), set.end(), ostream_iterator<T>(cout, ", "));
	cout << endl << endl;
}

//Task 2

multimap<int, string> WorkWithWords(const string& text) {

	multimap<int, string>Words;

	auto Begin = text.begin();
	auto End = text.end();
	auto WhereIsThePoint = find(Begin, End, '.');

	while (Begin != End && distance(Begin, WhereIsThePoint) > 0) {
		string WordsBeforePointer = string{ Begin,WhereIsThePoint };
		int WordsSumm = count(WordsBeforePointer.begin(), WordsBeforePointer.end(), ' ');
		Words.insert(make_pair(WordsSumm, move(WordsBeforePointer)));
		Begin = next(WhereIsThePoint, 1);
		WhereIsThePoint = find(Begin, End, '.');

	}
	return Words;
}
int main()
{
	//Task 1
	cout << "Task 1. Work with Unique"<<endl;
	vector<int>Vec1{ 1,2,3,4,5,6,7,7,8,9 };
	cout << "Print some vecor :" << endl;
	PrintContainer(Vec1);
	cout << "Print unque vector :" << endl;
	PrintUnique<int>(Vec1.begin(), Vec1.end());


	list<int>List1{ 1,2,3,4,5,6,6,7,8,9 };


	cout << "Print some list :" << endl;
	PrintContainer(List1);
	cout << "Print unique list :" << endl;
	PrintUnique<int>(List1.begin(), List1.end());
	cout << endl;

	//Task 2

	string txt;
	cout <<"Task2. How many words."<<endl;
	cout << "Enter some text :"<<endl;
	getline(cin, txt);
	cout << endl;

	cout << "Your Text got :"<<endl;
	for (const auto& x : WorkWithWords(txt)) {
		cout <<" number of words : " << x.first <<", proposal :" << x.second << endl;
	}


}

