#include<cmath>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

using namespace std;

int sum(int a, int b, int *array);
string balance(int start1, int end1, int start2, int end2, int *array, int oddcoin);

int main()
{
	srand(time(NULL));
	int g = 1;
	while (g) {
		int a;
		int badcoindiffweight;
		cout << "Enter the number of coins:";
		cin >> a;
		int *array = new int[a];
		int f = rand() % a;
		int arrayNum[2];
		arrayNum[0] = 1;
		arrayNum[1] = 3;
		int RandIndex = rand() % 2;
		for (int z = 0; z < a; z++) {
			if (z == f) {
				array[z] = arrayNum[RandIndex];
			}
			else {
				array[z] = 2;
			}
		}
		for (int y = 0; y < a; y++) {
			cout << y << ":" << array[y] << endl;
		}
		int k = 1;
		int d = 0;
		int start = 0;
		int total = (a);
		int part = (a / 3);
		int end = a;
		string test;
		int oddcoinfind=0;
		int timesweigh=0;
		while (k) {
			if (part == 0) {
				part = 1;
			}
			if (total == 2) {
				test = balance(start, (start + 1), (start + 1), (end), array, arrayNum[RandIndex]);
				timesweigh++;
				if (badcoindiffweight < 0) {
					if (test == "lighter") {
						//cout<<"lighter"<<endl;
						start = start;
						total = 1;
					}
					else if (test == "heavier") {
						//cout<<"heavier"<<endl;
						start = (end-1);
						total = 1;
					}
				}
				else if (badcoindiffweight > 0) {
					if (test == "heavier") {
						//cout<<"heavier"<<endl;
						start = start;
						total = 1;
					}
					else if (test == "lighter") {
						//cout<<"lighter"<<endl;
						start = (end - 1);
						total = 1;
					}
				}
			}
			if (total == 1)
			{
				k = 0;
			}
			if (total % 3 != 0 && g != (a - 1)) {
				//test = balance(start, (start + part), (start + part), (start + (2 * part)), array, arrayNum[RandIndex]);
				if (balance(start, (start + part), (start + part), (start + (2 * part)), array, arrayNum[RandIndex]) == "equal") {
					timesweigh++;
					//cout<<"equal"<<endl;
					start = (start + 2 * part);
					end = end;
					total = (total - (2 * part));
					part = (total / 3);
				}
				else if (badcoindiffweight < 0) {
					if (test == "lighter")
					{
						//cout<<"lighter"<<endl;
						start = start;
						end = (start + part);
						total = part;
						part = (total / 3);
					}
					else if (test == "heavier") {
						//cout<<"heavier"<<endl;
						start = (start + part);
						end = (start + 2 * part);
						total = part;
						part = (total / 3);
					}
				}
				else if (badcoindiffweight > 0) {
					if (test == "heavier") {
						//cout<<"heavier"<<endl;
						start = start;
						end = (start + part);
						total = part;
						part = (total / 3);
					}
					else if (test == "lighter") {
						//cout<<"lighter"<<endl;
						start = (start + part);
						end = (start + 2 * part);
						total = part;
						part = (total / 3);
					}
				}

			}
			//test = balance(start, (start + part), (start + part), (start + (2 * part)), array, arrayNum[RandIndex]);
			else if (balance(start, (start + part), (start + part), (start + (2 * part)), array, arrayNum[RandIndex]) == "equal" && part != 0 && total % 3 == 0) {
				timesweigh++;
				//cout<<"equal"<<endl;
				if(oddcoinfind!=0)
				{
					oddcoinfind++;
					test = balance(start, (start + part), (start + (2 * part)), end, array, arrayNum[RandIndex]);
					timesweigh++;
					if (test == "lighter") {
						//cout<<"lighter"<<endl;
						badcoindiffweight = 1;
					}
					else if (test == "heavier") {
						//cout<<"heavier"<<endl;
						badcoindiffweight = -1;
					}
				}
				start = (start + (2 * part));
				total = part;
				part = (part / 3);
				end = end;
			}
			//test = balance((start + part), (start + (2 * part)), (start + (2 * part)), end, array, arrayNum[RandIndex]);
			else if (balance((start + part), (start + (2 * part)), (start + (2 * part)), end, array, arrayNum[RandIndex]) == "equal" && part != 0 && total % 3 == 0) {
				timesweigh++;
				//cout<<"equal"<<endl;
				if(oddcoinfind!=0)
				{
					oddcoinfind++;
					test = balance((start + part), (start + (2 * part)), start, (start + part), array, arrayNum[RandIndex]);
					timesweigh++;
					if (test == "lighter") {
						//cout<<"lighter"<<endl;
						badcoindiffweight = 1;
					}
					else if (test == "heavier") {
						//cout<<"heavier"<<endl;
						badcoindiffweight = -1;
					}
				}
				start = start;
				total = part;
				end = (start + part);
				part = (part / 3);
			}
			//test = balance(start, (start + part), (start + 2 * part), end, array, arrayNum[RandIndex]);
			else if (balance(start, (start + part), (start + 2 * part), end, array, arrayNum[RandIndex]) == "equal" && part != 0 && total % 3 == 0) {
				timesweigh++;
				//cout<<"equal"<<endl;
				if(oddcoinfind!=0)
				{
					oddcoinfind++;
					test = balance(start, (start + part), (start + part), (start + (2 * part)), array, arrayNum[RandIndex]);
					timesweigh++;
					if (test == "lighter") {
						//cout<<"lighter"<<endl;
						badcoindiffweight = 1;
					}
					else if (test == "heavier") {
							//cout<<"heavier"<<endl;
							badcoindiffweight = -1;
					}
				}
				start = (start + part);
				total = part;
				end = (start + 2 * part);
				part = (part / 3);
			}
		}
		d = start;
		cout << "The odd coin is number " << d << endl;
		cout<<"Times the coins where weighed "<<timesweigh<<endl;

		delete[] array;
		cout << "Another?" << endl;
		cin >> g;
	}
	return 0;
}

int sum(int a, int b, int *array){
	int count = 0;
	for (int x = a; x < b; x++) {
		count = count + array[x];
	}
	return count;
}

string balance(int start1, int end1, int start2, int end2, int *array, int oddcoin){
	if(sum(start1,end1,array)==sum(start2,end2,array)){
		return "equal";
	}
	else if(sum(start1,end1,array)>sum(start2,end2,array)){
		return "heavier";
	}
	else if(sum(start2,end2,array)>sum(start1,end1,array)){
		return "lighter";
	}
}