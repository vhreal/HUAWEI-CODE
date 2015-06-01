    #include<iostream>  
    using namespace std;  
      
    typedef struct LNode {  
        int m_nValue;  
        struct LNode* m_pNext;  
    }LNode;  
      
    LNode* reverseList(LNode* pHead) {  
        if (NULL == pHead || NULL == pHead->m_pNext)  
            return pHead;  
        LNode* pNode;  
        LNode* pNewHead = NULL;  
        while (pHead) {  
            pNode = pHead;  
            pHead = pHead->m_pNext;  
            pNode->m_pNext = pNewHead;  
            pNewHead = pNode;  
        }  
        return pNewHead;  
    }  
      
    LNode* getLastNode(LNode* pHead) {  
        while (NULL != pHead->m_pNext)  
            pHead = pHead->m_pNext;  
        return pHead;  
    }  
      
    LNode* swapListByK(LNode* pHead, int k) {  
        if (k <= 1)  
            return pHead;  
        int pos;  
        LNode* pNode = pHead;  
        LNode* pNewHead;  
        LNode* pNextNode;  
        LNode* pLastNode = NULL;;  
        pHead = NULL;  
        while (pNode) 
		{  
            pos = 0;  
            pNewHead = pNode;  
            while (pNode && pos < k - 1) {  
                pNode = pNode->m_pNext;  
                pos++;  
            }  

            if (pNode)
			{  
                pNextNode = pNode->m_pNext;  
                pNode->m_pNext = NULL;  
                if (NULL != pLastNode) 
				{  
                    pLastNode->m_pNext = NULL;  
                }  
                pNewHead = reverseList(pNewHead);  
                if (NULL == pHead) 
                    pHead = pNewHead; 
				else
                    pLastNode->m_pNext = pNewHead;

                pNode = getLastNode(pNewHead);  
                pNode->m_pNext = pNextNode;  
                pLastNode = pNode;  
                pNode = pNextNode;  
            }
			else 
                break;  
        }  
        return pHead;  
    }  
      
    void printList(LNode* pHead) {  
        LNode* pNode = pHead;  
        while (pNode) {  
            cout << pNode->m_nValue << " ";  
            pNode = pNode->m_pNext;  
        }  
        cout << endl;  
    }  
      
    LNode* createList(int* arr, int length) {  
        LNode* pHead = NULL;  
        LNode* pTemp, *pNode;  
        for (int i = 0; i < length; i++) {  
            pNode = (LNode*)malloc(sizeof(LNode));  
            pNode->m_nValue = arr[i];  
            pNode->m_pNext = NULL;  
            if (NULL == pHead)  
                pHead = pNode;  
            else  
                pTemp->m_pNext = pNode;  
            pTemp = pNode;  
        }  
        return pHead;  
    }  
      
    void destroyList(LNode* pHead) {  
        LNode* pNode;  
        while (pHead) {  
            pNode = pHead;  
            pHead = pHead->m_pNext;  
            free(pNode);  
        }  
    }  
      
    int main() 
	{  
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  
        int length = sizeof(arr) / sizeof(arr[0]);  
        LNode* pHead = createList(arr, length);  

        pHead = swapListByK(pHead, 2);  

        printList(pHead);  
        destroyList(pHead);   
		
        return 0;  
    }  