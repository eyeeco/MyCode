// 1. 带过期时间LRU
class LRU{
public:
  LRU(int t, int timeO):cap(t), timeout(timeO){};
  int get(int key, int now){
    int t = now + timeout;
    if(kv.count(key)){
      touch(key, t);
      return kv[key];
    }else{
      return -1;
    }
  }
  void put(int key, int val, int now){
    int t = now + timeout;
    if(!kl.count(key)&&arr.size()==cap){
      kv.erase(arr.back());
      kl.erase(arr.back());
      kt.erase(arr.back());
      arr.pop_back();
    }
    touch(key, t);
    kv[key] = val;
  }

  int out(int key, int now){
    int count = 0;
    while(!arr.empty()&&kt[arr.back()] < now){
      kv.erase(arr.back());
      kl.erase(arr.back());
      kt.erase(arr.back());
      arr.pop_back();
      count++;
    }
    return count;
  }

private:
  list<int> arr;
  int cap, timeout;
  unordered_map<int, list<int>::iterator> kl;
  unordered_map<int, int> kv;
  unordered_map<int, int> kt;
  int touch(int key, int t){
    if(kl.count(key)){
      arr.erase(kl[key]);
    }
    arr.push_front(key);
    kl[key] = arr.begin();
    kt[key] = t;
  }
}


// 生产、消费者问题
#define int asph
asph mutex = 1;
asph empty = 100;
asph full = 0;
void producer(){
  while(1){
    P(&empty);
    P(&mutex);
    Item* item = new Item();
    vec.push_back(item);
    V(&mutex);
    V(&full);
  }
}
void consumer(){
  while(1){
    P(&full);
    P(&mutex);
    Item* item = vec.top();
    vec.pop();
    V(&mutex);
    V(&full);
  }
}

// 读写者问题
#define int asph
asph read = 1;
asph write = 1;
int count = 0;
void _read(){
  P(&read);
  count++;
  if(count == 1) P(&wirte);
  V(&read);
  read();
  P(&read);
  count--;
  if(count==0) V(&write);
  V(&read);
}

void _write(){
  P(&wirte);
  wirte();
  V(&write);
}


// 哲学家进餐问题
#define int asph
asph chp[] = {1,1,1,1,1};
asph mutex = 1;
void eat(i){
  while(True){
    P(&mutex);
    P(chp[i]);
    p(chp[(i+1)%5]);
    V(&mutex);
    _eat(i);
    V(chp[i]);
    V(chp[(i+1)%5]);
  }
}

// LCA问题
TreeNode* findLCA(TreeNode* root, TreeNode* left, TreeNode* right){
  if(root==NULL||root==left||root==right) return root;
  TreeNode* left = findLCA(root->left, left, right);
  TreeNode* right = findLCA(root->right, left, right);
  if(left==NULL&&right==NULL) return root;
  return left==NULL?right:left;
}

struct Node{
  Node* next;
  int key;
  int val;
  Node(int k, int v):key(k),val(v),next(NULL){};
}

// hash算法
class HashMap{
public:
  HashMap(int n){
    vec.resize(n);
  }
  void put(int key, int val){
    int index = getIndex(key);
    if(vec[index].empty()){
      Node* node = new Node(key, val);
      temp.push_back(node);
    }else{
      Node* temp = vec[index];
      Node* pre = search(temp, key);
      if(pre==NULL){
        temp->val = val;
      }else if(pre->next==NULL){
        Node* temp = new Node(key, val);
        pre->next = temp;
      }else{
        pre->next->val = val;
      }
    }
  }
  int get(int key){
    int index = getIndex(key);
    Node* temp = vec[index];
    Node* pre = search(temp, key);
    if(pre==NULL){
      return temp->val;
    }else if(pre->next==NULL){
      return -1;
    }else{
      return pre->next->val;
    }
  }
  void del(int key){
    int index = getIndex(key);
    Node* temp = vec[index];
    Node* pre = search(temp, key);
    if(pre==NULL){
      vec[index] = temp->next;
      delete(temp);
      temp=NULL;
    }else if(pre->next==NULL){
      printf("Error!");
      exit();
    }else{
      Node* old = pre->next;
      pre->next = pre->next->next;
      delete(old);
      old = NULL;
    }
  }
  Node* search(Node* root, int key){
    Node* pre = NULL;
    while(root!=NULL){
      if(root->key==key) break;
      pre = node;
      node = node->next;
    }
    return pre;
  }
  int hash(int key){
    return (key.hash()>>16)^key.hash();
  }
  int getIndex(int key){
    reurn hash(key)%vec.size();
  }
private:
  vector<Node*> vec;
}
