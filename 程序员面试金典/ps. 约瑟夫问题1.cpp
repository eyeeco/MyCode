class Joseph {
public:
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};
	int getResult(int n, int m) {
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		for (int i = 1; i <= n; i++){
			ListNode* temp = new ListNode(i);
			p->next = temp;7
			p = p->next;
		}
		p->next = head->next;
		while (p&&p->next!=p){
			int t = m;
			while (--t){
				p = p->next;
			}
			p->next = p->next->next;
		}
		return p->val;
	}
};
