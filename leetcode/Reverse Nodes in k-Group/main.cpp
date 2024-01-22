#include <cstddef>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode	*buildList(vector<int>& values)
{
	ListNode	*next;
	ListNode	*head;

	next = 0;
	for (int i = 0; i < values.size(); i++)
	{
		head = new ListNode(values[i], next);
		next = head;
	}
	return head;

}

ListNode* reverseKGroup(ListNode* head, int k)
{
	int			i;
	ListNode	*ret;
	ListNode	*next;
	ListNode	*previous;
	ListNode	*tailList;
	ListNode	*NextList;
	ListNode	*prevListLastElem;

	ret = 0;
	tailList = head;
	prevListLastElem = 0;
	while (1)
	{
		//check if the current list is of size >= k
		for (i = 0, head = tailList; i < k && head; head = head->next)
		{
			i++;
			if (i == k)
				break;
		}
		cout << i << endl;
		if (!ret)
			ret = head;
		if (i != k)
			break;
		//end
		NextList = head->next;//0
		cout << head << endl;
		previous = NextList;
		for (head = tailList; head != NextList; head = next)
		{
			next = head->next;
			head->next = previous;
			previous = head;
		}
		if (prevListLastElem)
			prevListLastElem->next = previous;
		prevListLastElem = tailList;
		tailList = NextList;
	}
	return ret;
}

int main()
{
	vector<int> values;
	ListNode	*nodes;
	ListNode	*reversedList;

	int n = 5;
	for (int i = 0; i < n; i++)
		values.push_back(i);
	for (int i = values.size() - 1; i >= 0; i--)
		cout << values[i] << " ";
	cout << endl;

	nodes = buildList(values);
	for (ListNode *head = nodes; head; head = head->next)
		cout << head->val << " ";
	cout << endl;

	reversedList = reverseKGroup(nodes, 2);
	for (ListNode *head = reversedList; head; head = head->next)
		cout << head->val << " ";
	cout << endl;
	return 0;
}