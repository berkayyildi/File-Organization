#include <vector>

using std::vector;



class BDT {
public:					// Would normally be private. Decleared public for testing purposes.
	class entry {
	public:
		bool valid;
		int data;

		entry() {
			valid = false;
		}
	};

	vector<entry> data_vec;

	int find_moving_cost(int, int) const;
	int h1(int) const;
	int h2(int) const;

	void * helper(void *);
	void * helper2(void *);
	void * helper3(void *);

public:

	BDT(int);
	void insert(int);
	int find_num_probes(int) const;
	double find_average_num_probes() const;

};