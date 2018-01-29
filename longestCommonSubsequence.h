#pragma once
#include <vector>
#include <string>
class longestCommonSubsequence
{
public:
	void start();
	void printAllSubSets(char cArr[], int cSize, std::vector<std::string> &vecSubset);
	void helperFun(char  arrOrig[], char arrSub[], int sizeOfArrOrg, int index, std::vector<std::string> &vecSubset);
	void startSubsets(char arr[], int sizeOfArr, std::vector<std::string> &vecSubset);
	void vecComparison(std::vector<std::string> &vecSubset1, std::vector<std::string> &vecSubset2);
	longestCommonSubsequence();
	~longestCommonSubsequence();
};

