# Reverse a Linked List (Iterative)

## Problem
Given the head of a singly linked list, reverse the list and return the new head.

---

## Logic (Core Idea)
<img width="686" height="193" alt="image" src="https://github.com/user-attachments/assets/617fb343-e26c-4d0b-9dc3-ba5e97c670b2" />

We reverse links **one by one**.

At each node:
- Save next node
- Reverse current node’s `next`
- Move forward

We use **3 pointers**:
- `prev` → previous node
- `curr` → current node
- `next` → next node (backup)

---

## Algorithm
1. Initialize `prev = NULL`
2. Set `curr = head`
3. While `curr != NULL`:
   - `next = curr->next`
   - `curr->next = prev`
   - `prev = curr`
   - `curr = next`
4. `prev` becomes the new head

---

## C Code
```c
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;

    while (curr != NULL) {
        next = curr->next;   // store next
        curr->next = prev;   // reverse link
        prev = curr;         // move prev
        curr = next;         // move curr
    }

    return prev;
}
