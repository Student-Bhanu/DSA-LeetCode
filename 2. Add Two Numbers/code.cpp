#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = NULL;
    }

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }

    ListNode(int x, ListNode *Next)
    {
        val = x;
        next = Next;
    }
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *currl1 = l1;
        ListNode *currl2 = l2;
        ListNode *head = NULL;
        ListNode *prev = NULL;
        int carry = 0;
        while (currl1 != NULL && currl2 != NULL)
        {
            int sum = currl1->val + currl2->val + carry;
            carry = sum / 10;
            ListNode *curr = new ListNode(sum % 10);

            if (head == NULL)
            {
                head = curr;
                prev = curr;
            }
            else
            {
                prev->next = curr;
                prev = curr;
            }

            currl1 = currl1->next;
            currl2 = currl2->next;
        }

        while (currl1 != NULL)
        {
            int sum = currl1->val + carry;
            carry = sum / 10;
            ListNode *curr = new ListNode(sum % 10);

            if (head == NULL)
            {
                head = curr;
                prev = curr;
            }
            else
            {
                prev->next = curr;
                prev = curr;
            }

            currl1 = currl1->next;
        }

        while (currl2 != NULL)
        {
            int sum = currl2->val + carry;
            carry = sum / 10;
            ListNode *curr = new ListNode(sum % 10);

            if (head == NULL)
            {
                head = curr;
                prev = curr;
            }
            else
            {
                prev->next = curr;
                prev = curr;
            }

            currl2 = currl2->next;
        }

        if (carry != 0)
        {
            ListNode *temp = new ListNode(carry);
            prev->next = temp;
        }

        return head ? head : prev;
    }
};