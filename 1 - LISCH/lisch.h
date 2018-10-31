#include <vector>

using std::vector;



class LISCH{
public:					// Would normally be private. Decleared public for testing purposes.
	class lisch_entry{
	public:
		bool valid;
		int link;
		int data;

		lisch_entry(){
			valid = false;
		}
	};

	vector<lisch_entry> data_vec;


public:

	LISCH(int);
	void insert(int);
	int find_num_probes(int) const;
	double find_average_num_probes() const;
	bool does_include(int) const;

};
