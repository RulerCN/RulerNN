/*====================================================================
BSD 2-Clause License

Copyright (c) 2020, Ruler
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
====================================================================*/
#pragma once

#ifndef __CORE_WSTRING_H__
#define __CORE_WSTRING_H__

#include <iomanip>
#include <list>
#include <regex>
#include <sstream>
#include <string>

namespace core
{
	// Class wstring
	class wstring
	{
	public:
		// converts a signed short integer to a string
		static std::wstring to_wstring(signed short val, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base << val;
			return wss.str();
		}

		// converts a signed integer to a wide string
		static std::wstring to_wstring(signed int val, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base << val;
			return wss.str();
		}

		// converts a signed integer to a wide string
		static std::wstring to_wstring(signed long val, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base << val;
			return wss.str();
		}

		// converts a signed long integer to a wide string
		static std::wstring to_wstring(signed long long val, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base << val;
			return wss.str();
		}

		// converts an unsigned short integer to a string
		static std::wstring to_wstring(unsigned short val, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base << val;
			return wss.str();
		}

		// converts an unsigned integer to a wide string
		static std::wstring to_wstring(unsigned int val, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base << val;
			return wss.str();
		}

		// converts an unsigned integer to a wide string
		static std::wstring to_wstring(unsigned long val, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base << val;
			return wss.str();
		}

		// converts an unsigned long integer to a wide string
		static std::wstring to_wstring(unsigned long long val, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base << val;
			return wss.str();
		}

		// converts a floating point value to a wide string
		static std::wstring to_wstring(float val, std::ios_base::fmtflags flags = std::ios::left, int precision = 6)
		{
			wss.clear();
			wss.str(L"");
			wss << std::setiosflags(flags) << std::setprecision(precision) << val;
			return wss.str();
		}

		// converts a floating point value to a wide string
		static std::wstring to_wstring(double val, std::ios_base::fmtflags flags = std::ios::left, int precision = 6)
		{
			wss.clear();
			wss.str(L"");
			wss << std::setiosflags(flags) << std::setprecision(precision) << val;
			return wss.str();
		}

		// converts a floating point value to a wide string
		static std::wstring to_wstring(long double val, std::ios_base::fmtflags flags = std::ios::left, int precision = 6)
		{
			wss.clear();
			wss.str(L"");
			wss << std::setiosflags(flags) << std::setprecision(precision) << val;
			return wss.str();
		}

		// converts a string to a signed short integer
		static signed short to_short(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			signed short val;
			wss.clear();
			wss.str(str);
			wss >> base >> val;
			return val;
		}

		// converts a string to a signed integer
		static signed int to_int(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			signed int val;
			wss.clear();
			wss.str(str);
			wss >> base >> val;
			return val;
		}

		// converts a string to a signed integer
		static signed long to_long(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			signed long val;
			wss.clear();
			wss.str(str);
			wss >> base >> val;
			return val;
		}

		// converts a string to a signed long integer
		static signed long long to_longlong(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			signed long long val;
			wss.clear();
			wss.str(str);
			wss >> base >> val;
			return val;
		}

		// converts a string to an unsigned short integer
		static unsigned short to_ushort(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			unsigned short val;
			wss.clear();
			wss.str(str);
			wss >> base >> val;
			return val;
		}

		// converts a string to an unsigned integer
		static unsigned int to_uint(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			unsigned int val;
			wss.clear();
			wss.str(str);
			wss >> base >> val;
			return val;
		}

		// converts a string to an unsigned integer
		static unsigned long to_ulong(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			unsigned long val;
			wss.clear();
			wss.str(str);
			wss >> base >> val;
			return val;
		}

		// converts a string to an unsigned integer
		static unsigned long long to_ulonglong(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			unsigned long long val;
			wss.clear();
			wss.str(str);
			wss >> base >> val;
			return val;
		}

		// converts a string to a floating point value
		static float to_float(const std::wstring& str)
		{
			float val;
			wss.clear();
			wss.str(str);
			wss >> val;
			return val;
		}

		// converts a string to a floating point value
		static double to_double(const std::wstring& str)
		{
			double val;
			wss.clear();
			wss.str(str);
			wss >> val;
			return val;
		}

		// converts a string to a floating point value
		static long double to_longdouble(const std::wstring& str)
		{
			long double val;
			wss.clear();
			wss.str(str);
			wss >> val;
			return val;
		}

		// splits a string into a list
		static std::list<std::wstring> split(const std::wstring& str)
		{
			std::list<std::wstring> lst;
			std::wsregex_token_iterator itr(str.begin(), str.end(), non_word, -1);
			std::wsregex_token_iterator end;
			while (itr != end)
				lst.push_back(*itr++);
			return lst;
		}

		// splits a string into a list of signed short integer
		static std::list<signed short> split_short(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			signed short val;
			std::list<signed short> lst;

			wss.clear();
			wss.str(std::regex_replace(str, non_integer, L" "));
			wss >> base;
			while (wss >> val)
				lst.push_back(val);
			return lst;
		}

		// splits a string into a list of signed integer
		static std::list<signed int> split_int(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			signed int val;
			std::list<signed int> lst;

			wss.clear();
			wss.str(std::regex_replace(str, non_integer, L" "));
			wss >> base;
			while (wss >> val)
				lst.push_back(val);
			return lst;
		}

		// splits a string into a list of signed integer
		static std::list<signed long> split_long(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			signed long val;
			std::list<signed long> lst;

			wss.clear();
			wss.str(std::regex_replace(str, non_integer, L" "));
			wss >> base;
			while (wss >> val)
				lst.push_back(val);
			return lst;
		}

		// splits a string into a list of signed long integer
		static std::list<signed long long> split_longlong(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			signed long long val;
			std::list<signed long long> lst;

			wss.clear();
			wss.str(std::regex_replace(str, non_integer, L" "));
			wss >> base;
			while (wss >> val)
				lst.push_back(val);
			return lst;
		}

		// splits a string into a list of unsigned short integer
		static std::list<unsigned short> split_ushort(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			unsigned short val;
			std::list<unsigned short> lst;

			wss.clear();
			wss.str(std::regex_replace(str, non_integer, L" "));
			wss >> base;
			while (wss >> val)
				lst.push_back(val);
			return lst;
		}

		// splits a string into a list of unsigned integer
		static std::list<unsigned int> split_uint(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			unsigned int val;
			std::list<unsigned int> lst;

			wss.clear();
			wss.str(std::regex_replace(str, non_integer, L" "));
			wss >> base;
			while (wss >> val)
				lst.push_back(val);
			return lst;
		}

		// splits a string into a list of unsigned integer
		static std::list<unsigned long> split_ulong(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			unsigned long val;
			std::list<unsigned long> lst;

			wss.clear();
			wss.str(std::regex_replace(str, non_integer, L" "));
			wss >> base;
			while (wss >> val)
				lst.push_back(val);
			return lst;
		}

		// splits a string into a list of unsigned long integer
		static std::list<unsigned long long> split_ulonglong(const std::wstring& str, std::ios_base& base(std::ios_base& str) = std::dec)
		{
			unsigned long long val;
			std::list<unsigned long long> lst;

			wss.clear();
			wss.str(std::regex_replace(str, non_integer, L" "));
			wss >> base;
			while (wss >> val)
				lst.push_back(val);
			return lst;
		}

		// splits a string into a list of floating point value
		static std::list<float> split_float(const std::wstring& str)
		{
			float val;
			std::list<float> lst;

			wss.clear();
			wss.str(std::regex_replace(str, non_float, L" "));
			while (wss >> val)
				lst.push_back(val);
			return lst;
		}

		// splits a string into a list of floating point value
		static std::list<double> split_double(const std::wstring& str)
		{
			double val;
			std::list<double> lst;

			wss.clear();
			wss.str(std::regex_replace(str, non_float, L" "));
			while (wss >> val)
				lst.push_back(val);
			return lst;
		}

		// splits a string into a list of floating point value
		static std::list<long double> split_longdouble(const std::wstring& str)
		{
			long double val;
			std::list<long double> lst;

			wss.clear();
			wss.str(std::regex_replace(str, non_float, L" "));
			while (wss >> val)
				lst.push_back(val);
			return lst;
		}

		// converts a list to string
		static std::wstring jion(const std::list<std::wstring>& lst, const std::wstring& delim)
		{
			wss.clear();
			wss.str(L"");
			auto itr = lst.begin();
			if (itr != lst.end())
				wss << *itr++;
			while (itr != lst.end())
				wss << delim << *itr++;
			return wss.str();
		}

		// converts a list of signed short integer to string
		static std::wstring jion(const std::list<signed short>& lst, const std::wstring delim = L" ", std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base;
			auto itr = lst.begin();
			if (itr != lst.end())
				wss << *itr++;
			while (itr != lst.end())
				wss << delim << *itr++;
			return wss.str();
		}

		// converts a list of signed integer to string
		static std::wstring jion(const std::list<signed int>& lst, const std::wstring delim = L" ", std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base;
			auto itr = lst.begin();
			if (itr != lst.end())
				wss << *itr++;
			while (itr != lst.end())
				wss << delim << *itr++;
			return wss.str();
		}

		// converts a list of signed integer to string
		static std::wstring jion(const std::list<signed long>& lst, const std::wstring delim = L" ", std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base;
			auto itr = lst.begin();
			if (itr != lst.end())
				wss << *itr++;
			while (itr != lst.end())
				wss << delim << *itr++;
			return wss.str();
		}

		// converts a list of signed long integer to string
		static std::wstring jion(const std::list<signed long long>& lst, const std::wstring delim = L" ", std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base;
			auto itr = lst.begin();
			if (itr != lst.end())
				wss << *itr++;
			while (itr != lst.end())
				wss << delim << *itr++;
			return wss.str();
		}

		// converts a list of unsigned short integer to string
		static std::wstring jion(const std::list<unsigned short>& lst, const std::wstring delim = L" ", std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base;
			auto itr = lst.begin();
			if (itr != lst.end())
				wss << *itr++;
			while (itr != lst.end())
				wss << delim << *itr++;
			return wss.str();
		}

		// converts a list of unsigned integer to string
		static std::wstring jion(const std::list<unsigned int>& lst, const std::wstring delim = L" ", std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base;
			auto itr = lst.begin();
			if (itr != lst.end())
				wss << *itr++;
			while (itr != lst.end())
				wss << delim << *itr++;
			return wss.str();
		}

		// converts a list of unsigned integer to string
		static std::wstring jion(const std::list<unsigned long>& lst, const std::wstring delim = L" ", std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base;
			auto itr = lst.begin();
			if (itr != lst.end())
				wss << *itr++;
			while (itr != lst.end())
				wss << delim << *itr++;
			return wss.str();
		}

		// converts a list of unsigned long integer to string
		static std::wstring jion(const std::list<unsigned long long>& lst, const std::wstring delim = L" ", std::ios_base& base(std::ios_base& str) = std::dec)
		{
			wss.clear();
			wss.str(L"");
			wss << base;
			auto itr = lst.begin();
			if (itr != lst.end())
				wss << *itr++;
			while (itr != lst.end())
				wss << delim << *itr++;
			return wss.str();
		}

		// converts a list of floating point value to string
		static std::wstring jion(const std::list<float>& lst, const std::wstring delim = L" ", std::ios_base::fmtflags flags = std::ios::left, int precision = 6)
		{
			wss.clear();
			wss.str(L"");
			wss << std::setiosflags(flags) << std::setprecision(precision);
			auto itr = lst.begin();
			if (itr != lst.end())
				wss << *itr++;
			while (itr != lst.end())
				wss << delim << *itr++;
			return wss.str();
		}

		// converts a list of floating point value to string
		static std::wstring jion(const std::list<double>& lst, const std::wstring delim = L" ", std::ios_base::fmtflags flags = std::ios::left, int precision = 6)
		{
			wss.clear();
			wss.str(L"");
			wss << std::setiosflags(flags) << std::setprecision(precision);
			auto itr = lst.begin();
			if (itr != lst.end())
				wss << *itr++;
			while (itr != lst.end())
				wss << delim << *itr++;
			return wss.str();
		}

		// converts a list of floating point value to string
		static std::wstring jion(const std::list<long double>& lst, const std::wstring delim = L" ", std::ios_base::fmtflags flags = std::ios::left, int precision = 6)
		{
			wss.clear();
			wss.str(L"");
			wss << std::setiosflags(flags) << std::setprecision(precision);
			auto itr = lst.begin();
			if (itr != lst.end())
				wss << *itr++;
			while (itr != lst.end())
				wss << delim << *itr++;
			return wss.str();
		}
	public:
		static std::wstringstream wss;
		static std::wregex        non_word;
		static std::wregex        non_integer;
		static std::wregex        non_float;
	};

	// Initialize static variables
	std::wstringstream wstring::wss;
	std::wregex        wstring::non_word(L"\\W");
	std::wregex        wstring::non_integer(L"[^\\+\\-0-9A-Za-z]");
	std::wregex        wstring::non_float(L"[^\\+\\-.0-9A-DF-Za-df-z]");

} // namespace core

#endif
