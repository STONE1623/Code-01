#include <iostream>
#include <string>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

class BigInt {
private:
	Node* head; 
	bool isNegative; 

public:
	BigInt() {
		head = new Node();
		head->data = 0;
		head->next = head;
		head->prev = head;
		isNegative = false;
	}
	
	void InsertBack(int data) {
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = head;
		newNode->prev = head->prev;
		head->prev->next = newNode;
		head->prev = newNode;
	}

	void RemoveFrontZeros() {
		Node* currentNode = head->next;

		while (currentNode != head && currentNode->data == 0) {
			Node* temp = currentNode;
			currentNode = currentNode->next;
			currentNode->prev = head;
			head->next = currentNode;
			delete temp;
		}
	}

	void InsertFront(int data) {
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = head->next;
		newNode->prev = head;
		head->next->prev = newNode;
		head->next = newNode;
	}

	BigInt(const string& numStr) {
		head = new Node();
		head->data = 0;
		head->next = head;
		head->prev = head;
		isNegative = false;

		int startIndex = 0;
		if (numStr[0] == '-') {
			isNegative = true;
			startIndex = 1;
		}

		for (int i = numStr.size() - 1; i >= startIndex; i -= 3) {
			int num = 0;
			int multiplier = 1;
			for (int j = 0; j < 3 && i - j >= startIndex; j++) {
				num += (numStr[i - j] - '0') * multiplier;
				multiplier *= 10;
			}
			InsertFront(num);
		}
	}

	BigInt(int num) {
		head = new Node();
		head->data = 0;
		head->next = head;
		head->prev = head;
		isNegative = false;

		while (num > 0) {
			int threeDigitGroup = num % 1000; 
			InsertFront(threeDigitGroup); 
			num /= 1000;
		}
	}

	BigInt operator+(const BigInt& other) const {

		BigInt result;

		if (isNegative != other.isNegative) result = SubAbsoluteValue(other);
		else result = AddAbsoluteValue(other);

		if (isNegative && other.isNegative) {
			// 当前两个数均为负数
			result.setSign(true); // 结果为负数
		}
		else if (compareAbsoluteValue(other) == 1 && isNegative) {
			//前者是负数，且绝对值大
			result.setSign(true); // 结果为负数
		}
		else if (compareAbsoluteValue(other) == -1 && other.isNegative) {
			//后者是负数，且绝对值大
			result.setSign(true); // 结果为负数
		}

		return result;
	}

	// 实现减法运算
	BigInt operator-(const BigInt& other) const {
		BigInt result;


		if (other.isNegative != isNegative)result = AddAbsoluteValue(other);
		else result = SubAbsoluteValue(other);


		if (isNegative && !other.isNegative) {
			// 前负后正
			result.setSign(true); // 结果为负数
		}
		else if (!other.isNegative && !isNegative && (compareAbsoluteValue(other) == -1)) {
			result.setSign(true); // 都是正数，且前者比后者绝对值小
		}
		else if (compareAbsoluteValue(other) == 1 && other.isNegative && isNegative) {
			result.setSign(true); // 都是负数，且后者比前者绝对值小
		}
		return result;


	}

	

	// 输出 BigInt
	friend ostream& operator<<(ostream& os, const BigInt& num) {
		Node* currentNode = num.head->next;
		if (num.isNegative)
			os << "-";

		os << currentNode->data;
		currentNode = currentNode->next;

		while (currentNode != num.head) {
			os << ",";
			os.width(3);
			os.fill('0');
			os << currentNode->data;
			currentNode = currentNode->next;
		}

		return os;
	}

	void setSign(bool negative) {
		isNegative = negative;
	}

	int compareAbsoluteValue(const BigInt& other) const {
		Node* thisNode = head->prev;
		Node* otherNode = other.head->prev;
		int thisSize = 0;
		int otherSize = 0;

		while (thisNode != head) {
			thisSize++;
			thisNode = thisNode->prev;
		}

		while (otherNode != other.head) {
			otherSize++;
			otherNode = otherNode->prev;
		}

		if (thisSize < otherSize) {
			return -1; 
		}
		else if (thisSize > otherSize) {
			return 1; 
		}

		thisNode = head->next;
		otherNode = other.head->next;
		while (thisNode != head) {
			int thisData = thisNode->data;
			int otherData = otherNode->data;

			if (thisData < otherData) {
				return -1;
			}
			else if (thisData > otherData) {
				return 1; 
			}

			thisNode = thisNode->next;
			otherNode = otherNode->next;
		}

		return 0;
	}

	// 绝对值加法函数
	BigInt AddAbsoluteValue(const BigInt& other) const {
		BigInt result;
		Node* thisNode = head->prev;
		Node* otherNode = other.head->prev;
		int carry = 0;

		while (thisNode != head || otherNode != other.head || carry) {
			int thisData = thisNode != head ? thisNode->data : 0;
			int otherData = otherNode != other.head ? otherNode->data : 0;
			int sum = thisData + otherData + carry;
			carry = sum / 1000;
			result.InsertFront(sum % 1000);

			if (thisNode != head)
				thisNode = thisNode->prev;
			if (otherNode != other.head)
				otherNode = otherNode->prev;
		}

		return result;
	}

	BigInt SubAbsoluteValue(const BigInt& other) const {
		if (compareAbsoluteValue(other) == -1) {
			return other.SubAbsoluteValue(*this);
		}

		BigInt result;
		Node* thisNode = head->prev;
		Node* otherNode = other.head->prev;
		int borrow = 0;

		while (thisNode != head) {
			int thisData = thisNode->data;
			int otherData = otherNode != other.head ? otherNode->data : 0;
			int diff = thisData - otherData - borrow;
			if (diff < 0) {
				diff += 1000;
				borrow = 1;
			}
			else {
				borrow = 0;
			}
			result.InsertFront(diff);

			if (thisNode != head)
				thisNode = thisNode->prev;
			if (otherNode != other.head)
				otherNode = otherNode->prev;
		}

		// 处理当前数多出来的位数
		while (thisNode != head) {
			int thisData = thisNode->data - borrow;
			if (thisData < 0) {
				thisData += 1000;
				borrow = 1;
			}
			else {
				borrow = 0;
			}
			result.InsertFront(thisData);
			thisNode = thisNode->prev;
		}

		result.RemoveFrontZeros();
		return result;
	}

	

	

};

int main() {
	string numStr1, numStr2;
	cout << "请输入第一个长整数: ";
	cin >> numStr1;
	cout << "请输入第二个长整数: ";
	cin >> numStr2;

	BigInt num1(numStr1);
	BigInt num2(numStr2);
	BigInt quotient;
	BigInt sum = num1 + num2;
	BigInt diff = num1 - num2;
	
	cout << "加法结果: " << sum << endl;
	cout << "减法结果: " << diff << endl;
	
	system("pause");

	return 0;

}