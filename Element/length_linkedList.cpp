// Program which output the length of linked list

#include<bits/stdc++.h>
using namespace std;

class LL{
    private:
        int val;
        LL *next;
    public:
        LL(int x): val(x), next(NULL){}
        static LL *createLL(int key){
            LL *temp = new LL(key);
            temp->val = key;
            temp->next = NULL;
            return temp;
        }
        static LL *insert(LL *root, int key){
            if(root == NULL)
                return createLL(key);
            root->next = insert(root->next,key);
            return root;
        }
        static int lenLL(LL *root){
            int count = 1;
            while(root!=NULL){
                count += 1;
                root = root->next;
            }
            return count;
        }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LL *root = NULL;
    root = LL::insert(root,1);
    
    // Linked list is 1->2->3->4->5
    for(auto i = 2; i < 5; ++i)
        LL::insert(root,i);
    cout << LL::lenLL(root); // 5
}
