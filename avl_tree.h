#pragma once
#include <utility>
#include <iostream>
//Dylan Rollins 332001458

template <typename Comparable>
class AVLTree {
public:
    class Node{
    public:
        Comparable value;
        Node* left= nullptr;
        Node* right= nullptr;
        Node* parent= nullptr;
        Node* sibling= nullptr;
    };
    AVLTree()= default;

    ~AVLTree()=default;
    AVLTree(const AVLTree& copy)=default;

    [[maybe_unused]] int max(int a, int b){
        if (a>b){
            return a;
        }
        if(b>a){
            return b;
        }
        if(a==b){
            return a;
        }
    }

// Printmapgen does tree traversal recursively
    void printMapGen(Node* node, int gap, std::ostream& h)
    {
        //though we've built this list iteratively,
        //a recursive solution to printing is a lot better.
        if (node == nullptr)
            //base of recursion
            return;

        gap = gap + i;


        printMapGen(node->right, gap, h);

        for (int n = i; n < gap; n++){
            h << " ";
        }
        h << node->value;
        endl(h);
        //prints the value

        printMapGen(node->left, gap, h);
    }



    int height(Node* tick){
        if(tick== nullptr){
            return 0;
        }

        return (std::max(height(tick->left),height(tick->right))+1);
    }


    void print_tree(std::ostream& k= std::cout)
    {
        if(isRoot){
            k<<"<empty>";
            endl(k);
            return;

        }
        else {
            //begin recursion
            printMapGen(root, 0,k);
        }
    }

    void leftRotate(Node* current){


        Node* temp=current->sibling;
        Node* temp2;
        bool hasSib= false;
        if(temp!= nullptr){
            hasSib= true;
        }
        if(current->parent->left != nullptr){
            hasSib= true;
            temp2=current->parent->left;
        }

        current->sibling = current->parent->parent;
            current->parent->parent = current->sibling->parent;
            current->sibling->parent = current->parent;

            current->parent->left = current->sibling;


            //
            if(current->parent->parent!= nullptr)
            {
                if(current->parent->parent->left==current||current->parent->parent->left==current->sibling)
                    current->parent->parent->left = current->parent;
                //orig
                else{
                    current->parent->parent->right=current->parent;
                }
                if(current->sibling->sibling!=nullptr){
                    current->sibling->sibling->sibling = nullptr;
                }


            }
            if(!hasSib) {
                current->sibling->right = nullptr;
            }
            if(hasSib){
                current->sibling->right=temp2;
            }
            current->sibling->sibling = current;


            if(current->parent->parent== nullptr) {
                root = current->parent;

            }

              }

    void rightRotate(Node* current){

        Node* temp=current->sibling;
        Node* temp2;
        bool hasSib= false;
        if(temp!= nullptr){
            hasSib= true;
        }
        if(current->parent->right != nullptr){
            hasSib= true;
            temp2=current->parent->right;
        }

            current->sibling = current->parent->parent;
            current->parent->parent = current->sibling->parent;
            current->sibling->parent = current->parent;


            current->parent->right = current->sibling;
            if(current->parent->parent!= nullptr) {
                //
                if(current->parent->parent->right==current||current->parent->parent->right==current->sibling)
                    current->parent->parent->right = current->parent;
                    //orig
                else{
                    current->parent->parent->left=current->parent;
                }

                if(current->sibling->sibling!=nullptr){
                    current->sibling->sibling->sibling = nullptr;
                }
            }

        if(!hasSib) {
            current->sibling->left = nullptr;
        }
        if(hasSib){
            current->sibling->left=temp2;
        }
            current->sibling->sibling = current;

            if(current->parent->parent== nullptr) {
                root = current->parent;

            }
            //return;
            //. . .so these operations should complete any arbitrary right rotation
        //return;

    }
    void rightLeft(Node* current) {
            //in this case, a double rotation is required. . .
            //the implementation of this logically was hellish, but
            //gotta do what you gotta do for CSCE. Honestly, I know this
            //would have been easier if I just used grandparent instead of parent->parent
            //but you live and you learn.
            /*
            current->sibling = current->parent->parent;
            current->parent->parent = current->sibling->parent;
            current->sibling->parent = current->parent;

            current->parent->left = current->sibling;
            if(current->parent->parent!= nullptr) {
                current->parent->parent->right = current->parent;
                current->sibling->sibling->sibling = nullptr;

            }
            current->sibling->right = nullptr;
            current->sibling->sibling = current;
            if(current->parent->parent== nullptr) {
                root = current->parent;

            }
            return;

             */
             Node *tempp= nullptr;

            if(current->right!= nullptr) {
            tempp = current->right;
        }
        if(current == current->parent->left){
            current->sibling = current->parent;

            current->parent=current->sibling->parent;

            current->sibling->parent=current;
            current->sibling->parent = current->parent;

            current->parent->right = current;
            current->right=current->sibling;
            current->sibling->left= nullptr;
            current->sibling = nullptr;

            //flips one out


            current->left=current->parent;
            current->sibling=current->parent;
            current->parent=current->parent->parent;

            if(current->parent!= nullptr) {
                current->parent->right = current;
                current->sibling->right= nullptr;

                if(current->parent->left != nullptr){
                    current->parent->left->sibling=current;
                }
                current->right->parent=current;
                current->sibling->sibling=current;
                current->sibling=current->parent->left;
                if(current->sibling!= nullptr){
                    current->sibling->sibling=current;

                }
                current->right->sibling=current->left;
                current->left->sibling=current->right;

            }
            else {
                current->left->right = nullptr;
                root=current;
            }

            //
            if(tempp!= nullptr){
                current->right->left=tempp;

            }

            //
            current->left->parent=current;
            current->sibling= nullptr;

            current->right->sibling=current->left;
            current->left->sibling=current->right;

            current->right->parent=current;

            //
            if(current->right->left!= nullptr){
                current->right->left->parent=current->right;

            }
            if(current->right->right!= nullptr){
                if(current->right->left!= nullptr){
                    current->right->left->sibling=current->right->right;
                }
                current->right->right->sibling=current->right->left;
            }






            return;
            //12,76,69,3,19,31,40,80,24,4,95

        }
    }
    void leftRight(Node* current){\

        Node *tempp= nullptr;

        if(current->left!= nullptr) {
            tempp = current->left;
        }


        if(current == current->parent->right){
            current->sibling = current->parent;

            current->parent=current->sibling->parent;

            current->sibling->parent=current;
            current->sibling->parent = current->parent;

            current->parent->left = current;
            current->left=current->sibling;
            current->sibling->right= nullptr;
            current->sibling = nullptr;

            //flips one out


            current->right=current->parent;
            current->sibling=current->parent;
            current->parent=current->parent->parent;
            if(current->parent!= nullptr) {
                current->parent->left = current;
                current->sibling->left= nullptr;

                if(current->parent->right!= nullptr){
                    current->parent->right->sibling=current;
                }
                current->left->parent=current;
                current->sibling->sibling=current;
                current->sibling=current->parent->right;
                if(current->sibling!= nullptr){
                    current->sibling->sibling=current;

                }
                current->left->sibling=current->right;
                current->right->sibling=current->left;

            }
            else {
                current->right->left = nullptr;
                root=current;
            }

            //add

            if(tempp!= nullptr){
                current->right->left=tempp;

            }

            current->right->parent=current;
            current->sibling= nullptr;

            current->left->sibling=current->right;
            current->right->sibling=current->left;

            current->left->parent=current;


            if(current->left->right!= nullptr){
                current->left->right->parent=current->left;

            }
            if(current->left->left!= nullptr){
                if(current->left->right!= nullptr){
                    current->left->right->sibling=current->left->left;
                }
                current->left->left->sibling=current->left->right;
            }







            return;

        }
    }

    void insert(const Comparable& val){
        test=0;
        //TODO: handle nullptr return case (already in list)
        Node* current = avl_insert(val);
        if(isRoot){
            //is isRoot==true equivalent to current->parent->. . .no
            isRoot= false;
            return;
        }
        if (current== nullptr){
            std::cout<<"already in list";
            return;
        }
        if (current->parent== nullptr){
            return;
        }
        if(current->parent->parent== nullptr){
            //std::cout<<"leftHeight="<<height(root->left)<<"\n";
            //std::cout<<"mightHeight="<<height(root->right)<<"\n";
            return;
            //since BST and AVL tree are equal upto n=3,
            // we can just use BST insertion.
        }
        if(val==4){
            //leftRight(root->left->right);
        }
        Node* valium= nullptr;
        while (current->parent != nullptr){
            test++;
                //std::cout<<"current height ="<<height(current->parent->left)<<"-"<<height(current->parent->right)<<"="<<height(current->parent->left) - height(current->parent->right);

                if(std::abs(height(current->parent->left)- height(current->parent->right))<=1){
                    valium=current;
                    current=current->parent;
                    continue;
                }
                //std::cout<<"imbalance!!";


                //currprev=current;
                //clang-tidy


                current=valium;
                //and so it went. . . Might the work be done?
                //might the AVL tree be balanced all the way?
            if(current== nullptr){return;}
                    if (current->parent == current->parent->parent->right) {
                        if (current == current->parent->right) {
                            leftRotate(current);
                            current = current->parent;
                            continue;
                        } else if (current == current->parent->left) {
                            rightLeft(current);
                            if (current->parent != nullptr) {
                                current = current->parent;
                            } else { return; }
                            continue;
                        }

                    }

                    if (current->parent == current->parent->parent->left) {
                        if (current == current->parent->left) {
                            rightRotate(current);
                            current = current->parent;
                            continue;
                        } else if (current == current->parent->right) {
                            leftRight(current);
                            if (current->parent != nullptr) {
                                current = current->parent;
                            } else { return; }

                            continue;
                        }
                    }
                    else {
                        current = current->parent;
                        continue;
                    }
        }
        //else we potentially do the rotations.

        //if(current->parent==current->parent->parent->right&&current->parent->sibling== nullptr) {
            //double 1
        //}
        //if(current->parent==current->parent->parent->left&&current->parent->sibling== nullptr){
           //double 2
        //}

        //std::cout<<"leftHeight="<<height(root->left)<<"\n";
        //std::cout<<"mightHeight="<<height(root->right)<<"\n";

        //std::cout<<"**********";



    }


    Node* avl_insert(const Comparable& val){
        //while deriving this algorithm, I ran into a problem——there is no
        // way to know what the parent element is once we get to the nullptr.
        // This is simply resolved by adding a temporary parent pointer.
        //tThe issue that follows after this is knowing if the child
        //is right or left of the parent. A simple bool fix.

        bool parity;
        if(contains(val)==true){
            return nullptr;
        }

        //parity: 0 = left, 1 = right

        if (isRoot){
            root = new Node();
            root->value = val;
            size++;
            return nullptr;
        }
        else{
            Node* return_parent;
            //send to left
            Node* dig = root;
            //***
            Node* tempP;
            //temporary parent
            while(dig!= nullptr){
                if (val == dig->value){
                    std::cout<<"this value is already in the tree";
                    return nullptr;
                }
                if (val > dig->value){
                    //send to the right
                    tempP=dig;
                    dig=dig->right;
                    parity=true;
                }
                else if(val < dig->value){
                    tempP=dig;
                    dig=dig->left;
                    parity=false;
                }
            }
            if (parity==0){
                return_parent=tempP;
                tempP->left=new Node();
                tempP->left->value=val;
                tempP->left->parent=return_parent;
                tempP->left->sibling=return_parent->right;

                if(tempP->left->parent->right!= nullptr){
                    //assignment of siblings to each of the members helps us a lot in AVL.
                    //I'd say the memory overhead is worth it.
                    tempP->left->parent->right->sibling=tempP->left;
                }
                size++;
                return tempP->left;

            }
            if (parity==1){
                return_parent=tempP;
                tempP->right=new Node();
                tempP->right->value=val;
                tempP->right->parent=return_parent;
                tempP->right->sibling=return_parent->left;
                size++;

                if(tempP->right->parent->left!= nullptr){
                    tempP->right->parent->left->sibling=tempP->right;
                }
                return tempP->right;
            }
        }
    }


    std::pair<Node*,std::pair<Node*,int>> find(const Comparable& val){
        std::pair<Node*,std::pair<Node*,int>> tuple;
        //current,parent,parity

        int parity=-1;

        //parity: 0 = left, 1 = right

        if (isRoot){
            //never touched
        }
        else{
            //send to left
            Node* dig = root;
            //***
            Node* tempP;
            //temporary parent
            while(dig!= nullptr){
                if (val == dig->value){
                    tuple.first=dig;
                    tuple.second.first=tempP;
                    tuple.second.second=parity;
                    return tuple;
                }
                if (val > dig->value){
                    //send to the right
                    tempP=dig;
                    dig=dig->right;
                    parity=1;
                }
                else if(val < dig->value){
                    tempP=dig;
                    dig=dig->left;
                    parity=0;
                }
            }
            tuple.first= nullptr;
            tuple.second.first= nullptr;
            tuple.second.second=-1;
            return tuple;
        }
    }
    void remove(const Comparable& val){
        if(contains(val)== false){
            std::cout<<"not in the tree";
            return;
        }

        if((root->right== nullptr&&root->left== nullptr) &&root->value==val){
            delete root;
            isRoot= true;
            size--;
            return;
        }

        Node* current =(find(val).first);
        Node* parent =(find(val).second.first);
        bool parentParity= find(val).second.second;


        if(current->left == nullptr&&current->right == nullptr){
            //the case where both are nullptr (leaves)
            delete current;
            if(parentParity == 0){
                parent->left= nullptr;
            }
            if(parentParity == 1){
                parent->right= nullptr;
            }
            size--;
            return;
        }
        if(current->left == nullptr&&current->right != nullptr){
            //1/2 cases that one is null and the other has a value (rightval)
            if(parentParity == 0){
                parent->left= current->right;
            }
            if(parentParity == 1){
                parent->right= current->right;
            }
            delete current;
            size--;
            return;
        }
        if(current->left != nullptr&&current->right == nullptr){
            //1/2 cases that one is null and the other has a value (leftval)
            if(parentParity == 0){
                parent->left= current->left;
            }
            if(parentParity == 1){
                parent->right= current->left;
            }
            delete current;
            size--;
            return;
        }
        else{
            //case of both children non-null
            Node* minRST = current->right;
            //Does the good old minimum right subtree dive
            //it also removes the value that has
            Comparable temp;
            while(minRST->left!= nullptr){
                minRST=minRST->left;
            }
            temp = minRST->value;
            remove(minRST->value);
            current->value=temp;
            size--;
        }
        std::cout<<"invalid";

    }

    bool contains(const Comparable& val){
        //while deriving this algorithm, I ran into a problem——there is no
        // way to know what the parent element is once we get to the nullptr.
        // This is simply resolved by adding a temporary parent pointer.
        //tThe issue that follows after this is knowing if the child
        //is right or left of the parent. A simple bool fix.

        //parity: 0 = left, 1 = right

        if (isRoot){
            //TODO:
            return false;
        }
        else{
            Node* dig = root;
            while(dig!= nullptr){
                if (val == dig->value){
                    std::cout<<"this value is already in the tree";
                    return true;
                }
                if (val > dig->value){
                    //send to the right
                    dig=dig->right;
                }
                else if(val < dig->value){
                    dig=dig->left;
                }
            }
            //std::cout<<"this value is not in the tree";
            return false;
        }
    }
    const Comparable& find_min() const{
        if(isRoot||size==0){
            throw std::out_of_range("the tree is empty");
        }
        else{
            Node* trav = root;
            while(trav->left!= nullptr){
                trav=trav->left;
            }
            return trav->value;
        }

    }
    const Comparable& find_max() const{
        if(isRoot||size==0){
            throw std::out_of_range("the tree is empty");
        }
        else{
            Node* trav = root;
            while(trav->right!= nullptr){
                trav=trav->right;
            }
            return trav->value;
        }

    }

    [[maybe_unused]] [[nodiscard]] int siz() const{
        return size;
    }

private:
    Node* root= nullptr;
    bool isRoot=true;
    [[maybe_unused]] bool hasChild= false;
    int i = 2;
    int size=1;
    [[maybe_unused]] int right_iter=0;
    [[maybe_unused]] int left_iter=0;
    int test=0;

};
