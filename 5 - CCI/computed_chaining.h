#include <vector>
#include <iostream>
#include <iomanip>
using std::vector;
using std::ostream;
using std::endl;
using std::setw;

class ComputedChaining {
private:
	class entry {
	public:
		int key;
		int plink;
		bool valid;
		
		entry() { valid = false; }
	};

	int h1(int key);
	int h2(int key);

public:

	vector<entry> data;

	ComputedChaining(int size) {
		data.resize(size);
	}

	void insert(int key);
	int remove(int pos);
	void remove(vector<int> &);

	friend ostream& operator<<(ostream& out, const ComputedChaining & chain) {
		out << "------------------------------------------------" << endl;
		for (int i = 0; i < chain.data.size(); i++) {
			out << setw(4) << i << ":";
			if (chain.data[i].valid) {
				out << setw(7) << chain.data[i].key << setw(12) << chain.data[i].plink;
			}
			out << endl;
		}
		out << "------------------------------------------------" << endl;
		return out;
	}
};