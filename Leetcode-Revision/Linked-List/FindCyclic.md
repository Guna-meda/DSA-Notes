# Detect Cycle in Linked List & Find Cycle Start

We solve **two related problems** using **Floyd’s Cycle Detection (Tortoise–Hare)**.

---

## 1️⃣ Check if a Cycle Exists

### Idea
Use two pointers:
- `slow` moves **1 step**
- `fast` moves **2 steps**

If there is a cycle, they **will meet**.

---

### Algorithm
1. Initialize `slow = head`, `fast = head`
2. While `fast` and `fast->next` exist:
   - `slow = slow->next`
   - `fast = fast->next->next`
3. If `slow == fast` → **cycle exists**
4. If loop ends → **no cycle**

---

### C Code (Cycle Exists)
```c
int hasCycle(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1; // cycle found
    }
    return 0; // no cycle
}
```


# Find the Node Where the Cycle Begins (Linked List)

This problem is solved using **Floyd’s Cycle Detection Algorithm (Tortoise–Hare)**  
and **does NOT modify the linked list**.

---

## 🧠 Problem Statement

Given the head of a linked list, return the node where the **cycle begins**.  
If there is **no cycle**, return `NULL`.

---

## 💡 Core Idea

1. Use **slow (1 step)** and **fast (2 steps)** pointers to detect a cycle.
2. If they meet, a cycle exists.
3. Reset one pointer to `head`.
4. Move both pointers **one step at a time**.
5. The node where they meet again is the **cycle start**.

---

## 🧮 Distance Logic (Why This Works)

Let:
- `L` = distance from **head → cycle start**
- `C` = length of the cycle
- `x` = distance from **cycle start → meeting point**

When slow and fast meet:
- Slow has traveled: `L + x`
- Fast has traveled: `L + x + n*C` (where `n` is number of full cycles)

Since fast loops inside the cycle:
2 * (L + x) = L + x + n * C  
=> L + x = n * C


👉 Distance from **head to cycle start**  
equals distance from **meeting point to cycle start**.

---

## 📐 Distance Diagram (Conceptual)

head →───── L ─────→ cycle start →─── x ───→ meeting point
                        ↑                     ↓
                        ←────── remaining cycle ──────


---

## 🪜 Algorithm (Step-by-Step)

1. Initialize `slow = head`, `fast = head`
2. Move slow by 1 step, fast by 2 steps
3. If `slow == fast`, cycle exists
4. Set `ptr1 = head`, `ptr2 = slow`
5. Move both pointers one step at a time
6. When `ptr1 == ptr2`, that node is the **cycle start**

---

## 💻 C Code (Find Cycle Start)

```c
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;

    // Step 1: detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: find cycle start
            struct ListNode* ptr1 = head;
            struct ListNode* ptr2 = slow;

            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            return ptr1; // cycle start
        }
    }
    return NULL; // no cycle
}
```


