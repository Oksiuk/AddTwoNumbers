//https://leetcode.com/problems/add-two-numbers/

//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode*next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int number1 = l1->val;
		int number2 = l2->val;
		int number3 = 0;
		int additionalDigit = 0;

		if (number1 + number2 < 10)
		{
			number3 = number1 + number2;
		}
		else
		{
			number3 = number1 + number2 - 10;
			additionalDigit = 1;
		}

		ListNode* temp3 = new ListNode(number3);
		ListNode*l3 = temp3;
		ListNode* temp1 = l1->next;
		ListNode*temp2 = l2->next;

		while (temp1 != nullptr || temp2 != nullptr)
		{
			number1 = 0;
			number2 = 0;

			if (temp1 != nullptr)
			{
				number1 = temp1->val;
				temp1 = temp1->next;
			}

			if (temp2 != nullptr)
			{
				number2 = temp2->val;
				temp2 = temp2->next;
			}

			if (number1 + number2 + additionalDigit < 10)
			{
				number3 = number1 + number2 + additionalDigit;
				additionalDigit = 0;
			}
			else if (number1 + number2 + additionalDigit >= 10)
			{
				number3 = number1 + number2 + additionalDigit - 10;
				additionalDigit = 1;
			}

			ListNode* temp3next = new ListNode(number3);
			temp3->next = temp3next;
			temp3 = temp3next;
		}
		if (additionalDigit > 0)
		{
			ListNode* temp3next = new ListNode(additionalDigit);
			temp3->next = temp3next;
		}
		return l3;
	}
};