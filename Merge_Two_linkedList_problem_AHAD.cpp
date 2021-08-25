// Merge_Two_linkedList_problem_AHAD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* third, * last;
        if (l1->val < l2->val) {
            third = l1;
            last = l1;
            l1 = l1->next;
            last->next = NULL;
        }
        else {
            third = l2;
            last = l2;
            l2 = l2->next;
            last->next = NULL;
        }

        while (l1 && l2) {

            if (l1->val < l2->val) {
                last->next = l1;
                last = l1;
                l1 = l1->next;
                last->next = NULL;
            }
            else {
                last->next = l2;
                last = l2;
                l2 = l2->next;
                last->next = NULL;
            }

        }//while
        if (l1 != NULL)
            last->next = l1;
        else
            last->next = l2;
        //third=last;
        return third;
    }
};

int main()
{
}