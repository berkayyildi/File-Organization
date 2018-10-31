#include <vector>

using std::vector;



class LQ{
public:					// Would normally be private. Decleared public for testing purposes.
	class lq_entry{
	public:
		bool valid;
		int data;

		lq_entry(){
			valid = false;
		}
	};

	vector<lq_entry> data_vec;


public:

	LQ(int);
	void insert(int);
	int find_num_probes(int) const;
	double find_average_num_probes() const;

};