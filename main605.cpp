 /*
 * Kcracken v0.1
 *
 * Thank you to Dr. Dr. Morton,
 * Whom without the help of his
 * once in his classroom, I
 * would not have reviled math
 * as I now do -thexiv
*/

#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <locale>
#include <exception>
#include <set>
#include <time.h>

using namespace std;

/**
 *
 * To unzip, these need to be decompressed from the set_binary_tree() function.
 * Then, they need to be found again according to the c and z values from make_breadcrumbs.
 * This needs to be repeated the same amount of times as was done to compress.
 *
 * File dimensions per set of `credit` once binary tree is set
 * 1st	   2nd	          3rd		   4th	           5th	6th		7th	    8th
 *				    	Condensed
 *					to 64 bits
 *					or less
 * [lambda][alpha][unique bytes][::2::4][2-byte range][message bytes][::0;1]
 *
 */

class S_Rend {

	protected:
	bitset<8> large_lambda = 0, lambda = 0, delta = 0, alpha = 0;
	bitset<8> lambda_now = 0, alpha_now = 0;

	public:
	int times_looped = 1;
	int characters_wide = 5;
	int length = 0, flag = 0;
	long tally = 0, size_of_block = 0;
	short int extra = 0;
	short int max_hashes = 800, max_byte = 255;
	short int beans = 0, bytes = 0;
	char first_character = 0, last_character = 0, current = 0;
	string in_file = "";
	string returning = "";
	long tallyho = 0, really = 0;

	S_Rend() { };
	~S_Rend() { };
	vector<char> make_breadcrumbs(string);
	void compress(ifstream&,ofstream&);
	bool compress_points(ofstream&, string);
	vector<char> set_binary_tree(ofstream&, vector<char>);
	void algorithm_decompress(uint8_t&, uint8_t&, short int);
	void uncompress(ofstream&, string);
	vector<uint32_t> algorithm_bits(long long int, int);
	bool test_max(string, uint32_t);
	uint64_t get_ints(string, uint32_t);
	void xor_stuffing(ofstream&, string, uint8_t&, uint8_t&);
} n;

/*+**- Project::Sailwinds -**+*/
//added print method for vector**

/* *
 *
 * void S_Rend::make_breadcrumbs()
 * Finds fastest route through lambda byte.
 * 
 * length: index for credit
 * first_character/last_character: byte found / current byte to find
 * lambda: total of all bytes per max_hashes
 * alpha: holds z for hashing
 * z: incremented to find last_character through
 * 	adding 1 more to alpha than before
 * c: consecutive hits with algorithm
 * Alg. [1] produces byte
 * Alg. [2] produces multiple answers in sequence with algorithm
 *
 *
 *
 */

vector<char> S_Rend::make_breadcrumbs(string credit) {
	uint8_t x = 0, v = 0;
	uint8_t current = 0; // current z
	bitset<8> y = 0;
	length = 0; // index of credit[]

	vector<char> bean_place;
	string bean_trace;
	bean_place.push_back(large_lambda.to_ulong());
	uint8_t c = 0; // count of sequenced unwrapping
	uint8_t z = 0; // alpha substitute

	last_character = credit[length%credit.length()]; // comparative variable to first_character (delta)

	while (bean_trace != credit) {

	// Algorithm [1];
		lambda = lambda_now;

		alpha = z %= 256;

		delta = (alpha.to_ulong() ^ lambda.to_ulong());

		first_character = delta.to_ulong();
		if ((char)first_character == (char)last_character) {
			if (bean_place.size() == 1) {
				bean_place.push_back(z);
				if (z == 0 || z == 255)
					bean_place.push_back(255);
			}
			do {
				c++;
			// Algorithm [2];
				lambda ^= (delta.to_ulong() ^ alpha.to_ulong()) - 1;
				alpha_now = (delta.to_ulong() ^ lambda.to_ulong());
				lambda_now = lambda;
				delta = (alpha_now.to_ulong() ^ lambda.to_ulong());
				if (c%2 == 0) {
					bean_place.push_back(1);
				///	if ((char)0 == '\0')
				//	exit(0);
					bean_trace.push_back((char)credit.at(length));
					length++;
					continue;
				}
				else if (length + 1 < credit.size() && (char)delta.to_ulong() == credit.at(length + 1)) {
					length++;
					bean_trace.push_back((char)credit.at(length));
					if (bean_trace == credit) {
						bean_place.push_back(z);
						if (z == 0 || z == 255)
							bean_place.push_back(255);
						bean_trace.clear();
				//		printf("*");
						credit.clear();
						return bean_place;
					}
				}
				else if (length + 1 < credit.size() && c == 1 && (char)delta.to_ulong() != credit.at(length + 1)) {
					bean_trace.push_back((char)credit.at(length));
					z %= 256;
					length++;
				//	bean_place.push_back(1);
					bean_place.push_back(z);
					if (z < 4 || z == 255)
						bean_place.push_back(255);
					c = 0;
				}
				if (bean_trace == credit && c == 1) {
				//	if (bean_place[bean_place.size()-1] != (char)(255)) {
				//		bean_place.push_back(1);
						bean_place.push_back(z);
						if (z == 0 || z == 255)
							bean_place.push_back(255);
				//	}
				//	printf("*");
					bean_trace.clear();
					credit.clear();
					return bean_place;
				}
				if (bean_trace == credit) {
				//	if (bean_place[bean_place.size()-1] != (char)(255)) {
						bean_place.push_back(z);
						if (z == 0 || z == 255)
							bean_place.push_back(255);
				//	}
				//	printf("*");
					bean_trace.clear();
					credit.clear();
					return bean_place;
				}
				first_character = delta.to_ulong();
			//	z *= z;
			} while (length < credit.size() && first_character == credit.at(length));
			if (length + 1 < credit.length())
				last_character = credit.at(length);
			if (bean_trace == credit) {
				bean_place.push_back(z);
				if (z == 0 || z == 255)
					bean_place.push_back(255);
				bean_trace.clear();
			//	printf("*");
				credit.clear();
				return bean_place;
			}
		//	z = 0;
		}
		z++;
	}
	if (bean_trace == credit) {
		bean_trace.clear();
		//printf("*");
		credit.clear();
		return bean_place;
	}
	//cout << "Error During Archiving " << bean_trace.size() << " " << credit.size() << "\n" <<flush;
	bean_trace.clear();
	exit(0);
}

/* *
 *
 * void S_Rend::set_binary_tree(char, string&)
 * zip files
 * bean_place[0] = lambda
 * bean_place[0] = first alpha (z)
 * total = numbre of unique bytes at this point
 * all_vect.size() >> 8 = how many bean_places are three without the ones listed here
 * 	all_vect.size() >> 8 << 8 = second mash of it here. 
 * function takes a total, populates with bytes that are not to be zipped
 * and fills in the rest within the scope of `total` and all_vect.size()
 *
 * 1st	   2nd	          3rd		   4th	           5th	6th
 *					Condensed
 * 					to 64 bits
 *					or less
 * [lambda][alpha][unique bytes][::2::4][2-byte range][message bytes][::0;1]
 *
 */


vector<char> S_Rend::set_binary_tree(ofstream& out, vector<char> all_vect) {
	uint64_t f = 0, cnt_8 = 0, temp = 0;
	//cout << all_vect.size() << flush;
	vector<char> credit;
	credit.push_back((char)(all_vect[0]));
	credit.push_back((char)(all_vect[1]));
	vector<string> all_now;
	vector<uint32_t> all_ints, indices, all_outs;
	all_vect.erase(all_vect.begin(),all_vect.begin()+2);
	//cout << all_vect.size() << flush;
	set<string> all_in;
	string m = "";

	for (char n : all_vect) {
		if (m.length() == characters_wide) {
			all_in.insert(m);
			all_now.push_back(m);
			m = "";
		}
		m = m + n;
	}
	credit.push_back((char)(all_in.size() >> 8));
	if (m.length() >= 1) {
		all_in.insert(m);
		all_now.push_back(m);
	}
	for (string x : all_in)
		for (char v : x)
			credit.push_back(v);
//	cout << "!";
	credit.push_back((char)':');
	credit.push_back((char)':');
	credit.push_back('2');
	int total = all_in.size();
// Third message of block [1 byte] (unique count of bytes in block; total)
// Fourth message of block [x byte] (unique bytes in block)

// Fifth message of block [bean_place = all_vect] (stacking the deck)
	int j = 0, h = 0, powr = 1, a = 0, y = 0;
//	printf("%d ", total);
	for (string m : all_now) {
	// Find character in all_in Set
		auto r = find(all_in.begin(),all_in.end(),m);
		long int y = distance(all_in.begin(), r);
		all_ints.push_back(y);
		if (h < y)
			h = y;
	// Sets in indexable mode to start at 0;	
	}
//	cout << "@" << flush;
	all_now.clear();
	int xx = 0;
// If 3rd message is 2, it moves over 1, and uses 0 or 1;
	f = 0;
	a = 0;
	int b = 0, z = 0;

	credit.push_back((char)':');
	credit.push_back((char)':');
	credit.push_back((char)'4');
	credit.push_back((char)h >> 8);
	credit.push_back((char)h);
	vector<uint64_t> ff;
	string ty = "";
	for (uint32_t x : all_ints) {
		char n[3] = { (uint8_t)(x >> 8), (uint8_t)(x), '\0' };
		if ('\0' == n[0] && '\0' == n[1]) {
			ty.push_back('*');
			ty.push_back('^');
		}
		if ('\0' == n[0])
			ty.push_back('*');
		if ('\0' == n[1])
			ty.push_back('^');
		if (ty.back() == '^')
			continue;
		else
			ty.push_back(x);
		if (test_max(ty,h)) {
			ff.push_back(get_ints(ty,h));
			ty.clear();
		}
	}
	if (test_max(ty,h)) {
		ff.push_back(get_ints(ty,h));
		ty.clear();
	}
	if (ty.length() > 0)
		ff.push_back(get_ints(ty,h));

	all_ints.clear();
	int hi = 0;
	string k = "";
	all_now.clear();
	for (uint64_t x : ff) {
		hi = 1;
		f = x;
		while (f > 0) {
			uint8_t m = (f >> (8*(8-hi)));
			uint64_t g = f << (8 * hi);
			if (m == '\0')
				credit.push_back('#');
			else
				credit.push_back((char)m);
			f = g >>= 8;
			hi++;
		}
	//	all_now.push_back(k);
	//	k.clear();
	}
// If 3rd message is > 7 we go to normal bytes;
// Pop a terminator on the end
//	for (string x : all_now) {
//		for(char yy : x)
//			credit.push_back(yy);
//	}
	credit.push_back((char)':');
	credit.push_back((char)':');
	credit.push_back((char)'0');
	vector<char> temp_cred = credit;
	credit.clear();
	return temp_cred;
}

/* *
 *
 * void S_Rend::compress_points(char, string&)
 * start combing data.
 * lambda is first given byte per max_hashes
 *	it is also the full combination of all deltas and alphas
 *
 * Loop a few times so the compression gets radical
 * and then output.
 */

bool S_Rend::compress_points(ofstream& out, string credit) {
//	//cout << "compress_points\n";

	stringstream valid;
	vector<char> xxy, yyx;
// Use the two compression functions 4x to burn up the entropy
	int i = 0;
	while (i < times_looped) {
		xxy = make_breadcrumbs(credit);
		credit.clear();
		yyx = set_binary_tree(out, xxy);
		for (char x : yyx)
			credit.push_back(x);
		i++;
	}
	for (char x : yyx)
		valid << x;
// Pop a segment terminator on the end
	valid << ";1";
	out << valid.str();
	valid.str("");
	yyx.clear();
	return 1;
}

vector<uint32_t> S_Rend::algorithm_bits (long long int Ti, int range_size) {
	long long int n = Ti%range_size, m = 0, h = 0;
	vector<uint32_t> results;
	results.push_back(Ti%range_size);
	int i = 0;
	printf("%");
	while (h < Ti) {
		int j = 0;
		for (int x : results) {
			long long powr = 1;
			for (int u = 0 ; u < j ; u++)
				powr *= range_size;
			m = m + (powr * x);
			j++;
		}
		h = m;
		n = Ti;
		n -= m;
		m = 0;

		for (int o = 0 ; o < results.size() ; o++)
			n = n/range_size;
		results.push_back(n%range_size);
	}
	if (h != Ti)
		printf("?");
	return results;
}

/* *
 *
 * void S_Rend::compress(ifstream&, ofstream&)
 * start combing data.
 * lambda is first given byte per max_hashes
 *	it is also the full combination of all deltas and alphas
 *
 * delta = iterated to byte; a sequence of the file
 *
 */

void S_Rend::compress(ifstream& in, ofstream& out) {
	//cout << "compressing hard now...\n";
	vector<char> credit;
	stringstream full_file;
	full_file << in.rdbuf();
	string file_string = full_file.str();
	full_file.str("");
	in.close();
	// anything over 10 million bytes
	// gets zipped twice.
	if (file_string.length() > 1000000)
		times_looped = 3;
	while (file_string.size() > 0) {
	// Smash bytes to create 8bit cipher
	// delta is a character from the file
		short int d = 0;
		string buffer = "";
		if (file_string.length() >= max_hashes)
			buffer = file_string.substr(0,max_hashes);
		else
			buffer = file_string;
		for (int x : buffer) {
		// delta is the progression of characters
			delta = x;
		// `credit` is our fault checker vector
		// in make_breadcrumbs() we're going to
		// to make the smallest sorting of it
		// then we'll use set_binary_tree()
		// to make it smaller
	// lambda's in this project are fully XOR'd by each delta
			lambda_now ^= delta.to_ulong();
			tallyho++;
		}
	// Header [1 byte] of message (lambda)
	// alpha_now is the first successful XOR
	// to create a delta in order. This is in make_breadcrumbs().
		large_lambda = lambda_now;
	// Send to get boxed up
		compress_points(out, buffer);
	// start again
		large_lambda = lambda_now = 0;
	// max_hashes is the most characters (delta) we can use at once
	// It's optimized IMHO at 20,000
		
		if (file_string.length() >= max_hashes)
			file_string = file_string.substr(max_hashes+1);
		else
			file_string.clear();
	}
   	printf("%u bytes zipped", tallyho);

	return;
}

/* *
 *
 * bool S_Rend::test_max(string, uint32_t)
 *
 * 
 *
 */

bool S_Rend::test_max(string vcx, uint32_t h) {
	int a = 0, b = 0;
	uint64_t f = 0;
	for (uint32_t x : vcx) {
		uint64_t powr = 1;
		for (int u = 0 ; u < a ; u++) {
			powr *= h;
		}
		f = f + (powr * x);
		if (f > pow(2,60)) {
			return 1;
		}
		a++;
		b++;
	}
	return 0;
}

/* *
 *
 * uint64_t S_Rend::get_ints(string, uint32_t)
 *
 * 
 *
 */

uint64_t S_Rend::get_ints(string vcx, uint32_t h) {
	int a = 0, b = 0;
	uint64_t f = 0;
	uint64_t ff = 0;
	for (uint32_t x : vcx) {
		uint64_t powr = 1;
		for (int u = 0 ; u < a ; u++) {
			powr *= h;
		}
		f = f + (powr * x);
		if (f > pow(2,60)) {
			ff = f;
			a = 0;
			f = 0;
			return ff;
		}
		a++;
		b++;
	}
	return 0;
}

/* *
 *
 * void S_Rend::algorithm_decompress(bitset<8>, bitset<8>,  long int)
 *
 * This is the algorithm that loops once or twice to ouput the file.
 * This will be done enough so each previous compression will have been undone
 *
 */

void S_Rend::algorithm_decompress(uint8_t& L, uint8_t& A, short int count) {

	vector<char> copy_txt;
	for (int i = 0 ; i < count ; i++) {
		L ^= (delta.to_ulong() ^ A) - 1;
		A = (delta.to_ulong() ^ L);
		delta = (A ^ L);
		current = delta.to_ulong();
		copy_txt.push_back((char)current);
	//	A *= A;
	}
	return;
}

/* *
 *
 * string S_Rend::uncompress(ofstream&, string)
 *
 * Find roots of the compression.
 * Here we slice the compressed data into the
 * breadcrumbs and the non-zipped bytes.
 * this is what you would run multiple times to totally unzip the file.
 *
 * 1st	   2nd	          3rd		   4th	5th	      6th
 *					Condensed
 *					to 64 bits
 *					or less
 * [lambda][alpha][unique bytes][::2::4][message bytes][::0;1]
 */

void S_Rend::uncompress(ofstream& out, string all_txt) {

	uint32_t c = 0, x = 0, y = 0, h = 0;
	char z = 0;

// Splitting max_hash'd segments into vector
	std::size_t found_z = 0, found_x = 0;

	vector<string> vals;
	vector<char> keys;
	vector<uint64_t> ints;
	vector<uint32_t> bytes_back;

// [lambda][alpha][unique bytes][::2::4][message bytes][::0;1]
	int i = 0, j = 0;
	string branches = "";
	string new_txt = "";

// Going thru vector
// [lambda][alpha][unique bytes][::2::4][message bytes][::0;1]
	while (all_txt.length() > 0) {
		uint8_t L = all_txt[0];
	// last byte in the chain is alpha;
	// (or z, here)
		uint8_t A = all_txt[1];
		all_txt = all_txt.substr(2);
		found_x = all_txt.find("::2::4");
		string body_unique = all_txt.substr(0, found_x-1);
		all_txt = all_txt.substr(found_x+6);
		h = all_txt[0] << 8;
		h += all_txt[1];
		found_z = all_txt.find("::0;1");
		string body_message = all_txt.substr(2, found_z-1);
		all_txt = all_txt.substr(found_z+5);
		if (all_txt.length() == 0) {
			cout << "\a" << flush;
		}
		string n = "";
	// make body into the unique parts it concises
		for (char x : body_unique) {
			if (n.length() == characters_wide) {
				vals.push_back(n);
				n.clear();
			}
			n.push_back(x);
		}
		if (n.length() > 0)
			vals.push_back(n);
		n.clear();
		int a = 0;
	// to create large numbers for algorithm_bits()
	// which is taken apart by the function into
	// make_breadcrumbs() style bytes
	
		for (char x : body_message) {
		// tests if string is over pow(2,60)
		// if so, save it. imperative.
			if (test_max(n,h) || a + 1 == body_message.length()) {
				ints.push_back(get_ints(n,h));
				n.clear();
			}
			n.push_back(x);
			a++;
		}

		string message_string = "";

	// recreates bytes from unique bytes
	// that come from make_breadcrumbs()
		for (uint64_t d : ints) {
		// returns points to be used in XOR
			bytes_back = algorithm_bits(d, h+1);
			for (uint32_t x : bytes_back) {
				cout << x << " " << vals.size() << "*" << flush;
				message_string.append(vals[x]);
			}
		}
		cout << message_string.length() << " " << flush;
		xor_stuffing(out, message_string, L, A); 
	}
	return;
}

/* *
 *
 * string S_Rend::xor_stuffing(ofstream&, string, uint8_t&, uint8_t&)
 *
 * 
 *
 */

void S_Rend::xor_stuffing(ofstream& out, string vals, uint8_t& L, uint8_t& A) {
//	string::iterator ivals = vals.begin();
	int c  = 0;
	delta = L ^ A;
	vector<char> copy_txt;
	copy_txt.push_back(delta.to_ulong());
	int ivals = 0;
	while(ivals < vals.size()) {
		c = 1;

		//if the number is 0, then we have a 2
		if ((ivals+1) != vals.size() && vals.at(ivals) == 0 && vals.at(ivals+1) != 255) {
			c = 2;
		}
		else if ((ivals+1) != vals.size() && vals.at(ivals) == 0 && vals.at(ivals+1) == 255) {
			A = vals.at(ivals);
			c = 1;
		}
		else if ((ivals+2) != vals.size() && vals.at(ivals) == 255 && vals.at(ivals+1) == 255 && vals.at(ivals+2) == 255) {
			A = vals.at(ivals);
			c = 1;
		}
		else if ((ivals+1) != vals.size() && vals.at(ivals) == 255 && vals.at(ivals+1) == 255) {
			A = vals.at(ivals);
			c = 1;
		}
		else if (vals.at(ivals) == 0)
			c = 2;
		else if (vals.at(ivals) > 0) {
			A = vals.at(ivals);
			c = 1;
		}

		lambda = L;

		alpha = A %= 256;

		delta = (alpha.to_ulong() ^ lambda.to_ulong());

		out << (char)(A ^ L);

		if (c == 2) {
			 {
				L ^= (delta.to_ulong() ^ A) - 1;
				A = (delta.to_ulong() ^ L);
				delta = (A ^ L);
				current = delta.to_ulong();
				out << ((char)current);
				L ^= (delta.to_ulong() ^ A) - 1;
				A = (delta.to_ulong() ^ L);
				delta = (A ^ L);
				current = delta.to_ulong();
				out << ((char)current);
			}
			ivals++;
		}
		else
			ivals++;
	}
	for (char x : copy_txt)
		out << x;
	copy_txt.clear();
	return;
}

int main() {

	string outfile = "";
	string infile = "";
	string DC = "1";
	printf("Enter <C> or <D> to compress or decompress ");
	cin >> DC;

	printf("\nInput File: ");
	cin >> infile;
	ifstream in;
	in.open(infile.c_str(), std::ios::in | std::ios::binary);

	if (in.fail())
		return -1;

	printf("\nOutput File: ");
	cin >> outfile;
	ofstream out;
	out.open(outfile.c_str(), std::ios::out);

	if (out.fail()){
		//cout << "open failed ... exiting\n";
		return -1;
	}

	locale mylocale("");   // get global locale
	out.imbue(mylocale);

	if ((DC=="c") || (DC=="C")){
		//cout << "\ncompressing...\n";
		try {

			n.compress(in, out);

		}
		catch (exception e) {
			//cout << e.what();
		}
	}
	if ((DC=="d") || (DC=="D")){
		try {
			stringstream all_txt;
			all_txt << in.rdbuf();
			string all_of_it = all_txt.str();
			all_txt.str("");
			n.uncompress(out, all_of_it);
		}
		catch (exception& ex) {
			//cout << ex.what();
		}
	}


	in.close();
	out.close();
	n.~S_Rend();
	return 0;

}