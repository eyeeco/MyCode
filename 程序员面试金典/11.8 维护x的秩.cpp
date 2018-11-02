class SearchTree {
public:
	int data;
	SearchTree* left,* right;
	int leftsize;
	SearchTree(int d):data(d),left(NULL),right(NULL),leftsize(0){}
	void insert(int num){
		if (num <= data){
			if (left == NULL) {
				left = new SearchTree(num);
			}
			else{
				left->insert(num);
			}
            leftsize++;
		}
		else{
			if (right != NULL) right->insert(num);
			else right = new SearchTree(num);
		}
	}
	int search(int num){
		if (num == data) return leftsize;
		else if (num<data){
			if (left == NULL) return -1;
			return left->search(num);
		}
		else{
			if (right == NULL) return -1;
			return leftsize + 1 + right->search(num);
		}
        return 0;
	}
};

class Rank {
public:
	vector<int> getRankOfNumber(vector<int> A, int n) {
		// write code here
		vector<int> res;
		if (n){
			SearchTree* root = new SearchTree(A[0]);
			res.push_back(0);
			for (int i = 1; i<A.size(); i++){
				root->insert(A[i]);
				res.push_back(root->search(A[i]));
            }
		}
		return res;
	}
};
