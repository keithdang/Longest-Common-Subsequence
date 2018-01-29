//5 1 2 3 4 1
//3 4 1 2 1 3
//LCS: 1 2 3 , 3 4 1 or 1 2 1
#include "longestCommonSubsequence.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
void longestCommonSubsequence::start()
{
	std::cout << "Longest Common Subsequence\n";
	
	char cArr1[] = { '1','2','3','4','1' };
	char cArr2[] = { '3','4','1','2','1','3' };
	std::vector<std::string> vecLcs1, vecLcs2;

	int sizeOfcArr1 = sizeof(cArr1) / sizeof(cArr1[0]);
	int sizeOfcArr2 = sizeof(cArr2) / sizeof(cArr2[0]);
	std::cout << "First Set\n";
	startSubsets(cArr1, sizeOfcArr1, vecLcs1);
	std::cout << "Second Set\n";
	startSubsets(cArr2, sizeOfcArr2, vecLcs2);
	
	vecComparison(vecLcs1,vecLcs2);
}
void longestCommonSubsequence::vecComparison(std::vector<std::string> &vecSubset1, std::vector<std::string> &vecSubset2)
{
	std::cout << "Vectors\n";
	int sizeOfLargestSubset = 0;
	std::vector<std::string> strVecSub;
	std::string strSubset;
	for (int i = 0; i < vecSubset1.size(); i++)
	{
		for (int j = 0; j < vecSubset2.size(); j++)
		{
			if (vecSubset1[i].compare(vecSubset2[j]) == 0)
			{
				if (vecSubset1[i].length() > sizeOfLargestSubset)
				{
					sizeOfLargestSubset=vecSubset1[i].length();
					strVecSub.clear();
					strVecSub.push_back(vecSubset1[i]);
				}
				else if (vecSubset1[i].length() == sizeOfLargestSubset)
				{
					bool bAdd = true;
					for (int m = 0; m < strVecSub.size(); m++)
					{
						if (vecSubset1[i].compare(strVecSub[m]) == 0)
						{
							bAdd = false;
						}
					}
					if (bAdd)
					{
						strVecSub.push_back(vecSubset1[i]);
					}
				}
			}
		}
	}
	std::cout << "Longest Common Subsequence:";
	for (int k = 0; k < strVecSub.size(); k++)
	{
		std::cout << "\n"<< strVecSub[k];
	}
	
}
void longestCommonSubsequence::startSubsets(char arr[], int sizeOfArr, std::vector<std::string> &vecSubset)
{
	char * arrSub = NULL;
	arrSub = new char[sizeOfArr];
	helperFun(arr, arrSub, sizeOfArr, 0, vecSubset);
}
void longestCommonSubsequence::helperFun(char arrOrig[], char arrSub[], int sizeOfArrOrg, int index, std::vector<std::string> &vecSubset)
{
	if (index == sizeOfArrOrg)
	{
		printAllSubSets(arrSub, sizeOfArrOrg, vecSubset);
	}
	else
	{
		arrSub[index] = NULL;
		helperFun(arrOrig, arrSub, sizeOfArrOrg, index + 1, vecSubset);
		arrSub[index] = arrOrig[index];
		helperFun(arrOrig, arrSub, sizeOfArrOrg, index + 1, vecSubset);
	}
}
void longestCommonSubsequence::printAllSubSets(char cArr[], int cSize, std::vector<std::string> &vecSubset)
{
	string word;
	
	for (int i = 0; i < cSize; i++)
	{
		if (cArr[i] != NULL)
		{
			std::cout << cArr[i] << " , ";
			word.push_back(cArr[i]);
		}
	}
	vecSubset.push_back(word);
	std::cout << "\n";
}
longestCommonSubsequence::longestCommonSubsequence()
{
}


longestCommonSubsequence::~longestCommonSubsequence()
{
}
