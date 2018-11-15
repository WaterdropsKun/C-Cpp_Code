#include <string>
#include <iostream>
#include <vector>

class CPerson
{
public:
	CPerson() {}

	CPerson(std::string strName, int nAge, float fWeight, float fHeight)
	{
		m_strName = strName;
		m_nAge = nAge;
		m_nWeight = fWeight;
		m_nHeight = fHeight;
	}

	void ShowMysef()
	{
		std::cout << m_strName << " " << m_nAge << " years old " << m_nWeight << "kg, " << m_nHeight << "m." << std::endl;
	}

public:
	std::string m_strName;
	int m_nAge;
	float m_nWeight;
	float m_nHeight;
};


class CCompare
{
public:
	CCompare() {}
	virtual ~CCompare() {}

	virtual int Compareble(CPerson cPerson1, CPerson cPerson2) = 0;
};

class CCompareByAge : public CCompare
{
public: 
	CCompareByAge() {}
	virtual ~CCompareByAge() {}

	int Compareble(CPerson cPerson1, CPerson cPerson2)
	{
		return ((cPerson1.m_nAge - cPerson2.m_nAge) < 0);
	}
};

class CCompareByHeight : public CCompare
{
public:
	CCompareByHeight() {}
	virtual ~CCompareByHeight() {}

	int Compareble(CPerson cPerson1, CPerson cPerson2)
	{
		return ((cPerson1.m_nHeight - cPerson2.m_nHeight) < 0.0);
	}
};

class CSortPerson
{
public:
	CSortPerson(CCompare *pcCompare) : m_pcCompare(pcCompare) {}

	~CSortPerson()
	{
		if (m_pcCompare != NULL)
		{
			delete m_pcCompare;
			m_pcCompare = NULL;
		}
	}

	std::vector<CPerson> sort(std::vector<CPerson> vcPersonList)
	{
		int n = vcPersonList.size();

		CPerson tmp;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				int mk = m_pcCompare->Compareble(vcPersonList[j], vcPersonList[j + 1]);
				if (m_pcCompare->Compareble(vcPersonList[j], vcPersonList[j + 1]))
				{
					tmp = vcPersonList[j];
					vcPersonList[j] = vcPersonList[j + 1];
					vcPersonList[j + 1] = tmp;
				}
			}
		}

		return vcPersonList;
	}

private:
	CCompare *m_pcCompare;
};

int main_strategy()
{
	std::vector<CPerson> vcPersonList;	
	std::vector<CPerson> vcPersonListListResult;

	vcPersonList.push_back(CPerson("Tony", 2, 54.5, 0.82));
	vcPersonList.push_back(CPerson("Jack", 31, 74.5, 0.82));
	vcPersonList.push_back(CPerson("Nick", 54, 44.5, 0.82));
	vcPersonList.push_back(CPerson("Eric", 23, 62.5, 0.82));
	vcPersonList.push_back(CPerson("Helen", 16, 45.5, 0.82));

	
	CSortPerson cSortPerson = CSortPerson(new CCompareByAge());

	vcPersonListListResult = cSortPerson.sort(vcPersonList);
	for (std::vector<CPerson>::iterator it = vcPersonListListResult.begin(); it != vcPersonListListResult.end(); it++)
	{
		it->ShowMysef();
	}

	return 0;
}

