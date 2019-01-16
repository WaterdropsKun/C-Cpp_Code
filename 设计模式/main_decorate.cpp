#include <string>
#include <iostream>

// ����������
class Phone
{
public:
	Phone() {}
	virtual ~Phone() {}   

	virtual void ShowDecorate() {}   //Debug
};

// ������ֻ���
class iPhone : public Phone
{
public:
	iPhone(std::string name) : m_name(name) {}   //Debug
	virtual ~iPhone() {}

	void ShowDecorate()
	{
		std::cout << m_name << "��װ��" << std::endl;
	}

private:
	std::string m_name;
};

//������ֻ���
class NokiaPhone : public Phone
{
public:
	NokiaPhone(std::string name) : m_name(name) {}
	virtual ~NokiaPhone() {}

	void ShowDecorate()
	{
		std::cout << m_name << "��װ��" << std::endl;
	}

private:
	std::string m_name;
};


//װ����
class DecoratorPhone : public Phone
{
public:
	DecoratorPhone(Phone *phone) : m_phone(phone) {}

	virtual void ShowDecorate() 
	{
		m_phone->ShowDecorate();
	}

private:
	// Ҫװ�ε��ֻ�
	Phone *m_phone;
};

// �����װ����
class DecoratorPhoneA : public DecoratorPhone
{
public:
	DecoratorPhoneA(Phone *phone) : DecoratorPhone(phone) {} //Debug

	void ShowDecorate()
	{
		DecoratorPhone::ShowDecorate();
		AddDecorate();
	}

private:
	void AddDecorate()
	{
		std::cout << "���ӹҼ�" << std::endl;
	}

};

class DecoratorPhoneB : public DecoratorPhone
{
public:
	DecoratorPhoneB(Phone *phone) : DecoratorPhone(phone) {}

	void ShowDecorate()
	{
		DecoratorPhone::ShowDecorate();
		AddDecorate();
	}

private:
	void AddDecorate()
	{
		std::cout << "��Ļ��Ĥ" << std::endl;
	}
};



int main_decorate()
{
	Phone *phone = new NokiaPhone("888");
	Phone *dpa = new DecoratorPhoneA(phone);
	Phone *dpb = new DecoratorPhoneB(dpa);
	dpb->ShowDecorate();

	Phone *pPhone = new DecoratorPhoneB(new DecoratorPhoneA(new iPhone("iphone6")));	
	pPhone->ShowDecorate();

	delete dpa;
	delete dpb;
	delete phone;

	delete pPhone;

	return 0;
}
