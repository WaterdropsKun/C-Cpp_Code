#include <string>
#include <iostream>

// 公共抽象类
class Phone
{
public:
	Phone() {}
	virtual ~Phone() {}   

	virtual void ShowDecorate() {}   //Debug
};

// 具体的手机类
class iPhone : public Phone
{
public:
	iPhone(std::string name) : m_name(name) {}   //Debug
	virtual ~iPhone() {}

	void ShowDecorate()
	{
		std::cout << m_name << "的装饰" << std::endl;
	}

private:
	std::string m_name;
};

//具体的手机类
class NokiaPhone : public Phone
{
public:
	NokiaPhone(std::string name) : m_name(name) {}
	virtual ~NokiaPhone() {}

	void ShowDecorate()
	{
		std::cout << m_name << "的装饰" << std::endl;
	}

private:
	std::string m_name;
};


//装饰类
class DecoratorPhone : public Phone
{
public:
	DecoratorPhone(Phone *phone) : m_phone(phone) {}

	virtual void ShowDecorate() 
	{
		m_phone->ShowDecorate();
	}

private:
	// 要装饰的手机
	Phone *m_phone;
};

// 具体的装饰类
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
		std::cout << "增加挂件" << std::endl;
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
		std::cout << "屏幕贴膜" << std::endl;
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
