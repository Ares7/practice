#include <iostream>
#include <sys/types.h>
#include <sys/stat.h> // for file functions, e.g. open()
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <unistd.h>


#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <bitset>

using namespace std;

class RandomLong
{
	/// The state
	uint64_t state;
	
public:
	/// Constructor
	explicit RandomLong(uint64_t seed=88172645463325252ull) : state(seed) {}
	
	/// Get the next value
	uint64_t next() { state^=(state<<13); state^=(state>>7); return (state^=(state<<17)); }
};

/* posix_fallocate is mising in macOS */
int posix_fallocate(int fd, off_t offset, off_t len)
{
	fstore_t fst;
	fst.fst_flags = F_ALLOCATECONTIG;
	fst.fst_posmode = F_PEOFPOSMODE;
	fst.fst_offset = offset;
	fst.fst_length = len;
	fst.fst_bytesalloc = 0;
	return fcntl( fd, F_PREALLOCATE, &fst );
}

int generate_data(int argc, char* argv[])
{
	if (argc < 3) {
		std::cerr << "usage: " << argv[0] << " <file name> <number of elements>" << std::endl;
		return -1;
	}
	RandomLong rand;
	unsigned n = atoi(argv[2]);
	if (n==0) {
		std::cerr << "invalid length: " << argv[2] << std::endl;
		return -1;
	}
	int fd, ret;
	if ((fd = open(argv[1], O_CREAT|O_TRUNC|O_WRONLY, S_IRUSR|S_IWUSR)) < 0) {
		std::cerr << "cannot open file '" << argv[1] << "': " << strerror(errno) << std::endl;
		return -1;
	}
	if ((ret = posix_fallocate(fd, 0, n*sizeof(uint64_t))) != 0)
		std::cerr << "warning: could not allocate file space: " << strerror(ret) << std::endl;
	for (unsigned i=0; i<n; ++i) {
		uint64_t x = rand.next();
		if (write(fd, &x, sizeof(uint64_t)) < 0) {
			std::cout << "error writing to " << argv[1] << ": " << strerror(errno) << std::endl;
		}
	}
	close(fd);
	
	return 0;
}

int main(int argc, char* argv[]) {

	char *filename = "/Users/sergey/Documents/practice/task1.ems/task1.ems/test.txt";
	ifstream myfile (filename, ios::in | ios::binary );
	//test.txt
	//64unsingedintdata
	//std::cout << "test! ";
	if (myfile.is_open())
	{
		std::cout << "OK 1! ";
		uint64_t a=8;
		uint64_t size = myfile.tellg();
	
		char * memblock = new char [size];
		myfile.read(memblock,sizeof(size));
	
		cout << memblock<<", ";
	
		a=atoi(memblock);
		std::cout << "a = " << std::bitset<64>(a)  << std::endl;

		//another way of putting it in a binary view:
		std::cout.write(reinterpret_cast<const char*>(&a), sizeof a);

	}
	
	int fd= open(filename, O_RDONLY);
	if (fd!=-1)
		{
			std::cout << "OK 2! ";
			uint64_t a;
			read(fd, &a, sizeof(uint64_t));
			cout << a<<", ";
//			read(fd, &a, sizeof(uint64_t));
//			cout << a<<", ";
		}
	close(fd);
	
	
//	for (unsigned i=0; i<10; ++i) {
//		
//		uint64_t x;
//		read(fd, &x, sizeof(uint64_t));
//		std::cout << "integers: " << argv[1] << ": " << strerror(errno) << std::endl;
//		}
//	
//	std::fstream myfile("D:\\data.txt", std::ios_base::in);
//	

	
	//getchar();

	return 0;
}
