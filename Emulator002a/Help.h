#pragma once
#include <iostream>
#include <string>
#include <map>

namespace emulator {

	typedef unsigned char byte;
	typedef unsigned short word;
	typedef unsigned int dword;

	class MyByte {
	private:
		std::string value;
		std::map<char, int> hex_value_of_dec(void)
		{
			std::map<char, int> m{ { '0', 0 }, { '1', 1 },
							  { '2', 2 }, { '3', 3 },
							  { '4', 4 }, { '5', 5 },
							  { '6', 6 }, { '7', 7 },
							  { '8', 8 }, { '9', 9 },
							  { 'A', 10 }, { 'B', 11 },
							  { 'C', 12 }, { 'D', 13 },
							  { 'E', 14 }, { 'F', 15 } };
			return m;
		}
		std::map<int, char> dec_value_of_hex(void)
		{
			std::map<int, char> m{ { 0, '0' }, { 1, '1' },
							  { 2, '2' }, { 3, '3' },
							  { 4, '4' }, { 5, '5' },
							  { 6, '6' }, { 7, '7' },
							  { 8, '8' }, { 9, '9' },
							  { 10, 'A' }, { 11, 'B' },
							  { 12, 'C' }, { 13, 'D' },
							  { 14, 'E' }, { 15, 'F' } };
			return m;
		}
	public:
		MyByte() {
			setValue("");
		}
		MyByte(byte b) {
			std::string s(1, b);
			setValue(s);
		}
		void setValue(const std::string value) {
			this->value = value;
		}
		std::string getValue() {
			return this->value;
		}
		MyByte operator+(const MyByte& bincoming) {
			MyByte myb;

			std::string a = getValue();
			std::string b = bincoming.value;

			std::map<char, int> m = hex_value_of_dec();
			std::map<int, char> k = dec_value_of_hex();

			// Check if length of string first is 
			// greater than or equal to string second 
			if (a.length() < b.length()) swap(a, b);

			
			std::string ans = "";

			// Initialize carry as zero 
			int carry = 0, i, j;

			// Traverse till second string 
			// get traversal completely 
			for (i = a.length() - 1, j = b.length() - 1;
				j >= 0; i--, j--) {

				// Decimal value of element at a[i] 
				// Decimal value of element at b[i] 
				int sum = m[a[i]] + m[b[j]] + carry;

				// Hexadecimal value of sum%16 
				// to get addition bit 
				int addition_bit = k[sum % 16];

				// Add addition_bit to answer 
				ans.push_back(addition_bit);

				// Update carry 
				carry = sum / 16;
			}

			// Traverse remaining element 
			// of string a 
			while (i >= 0) {

				// Decimal value of element 
				// at a[i] 
				int sum = m[a[i]] + carry;

				// Hexadecimal value of sum%16 
				// to get addition bit 
				int addition_bit = k[sum % 16];

				// Add addition_bit to answer 
				ans.push_back(addition_bit);

				// Update carry 
				carry = sum / 16;
				i--;
			}

			// Check if still carry remains 
			if (carry) {
				ans.push_back(k[carry]);
			}

			// Reverse the final string 
			// for desired output 
			reverse(ans.begin(), ans.end());

			// Return the answer
			//return ans;
			myb.setValue(ans);
			return myb;
		}
		friend std::ostream& operator<<(std::ostream& os, MyByte const& b) {
			return os << "I'm in the class, msg=" << b.value << std::endl;
		}

	};
}